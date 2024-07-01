#pragma once

#include "../StdUtil.h"

#include <set>

using std::set;

/// <summary> Enumaration of all step types </summary>
enum StepType
{
	e_stop, 
	e_build, 
	e_craft, 
	e_game_speed, 
	e_pause,
	e_save, 
	e_recipe, 
	e_limit,
	e_filter, 
	e_rotate, 
	e_priority, 
	e_put,
	e_take, 
	e_mine, 
	e_launch,
	e_next,
	e_walk,
	e_tech,
	e_drop, 
	e_pick_up, 
	e_idle, 
	e_cancel_crafting,
	e_never_idle, 
	e_keep_walking, 
	e_keep_on_path, 
	e_keep_crafting,
	e_shoot,
	e_equip,
	e_throw,
	e_enter,
	e_drive,
	e_send,
};

/// <summary> Contains every step name, aligned with StepType </summary>
static const vector<string> StepNames = {
	"Stop", 
	"Build", 
	"Craft", 
	"Game speed", 
	"Pause", 
	"Save",
	"Recipe", 
	"Limit", 
	"Filter", 
	"Rotate", 
	"Priority", 
	"Put", 
	"Take", 
	"Mine", 
	"Launch",
	"Next",
	"Walk", 
	"Tech", 
	"Drop", 
	"Pick up", 
	"Idle", 
	"Cancel",
	"Never idle", 
	"Keep walking", 
	"Keep on path", 
	"Keep crafting",
	"Shoot",
	"Equip",
	"Throw",
	"Enter",
	"Drive",
	"Send",
};

/// <summary> Maps StepName::string to StepType::enum </summary>
static const map<string, StepType> MapStepNameToStepType = convert_vector_to_enummap<StepType>(StepNames);

/// <summary> Fast way to convert string to step type - however throws an error instead of returning not found </summary>
static inline const StepType ToStepType(const string step)
{
	auto value = MapStepNameToStepType.find(step);
	return value != MapStepNameToStepType.end() ? value->second : throw("Step type not found");
}

static struct ModifierTypeSets{
	set<StepType> all{
		e_take,
	};
	set<StepType> walk_towards{
		e_walk,
	};
	set<StepType> no_order{
		e_build,
		e_craft,
		e_recipe,
		e_limit,
		e_filter,
		e_rotate,
		e_priority,
		e_put,
		e_take,
		e_launch,
		e_tech,
		e_drop,
		e_cancel_crafting,
		e_equip,
	};
	set<StepType> cancel{
		e_tech,
		e_craft,
	};
	set<StepType> wait_for{
		e_recipe,
		e_craft,
	};
	set<StepType> skip{ //all		
		e_stop,
		e_build,
		e_craft,
		e_game_speed,
		e_pause,
		e_save,
		e_recipe,
		e_limit,
		e_filter,
		e_rotate,
		e_priority,
		e_put,
		e_take,
		e_mine,
		e_launch,
		e_next,
		e_walk,
		e_tech,
		e_drop,
		e_pick_up,
		e_idle,
		e_cancel_crafting,
		e_never_idle,
		e_keep_walking,
		e_keep_on_path,
		e_keep_crafting,
		e_shoot,
		e_equip,
		e_throw,
		e_enter,
		e_drive,
		e_send,
	};
	set<StepType> force{
		//character steps
		e_drop, 
		e_mine,
		//building steps
		e_take, 
		e_put, 
		e_build, 
		e_recipe, 
		e_limit,
		e_filter,
		e_priority,
		e_launch,
		e_rotate,
	};
	set<StepType> split{
		e_mine,
	};
	set<StepType> vehicle{
		e_take,
		e_put,
		e_limit,
		e_filter,
		e_mine,
	};
} modifier_types;
