#pragma once

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

// it is important to go though all of the lists When changes to the game is implemented to ensure that the lists are still accurate

static const double invalidX = 0.3543534;

static const struct GeneratorThumbprint
{
	string name = "Factorio TAS Generator";
	string version = "0.4.3";
} generator_thumbprint;

static const vector<string> fuel_list = {
	"Wood",
	"Coal",
	"Solid fuel",
	"Rocket fuel",
	"Nuclear fuel",
	"Uranium fuel cell"
};

static const vector<string> chest_list = {
	"Wooden chest",
	"Iron chest",
	"Steel chest",
	"Active provider chest",
	"Passive provider chest",
	"Storage chest",
	"Buffer chest",
	"Requester chest"
};

static const vector<string> splitter_list = {
	"Splitter",
	"Fast splitter",
	"Express splitter"
};

static const vector<string> filter_inserter_list = {
	"Filter inserter",
	"Stack filter inserter"
};

static const map<string, vector<float>> building_size_list = {
	{"Wooden chest", {0.695313f, 0.695313f}},
	{"Iron chest", {0.695313f, 0.695313f}},
	{"Steel chest", {0.695313f, 0.695313f}},
	{"Storage tank", {2.593750f, 2.593750f}},
	{"Transport belt", {0.796875f, 0.796875f}},
	{"Fast transport belt", {0.796875f, 0.796875f}},
	{"Express transport belt", {0.796875f, 0.796875f}},
	{"Underground belt", {0.796875f, 0.796875f}},
	{"Fast underground belt", {0.796875f, 0.796875f}},
	{"Express underground belt", {0.796875f, 0.796875f}},
	{"Splitter", {1.796875f, 0.796875f}},
	{"Fast splitter", {1.796875f, 0.796875f}},
	{"Express splitter", {1.796875f, 0.796875f}},
	{"Loader", {0.796875f, 1.796875f}},
	{"Fast loader", {0.796875f, 1.796875f}},
	{"Express loader", {0.796875f, 1.796875f}},
	{"Burner inserter", {0.296875f, 0.296875f}},
	{"Inserter", {0.296875f, 0.296875f}},
	{"Long-handed inserter", {0.296875f, 0.296875f}},
	{"Fast inserter", {0.296875f, 0.296875f}},
	{"Filter inserter", {0.296875f, 0.296875f}},
	{"Stack inserter", {0.296875f, 0.296875f}},
	{"Stack filter inserter", {0.296875f, 0.296875f}},
	{"Small electric pole", {0.296875f, 0.296875f}},
	{"Medium electric pole", {0.296875f, 0.296875f}},
	{"Big electric pole", {1.296875f, 1.296875f}},
	{"Substation", {1.398438f, 1.398438f}},
	{"Pipe", {0.578125f, 0.578125f}},
	{"Pipe to ground", {0.578125f, 0.488281f}},
	{"Pump", {0.578125f, 1.796875f}},
	{"Curved rail", {1.500000f, 2.144531f}},
	{"Straight rail", {1.398438f, 1.976563f}},
	{"Train stop", {1.000000f, 1.000000f}},
	{"Rail signal", {0.398438f, 0.398438f}},
	{"Rail chain signal", {0.398438f, 0.398438f}},
	{"Locomotive", {1.195313f, 5.195313f}},
	{"Cargo wagon", {1.195313f, 4.796875f}},
	{"Fluid wagon", {1.195313f, 4.796875f}},
	{"Artillery wagon", {1.195313f, 4.796875f}},
	{"Car", {1.398438f, 2.000000f}},
	{"Tank", {1.796875f, 2.593750f}},
	{"Spidertron", {2.000000f, 2.000000f}},
	{"Active provider chest", {0.695313f, 0.695313f}},
	{"Passive provider chest", {0.695313f, 0.695313f}},
	{"Storage chest", {0.695313f, 0.695313f}},
	{"Buffer chest", {0.695313f, 0.695313f}},
	{"Requester chest", {0.695313f, 0.695313f}},
	{"Roboport", {3.398438f, 3.398438f}},
	{"Small lamp", {0.296875f, 0.296875f}},
	{"Arithmetic combinator", {0.695313f, 1.296875f}},
	{"Decider combinator", {0.695313f, 1.296875f}},
	{"Constant combinator", {0.695313f, 0.695313f}},
	{"Power switch", {1.398438f, 1.398438f}},
	{"Programmable speaker", {0.593750f, 0.593750f}},
	{"Boiler", {2.578125f, 1.578125f}},
	{"Steam engine", {2.500000f, 4.695313f}},
	{"Solar panel", {2.796875f, 2.796875f}},
	{"Accumulator", {1.796875f, 1.796875f}},
	{"Nuclear reactor", {4.398438f, 4.398438f}},
	{"Heat pipe", {0.593750f, 0.593750f}},
	{"Heat exchanger", {2.578125f, 1.578125f}},
	{"Steam turbine", {2.500000f, 4.695313f}},
	{"Burner mining drill", {1.398438f, 1.398438f}},
	{"Electric mining drill", {2.796875f, 2.796875f}},
	{"Offshore pump", {1.195313f, 1.343750f}},
	{"Pumpjack", {2.398438f, 2.398438f}},
	{"Stone furnace", {1.398438f, 1.398438f}},
	{"Steel furnace", {1.398438f, 1.398438f}},
	{"Electric furnace", {2.398438f, 2.398438f}},
	{"Assembling machine 1", {2.398438f, 2.398438f}},
	{"Assembling machine 2", {2.398438f, 2.398438f}},
	{"Assembling machine 3", {2.398438f, 2.398438f}},
	{"Oil refinery", {4.796875f, 4.796875f}},
	{"Chemical plant", {2.398438f, 2.398438f}},
	{"Centrifuge", {2.398438f, 2.398438f}},
	{"Lab", {2.398438f, 2.398438f}},
	{"Beacon", {2.398438f, 2.398438f}},
	{"Rocket silo", {8.796875f, 8.796875f}},
	{"Land mine", {0.796875f, 0.796875f}},
	{"Stone wall", {0.578125f, 0.578125f}},
	{"Gate", {0.578125f, 0.578125f}},
	{"Gun turret", {1.398438f, 1.398438f}},
	{"Laser turret", {1.398438f, 1.398438f}},
	{"Flamethrower turret", {1.398438f, 2.398438f}},
	{"Artillery turret", {2.398438f, 2.398438f}},
	{"Radar", {2.398438f, 2.398438f}},
	{"Item on ground", {0.273438f, 0.273438f}},
	{"Rocket silo rocket", {4.000000f, 11.000000f}},
	{"Tile ghost", {1.000000f, 1.000000f}},
	{"Stone brick", {1, 1}},
	{"Concrete", {1, 1}},
	{"Hazard concrete left", {1, 1}},
	{"Hazard concrete right", {1, 1}},
	{"Refined concrete", {1, 1}},
	{"Refined hazard concrete left", {1, 1}},
	{"Refined hazard concrete right", {1, 1}},
	{"Landfill", {1, 1}},
	{"Wreck", {1, 1}}
};

static const map<string, vector<float>> old_building_size_list = {
	{"Accumulator", {2, 2}},
	{"Wooden chest", {1, 1}},
	{"Iron chest", {1, 1}},
	{"Steel chest", {1, 1}},
	{"Storage tank", {3, 3}},
	{"Transport belt", {1, 1}},
	{"Fast transport belt", {1, 1}},
	{"Underground belt", {1, 1}},
	{"Fast underground belt", {1, 1}},
	{"Splitter", {2, 1}},
	{"Fast splitter", {2, 1}},
	{"Burner inserter", {1, 1}},
	{"Inserter", {1, 1}},
	{"Long-handed inserter", {1, 1}},
	{"Fast inserter", {1, 1}},
	{"Filter inserter", {1, 1}},
	{"Stack inserter", {1, 1}},
	{"Stack filter inserter", {1, 1}},
	{"Small electric pole", {1, 1}},
	{"Medium electric pole", {1, 1}},
	{"Big electric pole", {2, 2}},
	{"Substation", {2, 2}},
	{"Pipe", {1, 1}},
	{"Pipe to ground", {1, 1}},
	{"Pump", {3, 3}},
	{"Rail", {1.7f, 2.4f}},
	{"Train stop", {1.8f, 1.8f}},
	{"Rail signal", {1, 1}},
	{"Rail chain signal", {1, 1}},
	{"Locomotive", {2, 6}},
	{"Cargo wagon", {2, 6}},
	{"Fluid wagon", {2, 6}},
	{"Artillery wagon", {2, 6}},
	{"Car", {1.2f, 1.9f}},
	{"Tank", {1.7f, 2.5f}},
	{"Spidertron", {2, 1.9f}},
	{"Logistic robot", {1, 1}},
	{"Construction robot", {1, 1}},
	{"Active provider chest", {1, 1}},
	{"Passive provider chest", {1, 1}},
	{"Storage chest", {1, 1}},
	{"Buffer chest", {1, 1}},
	{"Requester chest", {1, 1}},
	{"Roboport", {4, 4}},
	{"Lamp", {1, 1}},
	{"Red wire", {1, 1}},
	{"Green wire", {1, 1}},
	{"Arithmetic combinator", {1, 2}},
	{"Decider combinator", {1, 2}},
	{"Constant combinator", {1, 1}},
	{"Power switch", {2, 2}},
	{"Programmable speaker", {1, 1}},
	{"Hazard concrete", {1, 1}},
	{"Refined hazard concrete", {1, 1}},
	{"Landfill", {1, 1}},
	{"Land mine", {1, 1}},
	{"Wall", {1, 1}},
	{"Gate", {1, 1}},
	{"Gun turret", {2, 2}},
	{"Laser turret", {2, 2}},
	{"Flamethrower turret", {2, 3}},
	{"Artillery turret", {3, 3}},
	{"Radar", {3, 3}},
	{"Rocket silo", {9, 9}},
	{"Repair pack", {1, 1}},
	{"Boiler", {3, 2}},
	{"Steam engine", {3, 5}},
	{"Steam turbine", {3, 5}},
	{"Solar panel", {3, 3}},
	{"Nuclear reactor", {5, 5}},
	{"Heat exchanger", {3, 2}},
	{"Heat pipe", {1, 1}},
	{"Burner mining drill", {2, 2}},
	{"Electric mining drill", {3, 3}},
	{"Offshore pump", {1, 2}},
	{"Pumpjack", {3, 3}},
	{"Stone furnace", {1.6f, 2}},
	{"Steel furnace", {1.6f, 2}},
	{"Electric furnace", {1.6f, 2}},
	{"Assembling machine 1", {3, 3}},
	{"Assembling machine 2", {3, 3}},
	{"Assembling machine 3", {3, 3}},
	{"Oil refinery", {5, 5}},
	{"Chemical plant", {3, 3}},
	{"Centrifuge", {3, 3}},
	{"Lab", {3, 3}},
	{"Beacon", {3, 3}},
	{"Express transport belt", {1, 1}},
	{"Express underground belt", {1, 1}},
	{"Express splitter", {1, 1}},
	{"Concrete", {1, 1}},
	{"Refined concrete", {1, 1}},
	{"Stone brick", {1, 1}},
	{"Wreck", {1, 1}}
};

static const std::vector<std::string> science_packs = {
	"Automation science pack",
	"Logistic science pack",
	"Military science pack",
	"Chemical science pack",
	"Production science pack",
	"Utility science pack",
	"Space science pack",
};

static const std::vector<std::string> filter_take_put_drop_extra_list = 
{
	"Nuclear fuel",
	"Uranium-235",
	"Uranium-238",
	"Used-up uranium fuel cell"
};

static const std::vector<std::string> weapon_list = 
{
	"Pistol",
	"Submachine gun",
	"Shotgun",
	"Combat shotgun",
	"Flamethrower",
	"Rocket launcher"
};

static const std::vector<std::string> magazine_list = 
{
	"Firearm magazine",
	"Piercing rounds magazine",
	"Uranium rounds magazine"
};

static const std::vector<std::string> shotgun_shell_list = 
{
	"Shotgun shells",
	"Piercing shotgun shells"
};

static const std::vector<std::string> rocket_list = 
{
	"Rocket",
	"Explosive rocket",
	"Atomic bomb"
};

static const std::vector<std::string> flamethrower_fuel_list = 
{
	"Flamethrower ammo"
};

static const std::vector<std::string> tank_shell_list = 
{
	"Cannon shell",
	"Explosive cannon shell",
	"Uranium cannon shell",
	"Explosive uranium cannon shell"
};

static const std::vector<std::string> grenade_list = {};

static const std::vector<std::string> tank_shells = {};

static const std::vector<std::string> tank_shells2 = {};

static const std::vector<std::string> item_categories = 
{
	"Logistics",
	"Production",
	"Intermediates",
	"Combat"
};

static const std::vector<std::string> item_categories_fuel = 
{
	"Fuel"
};

static const std::vector<std::string> item_logistics = 
{
	"None",
	"Wooden chest",
	"Iron chest",
	"Steel chest",
	"Transport belt",
	"Burner inserter",
	"Inserter",
	"Long-handed inserter",
	"Fast inserter",
	"Filter inserter",
	"Stack inserter",
	"Stack filter inserter",
	"Small electric pole",
	"Pipe", "Pipe to ground",
	"Underground belt",
	"Splitter"
};

static const std::vector<std::string> item_production = 
{
	"Boiler",
	"Steam engine",
	"Burner mining drill",
	"Electric mining drill",
	"Offshore pump", "Pumpjack",
	"Stone furnace",
	"Steel furnace",
	"Assembling machine 1",
	"Assembling machine 2",
	"Lab",
	"Speed module",
	"Speed module 2",
	"Speed module 3",
	"Efficiency module",
	"Efficiency module 2",
	"Efficiency module 3",
	"Productivity module",
	"Productivity module 2",
	"Productivity module 3"
};

static const std::vector<std::string> item_intermediates = 
{
	"Wood",
	"Coal",
	"Stone",
	"Iron ore",
	"Copper ore",
	"Iron plate",
	"Copper plate",
	"Iron gear wheel",
	"Copper cable",
	"Automation science pack",
	"Electronic circuit"
};

static const std::vector<std::string> item_combat = 
{
	"Pistol",
	"Submachine gun",
	"Shotgun"
};

static const std::vector<std::string> module_list = 
{
	"Speed module",
	"Speed module 2",
	"Speed module 3",
	"Efficiency module",
	"Efficiency module 2",
	"Efficiency module 3",
	"Productivity module",
	"Productivity module 2",
	"Productivity module 3"
};

static const std::vector<std::string> tech_list =
{
	"Advanced electronics",
	"Advanced electronics 2",
	"Automation",
	"Automation 2",
	"Automation 3",
	"Electric energy accumulators",
	"Electric energy distribution 1",
	"Electric energy distribution 2",
	"Fast inserter",
	"Fluid handling",
	"Logistics",
	"Logistics 2",
	"Logistics 3",
	"Nuclear power",
	"Oil processing",
	"Rocket silo",
	"Solar energy",
	"Stack inserter",
	"Atomic bomb",
	"Combat robotics",
	"Combat robotics 2",
	"Combat robotics 3",
	"Flamethrower",
	"Military",
	"Military 2",
	"Military 3",
	"Military 4",
	"Rocketry",
	"Explosive rocketry",
	"Uranium ammo",
	"Artillery shell range",
	"Artillery shell shooting speed",
	"Braking force 1",
	"Braking force 2",
	"Braking force 3",
	"Braking force 4",
	"Braking force 5",
	"Braking force 6",
	"Braking force 7",
	"Energy weapons damage 1",
	"Energy weapons damage 2",
	"Energy weapons damage 3",
	"Energy weapons damage 4",
	"Energy weapons damage 5",
	"Energy weapons damage 6",
	"Energy weapons damage 7",
	"Follower robot count 1",
	"Follower robot count 2",
	"Follower robot count 3",
	"Follower robot count 4",
	"Follower robot count 5",
	"Follower robot count 6",
	"Follower robot count 7",
	"Inserter capacity bonus 1",
	"Inserter capacity bonus 2",
	"Inserter capacity bonus 3",
	"Inserter capacity bonus 4",
	"Inserter capacity bonus 5",
	"Inserter capacity bonus 6",
	"Inserter capacity bonus 7",
	"Lab research speed 1",
	"Lab research speed 2",
	"Lab research speed 3",
	"Lab research speed 4",
	"Lab research speed 5",
	"Lab research speed 6",
	"Laser turret shooting speed 1",
	"Laser turret shooting speed 2",
	"Laser turret shooting speed 3",
	"Laser turret shooting speed 4",
	"Laser turret shooting speed 5",
	"Laser turret shooting speed 6",
	"Laser turret shooting speed 7",
	"Mining productivity 1",
	"Mining productivity 2",
	"Mining productivity 3",
	"Mining productivity 4",
	"Mining productivity 4",
	"Physical projectile damage 1",
	"Physical projectile damage 2",
	"Physical projectile damage 3",
	"Physical projectile damage 4",
	"Physical projectile damage 5",
	"Physical projectile damage 6",
	"Physical projectile damage 7",
	"Refined flammables",
	"Refined flammables 2",
	"Stronger explosives 1",
	"Stronger explosives 2",
	"Stronger explosives 3",
	"Stronger explosives 4",
	"Stronger explosives 5",
	"Stronger explosives 6",
	"Stronger explosives 7",
	"Weapon shooting speed 1",
	"Weapon shooting speed 2",
	"Weapon shooting speed 3",
	"Weapon shooting speed 4",
	"Weapon shooting speed 5",
	"Weapon shooting speed 6",
	"Worker robot cargo size 1",
	"Worker robot cargo size 2",
	"Worker robot cargo size 3",
	"Worker robot speed 1",
	"Worker robot speed 2",
	"Worker robot speed 3",
	"Worker robot speed 4",
	"Worker robot speed 5",
	"Worker robot speed 6",
	"Construction robotics",
	"Logistic robotics",
	"Steel axe",
	"Toolbelt",
	"Heavy armor",
	"Modular armor",
	"Power armor",
	"Power armor MK2",
	"Gates",
	"Land mines",
	"Stone walls",
	"turrets",
	"Laser turrets",
	"Artillery",
	"Advanced material processing",
	"Advanced material processing 2",
	"Advanced oil processing",
	"Battery",
	"Circuit network",
	"Chemical science pack",
	"Cliff explosives",
	"Coal liquefaction",
	"Concrete",
	"Electronics",
	"Engine",
	"Electric engine",
	"Explosives",
	"Flammables",
	"Kovarex enrichment process",
	"Landfill",
	"Laser",
	"Logistic science pack",
	"Logistic system",
	"Low density structure",
	"Lubricant",
	"Military science pack",
	"Nuclear fuel reprocessing",
	"Optics",
	"Plastics",
	"Production science pack",
	"Robotics",
	"Rocket control unit",
	"Rocket fuel",
	"Space science pack",
	"Steel processing",
	"Sulfur processing",
	"Uranium processing",
	"Utility science pack",
	"Automated rail transportation",
	"Automobilism",
	"Fluid wagon",
	"Rail signals",
	"Railway",
	"Tanks",
	"Spidertron",
	"Belt immunity equipment",
	"Discharge defense",
	"Energy shield equipment",
	"Energy shield equipment MK2",
	"Exoskeleton equipment",
	"Nightvision equipment",
	"Personal battery",
	"Personal battery MK2",
	"Personal laser defense",
	"Personal roboport",
	"Personal roboport MK2",
	"Portable fusion reactor",
	"Portable solar panel",
	"Modules",
	"Effect transmission",
	"Efficiency module",
	"Efficiency module 2",
	"Efficiency module 3",
	"Productivity module",
	"Productivity module 2",
	"Productivity module 3",
	"Speed module",
	"Speed module 2",
	"Speed module 3"
};

static const std::vector<std::string> drills_list =
{
	"Electric mining drill",
	"Pumpjack"
};

static const struct
{
	std::string stone = "Stone furnace";
	std::string steel = "Steel furnace";
} struct_auto_put_furnace_list;

static const struct
{
	std::string burner_mining_drill = "Burner mining drill";
	std::string burner_inserter = "Burner inserter";
	std::string boiler = "Boiler";
} struct_auto_put_burner_list;

static const struct
{
	std::string wood = "Wood";
	std::string coal = "Coal";
	std::string solid_fuel = "Solid fuel";
	std::string rocket_fuel = "Rocket fuel";
	std::string nuclear_fuel = "Nuclear fuel";
	std::string uranium_fuel_cell = "Uranium fuel cell";
} struct_fuel_list;

static const struct
{
	std::string lab = "Lab";
	std::string red_science = "automation-science-pack";
	std::string green_science = "logistic-science-pack";
	std::string black_science = "military-science-pack";
	std::string blue_science = "chemical-science-pack";
	std::string purple_science = "production-science-pack";
	std::string yellow_science = "utility-science-pack";
	std::string white_science = "space-science-pack";
} struct_science_list;

struct log_config
{
	enum leveltype {DEBUG, DEV, RELEASE};
	bool savegame,
		tech,
		comment;
	leveltype level;
	std::string to_string()
	{
		return std::to_string(savegame) + ";" + std::to_string(tech) + ";" + std::to_string(comment) + ";" + std::to_string(level) + ";";
	}
};

// Additional script generation configurations
struct generate_config
{
	bool legacy_mining = false;
	bool intermediate_walk_towards = false;
	bool no_intermediate_walk = false;
	std::string to_string()
	{
		return std::to_string(legacy_mining) + ";" + std::to_string(intermediate_walk_towards) + ";" + std::to_string(no_intermediate_walk) + ";";
	}
};

struct WarningsStatesCounters
{
	int never_idle = 0;
	int keep_walking = 0;
	int keep_on_path = 0;
	int keep_crafting = 0;
	WarningsStatesCounters()
	{
		never_idle = 0; keep_walking = 0; keep_on_path = 0; keep_crafting = 0;
	}
};
