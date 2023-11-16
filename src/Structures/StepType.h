#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <set>

using std::unordered_map;
using std::string;
using std::vector;
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
	e_throw
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
	"Throw"
};

/// <summary> Maps StepName::string to StepType::enum </summary>
static const unordered_map<string, StepType> MapStepNameToStepType = {
	{"Stop", e_stop}, 
	{"Build", e_build}, 
	{"Craft", e_craft}, 
	{"Game speed", e_game_speed}, 
	{"Pause", e_pause}, 
	{"Save", e_save},
	{"Recipe", e_recipe}, 
	{"Limit", e_limit}, 
	{"Filter", e_filter},
	{"Rotate", e_rotate}, 
	{"Priority", e_priority}, 
	{"Put", e_put}, 
	{"Take", e_take},
	{"Mine", e_mine}, 
	{"Launch", e_launch},
	{"Next", e_next},
	{"Walk", e_walk}, 
	{"Tech", e_tech}, 
	{"Drop", e_drop},
	{"Pick up", e_pick_up}, 
	{"Idle", e_idle}, 
	{"Cancel", e_cancel_crafting},
	{"Never idle", e_never_idle},
	{"Keep walking", e_keep_walking}, 
	{"Keep on path", e_keep_on_path}, 
	{"Keep crafting", e_keep_crafting},
	{"Shoot", e_shoot},
	{"Equip", e_equip},
	{"Throw", e_throw},

	//lowercase
	{"stop", e_stop},
	{"build", e_build},
	{"craft", e_craft},
	{"game speed", e_game_speed},
	{"pause", e_pause},
	{"save", e_save},
	{"recipe", e_recipe},
	{"limit", e_limit},
	{"filter", e_filter},
	{"rotate", e_rotate},
	{"priority", e_priority},
	{"put", e_put},
	{"take", e_take},
	{"mine", e_mine},
	{"launch", e_launch},
	{"next", e_next},
	{"walk", e_walk},
	{"tech", e_tech},
	{"drop", e_drop},
	{"pick up", e_pick_up},
	{"idle", e_idle},
	{"cancel", e_cancel_crafting},
	{"never idle", e_never_idle},
	{"keep walking", e_keep_walking},
	{"keep on path", e_keep_on_path},
	{"keep crafting", e_keep_crafting},
	{"shoot", e_shoot},
	{"equip", e_equip},
	{"throw", e_throw}
};

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
		e_throw
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
} modifier_types;
