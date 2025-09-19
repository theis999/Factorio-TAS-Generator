require "util"
require "story"
mod_gui = require "mod-gui"
time_modifier = 1.4
points_per_second_start = 5
points_per_second_level_subtract = 0.2
levels =
{
  -- 1
  {
    requirements =
    {
      {name = "stone", count = 15 }
    },
    time = 240
  },

  -- 2
  {
    requirements =
    {
      {name = "iron-plate", count = 30}
    },
    time = 300
  },

  -- 3
  {
    requirements =
    {
      {name = "iron-plate", count = 30},
      {name = "copper-plate", count = 30}
    },
    time = 300
  },

  -- 4
  {
    requirements =
    {
      {name = "iron-plate", count = 30},
      {name = "iron-gear-wheel", count = 30}
    },
    time = 300
  },

  -- 5
  {
    requirements =
    {
      {name = "iron-plate", count = 40},
      {name = "iron-gear-wheel", count = 30},
      {name = "copper-cable", count = 40}
    },
    time = 300
  },

  -- 6
  {
    requirements =
    {
      {name = "iron-plate", count = 40},
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30}
    },
    time = 300
  },

  -- 7
  {
    requirements =
    {
      {name = "iron-plate", count = 40},
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 10},
      {name = "firearm-magazine", count = 50}
    },
    time = 300
  },

  -- 8
  {
    requirements =
    {
      {name = "iron-plate", count = 40},
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 10},
      {name = "transport-belt", count = 20}
    },
    time = 300
  },

  -- 9
  {
    requirements =
    {
      {name = "iron-plate", count = 50},
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 10},
      {name = "transport-belt", count = 20},
      {name = "inserter", count = 20}
    },
    time = 300
  },

  -- 10
  {
    requirements =
    {
      {name = "iron-plate", count = 50},
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 10},
      {name = "logistic-science-pack", count = 10}
    },
    time = 300
  },

  -- 11
  {
    requirements =
    {
      {name = "iron-plate", count = 50},
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "fast-transport-belt", count = 10}
    },
    time = 300
  },

  -- 12
  {
    requirements =
    {
      {name = "iron-plate", count = 50},
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "steel-plate", count = 10}
    },
    time = 420
  },

  -- 13
  {
    requirements =
    {
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "steel-plate", count = 15},
      {name = "piercing-rounds-magazine", count = 50}
    },
    time = 300
  },

  -- 14
  {
    requirements =
    {
      {name = "iron-gear-wheel", count = 30},
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "steel-plate", count = 15},
      {name = "grenade", count = 15},
      {name = "plastic-bar", count = 5}
    },
    time = 600
  },

  -- 15
  {
    requirements =
    {
      {name = "electronic-circuit", count = 30},
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "steel-plate", count = 15},
      {name = "advanced-circuit", count = 10}
    },
    time = 500
  },

  -- 16
  {
    requirements =
    {
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "steel-plate", count = 15},
      {name = "advanced-circuit", count = 10},
      {name = "sulfur", count = 10}
    },
    time = 500
  },

  -- 17
  {
    requirements =
    {
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "advanced-circuit", count = 10},
      {name = "engine-unit", count = 10},
      {name = "sulfur", count = 10}
    },
    time = 500
  },

  -- 18
  {
    requirements =
    {
      {name = "automation-science-pack", count = 20},
      {name = "logistic-science-pack", count = 20},
      {name = "chemical-science-pack", count = 20},
      {name = "grenade", count = 20}
    },
    time = 500
  },

  -- 19
  {
    requirements =
    {
      {name = "automation-science-pack", count = 30},
      {name = "logistic-science-pack", count = 30},
      {name = "chemical-science-pack", count = 30},
      {name = "stone-wall", count = 20}
    },
    time = 500
  },

  -- 20
  {
    requirements =
    {
      {name = "automation-science-pack", count = 40},
      {name = "logistic-science-pack", count = 40},
      {name = "chemical-science-pack", count = 40},
      {name = "stone-wall", count = 20},
      {name = "grenade", count = 20}
    },
    time = 600
  },

  -- 21
  {
    requirements =
    {
      {name = "automation-science-pack", count = 50},
      {name = "logistic-science-pack", count = 50},
      {name = "chemical-science-pack", count = 50},
      {name = "military-science-pack", count = 50}
    },
    time = 700
  }
}
local completed_label_color = {g = 1}

function get_time_left()
  return storage.level_started_at + time_modifier * levels[storage.level].time * 60 - game.tick
end

local accumulate_items = function()
  local accumulated = storage.accumulated
  for index, chest in pairs(storage.chests) do
    if chest.valid then
      local inventory = chest.get_inventory(defines.inventory.chest)
      local contents = inventory.get_contents()
      for item_name, count in pairs(contents) do
        if accumulated[item_name] then
          local count_to_consume = math.min(storage.required[item_name] - storage.accumulated[item_name], count)
          if count_to_consume ~= 0 then
            inventory.remove{name = item_name, count = count_to_consume}
            accumulated[item_name] = accumulated[item_name] + count_to_consume
          end
        end
      end
    end
  end
end

local get_next_level_button = function(player)
  local flow = mod_gui.get_button_flow(player)
  return flow.next_level or flow.add{type = "button", name = "next_level", caption={"next-level"}, style = mod_gui.button_style}
end

local low_time_left_label_color = {r = 1}

story_table =
{
  {
    {
      action = function()
        if false then
          game.show_message_dialog{text = {"welcome"}}
          game.show_message_dialog{text = {"rules1"}}
          game.show_message_dialog{text = {"rules2"}}
          game.show_message_dialog{text = {"rules3"}}
          game.show_message_dialog{text = {"rules4"}}
          game.show_message_dialog{text = {"rules5"}}
        end
      end
    },
    {},
    {
      name = "level-start",
      init = function(event)
        storage.accumulated = {}
        storage.required = {}
        storage.labels = {}
        storage.level_started_at = event.tick

        local level = levels[storage.level]
        for index, item in pairs(level.requirements) do
          storage.accumulated[item.name] = 0
          storage.required[item.name] = item.count
        end

        for k, player in pairs (game.players) do
          update_gui(player)
          get_next_level_button(player).enabled = false
        end
      end
    },
    {
      name = "level-progress",
      update = function(event)
        if event.tick % 60 ~= 0 then return end
        accumulate_items()
        for k, player in pairs(game.players) do
          update_gui(player)
        end
      end,
      condition = function(event)

        if event.name == defines.events.on_gui_click and
        event.element.name == "next_level" then
          local seconds_left = math.floor(get_time_left() / 60)
          local points_addition = math.floor(seconds_left * (points_per_second_start - storage.level * points_per_second_level_subtract))
          game.print({"time-bonus", util.format_number(points_addition), seconds_left, points_addition})
          storage.points = storage.points + points_addition
          return true
        end

        if event.tick % 60 ~= 0 then return end

        local result = true
        local level = levels[storage.level]
        for index, item in pairs(level.requirements) do
          local accumulated = storage.accumulated[item.name]
          if accumulated < item.count then
            result = false
          end
        end

        if result then
          for k, player in pairs (game.players) do
            get_next_level_button(player).enabled = true
          end
        end

        if get_time_left() <= 0 then
          if result == false then
            for k, player in pairs (game.players) do
              player.set_ending_screen_data({"points-achieved", util.format_number(storage.points), storage.points})
              player.gui.top.clear()
              player.gui.left.clear()
            end
            game.set_game_state{game_finished = true, player_won = false}
            return false
          else
            return true
          end
        end

        return false
      end,
      action = function(event, story)
        for k, player in pairs (game.players) do
          get_next_level_button(player).enabled = false
        end
        storage.level = storage.level + 1
        local points_addition = (storage.level - 1) * 10
        game.print({"level-completed", storage.level - 1, util.format_number(points_addition), points_addition})
        storage.points = storage.points + points_addition

        if storage.level < #levels + 1 then
          for k, player in pairs (game.players) do
            get_next_level_button(player).enabled = false
          end
          story_jump_to(story, "level-start")
        end
      end
    },
    {
      action = function()
        for k, player in pairs (game.players) do
          player.set_ending_screen_data({"points-achieved", util.format_number(storage.points), storage.points})
        end
      end
    }
  }
}

story_init_helpers(story_table)

script.on_init(function()
  validate_prototypes()
  storage.story = story_init()
  game.map_settings.pollution.enabled = false
  game.forces.enemy.evolution_factor = 0
  storage.required = {}
  storage.chests = {}
  for k, chest in pairs (game.surfaces[1].find_entities_filtered{name = "red-chest"}) do
    chest.minable = false
    chest.destructible = false
    storage.chests[chest.unit_number] = chest
  end
  storage.level = 1
  storage.points = 0
end)

supply_events =
{
  defines.events.on_gui_click,
  defines.events.on_tick
}

script.on_event(supply_events, function(event)
  story_update(storage.story, event, "")
end)

script.on_event(defines.events.on_player_created, function(event)
  game.get_player(event.player_index).insert{name = "iron-plate", count = 8}
end)

function update_gui(player)
  local flow = mod_gui.get_frame_flow(player)
  local frame = flow.supply_frame
  if not frame then
    frame = flow.add{type = "frame", name = "supply_frame", style = mod_gui.frame_style, direction = "vertical"}
  end
  frame.caption = {"level", storage.level}
  frame.clear()

  local inner = frame.add{type = "frame", direction = "vertical", style = "inside_shallow_frame"}
  local time_left = get_time_left()
  local info_table = inner.add{type = "table", column_count = 1, style = "bordered_table"}
  info_table.style.margin = 4
  local time_left_label = info_table.add{type = "label", name = "time_left", caption = {"time-left", util.formattime(time_left)}}
  if time_left < 60 * 30 then
    time_left_label.style.font_color = low_time_left_label_color
  end
  info_table.add{type = "label", caption = {"points-per-second", points_per_second_start - storage.level * points_per_second_level_subtract}}
  info_table.add{type = "label", caption = {"points", util.format_number(math.floor(storage.points))}}


  local required_items_flow = info_table.add{type = "flow", direction = "vertical"}

  required_items_flow.add{type = "label", caption = {"required-items"}, style = "caption_label"}

  local item_prototypes = prototypes.item
  local accumulated = storage.accumulated

  local table = required_items_flow.add{type = "table", column_count = 3}
  table.style.column_alignments[3] = "right"
  local level = levels[storage.level]
  for index, item in pairs(level.requirements) do
    local accumulated = accumulated[item.name]
    local sprite = table.add{type = "sprite", sprite = "item/"..item.name, style = "small_text_image"}
    table.add{type = "label", caption = {"", item_prototypes[item.name].localised_name, {"colon"}}}
    local label = table.add{type = "label", caption = accumulated .. "/" .. item.count}
    if accumulated == item.count then
      label.style.font_color = completed_label_color
    end
  end

  local next_level = levels[storage.level + 1]
  if next_level then
    local next_level_flow = info_table.add{type = "flow", direction = "vertical"}
    next_level_flow.add{type= "label", caption = {"next-level"}, style = "caption_label"}
    local next_level_table = next_level_flow.add{type = "table", column_count = 3}
    next_level_table.style.column_alignments[3] = "right"
    for index, item in pairs(next_level.requirements) do
      local sprite = next_level_table.add{type = "sprite", sprite = "item/"..item.name, style = "small_text_image"}
      next_level_table.add{type = "label", caption = {"", item_prototypes[item.name].localised_name, {"colon"}}}
      next_level_table.add{type = "label", caption = item.count}
    end
  end

end

function validate_prototypes()
  local items = prototypes.item
  local is_error = false
  local bad_items = {}
  for k, level in pairs (levels) do
    for k, item in pairs (level.requirements) do
      if not items[item.name] or item.count <= 0 then
        is_error = true
        bad_items[item.name] = item.count
      end
    end
  end
  if is_error then
    error("Bad prototypes in supply challenge:\n"..serpent.block(bad_items))
  end
end

function test_fill_chest_requirements()
  assert(storage.chests)
  local index, chest = next(storage.chests)
  assert(chest.valid)
  local level = levels[storage.level]
  assert(level)
  for k, item in pairs (level.requirements) do
    chest.insert(item)
  end
  storage.level_started_at = (game.tick + 5) - (level.time * 60 * time_modifier)
end


function TAS_Next()
  local player = game and game.player or game and game.players[1] or nil
  if not player then return false end
  local btn = get_next_level_button(player)
  if
    not btn.enabled
  then
    return false
  end
  story_update(storage.story, {name = defines.events.on_gui_click, element = btn, player_index = 1, tick = game.tick}, "")

  return true
end

local interface = {
  TAS_Next = TAS_Next,
}

if not remote.interfaces["DunRaider-TAS-supply"] then
	remote.add_interface("DunRaider-TAS-supply", interface)
end
