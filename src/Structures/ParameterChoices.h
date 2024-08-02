#pragma once

/* Enumarates bit vectors for specifing fields in the <Step detail> panel */ 
enum choice_bit_vector
{
	x_coordinate = 1 << 0,
	y_coordinate = 1 << 1,
	amount = 1 << 2,
	item = 1 << 3,
	from_to = 1 << 4,
	input = 1 << 5,
	output = 1 << 6,
	building_orientation = 1 << 7,
	direction_to_build = 1 << 8,
	building_size = 1 << 9,
	amount_of_buildings = 1 << 10,
	comment = 1 << 11,
};

/* Internal variables for parameter choices */
namespace parameter_choice_internal
{
	/* Common bit vector combinations */
	const int point = x_coordinate + y_coordinate,
	priority_io = input + output,
	multi_build = direction_to_build + building_size + amount_of_buildings,
	container = amount + item + from_to,
	building = point + multi_build + comment;
}

using namespace parameter_choice_internal;

const struct parameter_choices_struct
{
	//game interactions
	const int Pause = comment,
		stop = comment,
		save = comment,
		game_speed = amount | comment,
		never_idle = comment,
		keep_walking = comment,
		keep_on_path = comment,
		keep_crafting = comment;

	//game state interactions
	const int craft = amount | item | comment,
		tech = item | comment,
		cancel_crafting = amount | item | comment;

	//player state interactions
	const int walk = point | comment,
		pick = amount | comment,
		idle = amount | comment,
		mining = point | amount | comment,
		shoot = point | amount | comment,
		equip = amount | item | from_to | comment,
		_throw = point | item | comment;

	//building interactions
	const int build = building | item | building_orientation,
		take = building | container,
		put = building | container,
		rotate = building | amount,
		limit = building | amount,
		priority = building | priority_io,
		recipe = building | amount | item,
		filter = building | amount | item,
		launch = point | comment,
		next = comment;

	//vehicle interactions
	const int enter = comment,
		drive = amount | priority_io | comment,
		send = point | amount | comment;

	//misc
	const int drop = point | item | comment;
} parameter_choices;

// vector StepType to parameter_choices
const vector<int> listStepTypeToParameterChoices = {
	parameter_choices.stop, 
	parameter_choices.build, 
	parameter_choices.craft, 
	parameter_choices.game_speed, 
	parameter_choices.Pause, 
	parameter_choices.save, 
	parameter_choices.recipe, 
	parameter_choices.limit, 
	parameter_choices.filter, 
	parameter_choices.rotate, 
	parameter_choices.priority, 
	parameter_choices.put, 
	parameter_choices.take, 
	parameter_choices.mining,
	parameter_choices.launch,
	parameter_choices.next,
	parameter_choices.walk, 
	parameter_choices.tech, 
	parameter_choices.drop, 
	parameter_choices.pick, 
	parameter_choices.idle, 
	parameter_choices.cancel_crafting,
	parameter_choices.never_idle, 
	parameter_choices.keep_walking, 
	parameter_choices.keep_on_path, 
	parameter_choices.keep_crafting, 
	parameter_choices.shoot,
	parameter_choices.equip,
	parameter_choices._throw,
	parameter_choices.enter,
	parameter_choices.drive,
	parameter_choices.send,
};
