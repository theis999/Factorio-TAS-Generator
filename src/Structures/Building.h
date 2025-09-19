#pragma once

#include "Orientation.h"

#include "../StdUtil.h"

struct Building
{
	/* LUA CODE

	helpers.write_file(file,"")

	helpers.write_file(file, "\nenum BuildingType{\n", true)
	for _, prototype in pairs(prototypes.entity) do
		if not prototype.hidden and prototype.items_to_place_this and #prototype.items_to_place_this > 0 then
			helpers.write_file(file, string.format("\t%s,\n", prototype.name:gsub("-", "_")), true)
		end
	end
	for _, prototype in pairs(prototypes.tile) do
		if not prototype.hidden and prototype.items_to_place_this and #prototype.items_to_place_this > 0 then
			helpers.write_file(file, string.format("\t%s,\n", prototype.name:gsub("-", "_")), true)
		end
	end
	helpers.write_file(file, "} ;\n", true)

	helpers.write_file(file, "\nstatic inline const vector<string> BuildingNames = {\n", true)
	for _, prototype in pairs(prototypes.entity) do
		if not prototype.hidden and prototype.items_to_place_this and #prototype.items_to_place_this > 0 then
			helpers.write_file(file, "\t\"", true)
			helpers.write_file(file, prototype.localised_name, true)
			helpers.write_file(file, "\",\n", true)
		end
	end
	for _, prototype in pairs(prototypes.tile) do
		if not prototype.hidden and prototype.items_to_place_this and #prototype.items_to_place_this > 0 then
			helpers.write_file(file, "\t\"", true)
			helpers.write_file(file, prototype.localised_name, true)
			helpers.write_file(file, "\",\n", true)
		end
	end
	helpers.write_file(file, "};\n", true)

	helpers.write_file(file, "\nstatic inline const vector<string> BuildingLuaNames = {\n", true)
	for _, prototype in pairs(prototypes.entity) do
		if not prototype.hidden and prototype.items_to_place_this and #prototype.items_to_place_this > 0 then
			helpers.write_file(file, string.format("\t\"%s\",\n", prototype.name), true)
		end
	end
	for _, prototype in pairs(prototypes.tile) do
		if not prototype.hidden and prototype.items_to_place_this and #prototype.items_to_place_this > 0 then
			helpers.write_file(file, string.format("\t\"%s\",\n", prototype.name), true)

		end
	end
	helpers.write_file(file, "};\n", true)

	*/
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
		bulk_inserter,
		small_electric_pole,
		medium_electric_pole,
		big_electric_pole,
		substation,
		pipe,
		pipe_to_ground,
		pump,
		straight_rail,
		half_diagonal_rail,
		curved_rail_a,
		curved_rail_b,
		train_stop,
		rail_signal,
		rail_chain_signal,
		locomotive,
		cargo_wagon,
		fluid_wagon,
		artillery_wagon,
		car,
		tank,
		spidertron,
		logistic_robot,
		construction_robot,
		active_provider_chest,
		passive_provider_chest,
		storage_chest,
		buffer_chest,
		requester_chest,
		roboport,
		small_lamp,
		arithmetic_combinator,
		decider_combinator,
		selector_combinator,
		constant_combinator,
		power_switch,
		programmable_speaker,
		display_panel,
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
		cargo_landing_pad,
		stone_wall,
		gate,
		radar,
		land_mine,
		gun_turret,
		laser_turret,
		flamethrower_turret,
		artillery_turret,
		stone_path,
		concrete,
		hazard_concrete_left,
		hazard_concrete_right,
		refined_concrete,
		refined_hazard_concrete_left,
		refined_hazard_concrete_right,
		landfill,
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
		"Bulk inserter",
		"Small electric pole",
		"Medium electric pole",
		"Big electric pole",
		"Substation",
		"Pipe",
		"Pipe to ground",
		"Pump",
		"Straight rail",
		"Half diagonal rail",
		"Curved rail",
		"Curved rail",
		"Train stop",
		"Rail signal",
		"Rail chain signal",
		"Locomotive",
		"Cargo wagon",
		"Fluid wagon",
		"Artillery wagon",
		"Car",
		"Tank",
		"Spidertron",
		"Logistic robot",
		"Construction robot",
		"Active provider chest",
		"Passive provider chest",
		"Storage chest",
		"Buffer chest",
		"Requester chest",
		"Roboport",
		"Lamp",
		"Arithmetic combinator",
		"Decider combinator",
		"Selector combinator",
		"Constant combinator",
		"Power switch",
		"Programmable speaker",
		"Display panel",
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
		"Cargo landing pad",
		"Wall",
		"Gate",
		"Radar",
		"Land mine",
		"Gun turret",
		"Laser turret",
		"Flamethrower turret",
		"Artillery turret",
		"Stone path",
		"Concrete",
		"Hazard concrete left",
		"Hazard concrete right",
		"Refined concrete",
		"Refined hazard concrete left",
		"Refined hazard concrete right",
		"Landfill",
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
		"bulk-inserter",
		"small-electric-pole",
		"medium-electric-pole",
		"big-electric-pole",
		"substation",
		"pipe",
		"pipe-to-ground",
		"pump",
		"straight-rail",
		"half-diagonal-rail",
		"curved-rail-a",
		"curved-rail-b",
		"train-stop",
		"rail-signal",
		"rail-chain-signal",
		"locomotive",
		"cargo-wagon",
		"fluid-wagon",
		"artillery-wagon",
		"car",
		"tank",
		"spidertron",
		"logistic-robot",
		"construction-robot",
		"active-provider-chest",
		"passive-provider-chest",
		"storage-chest",
		"buffer-chest",
		"requester-chest",
		"roboport",
		"small-lamp",
		"arithmetic-combinator",
		"decider-combinator",
		"selector-combinator",
		"constant-combinator",
		"power-switch",
		"programmable-speaker",
		"display-panel",
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
		"cargo-landing-pad",
		"stone-wall",
		"gate",
		"radar",
		"land-mine",
		"gun-turret",
		"laser-turret",
		"flamethrower-turret",
		"artillery-turret",
		"stone-path",
		"concrete",
		"hazard-concrete-left",
		"hazard-concrete-right",
		"refined-concrete",
		"refined-hazard-concrete-left",
		"refined-hazard-concrete-right",
		"landfill",
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
