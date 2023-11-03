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
	string version = "0.4.2";
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

static const map<string, vector<string>> recipes = {
	{"None", {}},
	{"Assembling machine 1", {"Iron plate", "9", "Iron gear wheel", "5", "Electronic circuit", "3"}},
	{"Automation science pack", {"Copper plate", "1", "Iron gear wheel", "1"}},
	{"Firearm magazine", {"Iron plate", "4"}},
	{"Pistol", {"Iron plate", "5", "Copper plate", "5"}},
	{"Piercing rounds magazine", {"Copper plate", "5", "Steel plate", "1", "Firearm magazine", "1"}},
	{"Submachine gun", {"Iron plate", "10", "Copper plate", "5", "Iron gear wheel", "10"}},
	{"Uranium rounds magazine", {"Uranium 238", "1", "Piercing rounds magazine", "1"}},
	{"Beacon", {"Steel plate", "10", "Copper cable", "10", "Electronic circuit", "20", "Advanced circuit", "20"}},
	{"Burner inserter", {"Iron plate", "1", "Iron gear wheel", "1"}},
	{"Copper cable", {"Copper plate", "1"}},
	{"Electric energy interface", {"Iron plate", "2", "Electronic circuit", "5"}},
	{"Portable solar panel", {"Steel plate", "5", "Advanced circuit", "2", "Solar panel", "1"}},
	{"Portable fusion reactor", {"Processing unit", "200", "Low density structure", "50"}},
	{"Small electric pole", {"Wood", "1", "Copper cable", "2"}},
	{"Medium electric pole", {"Copper plate", "2", "Steel plate", "2", "Iron stick", "4"}},
	{"Big electric pole", {"Copper plate", "5", "Steel plate", "5", "Iron stick", "8"}},
	{"Substation", {"Copper plate", "5", "Steel plate", "10", "Advanced circuit", "5"}},
	{"Sulfuric acid", {"Iron plate", "1", "Sulfur", "5", "Water", "100"}},
	{"Grenade", {"Coal", "10", "Iron plate", "5"}},
	{"Cluster grenade", {"Steel plate", "5", "Explosives", "5", "Grenade", "7"}},
	{"Burner mining drill", {"Iron plate", "3", "Iron gear wheel", "3", "Stone furnace", "1"}},
	{"Wooden chest", {"Wood", "2"}},
	{"Electric mining drill", {"Iron plate", "10", "Iron gear wheel", "5", "Electronic circuit", "3"}},
	{"Iron chest", {"Iron plate", "8"}},
	{"Steel chest", {"Steel plate", "8"}},
	{"Light armor", {"Iron plate", "40"}},
	{"Small lamp", {"Iron plate", "1", "Copper cable", "3", "Electronic circuit", "1"}},
	{"Basic oil processing", {"Crude oil", "100"}},
	{"Advanced oil processing", {"Water", "50", "Crude oil", "100"}},
	{"Coal liquefaction", {"Coal", "10", "Heavy oil", "25", "Steam", "50"}},
	{"Pipe", {"Iron plate", "1"}},
	{"Pipe to ground", {"Iron plate", "5", "Pipe", "10"}},
	{"Logistic robot", {"Advanced circuit", "2", "Flying robot frame", "1"}},
	{"Construction robot", {"Electronic circuit", "2", "Flying robot frame", "1"}},
	{"Energy shield", {"Steel plate", "10", "Advanced circuit", "5"}},
	{"Energy shield mk2", {"Processing unit", "5", "Low density structure", "5", "Energy shield", "10"}},
	{"Speed module", {"Electronic circuit", "5", "Advanced circuit", "5"}},
	{"Speed module 2", {"Advanced circuit", "5", "Processing unit", "5", "Speed module", "4"}},
	{"Speed module 3", {"Advanced circuit", "5", "Processing unit", "5", "Speed module 2", "5"}},
	{"Stone brick", {"Stone", "2"}},
	{"Stone furnace", {"Stone", "5"}},
	{"Stone wall", {"Stone brick", "5"}},
	{"Rail", {"Stone", "1", "Steel plate", "1", "Iron stick", "1"}},
	{"Train stop", {"Iron plate", "6", "Steel plate", "3", "Iron stick", "6", "Electronic circuit", "5"}},
	{"Rail signal", {"Iron plate", "5", "Electronic circuit", "1"}},
	{"Rail chain signal", {"Iron plate", "5", "Electronic circuit", "1"}},
	{"Locomotive", {"Steel plate", "30", "Electronic circuit", "10", "Engine unit", "20"}},
	{"Cargo wagon", {"Iron plate", "20", "Steel plate", "20", "Iron gear wheel", "10"}},
	{"Fluid wagon", {"Steel plate", "16", "Iron gear wheel", "10", "Storage tank", "1", "Pipe", "8"}},
	{"Artillery wagon", {"Steel plate", "40", "Iron gear wheel", "10", "Advanced circuit", "20", "Engine unit", "64", "Pipe", "16"}},
	{"Transport belt", {"Iron plate", "1", "Iron gear wheel", "1"}},
	{"Fast transport belt", {"Iron gear wheel", "5", "Transport belt", "1"}},
	{"Express transport belt", {"Iron gear wheel", "10", "Fast transport belt", "1", "Lubricant", "20"}},
	{"Gate", {"Steel plate", "2", "Electronic circuit", "2", "Stone wall", "1"}},
	{"Personal laser defense", {"Processing unit", "20", "Low density structure", "5", "Laser turret", "5"}},
	{"Discharge defense", {"Steel plate", "20", "Processing unit", "5", "Laser turret", "10"}},
	{"Discharge defense remote", {"Electronic circuit", "1"}},
	{"Assembling machine 2", {"Steel plate", "2", "Iron gear wheel", "5", "Electronic circuit", "3", "Assembling machine 1", "1"}},
	{"Personal battery", {"Steel plate", "10", "Battery", "5"}},
	{"Personal battery mk2", {"Processing unit", "15", "Low density structure", "5", "Personal battery", "10"}},
	{"Concrete", {"Iron ore", "1", "Stone brick", "5", "Water", "100"}},
	{"Hazard concrete", {"Concrete", "10"}},
	{"Refined concrete", {"Steel plate", "1", "Iron stick", "8", "Concrete", "20", "Water", "100"}},
	{"Refined hazard concrete", {"Refined concrete", "10"}},
	{"Fill crude oil barrel", {"Empty barrel", "1", "Crude oil", "50"}},
	{"Fill heavy oil barrel", {"Empty barrel", "1", "Heavy oil", "50"}},
	{"Fill light oil barrel", {"Empty barrel", "1", "Light oil", "50"}},
	{"Fill lubricant barrel", {"Empty barrel", "1", "Lubricant", "50"}},
	{"Fill petroleum gas barrel", {"Empty barrel", "1", "Petroleum gas", "50"}},
	{"Fill sulfuric acid barrel", {"Empty barrel", "1", "Sulfuric acid", "50"}},
	{"Fill water barrel", {"Empty barrel", "1", "Water", "50"}},
	{"Heavy oil cracking", {"Water", "30", "Heavy oil", "40"}},
	{"Light oil cracking", {"Water", "30", "Light oil", "30"}},
	{"Solid fuel from light oil", {"Light oil", "10"}},
	{"Solid fuel from petroleum gas", {"Petroleum gas", "20"}},
	{"Solid fuel from heavy oil", {"Heavy oil", "20"}},
	{"Storage tank", {"Iron plate", "20", "Steel plate", "5"}},
	{"Offshore pump", {"Iron gear wheel", "1", "Electronic circuit", "2", "Pipe", "1"}},
	{"Pumpjack", {"Steel plate", "5", "Iron gear wheel", "10", "Electronic circuit", "5", "Pipe", "10"}},
	{"Heavy armor", {"Copper plate", "100", "Steel plate", "50"}},
	{"Inserter", {"Iron plate", "1", "Iron gear wheel", "1", "Electronic circuit", "1"}},
	{"Iron plate", {"Iron ore", "1"}},
	{"Iron stick", {"Iron plate", "1"}},
	{"Logistic science pack", {"Transport belt", "1", "Inserter", "1"}},
	{"Car", {"Iron plate", "20", "Steel plate", "5", "Engine unit", "8"}},
	{"Tank", {"Steel plate", "50", "Iron gear wheel", "15", "Advanced circuit", "10", "Engine unit", "32"}},
	{"Spidertron", {"Raw fish", "1", "Rocket control unit", "16", "Low density structure", "150", "Effectivity module 3", "2", "Rocket launcher", "4", "Fusion reactor equipment", "2", "Exoskeleton equipment", "4", "Radar", "2"}},
	{"Spidertron remote", {"Rocket control unit", "1", "Radar", "1"}},
	{"Pump", {"Steel plate", "1", "Engine unit", "1", "Pipe", "1"}},
	{"Poison capsule", {"Coal", "10", "Steel plate", "3", "Electronic circuit", "3"}},
	{"Repair pack", {"Iron gear wheel", "2", "Electronic circuit", "2"}},
	{"Shotgun", {"Wood", "5", "Iron plate", "15", "Copper plate", "10", "Iron gear wheel", "5"}},
	{"Shotgun shell", {"Iron plate", "2", "Copper plate", "2"}},
	{"Combat shotgun", {"Wood", "10", "Copper plate", "10", "Steel plate", "15", "Iron gear wheel", "5"}},
	{"Piercing shotgun shell", {"Copper plate", "5", "Steel plate", "2", "Shotgun shell", "2"}},
	{"Boiler", {"Pipe", "4", "Stone furnace", "1"}},
	{"Steam engine", {"Iron plate", "10", "Iron gear wheel", "8", "Pipe", "5"}},
	{"Steel furnace", {"Steel plate", "6", "Stone brick", "10"}},
	{"Logistic chest active provider", {"Electronic circuit", "3", "Advanced circuit", "1", "Steel chest", "1"}},
	{"Logistic chest passive provider", {"Electronic circuit", "3", "Advanced circuit", "1", "Steel chest", "1"}},
	{"Logistic chest storage", {"Electronic circuit", "3", "Advanced circuit", "1", "Steel chest", "1"}},
	{"Logistic chest buffer", {"Electronic circuit", "3", "Advanced circuit", "1", "Steel chest", "1"}},
	{"Logistic chest requester", {"Electronic circuit", "3", "Advanced circuit", "1", "Steel chest", "1"}},
	{"Gun turret", {"Iron plate", "20", "Copper plate", "10", "Iron gear wheel", "10"}},
	{"Laser turret", {"Steel plate", "20", "Battery", "12", "Electronic circuit", "20"}},
	{"Flamethrower turret", {"Steel plate", "30", "Iron gear wheel", "15", "Engine unit", "5", "Pipe", "10"}},
	{"Artillery turret", {"Steel plate", "60", "Iron gear wheel", "40", "Advanced circuit", "20", "Concrete", "60"}},
	{"Artillery targeting remote", {"Processing unit", "1", "Radar", "1"}},
	{"Underground belt", {"Iron plate", "10", "Transport belt", "5"}},
	{"Fast underground belt", {"Iron gear wheel", "40", "Underground belt", "2"}},
	{"Express underground belt", {"Iron gear wheel", "80", "Fast underground belt", "2", "Lubricant", "40"}},
	{"Red wire", {"Copper cable", "1", "Electronic circuit", "1"}},
	{"Green wire", {"Copper cable", "1", "Electronic circuit", "1"}},
	{"Assembling machine 3", {"Assembling machine 2", "2", "Speed module", "4"}},
	{"Belt immunity equipment", {"Steel plate", "10", "Advanced circuit", "5"}},
	{"Arithmetic combinator", {"Copper cable", "5", "Electronic circuit", "5"}},
	{"Decider combinator", {"Copper cable", "5", "Electronic circuit", "5"}},
	{"Constant combinator", {"Copper cable", "5", "Electronic circuit", "2"}},
	{"Copper plate", {"Copper ore", "1"}},
	{"Effectivity module", {"Electronic circuit", "5", "Advanced circuit", "5"}},
	{"Effectivity module 2", {"Advanced circuit", "5", "Processing unit", "5", "Effectivity module", "4"}},
	{"Effectivity module 3", {"Advanced circuit", "5", "Processing unit", "5", "Effectivity module 2", "5"}},
	{"Electric furnace", {"Steel plate", "10", "Advanced circuit", "5", "Stone brick", "10"}},
	{"Empty crude oil barrel", {"Crude oil barrel", "1"}},
	{"Empty heavy oil barrel", {"Heavy oil barrel", "1"}},
	{"Empty light oil barrel", {"Light oil barrel", "1"}},
	{"Empty lubricant barrel", {"Lubricant barrel", "1"}},
	{"Empty petroleum gas barrel", {"Petroleum gas barrel", "1"}},
	{"Empty sulfuric acid barrel", {"Sulfuric acid barrel", "1"}},
	{"Empty water barrel", {"Water barrel", "1"}},
	{"Iron gear wheel", {"Iron plate", "2"}},
	{"Landfill", {"Stone", "20"}},
	{"Long-handed inserter", {"Iron plate", "1", "Iron gear wheel", "1", "Inserter", "1"}},
	{"Military science pack", {"Piercing rounds magazine", "1", "Grenade", "1", "Stone wall", "2"}},
	{"Modular armor", {"Steel plate", "50", "Advanced circuit", "30"}},
	{"Productivity module", {"Electronic circuit", "5", "Advanced circuit", "5"}},
	{"Productivity module 2", {"Advanced circuit", "5", "Processing unit", "5", "Productivity module", "4"}},
	{"Productivity module 3", {"Advanced circuit", "5", "Processing unit", "5", "Productivity module 2", "5"}},
	{"Roboport", {"Steel plate", "45", "Iron gear wheel", "45", "Advanced circuit", "45"}},
	{"Slowdown capsule", {"Coal", "5", "Steel plate", "2", "Electronic circuit", "2"}},
	{"Splitter", {"Iron plate", "5", "Electronic circuit", "5", "Transport belt", "4"}},
	{"Fast splitter", {"Iron gear wheel", "10", "Electronic circuit", "10", "Splitter", "1"}},
	{"Express splitter", {"Iron gear wheel", "10", "Advanced circuit", "10", "Fast splitter", "1", "Lubricant", "80"}},
	{"Cannon shell", {"Steel plate", "2", "Plastic bar", "2", "Explosives", "1"}},
	{"Explosive cannon shell", {"Steel plate", "2", "Plastic bar", "2", "Explosives", "2"}},
	{"Uranium cannon shell", {"Uranium 238", "1", "Cannon shell", "1"}},
	{"Chemical science pack", {"Sulfur", "1", "Advanced circuit", "3", "Engine unit", "2"}},
	{"Cliff explosives", {"Explosives", "10", "Empty barrel", "1", "Grenade", "1"}},
	{"Defender capsule", {"Iron gear wheel", "3", "Electronic circuit", "3", "Piercing rounds magazine", "3"}},
	{"Empty barrel", {"Steel plate", "1"}},
	{"Exoskeleton", {"Steel plate", "20", "Processing unit", "10", "Electric engine unit", "30"}},
	{"Explosive uranium cannon shell", {"Uranium 238", "1", "Explosive cannon shell", "1"}},
	{"Artillery shell", {"Explosives", "8", "Explosive cannon shell", "4", "Radar", "1"}},
	{"Fast inserter", {"Iron plate", "2", "Electronic circuit", "2", "Inserter", "1"}},
	{"Power switch", {"Iron plate", "5", "Copper cable", "5", "Electronic circuit", "2"}},
	{"Programmable speaker", {"Iron plate", "3", "Copper cable", "5", "Iron stick", "4", "Electronic circuit", "4"}},
	{"Power armor", {"Steel plate", "40", "Processing unit", "40", "Electric engine unit", "20"}},
	{"Radar", {"Iron plate", "10", "Iron gear wheel", "5", "Electronic circuit", "5"}},
	{"Oil refinery", {"Steel plate", "15", "Iron gear wheel", "10", "Electronic circuit", "10", "Pipe", "10", "Stone brick", "10"}},
	{"Rocket launcher", {"Iron plate", "5", "Iron gear wheel", "5", "Electronic circuit", "5"}},
	{"Rocket", {"Iron plate", "2", "Explosives", "1", "Electronic circuit", "1"}},
	{"Explosive rocket", {"Explosives", "2", "Rocket", "1"}},
	{"Atomic bomb", {"Explosives", "10", "Rocket control unit", "10", "Uranium 235", "30"}},
	{"Solar panel", {"Copper plate", "5", "Steel plate", "5", "Electronic circuit", "15"}},
	{"Steel plate", {"Iron plate", "5"}},
	{"Accumulator", {"Iron plate", "2", "Battery", "5"}},
	{"Chemical plant", {"Steel plate", "5", "Iron gear wheel", "5", "Electronic circuit", "5", "Pipe", "5"}},
	{"Distractor capsule", {"Advanced circuit", "3", "Defender capsule", "4"}},
	{"Electronic circuit", {"Iron plate", "1", "Copper cable", "3"}},
	{"Filter inserter", {"Electronic circuit", "4", "Fast inserter", "1"}},
	{"Flamethrower", {"Steel plate", "5", "Iron gear wheel", "10"}},
	{"Flamethrower ammo", {"Steel plate", "5", "Crude oil", "100"}},
	{"Lubricant", {"Heavy oil", "10"}},
	{"Power armor mk2", {"Processing unit", "60", "Electric engine unit", "40", "Low density structure", "30", "Speed module 2", "25", "Effectivity module 2", "25"}},
	{"Production science pack", {"Rail", "30", "Electric furnace", "1", "Productivity module", "1"}},
	{"Personal roboport", {"Steel plate", "20", "Battery", "45", "Iron gear wheel", "40", "Advanced circuit", "10"}},
	{"Personal roboport mk2", {"Processing unit", "100", "Low density structure", "20", "Personal roboport", "5"}},
	{"Rocket silo", {"Steel plate", "1000", "Processing unit", "200", "Electric engine unit", "200", "Pipe", "100", "Concrete", "1000"}},
	{"Advanced circuit", {"Plastic bar", "2", "Copper cable", "4", "Electronic circuit", "2"}},
	{"Destroyer capsule", {"Speed module", "1", "Distractor capsule", "4"}},
	{"Land mine", {"Steel plate", "1", "Explosives", "2"}},
	{"Nightvision", {"Steel plate", "10", "Advanced circuit", "5"}},
	{"Nuclear reactor", {"Copper plate", "500", "Steel plate", "500", "Advanced circuit", "500", "Concrete", "500"}},
	{"Heat pipe", {"Copper plate", "20", "Steel plate", "10"}},
	{"Heat exchanger", {"Copper plate", "100", "Steel plate", "10", "Pipe", "10"}},
	{"Steam turbine", {"Copper plate", "50", "Iron gear wheel", "50", "Pipe", "20"}},
	{"Plastic bar", {"Coal", "1", "Petroleum gas", "20"}},
	{"Stack inserter", {"Iron gear wheel", "15", "Electronic circuit", "15", "Advanced circuit", "1", "Fast inserter", "1"}},
	{"Utility science pack", {"Processing unit", "2", "Flying robot frame", "1", "Low density structure", "3"}},
	{"Centrifuge", {"Steel plate", "50", "Iron gear wheel", "100", "Advanced circuit", "100", "Concrete", "100"}},
	{"Lab", {"Iron gear wheel", "10", "Electronic circuit", "10", "Transport belt", "4"}},
	{"Processing unit", {"Electronic circuit", "20", "Advanced circuit", "2", "Sulfuric acid", "5"}},
	{"Stack filter inserter", {"Electronic circuit", "5", "Stack inserter", "1"}},
	{"Sulfur", {"Water", "30", "Petroleum gas", "30"}},
	{"Battery", {"Iron plate", "1", "Copper plate", "1", "Sulfuric acid", "20"}},
	{"Engine unit", {"Steel plate", "1", "Iron gear wheel", "1", "Pipe", "2"}},
	{"Electric engine unit", {"Electronic circuit", "2", "Engine unit", "1", "Lubricant", "15"}},
	{"Explosives", {"Coal", "1", "Sulfur", "1", "Water", "10"}},
	{"Uranium processing", {"Uranium ore", "10"}},
	{"Flying robot frame", {"Steel plate", "1", "Battery", "2", "Electronic circuit", "3", "Electric engine unit", "1"}},
	{"Satellite", {"Processing unit", "100", "Low density structure", "100", "Rocket fuel", "50", "Solar panel", "100", "Accumulator", "100", "Radar", "5"}},
	{"Rocket control unit", {"Processing unit", "1", "Speed module", "1"}},
	{"Low density structure", {"Copper plate", "20", "Steel plate", "2", "Plastic bar", "5"}},
	{"Rocket fuel", {"Solid fuel", "10", "Light oil", "10"}},
	{"Nuclear fuel", {"Rocket fuel", "1", "Uranium 235", "1"}},
	{"Uranium fuel cell", {"Iron plate", "10", "Uranium 235", "1", "Uranium 238", "19"}},
	{"Nuclear fuel reprocessing", {"Used up uranium fuel cell", "5"}},
	{"Kovarex enrichment process", {"Uranium 235", "40", "Uranium 238", "5"}}
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

static std::vector<std::string> handcrafted_list = {
	"Accumulator",
	"Wooden chest",
	"Iron chest",
	"Steel chest",
	"Storage tank",
	"Transport belt",
	"Fast transport belt",
	"Underground belt",
	"Fast underground belt",
	"Splitter",
	"Fast splitter",
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
	"Rail",
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
	"Spidertron remote",
	"Logistic robot",
	"Construction robot",
	"Active provider chest",
	"Passive provider chest",
	"Storage chest",
	"Buffer chest",
	"Requester chest",
	"Roboport",
	"Lamp",
	"Red wire",
	"Green wire",
	"Arithmetic combinator",
	"Decider combinator",
	"Constant combinator",
	"Power switch",
	"Programmable speaker",
	"Hazard concrete",
	"Refined hazard concrete",
	"Landfill",
	"Cliff explosives",
	"Pistol",
	"Submachine gun",
	"Shotgun",
	"Combat shotgun",
	"Rocket launcher",
	"Flamethrower",
	"Land mine",
	"Firearm magazine",
	"Piercing rounds magazine",
	"Uranium rounds magazine",
	"Shotgun shells",
	"Piercing shotgun shells",
	"Cannon shell",
	"Explosive cannon shell",
	"Uranium cannon shell",
	"Explosive uranium cannon shell",
	"Artillery shell",
	"Rocket",
	"Explosive rocket",
	"Atomic bomb",
	"Grenade",
	"Cluster grenade",
	"Poison capsule",
	"Slowdown capsule",
	"Defender capsule",
	"Distractor capsule",
	"Destroyer capsule",
	"Discharge defense remote",
	"Artillery targeting remote",
	"Light armor",
	"Heavy armor",
	"Modular armor",
	"Power armor",
	"Power armor MK2",
	"Portable solar panel",
	"Portable fusion reactor",
	"Energy shield",
	"Energy shield MK2",
	"Personal battery",
	"Personal battery MK2",
	"Personal laser defense",
	"Discharge defense",
	"Belt immunity equipment",
	"Exoskeleton",
	"Personal roboport",
	"Personal roboport MK2",
	"Nightvision",
	"Wall",
	"Gate",
	"Gun turret",
	"Laser turret",
	"Flamethrower turret",
	"Artillery turret",
	"Radar",
	"Rocket silo",
	"Repair pack",
	"Boiler",
	"Steam engine",
	"Steam turbine",
	"Solar panel",
	"Nuclear reactor",
	"Heat exchanger",
	"Heat pipe",
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
	"Speed module",
	"Speed module 2",
	"Speed module 3",
	"Efficiency module",
	"Efficiency module 2",
	"Efficiency module 3",
	"Productivity module",
	"Productivity module 2",
	"Productivity module 3",
	"Copper cable",
	"Iron stick",
	"Iron gear wheel",
	"Empty barrel",
	"Electronic circuit",
	"Advanced circuit",
	"Flying robot frame",
	"Satellite",
	"Rocket control unit",
	"Low density structure",
	"Uranium fuel cell",
	"Automation science pack",
	"Logistic science pack",
	"Military science pack",
	"Chemical science pack",
	"Production science pack",
	"Utility science pack",
	"Space science pack"};

static const std::vector<std::string> science_packs = {
	"Automation science pack",
	"Logistic science pack",
	"Military science pack",
	"Chemical science pack",
	"Production science pack",
	"Utility science pack",
	"Space science pack"
};

static const std::vector<std::string> furnace_list = {
	"Iron plate",
	"Copper plate",
	"Steel plate",
	"Stone brick"
};

static const std::vector<std::string> assemply_level1_list =
{
	"Engine unit"
};

static const std::vector<std::string> assemply_level2_list =
{
	"Express transport belt",
	"Express underground belt",
	"Express splitter",
	"Concrete",
	"Refined concrete",
	"Processing unit",
	"Electric engine unit",
	"Rocket fuel",
	"Fill crude oil barrel",
	"Fill heavy oil barrel",
	"Fill light oil barrel",
	"Fill lubricant barrel",
	"Fill petroleum gas barrel",
	"Fill sulfuric acid barrel",
	"Fill water barrel"
};

static const std::vector<std::string> assemply_level2_extra_list =
{
	"None",
	"Empty crude oil barrel",
	"Empty heavy oil barrel",
	"Empty light oil barrel",
	"Empty lubricant barrel",
	"Empty petroleum gas barrel",
	"Empty sulfuric acid barrel",
	"Empty water barrel"
};

static const std::vector<std::string> chemical_plant_list =
{
	"Flamethrower ammo",
	"Solid fuel from light oil",
	"Solid fuel from petroleum gas",
	"Solid fuel from heavy oil",
	"Plastic bar",
	"Sulfur",
	"Battery",
	"Explosives"
};

static const std::vector<std::string> chemical_plant_extra_list =
{
	"None",
	"Sulfuric acid",
	"Lubricant",
	"Heavy oil cracking",
	"Light oil cracking"
};

static const std::vector<std::string> centrifuge_list =
{
	"Nuclear fuel",
	"Uranium processing",
	"Nuclear fuel reprocessing",
	"Kovarex enrichment process"
};

static const std::vector<std::string> oil_refinery_list = 
{
	"None",
	"Basic oil processing",
	"Advanced oil processing",
	"Coal liquefaction"
};

static const std::vector<std::string> rocket_silo_list = 
{
	"Rocket part"
};


static const std::vector<std::string> raw_resource_list = 
{
	"Wood",
	"Coal",
	"Stone",
	"Iron ore",
	"Copper ore",
	"Uranium ore",
	"Raw fish"
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
