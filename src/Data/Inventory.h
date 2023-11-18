#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

/// <summary>
/// Focused list of inventories, used for script generation
/// Full list available on https://lua-api.factorio.com/latest/defines.html#defines.inventory
/// </summary>
static const struct
{	
	string fuel = "defines.inventory.fuel";
	string chest = "defines.inventory.chest";
	string lab_input = "defines.inventory.lab_input";
	string lab_modules = "defines.inventory.lab_modules";
	string beacon_modules = "defines.inventory.beacon_modules";
	string drill_modules = "defines.inventory.mining_drill_modules";
	string assembly_input = "defines.inventory.assembling_machine_input";
	string assembly_output = "defines.inventory.assembling_machine_output";
	string assembly_modules = "defines.inventory.assembling_machine_modules";
} inventory_defines;

/*
/// <summary>
/// Full list of inventories, sub sorted by logically type
/// </summary>
static const struct{
	string fuel = "defines.inventory.fuel"; // 1
	string burnt_result = "defines.inventory.burnt_result"; // 6
	string chest = "defines.inventory.chest"; // 1
	string rocket = "defines.inventory.rocket"; // 1
	string wagon = "defines.inventory.cargo_wagon"; // 1
	string character_corpse = "defines.inventory.character_corpse"; // 1
	string artillery_turret_ammo = "defines.inventory.artillery_turret_ammo"; // 1
	string artillery_wagon_ammo = "defines.inventory.artillery_wagon_ammo"; // 1

	const struct{
		string source = "defines.inventory.furnace_source"; // 2
		string result = "defines.inventory.furnace_result"; // 3
		string modules = "defines.inventory.furnace_modules"; // 4
	} furnace;

	const struct
	{
		string main = "defines.inventory.character_main"; // 1
		string guns = "defines.inventory.character_guns"; // 3
		string ammo = "defines.inventory.character_ammo"; // 4
		string armor = "defines.inventory.character_armor"; // 5
		string vehicle = "defines.inventory.character_vehicle"; // 7
		string trash = "defines.inventory.character_trash"; // 8
	}character;

	const struct
	{
		string main = "defines.inventory.god_main"; // 2
	}god;

	const struct
	{
		string main = "defines.inventory.editor_main"; // 1
		string guns = "defines.inventory.editor_guns"; // 3
		string ammo = "defines.inventory.editor_ammo"; // 4
		string armor = "defines.inventory.editor_armor"; // 5
	}editor;

	const struct
	{
		string robot = "defines.inventory.roboport_robot"; // 1
		string material = "defines.inventory.roboport_material"; // 2
	}roboport;

	const struct
	{
		string cargo = "defines.inventory.robot_cargo"; // 1
		string repair = "defines.inventory.robot_repair"; // 2
	}robot;

	const struct
	{
		string input = "defines.inventory.assembling_machine_input"; // 2
		string output = "defines.inventory.assembling_machine_output"; // 3
		string modules = "defines.inventory.assembling_machine_modules"; // 4
	}assembling_machine;

	const struct
	{
		string input = "defines.inventory.lab_input"; // 2
		string modules = "defines.inventory.lab_modules"; // 3
	}lab;

	const struct
	{
		string modules = "defines.inventory.mining_drill_modules"; // 2
	}mining_drill;

	const struct
	{
		string main = "defines.inventory.item_main"; // 1
	}item;

	const struct
	{
		string input = "defines.inventory.rocket_silo_input"; // 2
		string output = "defines.inventory.rocket_silo_output"; // 3
		string modules = "defines.inventory.rocket_silo_modules"; // 4
		string rocket = "defines.inventory.rocket_silo_rocket"; // 5
		string result = "defines.inventory.rocket_silo_result"; // 6
	}rocket_silo;

	const struct
	{
		string trunk = "defines.inventory.car_trunk"; // 2
		string ammo = "defines.inventory.car_ammo"; // 3
	}car;

	const struct
	{
		string ammo = "defines.inventory.turret_ammo"; // 1
	}turret;

	const struct
	{
		string modules = "defines.inventory.beacon_modules"; // 1
	}beacon;

	const struct
	{
		string trunk = "defines.inventory.spider_trunk"; // 2
		string ammo = "defines.inventory.spider_ammo"; // 3
		string trash = "defines.inventory.spider_trash"; // 4
	}spider;
} inventory_defines_full;
*/

enum InventoryType
{
	Input,
	Output,
	Fuel,
	Modules,
	Chest,
	Wreck,

	Armor,
	Ammo_1,
	Ammo_2,
	Ammo_3,
	Weapon_1,
	Weapon_2,
	Weapon_3,
};

/// <summary>
/// Inventory types used in the GUI
/// </summary>
static const struct
{
	string input = "Input";
	string output = "Output";
	string fuel = "Fuel";
	string modules = "Modules";
	string chest = "Chest";
	string wreck = "Wreck";

	string armor = "Armor";
	string ammo_1 = "Ammo 1";
	string ammo_2 = "Ammo 2";
	string ammo_3 = "Ammo 3";
	string weapon_1 = "Weapon 1";
	string weapon_2 = "Weapon 2";
	string weapon_3 = "Weapon 3";
} inventory_types;

static const vector<string> inventory_types_list
{
	inventory_types.input,
	inventory_types.output,
	inventory_types.fuel,
	inventory_types.modules,
	inventory_types.chest,
	inventory_types.wreck,

	inventory_types.armor,
	inventory_types.ammo_1,
	inventory_types.ammo_2,
	inventory_types.ammo_3,
	inventory_types.weapon_1,
	inventory_types.weapon_2,
	inventory_types.weapon_3,
};

static inline InventoryType GetInventoryType(string inventory_type_string)
{
	for (int i = 0; i < inventory_types_list.size(); i++)
		if (inventory_type_string == inventory_types_list[i]) return (InventoryType)i;
	throw "unknown InventoryType";
}

static inline const string GetInventoryTypeForEntity(InventoryType type, string entity)
{
	static const string Lab = "Lab";
	static const string Beacon = "Beacon";
	static const string Drill = "Electric mining drill";

	switch (type)
	{
		case Input:
			if (entity == Lab)
				return inventory_defines.lab_input;
			else //assemblers
				return inventory_defines.assembly_input;
		case Output:
			return inventory_defines.assembly_output;
		case Fuel:
			return inventory_defines.fuel;
		case Modules:
			if (entity == Beacon)
				return inventory_defines.beacon_modules;
			else if (entity == Lab)
				return inventory_defines.lab_modules;
			else if (entity == Drill)
				return inventory_defines.drill_modules;
			else
				return inventory_defines.assembly_modules;
		case Chest:
			return inventory_defines.chest;
		case Wreck:
			return inventory_defines.chest;
		default:
			throw "unknown inventory_type";// unclear how we get here
	}
}
