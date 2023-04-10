local util = require("util")
local crash_site = require("crash-site")

local tas_generator = require("steps")
local steps = tas_generator.steps
local debug_state = require("goal")
local run = true

local step
local step_reached = 0
local idle
local pickup_ticks
local mining

local player
local player_selection
local player_position
local destination
local target_position
local target_inventory
local walking
local task
local task_category
local count
local item
local amount
local slot
local direction
local input
local output
local type
local rev
local duration
local ticks_mining
local idled
local font_size = 0.15 --best guess estimate of fontsize for flying text

local pos_pos
local pos_neg
local neg_pos
local neg_neg
local compatibility_mode
local keep_x
local keep_y
local diagonal

local drop_item
local drop_position

local queued_save
local tas_step_change = script.generate_event_name()
local tas_state_change = script.generate_event_name()

local function save_global()
	--if not global.tas then return end
	global.tas.step = step
	global.tas.idle = idle
	global.tas.pickup_ticks = pickup_ticks
	global.tas.mining = mining
	global.tas.pos_pos = pos_pos
	global.tas.pos_neg = pos_neg
	global.tas.neg_pos = neg_pos
	global.tas.neg_neg = neg_neg
	global.tas.compatibility_mode = compatibility_mode
	global.tas.keep_x = keep_x
	global.tas.keep_y = keep_y
	global.tas.diagonal = diagonal
	global.tas.player_selection = player_selection
	global.tas.destination = destination
	global.tas.target_position = target_position
	global.tas.target_inventory = target_inventory
	global.tas.walking = walking
	global.tas.task = task
	global.tas.task_category = task_category
	global.tas.count = count
	global.tas.item = item
	global.tas.amount = amount
	global.tas.slot = slot
	global.tas.direction = direction
	global.tas.input = input
	global.tas.output = output
	global.tas.type = type
	global.tas.rev = rev
	global.tas.duration = duration
	global.tas.ticks_mining = ticks_mining
	global.tas.idled = idled

	global.tas.player = player
end

--recreate crash site
local on_player_created = function(event)
	if remote.interfaces["freeplay"] == nil then return end
	
	local player = game.get_player(event.player_index)
	local surface = player.surface
	local crashed_ship_items = remote.call("freeplay", "get_ship_items")
	local crashed_debris_items = remote.call("freeplay", "get_debris_items")
	util.insert_safe(player, global.created_items)

    surface.daytime = 0.7
    crash_site.create_crash_site(surface, {-5,-6}, util.copy(crashed_ship_items), util.copy(crashed_debris_items))
    util.remove_safe(player, crashed_ship_items)
    util.remove_safe(player, crashed_debris_items)
    player.get_main_inventory().sort_and_merge()
end

--Print message intended for viewers
local function msg(msg)
    player.print(msg)
end

--Print debug message about what the tas is doing
local function debug(msg)
	if debug_state then
		player.print(msg)
        player.print(string.format(
            "Seconds: %s, tick: %s, player position [%d, %d]",
            game.tick / 60,
            game.tick,
            player.position.x,
            player.position.y
	))
	end
end

--Print warning in case of errors in tas programming
local function warning(msg)
    if debug_state then
		player.print(msg, {r=1, g=1}) -- print warnings in yellow
	end
end

---@param by number
local function change_step(by)
	local _task = 0
	if steps and steps[step] and steps[step][1][1] then
		_task = steps[step][1][1] 
	end
	step = step + by
	script.raise_event(tas_step_change, {
		change_step_by = by,
		step = step,
		task = _task,
		tick = game.tick,
	})
end

local function save(task, nameOfSaveGame)
	save_global()
	if game.is_multiplayer() then
		debug(string.format("Step: %s, saving game as %s", task, nameOfSaveGame))
		game.server_save(nameOfSaveGame)
		return true
	end

	debug(string.format("Step: %s, saving game as _autosave-%s", task, nameOfSaveGame))
	game.auto_save(nameOfSaveGame)
	return true;
end

local function format_name(str)
	return str:gsub("^%l", string.upper):gsub("-", " ") --uppercase first letter and replace dashes with spaces
end

-- Check that the entity can be selected and is within reach
local function check_selection_reach()
	player.update_selected_entity(target_position)
	player_selection = player.selected

	if not player_selection then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - %s: Cannot select entity", task[1], task[2], step, task_category))
		end

		return false
	end

	if not player.can_reach_entity(player_selection) then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - %s: Cannot reach entity", task[1], task[2], step, task_category))
		end

		return false
	end

	return true
end

-- Check that it is possible to get the inventory of the entity
local function check_inventory()
	target_inventory = player_selection.get_inventory(slot)

	if not target_inventory then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - %s: Cannot get entity inventory", task[1], task[2], step, task_category))
		end

		return false
	end

	return true
end

-- Place an item from the character's inventory into an entity's inventory
-- Returns false on failure to prevent advancing step until within reach
local function put()

	if not check_selection_reach() then
		return false;
	end

	if not check_inventory() then
		return false;
	end

	local removalable_items = player.get_item_count(item)
	local insertable_items = target_inventory.get_insertable_count(item)
	if amount < 1 then
		amount = math.min(removalable_items, insertable_items)
	end

	if removalable_items == 0 then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - Put: %s is not available in your inventory", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
		end

		return false;
	end

	if insertable_items == 0 then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - Put: %s can't be put into target inventory", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
		end

		return false;
	end

	if amount > removalable_items or amount > insertable_items then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - Put: not enough %s can be transferred. Amount: %d Removalable: %d Insertable: %d", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper), amount, removalable_items, insertable_items))
		end

		return false
	end

	amount=target_inventory.insert{
		name=item,
		count=amount,
	}

	if amount < 1 then
		warning(string.format("Step: %s, Action: %s, Step: %d - Put: %s can not be transferred. Amount: %d Removalable: %d Insertable: %d", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper), amount, removalable_items, insertable_items))
		return false
	end

	amount = player.remove_item{
		name=item,
		count=amount,
	}

	local text = string.format("-%d %s (%d)", amount, format_name(item), player.get_item_count(item)) --"-2 Iron plate (5)"
	local pos = {x = target_inventory.entity_owner.position.x + #text/2 * font_size, y = target_inventory.entity_owner.position.y }
	player.play_sound{path="utility/inventory_move"}
	player.create_local_flying_text{
		text=text,
		position=pos}

	return true
end

-- Place an item into the character's inventory from an entity's inventory
-- Returns false on failure to prevent advancing step until within reach
local function take()

	if not check_selection_reach() then
		return false
	end

	if not check_inventory() then
		return false;
	end

	local removalable_items = target_inventory.get_item_count(item)
	local insertable_items = player.get_main_inventory().get_insertable_count(item)
	if amount < 1 then
		amount = math.min(removalable_items, insertable_items)
	end

	if removalable_items == 0 then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - Take: %s is not available from the inventory", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
		end

		return false;
	end

	if insertable_items == 0 then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - Take: %s can't be put into your inventory", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
		end

		return false;
	end

	if amount > removalable_items or amount > insertable_items then
		if not walking.walking then
			warning(string.format("Step: %s, Action: %s, Step: %d - Take: not enough %s can be transferred. Amount: %d Removalable: %d Insertable: %d", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper), amount, removalable_items, insertable_items))
		end

		return false
	end

	amount = player.insert{
		name=item,
		count=target_inventory.remove{name=item, count=amount}
	}

	local text = string.format("+%d %s (%d)", amount, format_name(item), player.get_item_count(item)) --"+2 Iron plate (5)"
	local pos = {x = target_inventory.entity_owner.position.x + #text/2 * font_size, y = target_inventory.entity_owner.position.y }
	player.play_sound{path="utility/inventory_move"}
	player.create_local_flying_text{
		text=text,
		position=pos}

	return true
end

-- Handcraft one or more of a recipe
local function craft()
	if not player.force.recipes[item].enabled then
		if(step > step_reached) then
			warning(string.format("Step: %s, Action: %s, Step: %d - Craft: It is not possible to craft %s - It needs to be researched first.", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
			step_reached = step
		end

		return false;
	end

	amount = player.get_craftable_count(item)

	if amount > 0 then
		if count == -1 then
			player.begin_crafting{count = amount, recipe = item}
		elseif count <= amount then
			player.begin_crafting{count = count, recipe = item}
		else
			if not walking.walking then
				warning(string.format("Step: %s, Action: %s, Step: %d - Craft: It is not possible to craft %s - Only possible to craft %d of %d", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper), amount, count))
			end

			return false
		end

		return true
    else
        if(step > step_reached) then
            warning(string.format("Step: %s, Action: %s, Step: %d - Craft: It is not possible to craft %s - Please check the script", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
            step_reached = step
		end

        return false
	end
end

-- Cancels a handcraft a recipe
local function cancel_crafting()
	local queue = player.crafting_queue

	for i = 1, #queue do
		if queue[i].recipe == item then
			if count == -1 then
				player.cancel_crafting{index = i, count = 1000000}
				return true
			elseif queue[i].count >= count then
				player.cancel_crafting{index = i, count = count}
				return true
			else
				warning(string.format("Step: %s, Action: %s, Step: %d - Cancel craft: It is not possible to cancel %s - Please check the script", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
				return false
			end
		end
	end
	warning(string.format("Step: %s, Action: %s, Step: %d - Cancel craft: It is not possible to cancel %s - Please check the script", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
	return false
end

local function item_is_tile(item)
	if item == "stone-brick"
	or item == "concrete"
    or item == "hazard-concrete"
    or item == "refined-concrete"
    or item == "refined-hazard-concrete"
    or item == "landfill" then
        return true
    end
    return false
end

local function tile_is_in_reach()	
	local x = player.position.x - target_position[1]
	local y = player.position.y - target_position[2]
	local dis = math.sqrt(x^2+y^2) --sqrt(a^2+b^2)=sqrt(c^2)
	return dis <= 10.25 -- It seems like 10.25 aligns best with the current walking algorithm
end

---comment Places an entity, possibly fast replacing. Then handless 
---@return boolean true if an entity is created.
local function create_entity_replace()

	local fast_replace_type_lookup = {
		["underground-belt"] = {"transport-belt", "fast-transport-belt", "express-transport-belt"},
		["fast-underground-belt"] = {"transport-belt", "fast-transport-belt", "express-transport-belt"},
		["express-underground-belt"] = {"transport-belt", "fast-transport-belt", "express-transport-belt"},
		["pipe-to-ground"] = {"pipe"}
		}

	local created_entity = player.surface.create_entity{name = item, position = target_position, direction = direction, force="player", fast_replace=true, player=player, raise_built = true}
	if created_entity and fast_replace_type_lookup[created_entity.name] ~= nil and created_entity.neighbours  then --connected entities eg underground belt https://lua-api.factorio.com/latest/LuaEntity.html#LuaEntity.neighbours
		local replace_type = fast_replace_type_lookup[created_entity.name]

		local neighbour_position = nil
		if (#created_entity.neighbours == 0) then 
			neighbour_position = created_entity.neighbours.position
		else
			for _,neighbour in pairs(created_entity.neighbours[1]) do
				if (created_entity.name == neighbour.name) then
					neighbour_position = neighbour.position
				end
			end
		end
		if (not neighbour_position) then
			player.remove_item({name = item, count = 1})
			return true
		end

		local entities_between = player.surface.find_entities_filtered{name = replace_type, area = {
			{x=math.min(created_entity.position.x, neighbour_position.x), y=math.min(created_entity.position.y, neighbour_position.y)},
			{x=math.max(created_entity.position.x, neighbour_position.x), y=math.max(created_entity.position.y, neighbour_position.y)}}}
		local entities_between_length = math.abs(created_entity.position.x - neighbour_position.x + created_entity.position.y - neighbour_position.y) - 1
		local can_replace_all = entities_between_length == #entities_between

		--chech that all entities betweeen are in the same direction
		if can_replace_all and created_entity.name ~= "pipe-to-ground" then --ignore direction for pipes
			for __, e in pairs(entities_between) do
				if e.direction ~= created_entity.direction then
					can_replace_all = false
					break
				end
			end
		elseif can_replace_all and created_entity.name == "pipe-to-ground" then
			for __, e in pairs(entities_between) do --check all entities
				if e.neighbours and e.neighbours[1] then -- null check
					for ___, n in pairs(e.neighbours[1]) do --check all neighbours for each entity
						for i = 1, #entities_between do --make sure it exist every neighbour is only part of the set of entities between
							if entities_between[i] == n then
								can_replace_all = true
								break --break out when found
							else
								can_replace_all = false
							end
						end
						if not can_replace_all then break end --previous loop didn't find it
					end
				end
				if not can_replace_all then break end --break out
			end
		end
		--mine all entities inbetween
		if can_replace_all then
			for __, e in pairs(entities_between) do
				player.mine_entity(e, true)
			end
		end
		--spend the item placed
		player.remove_item({name = item, count = 1})
		return true
	end

	--no special fast replace handling
	if created_entity then
		player.remove_item({name = item, count = 1})
	end
	return created_entity ~= nil
end

-- Creating buildings
local function build()

	if player.get_item_count(item) == 0 then
		if(step > step_reached) then
			if walking.walking == false then
				warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s not available", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
				step_reached = step
			end
		end

		return false
	end

	if (item ~= "rail") then
		if item_is_tile(item) then
			if tile_is_in_reach() then
				if item == "stone-brick" then 
					player.surface.set_tiles({{position = target_position, name = "stone-path"}})
				elseif (item == "hazard-concrete") or (item == "refined-hazard-concrete") then
					player.surface.set_tiles({{position = target_position, name = item.."-left"}})
				else
					player.surface.set_tiles({{position = target_position, name = item}})
				end

				if(item == "landfill") then
					player.surface.play_sound{path="tile-build-small/landfill", position=target_position}
				else
					player.surface.play_sound{path="tile-build-small/concrete", position=target_position}
				end

				player.remove_item({name = item, count = 1})
				return true

			elseif not walking.walking then
				warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s not in reach", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
			end

			return false

		elseif player.can_place_entity{name = item, position = target_position, direction = direction} then
			return create_entity_replace()
		else 
			if not walking.walking then
				warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s cannot be placed", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
			end

			return false
		end
	else
		if player.can_place_entity{name = "straight-rail", position = target_position, direction = direction} then
			if player.surface.can_fast_replace{name = "straight-rail", position = target_position, direction = direction, force = "player"} then
				if player.surface.create_entity{name = "straight-rail", position = target_position, direction = direction, force="player", fast_replace=true, player=player, raise_built = true} then
					player.remove_item({name = item, count = 1})
					return true
				end
			else
				if player.surface.create_entity{name = "straight-rail", position = target_position, direction = direction, force="player", raise_built = true} then
					player.remove_item({name = item, count = 1})
					return true
				end
			end

		else
			if not walking.walking then
				warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s cannot be placed", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
			end

			return false
		end
	end
end

local function walk_pos_pos()
	if keep_x then
		if player_position.y > destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if keep_y then
		if player_position.x > destination.x then
			return {walking = true, direction = defines.direction.west}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if diagonal then
		if player_position.x > destination.x or player_position.y > destination.y then
			return {walking = true, direction = defines.direction.northwest}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if player_position.x > destination.x then
		if player_position.y > destination.y then
			return {walking = true, direction = defines.direction.northwest}
		else
			return {walking = true, direction = defines.direction.west}
		end
	else
		if player_position.y > destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			if compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = walking.direction}
			end
		end
	end
end

local function walk_pos_neg()
	if keep_x then
		if player_position.y < destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if keep_y then
		if player_position.x > destination.x then
			return {walking = true, direction = defines.direction.west}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if diagonal then
		if player_position.x > destination.x or player_position.y < destination.y then
			return {walking = true, direction = defines.direction.southwest}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if player_position.x > destination.x then
		if player_position.y < destination.y then
			return {walking = true, direction = defines.direction.southwest}
		else
			return {walking = true, direction = defines.direction.west}
		end
	else
		if player_position.y < destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			if compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = walking.direction}
			end
		end
	end
end

local function walk_neg_pos()
	if keep_x then
		if player_position.y > destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if keep_y then
		if player_position.x < destination.x then
			return {walking = true, direction = defines.direction.east}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if diagonal then
		if player_position.x < destination.x or player_position.y > destination.y then
			return {walking = true, direction = defines.direction.northeast}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if player_position.x < destination.x then
		if player_position.y > destination.y then
			return {walking = true, direction = defines.direction.northeast}
		else
			return {walking = true, direction = defines.direction.east}
		end
	else
		if player_position.y > destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			if compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = walking.direction}
			end
		end
	end
end

local function walk_neg_neg()
	if keep_x then
		if player_position.y < destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if keep_y then
		if player_position.x < destination.x then
			return {walking = true, direction = defines.direction.east}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if diagonal then
		if player_position.x < destination.x or player_position.y < destination.y then
			return {walking = true, direction = defines.direction.southeast}
		else
			return {walking = false, direction = walking.direction}
		end
	end

	if player_position.x < destination.x then
		if player_position.y < destination.y then
			return {walking = true, direction = defines.direction.southeast}
		else
			return {walking = true, direction = defines.direction.east}
		end
	else
		if player_position.y < destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			if compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = walking.direction}
			end
		end
	end
end

local function walk()
	if pos_pos then
		return walk_pos_pos()
	elseif pos_neg then
		return walk_pos_neg()
	elseif neg_pos then
		return walk_neg_pos()
	elseif neg_neg then
		return walk_neg_neg()
	end

	if compatibility_mode then
		return {walking = false, direction = defines.direction.north}
	else
		return {walking = false, direction = walking.direction}
	end
end

local function find_walking_pattern()
	if compatibility_mode then
		if (player_position.x - destination.x >= 0) then
			if (player_position.y - destination.y >= 0) then
				pos_pos = true
				pos_neg = false
				neg_pos = false
				neg_neg = false
			elseif (player_position.y - destination.y < 0) then
				pos_neg = true
				pos_pos = false
				neg_pos = false
				neg_neg = false
			end
		else
			if (player_position.y - destination.y >= 0) then
				neg_pos = true
				pos_pos = false
				pos_neg = false
				neg_neg = false
			elseif (player_position.y - destination.y < 0) then
				neg_neg = true
				pos_pos = false
				pos_neg = false
				neg_pos = false
			end
		end
	else
		pos_pos = false
		pos_neg = false
		neg_pos = false
		neg_neg = false

		if (player_position.x - destination.x >= 0) then
			if (player_position.y - destination.y >= 0) then
				pos_pos = true
			else
				pos_neg = true
			end
		else
			if (player_position.y - destination.y >= 0) then
				neg_pos = true
			else
				neg_neg = true
			end
		end
	end
end

local function update_player_position()
	player_position = player.position
end

local function update_destination_position(x, y)
	destination = { x = x, y = y }

	if compatibility_mode then
		return
	end

	keep_x = false
	keep_y = false
	diagonal = false

if steps[step] and steps[step][5] and steps[step][5] == "same_x" then
		keep_x = true
	end

	if steps[step] and steps[step][6] and steps[step][6] == "same_y" then
		keep_y = true
	end

	if steps[step] and steps[step][5] and steps[step][5] == "diagonal" then
		diagonal = true
	end
end

local function rotate()
	local r = false
	if not check_selection_reach() then
		return false;
	end

	if rev then
		r = player_selection.rotate({reverse = true})
	else
		r = player_selection.rotate({reverse = false})
	end

	if r then player.play_sound{path="utility/rotated_small"} end

	return true
end

local function recipe()

	if not check_selection_reach() then
		return false
	end

	if not player.force.recipes[item].enabled then
		if(step > step_reached) then
			warning(string.format("Step: %s, Action: %s, Step: %d - Recipe: It is not possible to set recipe %s - It needs to be researched first.", task[1], task[2], step, item:gsub("-", " "):gsub("^%l", string.upper)))
			step_reached = step
		end

		return false;
	end

	local items_returned = player_selection.set_recipe(item)

	for name, count_ in pairs (items_returned) do
		player.insert{name = name, count = count_}
	end

	return true
end

local function tech()
	if steps[step].comment and steps[step].comment == "Cancel" and player.force.current_research then
		player.force.research_queue = {}
		player.force.add_research(item)
		msg(string.format("Research: Cleared queue and %s added", item))
		return true
	end

	player.force.add_research(item)
	msg(string.format("Research: %s added", item))
	return true
end

local function pause()
	game.tick_paused = true
	run = false
	return true
end

-- Set the gameplay speed. 1 is standard speed
local function speed(speed)
	game.speed = speed
    msg(string.format("Changed game speed to %s", speed))
	return true
end

-- Set the inventory slot space on chests (and probably other items, which are untested)
-- Returns false on failure to prevent advancing step until within reach
local function limit()
	if not check_selection_reach() then
		return false
	end

	if not check_inventory() then
		return false
	end

	-- Setting set_bar to 1 completely limits all slots, so it's off by one
	target_inventory.set_bar(amount+1)
	return true
end

local function priority()

	if not check_selection_reach() then
		return false
	end

	player_selection.splitter_input_priority = input
	player_selection.splitter_output_priority = output

	return true
end

local function filter()

	if not check_selection_reach() then
		return false
	end

	if type == "splitter" then
		if item == "none" then
			player_selection.splitter_filter = nil
		else
			player_selection.splitter_filter = item
		end

		return true
	end

	if item == "none" then
		player_selection.set_filter(slot, nil)
	else
		player_selection.set_filter(slot, item)
	end

	return true
end

-- Drop items on the ground (like pressing the 'z' key)
local function drop()
	local can_reach = 10 > math.sqrt(
		math.abs(player.position.x - drop_position[1])^2 + math.abs(player.position.y - drop_position[2])^2
	)
	if player.get_item_count(drop_item) > 0 and can_reach then
		player.surface.create_entity{name = "item-on-ground",
								stack = {
									name = drop_item,
									count = 1,
								},
								position = drop_position,
								force = "player",
								spill = true
								}
		player.remove_item({name = drop_item})
		return true
	end

	return false
end

-- Manually launch the rocket
-- Returns false on failure to prevent advancing step until the launch succeeds
local function launch()
	if not check_selection_reach() then
		return false
	end

	return player_selection.launch_rocket()
end

-- Routing function to perform one of the many available steps
-- True: Indicates the calling function should advance the step. 
-- False: Indicates the calling function should not advance step.
local function doStep(current_step)
	if current_step[2] == "craft" then
        task_category = "Craft"
        task = current_step[1]
		count = current_step[3]
		item = current_step[4]

		return craft()

	elseif current_step[2] == "cancel crafting" then
        task_category = "Cancel craft"
        task = current_step[1]
		count = current_step[3]
		item = current_step[4]

		return cancel_crafting()

	elseif current_step[2] == "build" then
        task_category = "Build"
        task = current_step[1]
		target_position = current_step[3]
		item = current_step[4]
		direction = current_step[5]

		return build()

	elseif current_step[2] == "take" then
        task_category = "Take"
        task = current_step[1]
		target_position = current_step[3]
		item = current_step[4]
		amount = current_step[5]
		slot = current_step[6]

		return take()

	elseif current_step[2] == "put" then
        task_category = "Put"
        task = current_step[1]
		target_position = current_step[3]
		item = current_step[4]
		amount = current_step[5]
		slot = current_step[6]

		return put()

	elseif current_step[2] == "rotate" then
        task_category = "Rotate"
        task = current_step[1]
		target_position = current_step[3]
		rev = current_step[4]

		return rotate()

	elseif current_step[2] == "tech" then
        task_category = "Tech"
        task = current_step[1]
		item = current_step[3]

		return tech()

	elseif current_step[2] == "recipe" then
        task_category = "Recipe"
        task = current_step[1]
		target_position = current_step[3]
		item = current_step[4]

		return recipe()

	elseif current_step[2] == "limit" then
        task_category = "limit"
        task = current_step[1]
		target_position = current_step[3]
		amount = current_step[4]
		slot = current_step[5]

		return limit()

	elseif current_step[2] == "priority" then
        task_category = "priority"
        task = current_step[1]
		target_position = current_step[3]
		input = current_step[4]
		output = current_step[5]

		return priority()

	elseif current_step[2] == "filter" then
        task_category = "filter"
        task = current_step[1]
		target_position = current_step[3]
		item = current_step[4]
		slot = current_step[5]
		type = current_step[6]

		return filter()

    elseif current_step[2] == "drop" then
        task = current_step[1]
		drop_position = current_step[3]
		drop_item = current_step[4]
		return drop()

	elseif current_step[2] == "pick" then
		player.picking_state = true
		return true

	elseif current_step[2] == "idle" then
		idle = current_step[3]
		return true

	elseif current_step[2] == "launch" then
		task_category = "launch"
        task = current_step[1]
		target_position = current_step[3]

		return launch()
	end
end

local function handle_pretick()
	--pretick sets step directly so it doesn't raise too many events
	while run do
		if steps[step] == nil then
			debug_state = false
			run = false
			return
		elseif (steps[step][2] == "speed") then
			if steps[step].comment then msg(steps[step].comment) end
			debug(string.format("Step: %s, Action: %s, Step: %s - Game speed: %d", steps[step][1][1], steps[step][1][2], step, steps[step][3]))
			speed(steps[step][3])
			step = step + 1
		elseif steps[step][2] == "save" then
			queued_save = {name = steps[step][1][1], step = steps[step][3]}
			step = step + 1
		elseif steps[step][2] == "pick" then
			if steps[step].comment then msg(steps[step].comment) end
			pickup_ticks = pickup_ticks + steps[step][3] - 1
			player.picking_state = true
			change_step(1)
		elseif (steps[step][2] == "pause") then
			pause()
			msg("Script paused")
			msg(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", player_position.x, player_position.y, player.online_time / 60, player.online_time))
			change_step(1)
			debug_state = false
		elseif(steps[step][2] == "walk" and walking.walking == false and idle < 1) then
			update_destination_position(steps[step][3][1], steps[step][3][2])

			find_walking_pattern()
			walking = walk()
			change_step(1)
		else
			return --no more to do, break loop
		end
	end
end

local function handle_ontick()
	if pickup_ticks > 0 then
		player.picking_state = true
		pickup_ticks = pickup_ticks - 1
	end
	if walking.walking == false then
		if idle > 0 then
			idle = idle - 1
			idled = idled + 1

			debug(string.format("Step: %s, Action: %s, Step: %s - idled for %d", steps[step][1][1]-1, steps[step][1][2], step-1, idled))

			if idle == 0 then
				idled = 0
				if steps[step].comment then msg(steps[step].comment) end

				if steps[step][2] == "walk" then
					update_destination_position(steps[step][3][1], steps[step][3][2])

					find_walking_pattern()
					walking = walk()

					change_step(1)
				end
			end
		elseif steps[step][2] == "walk" then
			if steps[step].comment then msg(steps[step].comment) end
			update_destination_position(steps[step][3][1], steps[step][3][2])
			
			find_walking_pattern()
			walking = walk()
			
			change_step(1)

		elseif steps[step][2] == "mine" then
			if duration and duration == 0 and steps[step].comment then msg(steps[step].comment) end
			
			player.update_selected_entity(steps[step][3])

			player.mining_state = {mining = true, position = steps[step][3]}

			duration = steps[step][4]

			ticks_mining = ticks_mining + 1

			if ticks_mining >= duration then
				player.mining_state = {mining = false, position = steps[step][3]}
				change_step(1)
				mining = 0
				ticks_mining = 0
			end

			mining = mining + 1
			if mining > 5 then
				if player.character_mining_progress == 0 then
					warning(string.format("Step: %s, Action: %s, Step: %s - Mine: Cannot reach resource", steps[step][1][1], steps[step][1][2], step))
					debug_state = false
				else
					mining = 0
				end
			end

		elseif doStep(steps[step]) then
			-- Do step while standing still
			if steps[step].comment then msg(steps[step].comment) end
			change_step(1)
		end
	else
		if steps[step][2] ~= "walk" and steps[step][2] ~= "mine" and steps[step][2] ~= "idle" then
			if doStep(steps[step]) then
				-- Do step while walking
				if steps[step].comment then msg(steps[step].comment) end
				change_step(1)
			end
		end
	end
end

--- handle end the run
local function handle_posttick()
	if not run then
		return
	end

	if queued_save then
		save(queued_save.name, queued_save.step)
		queued_save = nil
	end

	if walking.walking or mining~=0 or pickup_ticks~=0 or idle~=0 then
		-- we wait to finish the previous step before we end the run
	elseif steps[step] == nil or steps[step][1] == "break" then
		msg(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", player_position.x, player_position.y, player.online_time / 60, player.online_time))
		debug_state = false
		run = false
		return
	end
end

local function handle_tick()
	walking = walk()
	handle_pretick()

	if not run then --early end from pretick
		return
	end

	handle_ontick()

	handle_posttick()
end

local function backwards_compatibility()
	if steps[step] == nil or steps[step][1] == "break" then
		debug(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", player_position.x, player_position.y, player.online_time / 60, player.online_time))
		debug_state = false
		return
	end

	if (steps[step][2] == "pause") then
		pause()
		debug("Script paused")
		debug(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", player_position.x, player_position.y, player.online_time / 60, player.online_time))
		debug_state = false
		return
	end

	if (steps[step][2] == "speed") then
		debug(string.format("Step: %s, Action: %s, Step: %s - Game speed: %d", steps[step][1][1], steps[step][1][2], step, steps[step][3]))
		speed(steps[step][3])
		change_step(1)
	end

	if steps[step][2] == "save" then
		change_step(1)
		save(steps[step-1][1][1], steps[step-1][3])
	end

	if pickup_ticks > 0 then
		player.picking_state = true
		pickup_ticks = pickup_ticks - 1
	end

	walking = walk()
	if walking.walking == false then
		if idle > 0 then
			idle = idle - 1
			idled = idled + 1

			debug(string.format("Step: %s, Action: %s, Step: %s - idled for %d", steps[step][1][1]-1, steps[step][1][2], step-1, idled))

			if idle == 0 then
				idled = 0
			end
		elseif steps[step][2] == "walk" then
			update_destination_position(steps[step][3][1], steps[step][3][2])

			find_walking_pattern()
			walking = walk()

			change_step(1)

		elseif steps[step][2] == "mine" then

			player.update_selected_entity(steps[step][3])

			player.mining_state = {mining = true, position = steps[step][3]}

			duration = steps[step][4]

			ticks_mining = ticks_mining + 1

			if ticks_mining >= duration then
				player.mining_state = {mining = false, position = steps[step][3]}
				change_step(1)
				mining = 0
				ticks_mining = 0
			end

			mining = mining + 1
			if mining > 5 then
				if player.character_mining_progress == 0 then
					warning(string.format("Step: %s, Action: %s, Step: %s - Mine: Cannot reach resource", steps[step][1][1], steps[step][1][2], step))
					debug_state = false
				else
					mining = 0
				end
			end

		elseif doStep(steps[step]) then
			-- Do step while standing still
			change_step(1)

		end
	else
		if steps[step][2] ~= "walk" and steps[step][2] ~= "mine" and steps[step][2] ~= "idle" and steps[step][2] ~= "pick" then
			if doStep(steps[step]) then
				-- Do step while walking
				change_step(1)
			end
		end
	end
end

-- Main per-tick event handler
script.on_event(defines.events.on_tick, function(event)
	if not run then --early end on console:release
		return
	end

    if not player then --set some parameters on the first tick
		player = game.players[1]
		player.surface.always_day = true
		player_position = player.position
		destination = { x = player.position.x, y = player.position.y }
		update_player_position()
		update_destination_position(player_position.x, player_position.y)
		player.force.research_queue_enabled = true
		walking = {walking = false, direction = defines.direction.north}
	end

	if player == nil or player.character == nil then --early end if in god mode
		return
	end

	if steps[step][2] == "walk" then
		if steps[step][4] == "old" then
			compatibility_mode = true
		end

		if steps[step].comment == "new" then
			compatibility_mode = false
		end
	end

	if steps[step] == nil or steps[step][1] == "break" then
		debug(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", player_position.x, player_position.y, player.online_time / 60, player.online_time))
		debug_state = false
		return
	end

	update_player_position()

	if compatibility_mode then
		backwards_compatibility()
	else
		handle_tick()
	end

	player.walking_state = walking
end)

local function mining_event_replace(event, item_name, amount)
	local count = event.buffer.get_item_count(item_name)
	if count < amount then
		event.buffer.insert({name=item_name, count=amount-count})
	elseif count > amount then
		event.buffer.remove({name=item_name, count=count-amount})
	end --on correct amount do nothing
end

script.on_event(defines.events.on_player_mined_entity, function(event)

	if player == nil or player.character == nil then --early end if in god mode
		return
	end

	if (steps[step][1] == "break") then
		return
	end

	if event.entity.name == "rock-huge" then
		mining_event_replace(event, "coal", 47)
		mining_event_replace(event, "stone", 47)
	end

	if event.entity.name == "rock-big" then
		-- do nothing, big rocks are always 20 stone
	end

	if event.entity.name == "sand-rock-big" then
		mining_event_replace(event, "stone", 24)
	end

	--change step when tas is running and the current step is mining step
	if run and steps[step] and steps[step][2] and steps[step][2] == "mine" then
		change_step(1)
	end

	mining = 0
	ticks_mining = 0

	if compatibility_mode then
		return
	end

	if run and steps[step] and steps[step][2] and steps[step][2] == "walk" then
		update_destination_position(steps[step][3][1], steps[step][3][2])

		find_walking_pattern()
		walking = walk()

		change_step(1)
	end
end)

-- Skips the freeplay intro
script.on_event(defines.events.on_game_created_from_scenario, function()

	remote.call("freeplay", "set_skip_intro", true)

end)

-- Triggered on script built
script.on_event(defines.events.script_raised_built, function(event)
	local entity = event.entity
	entity.create_build_effect_smoke()
	entity.surface.play_sound{path="entity-build/"..entity.prototype.name, position=entity.position}
end)

--modsetting names are stored in a global array for all mods, so each setting value needs to be unique among all mods
local settings_short = "DunRaider-quickbar-"
local function split_string(str)
	if str == nil then return end
	local t = {}
	for s in string.gmatch(str, "([^,]+)") do table.insert(t, s) end
	return t
end

--seperate functions in case we want it to trigger on other events
local function set_quick_bar(event)
	local player = game.players[event.player_index]
	for i = 1, 10 do
		local set = split_string(settings.global[settings_short..i].value)
		if set then
			for key,val in pairs(set) do
				local item = string.sub(val, 7, -2)-- removes "[item=" and "]"
				if item ~= "" then player.set_quick_bar_slot((i-1)*10 + key, item) end
			end
		end
	end
end

---Event handler for the player set quickslot, 
---Updates quickbar settings, to make it easier to set the filters you want 
---@param event EventData.on_player_set_quick_bar_slot
local function on_set_quickbar(event)
	local p = game.players[event.player_index]
	for i = 1, 10 do
		local set = settings.global[settings_short..i]
		local line = ""
		for j = 1, 10 do
			local slot = p.get_quick_bar_slot((i-1)*10 + j)
			if slot then
				line = line .. "[item=" .. slot.name .. "],"
			else
				line = line .. "[item],"
			end
		end
		set.value = string.sub(line, 0, -1)
		settings.global[settings_short..i] = set
	end
end

script.on_event(defines.events.on_player_joined_game, function(event)
	set_quick_bar(event)
	script.on_event(defines.events.on_player_set_quick_bar_slot, on_set_quickbar)
	game.players[event.player_index].game_view_settings.show_entity_info = true --Set alt-mode=true
end)

script.on_event(defines.events.on_player_created, function(event)
	set_quick_bar(event)
	on_player_created(event)
end)

local function create_tas_global_state()
	global.tas = {
		step = 1,
		idle = 0,
		pickup_ticks = 0,
		mining = 0,
		pos_pos = false,
		pos_neg = false,
		neg_pos = false,
 		neg_neg = false,
 		compatibility_mode = false,
 		keep_x = false,
 		keep_y = false,
		diagonal = false,
		duration = 0,
		ticks_mining = 0,
		idled = 0,
	}
end

local function migrate_global()
	if not global.tas then return end
	step = global.tas.step
	idle = global.tas.idle
	pickup_ticks = global.tas.pickup_ticks
	mining = global.tas.mining
	pos_pos = global.tas.pos_pos
	pos_neg = global.tas.pos_neg
	neg_pos = global.tas.neg_pos
	neg_neg = global.tas.neg_neg
	diagonal = global.tas.diagonal
	compatibility_mode = global.tas.compatibility_mode
	keep_x = global.tas.keep_x
	keep_y = global.tas.keep_y
	diagonal = global.tas.diagonal
	player_selection = global.tas.player_selection
	destination = global.tas.destination
	target_position = global.tas.target_position
	target_inventory = global.tas.target_inventory
	walking = global.tas.walking
	task = global.tas.task
	task_category = global.tas.task_category
	count = global.tas.count
	item = global.tas.item
	amount = global.tas.amount
	slot = global.tas.slot
	direction = global.tas.direction
	input = global.tas.input
	output = global.tas.output
	type = global.tas.type
	rev = global.tas.rev
	duration = global.tas.duration
	ticks_mining = global.tas.ticks_mining
	idled = global.tas.idled

	player = global.tas.player
	if player then
		player_position = player.position
	end
end

script.on_init(function()
    local freeplay = remote.interfaces["freeplay"] --Setup tas interface
    if freeplay then
		if freeplay["set_skip_intro"] then remote.call("freeplay", "set_skip_intro", true) end -- Disable freeplay popup-message
        if freeplay["set_disable_crashsite"] then remote.call("freeplay", "set_disable_crashsite", true) end --Disable crashsite
    end
	create_tas_global_state()
	migrate_global()
end)

script.on_load(migrate_global)

local function raise_state_change()
	script.raise_event(tas_state_change, {
		is_running = run,
		tick = game.tick,
	})
end

local function release()
	run = false
	raise_state_change()
end

local function resume()
	run = true
	raise_state_change()
end

local function skip(data)
	if data and data.parameter and tonumber( data.parameter ) then
		change_step(tonumber(data.parameter))
	else
		change_step(1)
	end
end

commands.add_command("release", nil, release)
commands.add_command("resume", nil, resume)
commands.add_command("skip", nil, skip)

local tas_interface =
{
	get_current_task = function()
		return step
	end,
	get_task_list = function()
		return steps
	end,
	get_tas_step_change_id = function ()
		return tas_step_change
	end,
	get_tas_step_change_id = function ()
		return tas_step_change
	end,
	get_tas_name = function ()
		return tas_generator.tas.name
	end,
	get_tas_timestamp = function ()
		return tas_generator.tas.timestamp
	end,
	get_generator_name = function ()
		return tas_generator.name
	end,
	get_generator_version = function ()
		return tas_generator.version
	end,
	--command interface
	release = release,
	resume = resume,
	skip = function (n)
		skip({parameter = n})
	end,
}

if not remote.interfaces["DunRaider-TAS"] then
	remote.add_interface("DunRaider-TAS", tas_interface)
end
