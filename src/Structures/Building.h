#pragma once

#include "Orientation.h"

#include "../StdUtil.h"

struct Building
{

	enum BuildingType
	{
		wooden_chest,
		iron_chest,
		steel_chest,
		storage_tank,
		transport_belt,
		fast_transport_belt,
		express_transport_belt,
		underground_belt,
		fast_underground_belt,
		express_underground_belt,
		splitter,
		fast_splitter,
		express_splitter,
		burner_inserter,
		inserter,
		long_handed_inserter,
		fast_inserter,
		filter_inserter,
		stack_inserter,
		stack_filter_inserter,
		small_electric_pole,
		medium_electric_pole,
		big_electric_pole,
		substation,
		pipe,
		pipe_to_ground,
		pump,
		curved_rail,
		straight_rail,
		train_stop,
		rail_signal,
		rail_chain_signal,
		logistic_chest_active_provider,
		logistic_chest_passive_provider,
		logistic_chest_storage,
		logistic_chest_buffer,
		logistic_chest_requester,
		roboport,
		small_lamp,
		arithmetic_combinator,
		decider_combinator,
		constant_combinator,
		power_switch,
		programmable_speaker,
		boiler,
		steam_engine,
		solar_panel,
		accumulator,
		nuclear_reactor,
		heat_pipe,
		heat_exchanger,
		steam_turbine,
		burner_mining_drill,
		electric_mining_drill,
		offshore_pump,
		pumpjack,
		stone_furnace,
		steel_furnace,
		electric_furnace,
		assembling_machine_1,
		assembling_machine_2,
		assembling_machine_3,
		oil_refinery,
		chemical_plant,
		centrifuge,
		lab,
		beacon,
		rocket_silo,
		land_mine,
		stone_wall,
		gate,
		gun_turret,
		laser_turret,
		flamethrower_turret,
		artillery_turret,
		radar,

		stone_brick,
	};

	BuildingType type = wooden_chest;
	double X;
	double Y = 0;
	Orientation orientation = Orientation::North;

	Building(double x, double y, BuildingType _type, Orientation _orientation);
	Building(double x);
	Building();

	string Name() const;
	string LuaName() const;

	static inline const vector<string> BuildingNames = {
		"Wooden chest",
		"Iron chest",
		"Steel chest",
		"Storage tank",
		"Transport belt",
		"Fast transport belt",
		"Express transport belt",
		"Underground belt",
		"Fast underground belt",
		"Express underground belt",
		"Splitter",
		"Fast splitter",
		"Express splitter",
		"Burner inserter",
		"Inserter",
		"Long-handed inserter",
		"Fast inserter",
		"Filter inserter",
		"Stack inserter",
		"Stack filter inserter",
		"Small electric pole",
		"Medium electric pole",
		"Big electric pole",
		"Substation",
		"Pipe",
		"Pipe to ground",
		"Pump",
		"Curved rail",
		"Straight rail",
		"Train stop",
		"Rail signal",
		"Rail chain signal",
		"Active provider chest",
		"Passive provider chest",
		"Storage chest",
		"Buffer chest",
		"Requester chest",
		"Roboport",
		"Lamp",
		"Arithmetic combinator",
		"Decider combinator",
		"Constant combinator",
		"Power switch",
		"Programmable speaker",
		"Boiler",
		"Steam engine",
		"Solar panel",
		"Accumulator",
		"Nuclear reactor",
		"Heat pipe",
		"Heat exchanger",
		"Steam turbine",
		"Burner mining drill",
		"Electric mining drill",
		"Offshore pump",
		"Pumpjack",
		"Stone furnace",
		"Steel furnace",
		"Electric furnace",
		"Assembling machine 1",
		"Assembling machine 2",
		"Assembling machine 3",
		"Oil refinery",
		"Chemical plant",
		"Centrifuge",
		"Lab",
		"Beacon",
		"Rocket silo",
		"Land mine",
		"Wall",
		"Gate",
		"Gun turret",
		"Laser turret",
		"Flamethrower turret",
		"Artillery turret",
		"Radar",

		"Stone brick",
	};

	static inline const vector<string> BuildingLuaNames = {
		"wooden-chest",
		"iron-chest",
		"steel-chest",
		"storage-tank",
		"transport-belt",
		"fast-transport-belt",
		"express-transport-belt",
		"underground-belt",
		"fast-underground-belt",
		"express-underground-belt",
		"splitter",
		"fast-splitter",
		"express-splitter",
		"burner-inserter",
		"inserter",
		"long-handed-inserter",
		"fast-inserter",
		"filter-inserter",
		"stack-inserter",
		"stack-filter-inserter",
		"small-electric-pole",
		"medium-electric-pole",
		"big-electric-pole",
		"substation",
		"pipe",
		"pipe-to-ground",
		"pump",
		"curved-rail",
		"straight-rail",
		"train-stop",
		"rail-signal",
		"rail-chain-signal",
		"logistic-chest-active-provider",
		"logistic-chest-passive-provider",
		"logistic-chest-storage",
		"logistic-chest-buffer",
		"logistic-chest-requester",
		"roboport",
		"small-lamp",
		"arithmetic-combinator",
		"decider-combinator",
		"constant-combinator",
		"power-switch",
		"programmable-speaker",
		"boiler",
		"steam-engine",
		"solar-panel",
		"accumulator",
		"nuclear-reactor",
		"heat-pipe",
		"heat-exchanger",
		"steam-turbine",
		"burner-mining-drill",
		"electric-mining-drill",
		"offshore-pump",
		"pumpjack",
		"stone-furnace",
		"steel-furnace",
		"electric-furnace",
		"assembling-machine-1",
		"assembling-machine-2",
		"assembling-machine-3",
		"oil-refinery",
		"chemical-plant",
		"centrifuge",
		"lab",
		"beacon",
		"rocket-silo",
		"land-mine",
		"stone-wall",
		"gate",
		"gun-turret",
		"laser-turret",
		"flamethrower-turret",
		"artillery-turret",
		"radar",

		"stone-brick",
	};

	struct BuildingSize
	{
		double x, y;
	};

	BuildingSize Size(bool old = false) const;

	static inline const vector<BuildingSize> BuildingSizes = {
		{0.695313, 0.695313},
		{0.695313, 0.695313},
		{0.695313, 0.695313},
		{2.593750, 2.593750},
		{0.796875, 0.796875},
		{0.796875, 0.796875},
		{0.796875, 0.796875},
		{0.796875, 0.796875},
		{0.796875, 0.796875},
		{0.796875, 0.796875},
		{1.796875, 0.796875},
		{1.796875, 0.796875},
		{1.796875, 0.796875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{0.296875, 0.296875},
		{1.296875, 1.296875},
		{1.398438, 1.398438},
		{0.578125, 0.578125},
		{0.578125, 0.488281},
		{0.578125, 1.796875},
		{1.500000, 2.144531},
		{1.398438, 1.976563},
		{1.000000, 1.000000},
		{0.398438, 0.398438},
		{0.398438, 0.398438},
		{0.695313, 0.695313},
		{0.695313, 0.695313},
		{0.695313, 0.695313},
		{0.695313, 0.695313},
		{0.695313, 0.695313},
		{3.398438, 3.398438},
		{0.296875, 0.296875},
		{0.695313, 1.296875},
		{0.695313, 1.296875},
		{0.695313, 0.695313},
		{1.398438, 1.398438},
		{0.593750, 0.593750},
		{2.578125, 1.578125},
		{2.500000, 4.695313},
		{2.796875, 2.796875},
		{1.796875, 1.796875},
		{4.398438, 4.398438},
		{0.593750, 0.593750},
		{2.578125, 1.578125},
		{2.500000, 4.695313},
		{1.398438, 1.398438},
		{2.796875, 2.796875},
		{1.195313, 1.343750},
		{2.398438, 2.398438},
		{1.398438, 1.398438},
		{1.398438, 1.398438},
		{2.398438, 2.398438},
		{2.398438, 2.398438},
		{2.398438, 2.398438},
		{2.398438, 2.398438},
		{4.796875, 4.796875},
		{2.398438, 2.398438},
		{2.398438, 2.398438},
		{2.398438, 2.398438},
		{2.398438, 2.398438},
		{8.796875, 8.796875},
		{0.796875, 0.796875},
		{0.578125, 0.578125},
		{0.578125, 0.578125},
		{1.398438, 1.398438},
		{1.398438, 1.398438},
		{1.398438, 2.398438},
		{2.398438, 2.398438},
		{2.398438, 2.398438},

		{1, 1},
	};

	static inline const vector<BuildingSize> OldBuildingSizes = {		
		{1, 1},
		{1, 1},
		{1, 1},
		{3, 3}, 
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{2, 1},
		{2, 1},
		{2, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{2, 2},
		{2, 2},
		{1, 1},
		{1, 1},
		{3, 3},
		{1.7f, 2.4f}, // curved rail
		{1.7f, 2.4f},
		{1.8f, 1.8f},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{1, 1},
		{4, 4},
		{1, 1},
		{1, 2},
		{1, 2},
		{1, 1},
		{2, 2},
		{1, 1},
		{3, 2},
		{3, 5},
		{3, 3},
		{2, 2},
		{5, 5},
		{1, 1},
		{3, 2},
		{3, 5},
		{2, 2},
		{3, 3},
		{1, 2},
		{3, 3},
		{1.6f, 2},
		{1.6f, 2},
		{1.6f, 2},
		{3, 3},
		{3, 3},
		{3, 3},
		{5, 5},
		{3, 3},
		{3, 3},
		{3, 3},
		{3, 3},
		{9, 9},
		{1, 1},
		{1, 1},
		{1, 1},
		{2, 2},
		{2, 2},
		{2, 3},
		{3, 3},
		{3, 3},
	};
	
	static inline map<string, BuildingType> Map_BuildingName_to_BuildingType = convert_vector_to_enummap<BuildingType>(BuildingNames);


	/*
	*  Curved rails
		{"Repair pack", {1, 1}},

		{"Wreck", {1, 1}}
		{"Locomotive", {2, 6}},
		{"Cargo wagon", {2, 6}},
		{"Fluid wagon", {2, 6}},
		{"Artillery wagon", {2, 6}},
		{"Car", {1.2f, 1.9f}},
		{"Tank", {1.7f, 2.5f}},
		{"Spidertron", {2, 1.9f}},
		{"Logistic robot", {1, 1}},
		{"Construction robot", {1, 1}},
		{"Red wire", {1, 1}},
		{"Green wire", {1, 1}},

		{"Concrete", {1, 1}},
		{"Refined concrete", {1, 1}},
		{"Stone brick", {1, 1}},
		{"Hazard concrete", {1, 1}},
		{"Refined hazard concrete", {1, 1}},
		{"Landfill", {1, 1}},
		*/
};
