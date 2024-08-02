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
	string version = "0.5.4";
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
	{"Wreck", {1, 1}},
	{"vehicle", {1, 1}}
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
