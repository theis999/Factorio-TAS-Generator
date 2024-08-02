local util = require("util")
local crash_site = require("crash-site")
require("goals")
local tas_generator = require("variables")
local steps = require("steps")
local debug_state = true
local run = true

local step_reached = 0

local font_size = 0.15 --best guess estimate of fontsize for flying text

local queued_save
local tas_step_change = script.generate_event_name()
local tas_state_change = script.generate_event_name()

local skipintro = false
--recreate crash site
local on_player_created = function(event)
	if remote.interfaces["freeplay"] == nil then return end
	
	local player = game.get_player(event.player_index)
	if not player then return end
	local surface = player.surface
	local crashed_ship_items = remote.call("freeplay", "get_ship_items")
	local crashed_debris_items = remote.call("freeplay", "get_debris_items")

	if skipintro then
		util.remove_safe(player, crashed_ship_items)
		util.remove_safe(player, crashed_debris_items)
		return
	end

	util.insert_safe(player, global.created_items)

    surface.daytime = 0.7
    crash_site.create_crash_site(surface, {-5,-6}, util.copy(crashed_ship_items), util.copy(crashed_debris_items))
    util.remove_safe(player, crashed_ship_items)
    util.remove_safe(player, crashed_debris_items)
    player.get_main_inventory().sort_and_merge()
	--game.auto_save("Start steel axe TAS")
end

---Print message intended for viewers
---@param message LocalisedString
---@param color Color | nil Message color or default white
local function Message(message, color)
    global.tas.player.print(message, color or {1,1,1})
end

---Print commment message intended for viewers
---@param message LocalisedString | nil
local function Comment(message)
	if PRINT_COMMENT and message and message ~= "" then
		global.tas.player.print(message)
	end
end

---Print Debug message about what the tas is doing
---@param message LocalisedString
---@param supress_info boolean? Includes extra information in message
local function Debug(message, supress_info)
	if LOGLEVEL == 0 then
		global.tas.player.print(message)
        if not supress_info then
			global.tas.player.print(string.format(
				"Seconds: %s, tick: %s, player position [%d, %d]",
				game.tick / 60,
				game.tick,
				global.tas.player.position.x,
				global.tas.player.position.y
			))
		end
	end
end

---Print warning in case of errors in tas programming
---@param message LocalisedString
---@param color Color | nil Message color or default yellow
local function Warning(message, color)
    if LOGLEVEL < 2 then
		global.warning_mode = global.warning_mode or {start = game.tick}
		global.tas.player.print(message, color or {r=1, g=1,})
	end
end

---Print warning in case of errors in tas programming
---@param message LocalisedString
---@param color Color | nil Message color or default red
local function Error(message, color)
    if LOGLEVEL < 3 then
		global.warning_mode = global.warning_mode or {start = game.tick}
		global.tas.player.print(message, color or {r=1,})
	end
end

local function end_warning_mode(msg)
	if global.warning_mode then
		global.tas.player.print({"step-warning.mode", msg, game.tick - global.warning_mode.start,}, {r=1, g=1}) -- print warnings in yellow
		global.warning_mode = nil
	end
end

local function end_never_stop_modifier_warning_mode()
	if global.never_stop_modifier_warning_mode then
		global.tas.player.print(string.format("Step: %d - The character stood stil for %d tick(s) ", global.never_stop_modifier_warning_mode.step, game.tick - global.never_stop_modifier_warning_mode.start),{r=1, g=1})
		global.never_stop_modifier_warning_mode = nil
	end
end

-- I think it should be possible to do something like looping through the different types and check if any are tagged for termination
local function end_use_all_ticks_warning_mode()
	if global.use_all_ticks_warning_mode then
		global.tas.player.print(string.format("Step: %d - %d tick(s) not used", global.use_all_ticks_warning_mode.step, game.tick - global.use_all_ticks_warning_mode.start), {r=1, g=1})
		global.use_all_ticks_warning_mode = nil
	end
end

local warnings = {
	never_idle = "never idle",
	keep_walking = "keep walking",
	keep_on_path = "keep on path",
	keep_crafting = "keep crafting",
}

local function end_state_warning_mode(warning, extra)
	if global[warning] then
		game.print(
			{"step-warning."..warning, steps[global[warning].step][1][1], game.tick - global[warning].start, extra}
		)
		global[warning] = nil
	end
end

---@param by number
local function change_step(by)
	local _task = 0
	if steps and steps[global.tas.step] and steps[global.tas.step][1][1] then
		_task = steps[global.tas.step][1][1]
	end
	global.tas.step = global.tas.step + by
	script.raise_event(tas_step_change, {
		change_step_by = by,
		step = global.tas.step,
		task = _task,
		tick = game.tick,
	})
end

local function save(task, nameOfSaveGame)
	if game.is_multiplayer() then
		if PRINT_SAVEGAME then Message(string.format("Step: %s, saving game as %s", task, nameOfSaveGame)) end
		game.server_save(nameOfSaveGame)
		return true
	end

	if PRINT_SAVEGAME then Message(string.format("Step: %s, saving game as _autosave-%s", task, nameOfSaveGame)) end
	game.auto_save(nameOfSaveGame)
	return true;
end

local function format_name(str)
	return str:gsub("^%l", string.upper):gsub("-", " ") --uppercase first letter and replace dashes with spaces
end

-- Check that the entity can be selected and is within reach
local function check_selection_reach()
	global.tas.player.update_selected_entity(global.tas.target_position)
	global.tas.player_selection = global.tas.player.selected

	if not global.tas.player_selection and global.vehicle then --if entity not found and vehichle modifier active, retry to find the car in 5 tile radius
		local vehicles = global.tas.player.surface.find_entities_filtered{
			position = global.tas.target_position,
			radius = 5,
			name = {"car", "cargo-wagon", "locomotive", "fluid-wagon", "tank"},
			limit = 1
		}
		if #vehicles > 0 then
			global.tas.player.update_selected_entity(vehicles[1].position)
			global.tas.player_selection = global.tas.player.selected
		end
	end

	if not global.tas.player_selection then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - %s: Cannot select entity", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.task_category))
		end

		return false
	end

	if not global.tas.player.can_reach_entity(global.tas.player_selection) then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - %s: Cannot reach entity", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.task_category))
		end

		return false
	end

	return true
end

-- Check that it is possible to get the inventory of the entity
local function check_inventory()
	global.tas.target_inventory = global.tas.player_selection.get_inventory(global.tas.slot) or global.tas.player_selection.get_inventory(1)

	if not global.tas.target_inventory then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - %s: Cannot get entity inventory", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.task_category))
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

	local removalable_items = global.tas.player.get_item_count(global.tas.item)
	local insertable_items = global.tas.target_inventory.get_insertable_count(global.tas.item)
	if global.tas.amount < 1 then
		global.tas.amount = math.min(removalable_items, insertable_items)
	end

	if removalable_items == 0 then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Put: %s is not available in your inventory", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
		end

		return false;
	end

	if insertable_items == 0 then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Put: %s can't be put into target inventory", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
		end

		return false;
	end

	if global.tas.amount > removalable_items or global.tas.amount > insertable_items then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Put: not enough %s can be transferred. Amount: %d Removalable: %d Insertable: %d", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper), global.tas.amount, removalable_items, insertable_items))
		end

		return false
	end

	local _amount = 0
	local c = global.tas.amount
	while c > 0 do
		local item_stack = global.tas.player.get_main_inventory().find_item_stack(global.tas.item)
		if not item_stack then Error("Item stack "..global.tas.item.." not found for put") return false end
		local health, durability, ammo = item_stack.health, item_stack.is_tool and item_stack.durability or 1, item_stack.is_ammo and item_stack.ammo or 10
		local count = c < item_stack.count and c or item_stack.count
		c = c - count

		_amount = global.tas.target_inventory.insert{
			name=global.tas.item,
			count=count,
			health=health,
			durability=durability,
			ammo=ammo,
		}

		if _amount ~= count then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Put: %s can not be transferred. Amount: %d Removalable: %d Insertable: %d", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper), global.tas.amount, removalable_items, insertable_items))
			return false
		end

		_amount = global.tas.player.remove_item{
			name=global.tas.item,
			count=count,
			health=health,
			durability=durability,
			ammo=ammo,
		}

		if _amount ~= count then
			Error(string.format("Step: %s, Action: %s, Step: %d - Put: %s can not be transferred. Amount: %d Removalable: %d Insertable: %d", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper), global.tas.amount, removalable_items, insertable_items))
			return false
		end
	end

	local text = string.format("-%d %s (%d)", global.tas.amount, format_name(global.tas.item), global.tas.player.get_item_count(global.tas.item)) --"-2 Iron plate (5)"
	local pos = {x = global.tas.target_inventory.entity_owner.position.x + #text/2 * font_size, y = global.tas.target_inventory.entity_owner.position.y }
	global.tas.player.play_sound{path="utility/inventory_move"}
	global.tas.player.create_local_flying_text{ text=text, position=pos}

	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Put: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
	return true
end

-- Place an item into the character's inventory from an entity's inventory
-- Returns false on failure to prevent advancing step until within reach
local function take_all()

	if not check_selection_reach() then
		return false
	end

	if not check_inventory() then
		return false;
	end

	local contents = global.tas.target_inventory.get_contents()
	for name, count in pairs(contents or global.tas.target_inventory) do
		local item_stack = global.tas.target_inventory.find_item_stack(name)
		if not item_stack then Error("Item stack "..global.tas.item.." not found for put") return false end
		local health, durability, ammo = item_stack.health, item_stack.is_tool and item_stack.durability or 1, item_stack.is_ammo and item_stack.ammo or 10
		
		global.tas.amount = global.tas.player.insert{
			name=name,
			durability=durability,
			health=health,
			ammo=ammo,
			count=global.tas.target_inventory.remove{name=name, count=count, durability=durability}
		}

		local text = string.format("+%d %s (%d)", global.tas.amount, format_name(name), global.tas.player.get_item_count(name)) --"+2 Iron plate (5)"
		local pos = {x = global.tas.target_inventory.entity_owner.position.x + #text/2 * font_size, y = global.tas.target_inventory.entity_owner.position.y }
		global.tas.player.play_sound{path="utility/inventory_move"}
		global.tas.player.create_local_flying_text{
			text=text,
			position=pos}
	end
	

	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Take: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
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

	local removalable_items = global.tas.target_inventory.get_item_count(global.tas.item)
	local insertable_items = global.tas.player.get_main_inventory().get_insertable_count(global.tas.item)
	if global.tas.amount < 1 then
		global.tas.amount = math.min(removalable_items, insertable_items)
	end

	if removalable_items == 0 then
		if not global.tas.walking.walking then
			Warning({"step-warning.take", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper), "is not available from the inventory"})
		end

		return false;
	end

	if insertable_items == 0 then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Take: %s can't be put into your inventory", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
		end

		return false;
	end

	if global.tas.amount > removalable_items or global.tas.amount > insertable_items then
		if not global.tas.walking.walking then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Take: not enough %s can be transferred. Amount: %d Removalable: %d Insertable: %d", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper), global.tas.amount, removalable_items, insertable_items))
		end

		return false
	end

	local c = global.tas.amount
	while c > 0 do
		local item_stack = global.tas.target_inventory.find_item_stack(global.tas.item)
		if not item_stack then Error("Item stack "..global.tas.item.." not found for put") return false end
		local health, durability, ammo = item_stack.health, item_stack.is_tool and item_stack.durability or 1, item_stack.is_ammo and item_stack.ammo or 10
		local stack_count = item_stack.count
		stack_count = stack_count < c and stack_count or c
		c = c - stack_count

		if stack_count ~= global.tas.player.insert{
			name=global.tas.item,
			durability=durability,
			health=health,
			ammo=ammo,
			count=global.tas.target_inventory.remove{name=global.tas.item, count=stack_count, durability=durability, health=health, ammo=ammo}
		} then
			Error(string.format("Step: %s, Action: %s, Step: %d - Take: %s can not be transferred. Amount: %d Removalable: %d Insertable: %d", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper), global.tas.amount, removalable_items, insertable_items))
			return false
		end
	end

	local text = string.format("+%d %s (%d)", global.tas.amount, format_name(global.tas.item), global.tas.player.get_item_count(global.tas.item)) --"+2 Iron plate (5)"
	local pos = {x = global.tas.target_inventory.entity_owner.position.x + #text/2 * font_size, y = global.tas.target_inventory.entity_owner.position.y }
	global.tas.player.play_sound{path="utility/inventory_move"}
	global.tas.player.create_local_flying_text{
		text=text,
		position=pos}

	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Take: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
	return true
end

-- Handcraft one or more of a recipe
local function craft()
	if not global.tas.player.force.recipes[global.tas.item].enabled then
		if(global.tas.step > step_reached) then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Craft: It is not possible to craft %s - It needs to be researched first.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			step_reached = global.tas.step
		end

		return false;
	end

	if global.cancel and global.tas.player.crafting_queue_size > 0 then
		global.tas.player.cancel_crafting{ index = 1, count = 1000000}
		return false
	elseif global.wait_for_recipe and global.tas.player.crafting_queue_size > 0 then
		Warning(string.format("Step: %s, Action: %s, Step: %d - Craft [item=%s]: It is not possible to craft as the queue is not empty", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
		step_reached = global.tas.step
		return false
	else
		global.wait_for_recipe = nil
	end
	global.cancel = nil

	global.tas.amount = global.tas.player.get_craftable_count(global.tas.item)

	if global.tas.amount > 0 then
		if global.tas.count == -1 then
			global.tas.player.begin_crafting{count = global.tas.amount, recipe = global.tas.item}
		elseif global.tas.count <= global.tas.amount then
			global.tas.player.begin_crafting{count = global.tas.count, recipe = global.tas.item}
		else
			if not global.tas.walking.walking then
				Warning(string.format("Step: %s, Action: %s, Step: %d - Craft: It is not possible to craft %s - Only possible to craft %d of %d", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper), global.tas.amount, global.tas.count))
			end

			return false
		end
		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Craft: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		return true
    else
        if(global.tas.step > step_reached) then
            Warning(string.format("Step: %s, Action: %s, Step: %d - Craft: It is not possible to craft %s - Please check the script", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
            step_reached = global.tas.step
		end

        return false
	end
end

-- Cancels a handcraft a recipe
local function cancel_crafting()
	local queue = global.tas.player.crafting_queue

	for i = 1, #queue do
		if queue[i].recipe == global.tas.item then
			if global.tas.count == -1 then
				global.tas.player.cancel_crafting{index = i, count = 1000000}
				end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Cancel: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
				return true
			elseif queue[i].count >= global.tas.count then
				global.tas.player.cancel_crafting{index = i, count = global.tas.count}
				end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Cancel: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
				return true
			else
				Warning(string.format("Step: %s, Action: %s, Step: %d - Cancel craft: It is not possible to cancel %s - Please check the script", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
				return false
			end
		end
	end
	Warning(string.format("Step: %s, Action: %s, Step: %d - Cancel craft: It is not possible to cancel %s - Please check the script", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
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
	local x = global.tas.player.position.x - global.tas.target_position[1]
	local y = global.tas.player.position.y - global.tas.target_position[2]
	local dis = math.sqrt(x^2+y^2) --sqrt(a^2+b^2)=sqrt(c^2)
	return dis <= 10.25 -- It seems like 10.25 aligns best with the current walking algorithm
end

---comment Places an entity, possibly fast replacing. Then handless 
---@return boolean true if an entity is created.
local function create_entity_replace()

	local stack, stack_location = global.tas.player.get_inventory(1).find_item_stack(global.tas.item)
	if not stack or not stack.valid then
		Error("Trying to create an entity of "..global.tas.item.." but couldn't find an stack of them in players inventory")
		return false
	end
	--[[ Using player.build_from_cursor
	
	global.tas.player.clear_cursor()
	global.tas.player.cursor_stack.swap_stack(stack)
	global.tas.player.hand_location = {inventory = 1, slot = stack_location}
	
	if global.tas.player.can_build_from_cursor{position = global.tas.target_position, direction = global.tas.direction, } then
		global.tas.player.build_from_cursor{position = global.tas.target_position, direction = global.tas.direction, }
		global.tas.player.clear_cursor()
		--if old_cursor then global.tas.player.cursor_stack.swap_stack(old_cursor) else global.tas.player.clear_cursor() end
		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Build: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		return true
	else
		--global.tas.player.clear_cursor()
		--global.tas.player.cursor_stack.set_stack(old_cursor)
		if not global.tas.player.walking.walking or not global.tas.player.driving then
			--idk
		end

		return false
	end]]

	local fast_replace_type_lookup = {
		["underground-belt"] = {"transport-belt", "fast-transport-belt", "express-transport-belt"},
		["fast-underground-belt"] = {"transport-belt", "fast-transport-belt", "express-transport-belt"},
		["express-underground-belt"] = {"transport-belt", "fast-transport-belt", "express-transport-belt"},
		["pipe-to-ground"] = {"pipe"}
	}

	local created_entity = global.tas.player.surface.create_entity{name = global.tas.item, position = global.tas.target_position, direction = global.tas.direction, force="player", fast_replace=true, player=global.tas.player, raise_built = true, item = stack}

	if created_entity and fast_replace_type_lookup[created_entity.name] ~= nil and created_entity.neighbours  then --connected entities eg underground belt https://lua-api.factorio.com/latest/LuaEntity.html#LuaEntity.neighbours
		created_entity.create_build_effect_smoke()
		created_entity.surface.play_sound{path="entity-build/"..created_entity.prototype.name, position=created_entity.position}

		created_entity.health = stack.health * created_entity.health

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
			global.tas.player.remove_item({name = global.tas.item, count = 1})
			end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Build: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
			return true
		end

		local entities_between = global.tas.player.surface.find_entities_filtered{name = replace_type, area = {
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
				global.tas.player.mine_entity(e, true)
			end
		end
		--spend the item placed
		global.tas.player.remove_item({name = global.tas.item, count = 1})
		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Build: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		return true
	end

	--no special fast replace handling
	if created_entity then
		created_entity.create_build_effect_smoke()
		created_entity.surface.play_sound{path="entity-build/"..created_entity.prototype.name, position=created_entity.position}

		created_entity.health = stack.health * created_entity.health

		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Build: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		global.tas.player.remove_item({name = global.tas.item, count = 1})
	end
	return created_entity ~= nil
end

-- Creating buildings
local function build()

	local _item = global.tas.item == "straight-rail" and "rail" or global.tas.item == "curved_rail" and "rail" or global.tas.item
	local take_4items = global.tas.item == "curved_rail"
	local _count = global.tas.player.get_item_count(_item)

	if _count < 1 or take_4items and _count < 4 then
		if(global.tas.step > step_reached) then
			if global.tas.walking.walking == false then
				Warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s not available", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
				step_reached = global.tas.step
			end
		end

		return false
	end

	if (_item ~= "rail") then
		if item_is_tile(global.tas.item) then
			if tile_is_in_reach() then
				if global.tas.item == "stone-brick" then
					global.tas.player.surface.set_tiles({{position = global.tas.target_position, name = "stone-path"}})
				elseif (global.tas.item == "hazard-concrete") or (global.tas.item == "refined-hazard-concrete") then
					global.tas.player.surface.set_tiles({{position = global.tas.target_position, name = global.tas.item.."-left"}})
				else
					global.tas.player.surface.set_tiles({{position = global.tas.target_position, name = global.tas.item}})
				end

				if(global.tas.item == "landfill") then
					global.tas.player.surface.play_sound{path="tile-build-small/landfill", position=global.tas.target_position}
				else
					global.tas.player.surface.play_sound{path="tile-build-small/concrete", position=global.tas.target_position}
				end

				global.tas.player.remove_item({name = global.tas.item, count = 1})
				end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Build: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
				return true

			elseif not global.tas.walking.walking then
				Warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s not in reach", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			end

			return false

		elseif global.tas.player.can_place_entity{name = global.tas.item, position = global.tas.target_position, direction = global.tas.direction} then
			end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Build: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
			return create_entity_replace()
		else
			if not global.tas.walking.walking then
				Warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s cannot be placed", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			end

			return false
		end
	else

		if global.tas.player.can_place_entity{name = global.tas.item, position = global.tas.target_position, direction = global.tas.direction} then
			
			if global.tas.player.surface.create_entity{name = global.tas.item, position = global.tas.target_position, direction = global.tas.direction, force="player", raise_built = true} then
				global.tas.player.remove_item({name = _item, count = take_4items and 4 or 1})
				end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Build: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
				return true
			end


		else
			if not global.tas.walking.walking then
				Warning(string.format("Step: %s, Action: %s, Step: %d - Build: %s cannot be placed", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			end

			return false
		end
	end
end

local function walk_pos_pos()
	local _player_position = global.tas.player.position
	if global.tas.keep_x then
		if _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.keep_y then
		if _player_position.x > global.tas.destination.x then
			return {walking = true, direction = defines.direction.west}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.diagonal then
		if _player_position.x > global.tas.destination.x or _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.northwest}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if _player_position.x > global.tas.destination.x then
		if _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.northwest}
		else
			return {walking = true, direction = defines.direction.west}
		end
	else
		if _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			if global.tas.compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = global.tas.walking.direction}
			end
		end
	end
end

local function walk_pos_neg()
	local _player_position = global.tas.player.position
	if global.tas.keep_x then
		if _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.keep_y then
		if _player_position.x > global.tas.destination.x then
			return {walking = true, direction = defines.direction.west}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.diagonal then
		if _player_position.x > global.tas.destination.x or _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.southwest}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if _player_position.x > global.tas.destination.x then
		if _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.southwest}
		else
			return {walking = true, direction = defines.direction.west}
		end
	else
		if _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			if global.tas.compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = global.tas.walking.direction}
			end
		end
	end
end

local function walk_neg_pos()
	local _player_position = global.tas.player.position
	if global.tas.keep_x then
		if _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.keep_y then
		if _player_position.x < global.tas.destination.x then
			return {walking = true, direction = defines.direction.east}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.diagonal then
		if _player_position.x < global.tas.destination.x or _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.northeast}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if _player_position.x < global.tas.destination.x then
		if _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.northeast}
		else
			return {walking = true, direction = defines.direction.east}
		end
	else
		if _player_position.y > global.tas.destination.y then
			return {walking = true, direction = defines.direction.north}
		else
			if global.tas.compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = global.tas.walking.direction}
			end
		end
	end
end

local function walk_neg_neg()
	local _player_position = global.tas.player.position
	if global.tas.keep_x then
		if _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.keep_y then
		if _player_position.x < global.tas.destination.x then
			return {walking = true, direction = defines.direction.east}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if global.tas.diagonal then
		if _player_position.x < global.tas.destination.x or _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.southeast}
		else
			return {walking = false, direction = global.tas.walking.direction}
		end
	end

	if _player_position.x < global.tas.destination.x then
		if _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.southeast}
		else
			return {walking = true, direction = defines.direction.east}
		end
	else
		if _player_position.y < global.tas.destination.y then
			return {walking = true, direction = defines.direction.south}
		else
			if global.tas.compatibility_mode then
				return {walking = false, direction = defines.direction.north}
			else
				return {walking = false, direction = global.tas.walking.direction}
			end
		end
	end
end

local function walk()
	if global.tas.player.driving then return {walking = false, direction = defines.direction.north} end --prevent walking while driving
	
	if global.tas.pos_pos then
		return walk_pos_pos()
	elseif global.tas.pos_neg then
		return walk_pos_neg()
	elseif global.tas.neg_pos then
		return walk_neg_pos()
	elseif global.tas.neg_neg then
		return walk_neg_neg()
	end

	if global.tas.compatibility_mode then
		return {walking = false, direction = defines.direction.north}
	else
		return {walking = false, direction = global.tas.walking.direction}
	end
end

local function find_walking_pattern()
	local _player_position = global.tas.player.position
	if global.tas.compatibility_mode then
		if (_player_position.x - global.tas.destination.x >= 0) then
			if (_player_position.y - global.tas.destination.y >= 0) then
				global.tas.pos_pos = true
				global.tas.pos_neg = false
				global.tas.neg_pos = false
				global.tas.neg_neg = false
			elseif (_player_position.y - global.tas.destination.y < 0) then
				global.tas.pos_neg = true
				global.tas.pos_pos = false
				global.tas.neg_pos = false
				global.tas.neg_neg = false
			end
		else
			if (_player_position.y - global.tas.destination.y >= 0) then
				global.tas.neg_pos = true
				global.tas.pos_pos = false
				global.tas.pos_neg = false
				global.tas.neg_neg = false
			elseif (_player_position.y - global.tas.destination.y < 0) then
				global.tas.neg_neg = true
				global.tas.pos_pos = false
				global.tas.pos_neg = false
				global.tas.neg_pos = false
			end
		end
	else
		global.tas.pos_pos = false
		global.tas.pos_neg = false
		global.tas.neg_pos = false
		global.tas.neg_neg = false

		if (_player_position.x - global.tas.destination.x >= 0) then
			if (_player_position.y - global.tas.destination.y >= 0) then
				global.tas.pos_pos = true
			else
				global.tas.pos_neg = true
			end
		else
			if (_player_position.y - global.tas.destination.y >= 0) then
				global.tas.neg_pos = true
			else
				global.tas.neg_neg = true
			end
		end
	end
end

local function update_destination_position(x, y)
	global.tas.destination = { x = x, y = y }

	if global.tas.compatibility_mode then return end

	global.tas.keep_x = false
	global.tas.keep_y = false
	global.tas.diagonal = false

	if steps[global.tas.step] and steps[global.tas.step][5] and steps[global.tas.step][5] == "same_x" then
		global.tas.keep_x = true
	end

	if steps[global.tas.step] and steps[global.tas.step][6] and steps[global.tas.step][6] == "same_y" then
		global.tas.keep_y = true
	end

	if steps[global.tas.step] and steps[global.tas.step][5] and steps[global.tas.step][5] == "diagonal" then
		global.tas.diagonal = true
	end
end

local function rotate()
	local has_rotated = false
	if not check_selection_reach() then
		return false;
	end

	if global.tas.rev then
		has_rotated = global.tas.player_selection.rotate({reverse = true})
	else
		has_rotated = global.tas.player_selection.rotate({reverse = false})
	end

	if has_rotated then global.tas.player.play_sound{path="utility/rotated_small"} end

	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Rotate", global.tas.task[1], global.tas.task[2], global.tas.step ))
	return true
end

local function recipe()

	if not check_selection_reach() then
		return false
	end

	if global.tas.item ~= "none" and not global.tas.player.force.recipes[global.tas.item].enabled then
		if(global.tas.step > step_reached) then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Recipe: It is not possible to set recipe %s - It needs to be researched first.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			step_reached = global.tas.step
		end

		return false;
	end

	if global.wait_for_recipe and global.tas.player_selection.crafting_progress ~= 0 then
		Warning(string.format("Step: %s, Action: %s, Step: %d - Set recipe %s: The entity is still crafting.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
		step_reached = global.tas.step
		return false
	end
	global.wait_for_recipe = nil

	local items_returned = global.tas.player_selection.set_recipe(global.tas.item ~= "none" and global.tas.item or nil)

	for name, count_ in pairs (items_returned) do
		global.tas.player.insert{name = name, count = count_}
	end

	global.tas.player.play_sound{ path = "utility/entity_settings_pasted", }
	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Recipe: [recipe=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
	return true
end

local function tech()
	if global.cancel and global.tas.player.force.current_research then
		global.tas.player.force.cancel_current_research()
		return false
	else
		global.cancel = nil
	end

	if steps[global.tas.step].comment and steps[global.tas.step].comment == "Cancel" and global.tas.player.force.current_research then
		global.tas.player.force.research_queue = {}
		global.tas.player.force.add_research(global.tas.item)
		if PRINT_TECH then Message(string.format("Research: Cleared queue and %s added", global.tas.item)) end
		return true
	end

	local was_addded = global.tas.player.force.add_research(global.tas.item)
	if PRINT_TECH then Message(string.format("Research: %s%s added", global.tas.item, was_addded and "" or " not")) end
	return true
end

local function raise_state_change()
	script.raise_event(tas_state_change, {
		is_running = run,
		tick = game.tick,
	})
end

local function pause()
	game.tick_paused = true
	run = false
	raise_state_change()
	return true
end

-- Set the gameplay speed. 1 is standard speed
local function speed(speed)
	game.speed = speed
    Message(string.format("Changed game speed to %s", speed))
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
	global.tas.target_inventory.set_bar(global.tas.amount+1)
	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Limit", global.tas.task[1], global.tas.task[2], global.tas.step))
	return true
end

local function priority()

	if not check_selection_reach() then
		return false
	end

	global.tas.player_selection.splitter_input_priority = global.tas.input
	global.tas.player_selection.splitter_output_priority = global.tas.output

	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Priority", global.tas.task[1], global.tas.task[2], global.tas.step))
	return true
end

local function filter()

	if not check_selection_reach() then
		return false
	end

	if global.tas.type == "splitter" then
		if global.tas.item == "none" then
			global.tas.player_selection.splitter_filter = nil
		else
			global.tas.player_selection.splitter_filter = global.tas.item
		end

		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Filter: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		return true
	end

	local inv = global.tas.player_selection
	if global.tas.player_selection.type == "car" or global.tas.player_selection.type == "tank" then
		inv = global.tas.player_selection.get_inventory(defines.inventory.car_trunk)
	elseif global.tas.player_selection.type == "cargo-wagon" then
		inv = global.tas.player_selection.get_inventory(defines.inventory.cargo_wagon)
	end

	if global.tas.item == "none" then
		inv.set_filter(global.tas.slot, nil)
	else
		inv.set_filter(global.tas.slot, global.tas.item)
	end

	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Filter: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
	return true
end

-- Drop items on the ground (like pressing the 'z' key)
local function drop()
	local can_reach = 10 > math.sqrt(
		math.abs(global.tas.player.position.x - global.tas.drop_position[1])^2 + math.abs(global.tas.player.position.y - global.tas.drop_position[2])^2
	)
	if global.tas.player.get_item_count(global.tas.drop_item) > 0 and can_reach then
		global.tas.player.surface.create_entity{
			name = "item-on-ground",
			stack = {
				name = global.tas.drop_item,
				count = 1,
			},
			position = global.tas.drop_position,
			force = "player",
			spill = true
		}
		global.tas.player.remove_item({name = global.tas.drop_item})
		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Drop: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
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

	end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Launch", global.tas.task[1], global.tas.task[2], global.tas.step ))
	return global.tas.player_selection.launch_rocket()
end

---Fires the next event of supply challenge
local function Next()
	local interface = remote.interfaces["DunRaider-TAS-supply"]
	if interface and interface.TAS_Next then
		local result = remote.call("DunRaider-TAS-supply", "TAS_Next")
		if not result then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Next is not available", global.tas.task[1], global.tas.task[2], global.tas.step ))
			return false
		end
		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Next", global.tas.task[1], global.tas.task[2], global.tas.step ))
		return result
	else
		Error("Called next without the function existing")
		error("Called next without the function existing")
	end
end

local function shoot()
	global.tas_shooting_amount = global.tas_shooting_amount or global.tas.amount
	---@cast global.tas.player LuaPlayer
	global.tas.player.update_selected_entity(global.tas.target_position)
	local can_shoot = not global.tas.player.selected or global.tas.player.character.can_shoot(global.tas.player.selected, global.tas.target_position)
	if can_shoot then
		global.tas.player.shooting_state = {state = defines.shooting.shooting_selected, position = global.tas.target_position}
		global.tas_shooting_amount = global.tas_shooting_amount - 1
	else
		Warning(string.format("Step: %s, Action: %s, Step: %d - Shoot: %d can't shoot location", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.amount ))
	end

	if global.tas_shooting_amount == 0 then
		global.tas_shooting_amount = nil
		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Shoot", global.tas.task[1], global.tas.task[2], global.tas.step))
		return true
	end

	return false
end

local function throw()
	---@cast global.tas.item string
	---@cast global.tas.player LuaPlayer
	global.tas.item = string.lower(global.tas.item:gsub(" ", "-"))
	if global.tas.player.get_item_count (global.tas.item) > 0 then
		local stack, index = global.tas.player.get_main_inventory().find_item_stack(global.tas.item)
		if not stack or not index then
			Warning(string.format("Step: %s, Action: %s, Step: %d - throw: [item=%s] can't find item in player inventory", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
			return false
		end

		local fish = false
		local prototype = stack.prototype
		if not prototype.capsule_action then 
			Warning(string.format("Step: %s, Action: %s, Step: %d - throw: [item=%s] is not a throwable type", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		end
		if prototype.capsule_action.type == "throw" then 
			local dist = math.sqrt(
				math.abs(global.tas.player.position.x - global.tas.target_position[1])^2 + math.abs(global.tas.player.position.y - global.tas.target_position[2])^2
			)
			local can_reach = prototype.capsule_action.attack_parameters.range > dist and dist > prototype.capsule_action.attack_parameters.min_range
			if not can_reach then
				Warning(string.format("Step: %s, Action: %s, Step: %d - throw: [item=%s] target is out of range", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
				return false
			end
		elseif prototype.capsule_action.type == "use-on-self" then
			fish = true
		else
			Warning(string.format("Step: %s, Action: %s, Step: %d - throw: [item=%s] is not a throwable type", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		end	

		global.tas_throw_cooldown = global.tas_throw_cooldown or 0
		if game.tick < global.tas_throw_cooldown then
			Warning(string.format("Step: %s, Action: %s, Step: %d - throw: [item=%s] is still on cooldown", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
			return false
		end

		global.tas_throw_cooldown = game.tick + prototype.capsule_action.attack_parameters.cooldown
		local created_entities = stack.use_capsule(global.tas.player.character, global.tas.target_position)
		end_warning_mode(string.format("Step: %s, Action: %s, Step: %d - Throw: [item=%s]", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item ))
		return fish or (created_entities and #created_entities > 0)
	end
	return false
end

--- Moves items between the characters main inventory and one of the ammo, weapon or the armor slot.
local function equip()
	if not global.tas.player then return false end
	local types = {
		["Armor"] = {defines.inventory.character_armor, 1, false},
		["Ammo 1"] = {defines.inventory.character_ammo, 1, false},
		["Ammo 2"] = {defines.inventory.character_ammo, 2, false},
		["Ammo 3"] = {defines.inventory.character_ammo, 3, false},
		["Weapon 1"] = {defines.inventory.character_guns, 1, true},
		["Weapon 2"] = {defines.inventory.character_guns, 2, true},
		["Weapon 3"] = {defines.inventory.character_guns, 3, true},
	}
	local type = types[global.tas.slot]
	local inventory = global.tas.player.get_inventory(type[1])
	local main_inventory = global.tas.player.get_main_inventory()
	if not inventory or not main_inventory then return false end

	if type[3] then global.tas.player.character.selected_gun_index = type[2] end -- cycle to new slot

	local main_count = main_inventory.get_item_count(global.tas.item)

	local stack = inventory[type[2]]
	if not stack.valid then -- something is very wrong
		Error("Inventory stack is invalid")
		run = false
		return false
	elseif not stack.valid_for_read then -- slot is clear
		if global.tas.amount == -1 then
			return true
		end
		if main_count < global.tas.amount then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Equip: It is not possible to equip %s - As the character does not hold enough in their inventory.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			return false
		end
		local _stack = main_inventory.find_item_stack(global.tas.item)
		local ammo = _stack.is_ammo and _stack.ammo or 10
		local main_removed = main_inventory.remove({
			name = global.tas.item,
			count = global.tas.amount})
		local c = stack.set_stack({ name = global.tas.item, count = main_removed, ammo = ammo})
		if not c then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Equip: It is not possible to equip %s - Maybe the corresponding ammo/weapon slot is not clear.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			main_inventory.insert({
				name = global.tas.item,
				count = main_removed})
			return false
		end
	elseif global.tas.amount == -1 then -- clear this slot
		local removed_stack_amount = stack.count + 0
		local returned_stack_amount = main_inventory.insert(stack)
		stack.clear()
		
		if removed_stack_amount > returned_stack_amount then
			Error(string.format("Step: %s, Action: %s, Step: %d - Equip: More items removed from the target inventory than inserted into main inventory - maybe there wasn't room in the main inventory", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			run = false
			return false
		end
	elseif stack.name ~= global.tas.item then -- change slot item
		if main_count < global.tas.amount then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Equip: It is not possible to equip %s - As the character does not hold enough in their inventory.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			return false
		end
		local returned_stack_amount = main_inventory.insert( stack )
		if stack.count > returned_stack_amount then
			Error(string.format("Step: %s, Action: %s, Step: %d - Equip: More items removed from the target inventory than inserted into main inventory - maybe there wasn't room in the main inventory", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			run = false
			return false
		end
		stack.clear()
		local main_removed = main_inventory.remove({
			name = global.tas.item,
			count = global.tas.amount})
		local c = stack.set_stack({ name = global.tas.item, count = main_removed})
		if not c then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Equip: It is not possible to equip %s - Maybe the corresponding ammo/weapon slot is not clear.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			main_inventory.insert({
				name = global.tas.item,
				count = main_removed})
			return false
		end
	
	elseif stack.count < global.tas.amount then -- add more items to the slot
		if main_count + stack.count < global.tas.amount then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Equip: It is not possible to equip %s - As the character does not hold enough in their inventory.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			return false
		end
		local _stack = main_inventory.find_item_stack(global.tas.item)
		local ammo = _stack.is_ammo and _stack.ammo or 10
		local main_removed = main_inventory.remove({
			name = global.tas.item,
			count = global.tas.amount - stack.count})
		local c = stack.transfer_stack({ name = global.tas.item, count = main_removed, ammo = ammo})
		if not c then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Equip: It is not possible to equip %s - Unknown error.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			return false
		end
	elseif stack.count > global.tas.amount then -- remove items from the slot
		local main_inserted = main_inventory.insert({
			name = global.tas.item,
			count = stack.count - global.tas.amount,
			ammo = stack.is_ammo and stack.ammo or 10,
		})
		stack.clear()
		local c = stack.set_stack({ name = global.tas.item, count = global.tas.amount})
		if not c then
			Warning(string.format("Step: %s, Action: %s, Step: %d - Equip: It is not possible to equip %s - Unknown error.", global.tas.task[1], global.tas.task[2], global.tas.step, global.tas.item:gsub("-", " "):gsub("^%l", string.upper)))
			return false
		end
	end

	return true
end

local function enter()
	if global.tas.player.driving then
		if global.riding_duration < 1 then
			global.tas.player.driving = false
			return true
		end
	else
		global.tas.player.driving = true
		if global.tas.player.driving then
			return true
		else
			return false
		end
	end
end

local function send()
	--idk
end

-- Routing function to perform one of the many available steps
-- True: Indicates the calling function should advance the step. 
-- False: Indicates the calling function should not advance step.
local function doStep(current_step)

	global.vehicle = current_step.vehicle
	global.wait_for_recipe = current_step.wait_for
	global.cancel = current_step.cancel

	if current_step[2] == "craft" then
        global.tas.task_category = "Craft"
        global.tas.task = current_step[1]
		global.tas.count = current_step[3]
		global.tas.item = current_step[4]
		return craft()

	elseif current_step[2] == "cancel crafting" then
        global.tas.task_category = "Cancel craft"
        global.tas.task = current_step[1]
		global.tas.count = current_step[3]
		global.tas.item = current_step[4]
		return cancel_crafting()

	elseif current_step[2] == "build" then
        global.tas.task_category = "Build"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.item = current_step[4]
		global.tas.direction = current_step[5]
		return build()

	elseif current_step[2] == "take" then
        global.tas.task_category = "Take"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.item = current_step[4]
		global.tas.amount = current_step[5]
		global.tas.slot = current_step[6]

		if current_step.all then
			return take_all()
		else
			return take()
		end

	elseif current_step[2] == "put" then
        global.tas.task_category = "Put"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.item = current_step[4]
		global.tas.amount = current_step[5]
		global.tas.slot = current_step[6]
		return put()

	elseif current_step[2] == "rotate" then
        global.tas.task_category = "Rotate"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.rev = current_step[4]
		return rotate()

	elseif current_step[2] == "tech" then
        global.tas.task_category = "Tech"
        global.tas.task = current_step[1]
		global.tas.item = current_step[3]
		return tech()

	elseif current_step[2] == "recipe" then
        global.tas.task_category = "Recipe"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.item = current_step[4]
		return recipe()

	elseif current_step[2] == "limit" then
        global.tas.task_category = "limit"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.amount = current_step[4]
		global.tas.slot = current_step[5]
		return limit()

	elseif current_step[2] == "priority" then
        global.tas.task_category = "priority"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.input = current_step[4]
		global.tas.output = current_step[5]
		return priority()

	elseif current_step[2] == "filter" then
        global.tas.task_category = "filter"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.item = current_step[4]
		global.tas.slot = current_step[5]
		global.tas.type = current_step[6]
		return filter()

    elseif current_step[2] == "drop" then
        global.tas.task = current_step[1]
		global.tas.drop_position = current_step[3]
		global.tas.drop_item = current_step[4]
		return drop()

	elseif current_step[2] == "pick" then
		global.tas.player.picking_state = true
		return true

	elseif current_step[2] == "idle" then
		global.tas.idle = current_step[3]
		return true

	elseif current_step[2] == "launch" then
		global.tas.task_category = "launch"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		return launch()

	elseif current_step[2] == "next" then
		global.tas.task_category = "next"
        global.tas.task = current_step[1]
		return Next()

	elseif current_step[2] == "shoot" then
		global.tas.task_category = "shoot"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.amount = current_step[4]
		return shoot()

	elseif current_step[2] == "throw" then
		global.tas.task_category = "throw"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		global.tas.item = current_step[4]
		return throw()

	elseif current_step[2] == "equip" then
		global.tas.task_category = "equip"
        global.tas.task = current_step[1]
		global.tas.amount = current_step[3]
		global.tas.item = current_step[4]
		global.tas.slot = current_step[5]
		return equip()

	elseif current_step[2] == "enter" then
		global.tas.task_category = "enter"
        global.tas.task = current_step[1]
		return enter()

	elseif current_step[2] == "send" then
		global.tas.task_category = "send"
        global.tas.task = current_step[1]
		global.tas.target_position = current_step[3]
		return send()
	end

end

local original_warning = Warning
local function load_StepBlock()
	if global.step_block or not steps[global.tas.step].no_order then return end
	global.step_block = {}
	global.executed_step_block = {finalized = false}
	Debug("entering step block")
	Warning = function ()
		--override Warning with a function that does nothing
	end
	for i = global.tas.step, #steps do
		local _step = steps[i]
		if not _step.no_order then
			break
		else
			table.insert(global.step_block, i)
		end
	end
	global.step_block_info = {
		total_steps = #global.step_block,
		steps_left = #global.step_block,
		start_tick = game.tick
	}
end

local function execute_StepBlock()
	local _success, _step_index, _step
	for i = 1, #global.step_block do
		_step_index = global.step_block[i]
		_step = steps[_step_index]
		_success = doStep(_step)
		if _success then
			Debug(string.format("Executed %d - Type: %s, Step: %d", _step[1][1], _step[2]:gsub("^%l", string.upper), _step_index), true)
			table.remove(global.step_block, i)
			table.insert(global.executed_step_block, _step)
			if i == 1 and #global.step_block > 1 then
				local fast_change_step = global.step_block[1] - global.tas.step
				change_step(fast_change_step)
				global.step_block_info.steps_left = global.step_block_info.steps_left - fast_change_step
			end
			break
		end
	end
	if #global.step_block < 1 then
		change_step(global.step_block_info.steps_left)
		global.step_block = nil
		global.step_block_info = nil
		global.executed_step_block.finalized = true
		Warning = original_warning
		Debug("Ending step block")
	elseif (game.tick - global.step_block_info.start_tick) > (15 * global.step_block_info.total_steps) then
		Warning = original_warning
		Error("Catastrofic execution of No order step block. Exceeeded ".. (15 * global.step_block_info.total_steps) .. " ticks.")
		Warning(string.format("Failed to execute %d steps", #global.step_block))
		for i = 1, #global.step_block do
			_step_index = global.step_block[i]
			_step = steps[_step_index]
			Warning(string.format("Step %d failed - Type: %s, substep: %d", _step[1][1], _step[2]:gsub("^%l", string.upper), _step_index))
		end
		run = false
		raise_state_change()
	end
end

local function handle_pretick()
	--pretick sets step directly so it doesn't raise too many events
	global.state = global.state or {}
	while run do
		if steps[global.tas.step] == nil then
			run = false
			raise_state_change()
			return
		elseif (steps[global.tas.step][2] == "speed") then
			if LOGLEVEL < 2 then
				Comment(steps[global.tas.step].comment)
				Debug(string.format("Step: %s, Action: %s, Step: %s - Game speed: %d", steps[global.tas.step][1][1], steps[global.tas.step][1][2], global.tas.step, steps[global.tas.step][3]))
				speed(steps[global.tas.step][3])
			end
			global.tas.step = global.tas.step + 1
		elseif steps[global.tas.step][2] == "save" then
			queued_save = LOGLEVEL < 2 and {name = steps[global.tas.step][1][1], step = steps[global.tas.step][3]} or nil
			global.tas.step = global.tas.step + 1
		elseif steps[global.tas.step][2] == "pick" then
			Comment(steps[global.tas.step].comment)
			if global.tas.pickup_ticks and global.tas.pickup_ticks > 0 then
				Debug(string.format("Previous pickup not completed with %d ticks left before adding %d extra.", global.tas.pickup_ticks, steps[global.tas.step][3]))
			end
			global.tas.pickup_ticks = global.tas.pickup_ticks + steps[global.tas.step][3] - 1
			global.tas.player.picking_state = true
			global.tas.step = global.tas.step + 1
		elseif (steps[global.tas.step][2] == "pause") then
			if LOGLEVEL < 2 then
				pause()
				Message("Script paused")
				Debug(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", global.tas.player.position.x, global.tas.player.position.y, global.tas.player.online_time / 60, global.tas.player.online_time))
			end
			change_step(1)
		elseif(steps[global.tas.step][2] == "walk" and (global.tas.walking.walking == false or global.walk_towards_state) and global.tas.idle < 1 and global.riding_duration < 1) then
			update_destination_position(steps[global.tas.step][3][1], steps[global.tas.step][3][2])
			global.walk_towards_state = steps[global.tas.step].walk_towards
			find_walking_pattern()
			global.tas.walking = walk()
			change_step(1)
		elseif(steps[global.tas.step][2] == "drive" and (not global.riding_state or global.tas.walking.walking == false or global.walk_towards_state) and global.tas.idle < 1 and global.riding_duration < 1) then
			global.riding_duration = steps[global.tas.step][3]
			global.riding_state = {acceleration = steps[global.tas.step][4], direction = steps[global.tas.step][5]}
			global.tas.player.riding_state = global.riding_state
			global.walk_towards_state = false
			change_step(1)
		elseif steps[global.tas.step][2] == warnings.never_idle then
			global.state.never_idle = not global.state.never_idle
			global.tas.step = global.tas.step + 1
		elseif steps[global.tas.step][2] == warnings.keep_walking then
			global.state.keep_walking = not global.state.keep_walking
			global.tas.step = global.tas.step + 1
		elseif steps[global.tas.step][2] == warnings.keep_on_path then
			global.state.keep_on_path = not global.state.keep_on_path
			global.tas.step = global.tas.step + 1
		elseif steps[global.tas.step][2] == warnings.keep_crafting then
			global.state.keep_crafting = not global.state.keep_crafting
			global.tas.step = global.tas.step + 1
		else
			return --no more to do, break loop
		end
	end
end

local function handle_ontick()
	if global.tas.pickup_ticks > 0 then
		global.tas.player.picking_state = true
		global.tas.pickup_ticks = global.tas.pickup_ticks - 1
	end
	if global.riding_duration > 0 then
		global.tas.player.riding_state = global.riding_state
		global.riding_duration = global.riding_duration - 1
		if global.riding_duration < 1 then global.riding_state = nil end
	end

	if global.tas.walking.walking == false and global.tas.player.driving == false then
		if global.tas.idle > 0 then
			global.tas.idle = global.tas.idle - 1
			global.tas.idled = global.tas.idled + 1

			Debug(string.format("Step: %s, Action: %s, Step: %s - idled for %d", steps[global.tas.step][1][1]-1, steps[global.tas.step][1][2], global.tas.step-1, global.tas.idled))

			if global.tas.idle == 0 then
				global.tas.idled = 0
				Comment(steps[global.tas.step].comment)

				if steps[global.tas.step][2] == "walk" then
					update_destination_position(steps[global.tas.step][3][1], steps[global.tas.step][3][2])
					global.walk_towards_state = steps[global.tas.step].walk_towards

					find_walking_pattern()
					global.tas.walking = walk()

					change_step(1)
					global.tas.step_executed = true
				end
			end
		elseif steps[global.tas.step][2] == "walk" then
			Comment(steps[global.tas.step].comment)
			update_destination_position(steps[global.tas.step][3][1], steps[global.tas.step][3][2])
			global.walk_towards_state = steps[global.tas.step].walk_towards
			
			find_walking_pattern()
			global.tas.walking = walk()
			
			change_step(1)

		elseif steps[global.tas.step][2] == "mine" then
			if global.tas.duration and global.tas.duration == 0 then Comment(steps[global.tas.step].comment) end
			
			global.tas.player.update_selected_entity(steps[global.tas.step][3])

			global.tas.player.mining_state = {mining = true, position = steps[global.tas.step][3]}
			if global.use_all_ticks_warning_mode then
				end_use_all_ticks_warning_mode()
			end

			global.tas.duration = steps[global.tas.step][4]

			global.tas.ticks_mining = global.tas.ticks_mining + 1

			if global.tas.ticks_mining >= global.tas.duration then
				if LEGACY_MINING then global.tas.player.mining_state = {mining = false, position = steps[global.tas.step][3]} end
				change_step(1)
				global.tas.step_executed = true
				global.tas.mining = 0
				global.tas.ticks_mining = 0
			end

			global.tas.mining = global.tas.mining + 1
			if global.tas.mining > 5 then
				if global.tas.player.character_mining_progress == 0 then
					Error(string.format("Step: %s, Action: %s, Step: %s - Mine: Cannot reach resource", steps[global.tas.step][1][1], steps[global.tas.step][1][2], global.tas.step))
				else
					global.tas.mining = 0
				end
			end

		elseif doStep(steps[global.tas.step]) then
			-- Do step while standing still
			Comment(steps[global.tas.step].comment)
			global.tas.step_executed = true
			change_step(1)
		end
	else
		if global.walk_towards_state and steps[global.tas.step][2] == "mine" then
			if global.tas.duration and global.tas.duration == 0 then Comment(steps[global.tas.step].comment) end
			
			global.tas.player.update_selected_entity(steps[global.tas.step][3])

			global.tas.player.mining_state = {mining = true, position = steps[global.tas.step][3]}

			global.tas.duration = steps[global.tas.step][4]

			global.tas.ticks_mining = global.tas.ticks_mining + 1

			if global.tas.ticks_mining >= global.tas.duration then
				if LEGACY_MINING then global.tas.player.mining_state = {mining = false, position = steps[global.tas.step][3]} end
				change_step(1)
				global.tas.mining = 0
				global.tas.ticks_mining = 0
			end

			global.tas.mining = global.tas.mining + 1
			if global.tas.mining > 5 then
				if global.tas.player.character_mining_progress == 0 then
					Debug(string.format("Step: %s, Action: %s, Step: %s - Mine: Cannot reach resource", steps[global.tas.step][1][1], steps[global.tas.step][1][2], global.tas.step))
				else
					global.tas.mining = 0
				end
			end
		elseif (global.walk_towards_state or global.tas.player.driving) and steps[global.tas.step][2] == "enter" then
			if doStep(steps[global.tas.step]) then
				-- Do step while walking
				Comment(steps[global.tas.step].comment)
				global.tas.step_executed = true
				change_step(1)
			end
		elseif steps[global.tas.step][2] ~= "walk" and steps[global.tas.step][2] ~= "enter" and steps[global.tas.step][2] ~= "idle" and steps[global.tas.step][2] ~= "mine" then
			if doStep(steps[global.tas.step]) then
				-- Do step while walking
				Comment(steps[global.tas.step].comment)
				global.tas.step_executed = true
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

	do -- check warning states
		if global.state.keep_crafting then
			if global.tas.player.crafting_queue_size > 0 then
				end_state_warning_mode(warnings.keep_crafting)
			else
				global[warnings.keep_crafting] = global[warnings.keep_crafting] or {step = global.tas.step, start = game.tick}
			end
		end

		if global.state.keep_on_path then
			if global.tas.player.character_running_speed > 0.16 then -- 0.15 is default
				end_state_warning_mode(warnings.keep_on_path)
			else
				global[warnings.keep_on_path] = global[warnings.keep_on_path] or {step = global.tas.step, start = game.tick}
			end
		end

		if global.state.keep_walking then
			if global.tas.walking.walking or global.tas.mining ~= 0 or global.tas.idle ~= 0 then
				end_state_warning_mode(warnings.keep_walking)
			else
				global[warnings.keep_walking] = global[warnings.keep_walking] or {step = global.tas.step, start = game.tick}
			end
		end

		global.last_step = global.last_step or 1
		if global.state.never_idle and not global.step_block then
			if global.tas.step ~= global.last_step  then
				end_state_warning_mode(warnings.never_idle)
			else
				global[warnings.never_idle] = global[warnings.never_idle] or {step = global.tas.step, start = game.tick}
			end
		end
		global.last_step = global.tas.step
	end

	if global.tas.walking.walking or global.tas.mining ~= 0 or global.tas.idle ~= 0 or global.tas.pickup_ticks ~= 0 then
		-- we wait to finish the previous step before we end the run
	elseif steps[global.tas.step] == nil or steps[global.tas.step][1] == "break" then
		Message(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", global.tas.player.position.x, global.tas.player.position.y, global.tas.player.online_time / 60, global.tas.player.online_time))
		run = false
		raise_state_change()
		return
	end
end

local function handle_tick()
	global.tas.walking = walk()
	handle_pretick()

	if not run then --early end from pretick
		return
	end
	load_StepBlock()
	if global.step_block then
		execute_StepBlock()
	else
		handle_ontick()
	end

	handle_posttick()
end

local function backwards_compatibility()
	if steps[global.tas.step] == nil or steps[global.tas.step][1] == "break" then
		Debug(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", global.tas.player.position.x, global.tas.player.position.y, global.tas.player.online_time / 60, global.tas.player.online_time))
		debug_state = false
		return
	end

	if (steps[global.tas.step][2] == "pause") then
		pause()
		Debug("Script paused")
		Debug(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", global.tas.player.position.x, global.tas.player.position.y, global.tas.player.online_time / 60, global.tas.player.online_time))
		debug_state = false
		return
	end

	if (steps[global.tas.step][2] == "speed") then
		Debug(string.format("Step: %s, Action: %s, Step: %s - Game speed: %d", steps[global.tas.step][1][1], steps[global.tas.step][1][2], global.tas.step, steps[global.tas.step][3]))
		speed(steps[global.tas.step][3])
		change_step(1)
	end

	if steps[global.tas.step][2] == "save" then
		change_step(1)
		save(steps[global.tas.step-1][1][1], steps[global.tas.step-1][3])
	end

	if global.tas.pickup_ticks > 0 then
		global.tas.player.picking_state = true
		global.tas.pickup_ticks = global.tas.pickup_ticks - 1
	end

	global.tas.walking = walk()
	if global.tas.walking.walking == false then
		if global.tas.idle > 0 then
			global.tas.idle = global.tas.idle - 1
			global.tas.idled = global.tas.idled + 1

			Debug(string.format("Step: %s, Action: %s, Step: %s - idled for %d", steps[global.tas.step][1][1]-1, steps[global.tas.step][1][2], global.tas.step-1, global.tas.idled))

			if global.tas.idle == 0 then
				global.tas.idled = 0
			end
		elseif steps[global.tas.step][2] == "walk" then
			update_destination_position(steps[global.tas.step][3][1], steps[global.tas.step][3][2])
			global.walk_towards_state = steps[global.tas.step].walk_towards

			find_walking_pattern()
			global.tas.walking = walk()

			change_step(1)

		elseif steps[global.tas.step][2] == "mine" then

			global.tas.player.update_selected_entity(steps[global.tas.step][3])

			global.tas.player.mining_state = {mining = true, position = steps[global.tas.step][3]}

			global.tas.duration = steps[global.tas.step][4]

			global.tas.ticks_mining = global.tas.ticks_mining + 1

			if global.tas.ticks_mining >= global.tas.duration then
				global.tas.player.mining_state = {mining = false, position = steps[global.tas.step][3]}
				change_step(1)
				global.tas.mining = 0
				global.tas.ticks_mining = 0
			end

			global.tas.mining = global.tas.mining + 1
			if global.tas.mining > 5 then
				if global.tas.player.character_mining_progress == 0 then
					Warning(string.format("Step: %s, Action: %s, Step: %s - Mine: Cannot reach resource", steps[global.tas.step][1][1], steps[global.tas.step][1][2], global.tas.step))
					debug_state = false
				else
					global.tas.mining = 0
				end
			end

		elseif doStep(steps[global.tas.step]) then
			-- Do step while standing still
			change_step(1)

		end
	else
		if steps[global.tas.step][2] ~= "walk" and steps[global.tas.step][2] ~= "mine" and steps[global.tas.step][2] ~= "idle" and steps[global.tas.step][2] ~= "pick" then
			if doStep(steps[global.tas.step]) then
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

    if not global.tas.player then --set some parameters on the first tick
		global.tas.player = game.players[1]
		global.tas.player.surface.always_day = true
		global.tas.destination = { x = global.tas.player.position.x, y = global.tas.player.position.y }
		update_destination_position(global.tas.player.position.x, global.tas.player.position.y)
		global.tas.player.force.research_queue_enabled = true
		global.tas.walking = {walking = false, direction = defines.direction.north}
		global.riding_duration = 0
	end

	if global.tas.player == nil or global.tas.player.character == nil then --early end if in god mode
		return
	end

	if steps[global.tas.step][2] == "walk" then
		if steps[global.tas.step][4] == "old" then
			global.tas.compatibility_mode = true
		end

		if steps[global.tas.step].comment == "new" then
			global.tas.compatibility_mode = false
		end
	end

	if steps[global.tas.step].comment and global.tas.step > global.tas.not_same_step then
		if steps[global.tas.step].comment == "Never Stop" then
			global.tas.never_stop = not global.tas.never_stop

			Message(string.format("Step: %d - Never Stop: %s", steps[global.tas.step][1][1], global.tas.never_stop))
			global.tas.not_same_step = global.tas.step
		elseif steps[global.tas.step].comment == "Use All Ticks" then
			global.tas.use_all_ticks = not global.tas.use_all_ticks
			
			Message(string.format("Step: %d - Use All Ticks: %s", steps[global.tas.step][1][1], global.tas.use_all_ticks))
			global.tas.not_same_step = global.tas.step
		end
	end

	if steps[global.tas.step] == nil or steps[global.tas.step][1] == "break" then
		Debug(string.format("(%.2f, %.2f) Complete after %f seconds (%d ticks)", global.tas.player.position.x, global.tas.player.position.y, global.tas.player.online_time / 60, global.tas.player.online_time))
		debug_state = false
		return
	end

	if global.tas.compatibility_mode then
		backwards_compatibility()
	else
		global.tas.step_executed = false
		handle_tick()

		if global.use_all_ticks_warning_mode and global.tas.step_executed then
			end_use_all_ticks_warning_mode()
		end

		if global.tas.use_all_ticks and not global.tas.step_executed and global.use_all_ticks_warning_mode == nil and not global.tas.player.mining_state.mining then
			global.use_all_ticks_warning_mode = {start = game.tick, step = steps[global.tas.step][1][1]}
		end
	end

	if global.never_stop_modifier_warning_mode and global.tas.walking.walking then
		end_never_stop_modifier_warning_mode()
	end

	if global.tas.never_stop and global.never_stop_modifier_warning_mode == nil and global.tas.walking.walking == false then
		global.never_stop_modifier_warning_mode = {start = game.tick, step = steps[global.tas.step][1][1]}
	end

	global.tas.player.walking_state = global.tas.walking
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

	if global.tas.player == nil or global.tas.player.character == nil then --early end if in god mode
		return
	end

	if (steps[global.tas.step][1] == "break") then
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
	if run and steps[global.tas.step] and steps[global.tas.step][2] and steps[global.tas.step][2] == "mine" and (LEGACY_MINING or global.tas.ticks_mining > 1) then
		change_step(1)
	end

	global.tas.mining = 0
	global.tas.ticks_mining = 0

	if global.tas.compatibility_mode then
		return
	end

	if run and steps[global.tas.step] and steps[global.tas.step][2] and steps[global.tas.step][2] == "walk" then
		update_destination_position(steps[global.tas.step][3][1], steps[global.tas.step][3][2])
		global.walk_towards_state = steps[global.tas.step].walk_towards

		find_walking_pattern()
		global.tas.walking = walk()

		change_step(1)
	end
end)

-- Skips the freeplay intro
script.on_event(defines.events.on_game_created_from_scenario, function(event)
	if event.tick ~= 0 then
		skipintro = true
	else
		if remote.interfaces["freeplay"] then
			remote.call("freeplay", "set_skip_intro", true)
		end
	end
end)

--[[ Triggered on script built
script.on_event(defines.events.script_raised_built, function(event)
	local entity = event.entity
	entity.create_build_effect_smoke()
	entity.surface.play_sound{path="entity-build/"..entity.prototype.name, position=entity.position}
end)]]

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
		never_stop = false,
		use_all_ticks = false,
		step_executed = false,
		duration = 0,
		ticks_mining = 0,
		idled = 0,
		not_same_step = 1,
	}
end

script.on_init(function()
    local freeplay = remote.interfaces["freeplay"] --Setup tas interface
    if freeplay then
		if freeplay["set_skip_intro"] then remote.call("freeplay", "set_skip_intro", true) end -- Disable freeplay popup-message
        if freeplay["set_disable_crashsite"] then remote.call("freeplay", "set_disable_crashsite", true) end --Disable crashsite
    end
	create_tas_global_state()
end)

script.on_load(function ()
	if global.tas.player then global.tas.player.clear_console() end
end)

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

local function re_order_step_block()
	if not global.executed_step_block or not global.executed_step_block.finalized then
		game.print("No order block is not valid for export")
		return
	end

	local function add_title_bar(frame, title)
        local title_bar = frame.add{ type = "flow", direction = "horizontal", name = "title_bar", }
        title_bar.drag_target = frame
        title_bar.add{ type = "sprite", sprite = "tas_helper_icon"}
        title_bar.add{ type = "label", style = "frame_title", caption = title, ignored_by_interaction = true, }
        title_bar.add{ type = "empty-widget", style = "tas_helper_title_bar_draggable_space", ignored_by_interaction = true, }
        local frame_close_button = title_bar.add{ type = "sprite-button", style = "frame_action_button", sprite = "utility/close_white", hovered_sprite = "utility/close_black", clicked_sprite = "utility/close_black", }
        return frame_close_button
    end

	local screen = global.tas.player.gui.screen
	local export_frame = screen.add{ type = "frame", direction = "vertical", visible = false, }
    export_frame.force_auto_center()

	local export_frame_close_button = add_title_bar(export_frame, "Export re-order to FTG")
	
    local export_task_list_label = export_frame.add{ type = "label", style = "caption_label", caption = "", tooltip = "Copy these into the FTGs re-order panel", }
    export_task_list_label.style.top_margin = 6

    local export_textbox = export_frame.add{ type = "text-box", style = "tas_helper_export_textbox", } -- local style
    export_textbox.read_only = true

	local lines = {}
    for i, _step in ipairs(global.executed_step_block) do
		local s = _step and string.format("%d;%d;%d;",i,_step[1][1], _step[1][2]) or nil
		if s then
            table.insert(lines, s)
        end
	end
	export_textbox.text = table.concat(lines, "\n")
	export_textbox.focus()
	export_textbox.select_all()

	export_frame.visible = true
    export_frame.bring_to_front()
    global.tas.player.opened = export_frame

	script.on_event(defines.events.on_gui_click, function(event)
		local element = event.element
		local _player = game.get_player(event.player_index)
		if element == export_frame_close_button then
			export_frame.visible = false
			if _player.opened == export_frame then
				_player.opened = nil
			end
		end
	end)
end

commands.add_command("reorder", nil, re_order_step_block)
commands.add_command("release", nil, release)
commands.add_command("resume", nil, resume)
commands.add_command("skip", nil, skip)

local tas_interface =
{
	get_current_task = function()
		return global.tas.step
	end,
	get_task_list = function()
		return steps
	end,
	get_tas_step_change_id = function ()
		return tas_step_change
	end,
	get_tas_state_change_id = function ()
		return tas_state_change
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
	get_tas_state = function ()
		return {
			is_running = run,
		}
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
