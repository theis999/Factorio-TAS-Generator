#pragma once

#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <map>

#include "Shared functions\Functions.h"

#include "Structures\Step.h"
#include "Structures\StepType.h"

#include "Data\Inventory.h"
#include "Data\utils.h"

#include "DialogProgressBar.h"

using std::string;
using std::vector;
using std::to_string;

class GenerateScript
{
public:
	GenerateScript(wxGrid* grid_steps);
	void generate(wxWindow* parent, DialogProgressBar* dialog_progress_bar, vector<Step> steps, string& folder_location, string goal, log_config logconfig);
	const std::string currentDateTime(); // Get current date/time, format is YYYY-MM-DD.HH:mm:ss

private:
	string name;

	wxGrid* grid_steps;
	string step_list;
	float target_x_cord;
	float target_y_cord;
	float x_building_size;
	float y_building_size;

	string current_step;
	int total_steps;

	string x_cord;
	string y_cord;
	string amount;
	string item;
	string build_orientation;
	string comment;
	string from_into;
	string priority_in;
	string priority_out;
	string building;

	StepModifiers modifiers;

	void reset();
	void ClearSteps();
	string EndSteps();
	void UnexpectedError(DialogProgressBar* dialog_progress_bar, int error_step);

	void AddVariableFile(string& folder_location, string& goal, log_config logconfig);
	void AddInfoFile(string& folder_location);

	void PaintWarningStateChanged(string step, int counter);

	/// <summary>Paints the step to indicate the walk is either diagonal, straight or neither</summary>
	/// <param name="step">The index of the step using a start of 1</param>
	void PaintWalkStep(string step, bool straight, bool diagonal);

	void SetBuildingAndOrientation(Step* step);
	void TransferParameters(Step& step);

	const map<string, string> map_translation{
		{"Passive provider chest", "logistic-chest-passive-provider"},
		{"Active provider chest", "logistic-chest-active-provider"},
		{"Storage chest", "logistic-chest-storage"},
		{"Buffer chest", "logistic-chest-buffer"},
		{"Requester chest", "logistic-chest-requester"},
		{"Wall", "stone-wall"},
		{"Discharge defense", "discharge-defense-equipment"},
		{"Exoskeleton", "exoskeleton-equipment"},
		{"Personal roboport", "personal-roboport-equipment"},
		{"Personal roboport MK2", "personal-roboport-mk2-equipment"},
		{"Night vision", "night-vision-equipment"},
		{"Personal battery", "battery-equipment"},
		{"Personal battery MK2", "battery-mk2-equipment"},
		{"Portable solar panel", "solar-panel-equipment"},
		{"Personal laser defence", "personal-laser-defence-equipment"},
		{"Energy shield", "energy-shield-equipment"},
		{"Energy shield MK2", "energy-shield-mk2-equipment"},
		{"Portable fusion reactor", "fusion-reactor-equipment"},
		{"Efficiency module", "effectivity-module"},
		{"Efficiency module 2", "effectivity-module-2"},
		{"Efficiency module 3", "effectivity-module-3"}
	};


	const map<string, string> map_translation_research{
		{"efficiency-module", "effectivity-module"},
		{"efficiency-module-2", "effectivity-module-2"},
		{"efficiency-module-3", "effectivity-module-3"},
		{"lab-research-speed-1", "research-speed-1"},
		{"lab-research-speed-2", "research-speed-2"},
		{"lab-research-speed-3", "research-speed-3"},
		{"lab-research-speed-4", "research-speed-4"},
		{"lab-research-speed-5", "research-speed-5"},
		{"lab-research-speed-6", "research-speed-6"},
		{"worker-robot-cargo-size-1", "worker-robots-storage-1"},
		{"worker-robot-cargo-size-2", "worker-robots-storage-2"},
		{"worker-robot-cargo-size-3", "worker-robots-storage-3"},
		{"worker-robot-speed-1", "worker-robots-speed-1"},
		{"worker-robot-speed-2", "worker-robots-speed-2"},
		{"worker-robot-speed-3", "worker-robots-speed-3"},
		{"worker-robot-speed-4", "worker-robots-speed-4"},
		{"worker-robot-speed-5", "worker-robots-speed-5"},
		{"worker-robot-speed-6", "worker-robots-speed-6"},
		{"portable-solar-panel", "solar-panel-equipment"},
		{"land-mines", "land-mine"},
		{"nightvision-equipment", "night-vision-equipment"},
		{"personal-battery", "battery equipment"},
		{"personal-MK2-battery", "battery mk2 equipment"},
	};

	string convert_string(string input);
	string check_item_name(string item);

	string signature(string step);
	string Comment(string comment);
	string StepSignature(string step, string details, string comment);
	WarningsStatesCounters warning_state_counters;

	void walk(string step, string x_cord, string y_cord, string comment);
	void mining(string step, string x_cord, string y_cord, string duration, string building_name, string OrientationEnum, bool is_building, string comment);
	void craft(string step, string amount, string item, string comment);
	void cancel_crafting(string step, string amount, string item, string comment);
	void tech(string step, string tech_to_research, string comment);
	void speed(string step, string speed, string comment);
	void pause(string step, string comment);
	void never_idle(string step, string comment);
	void keep_walking(string step, string comment);
	void keep_on_path(string step, string comment);
	void keep_crafting(string step, string comment);
	void launch(string step, string x_cord, string y_cord, string comment);
	void next(string step, string comment);
	void save(string step, string nameOfSaveGame);
	void wait(string step, string amount, string comment);
	void pick(string step, string amount, string comment);

	void shoot(string step, string x_cord, string y_cord, string amount, string comment);
	void _throw(string step, string x_cord, string y_cord, string item, string comment);
	void equip(string step, string amount, string item, InventoryType inventory, string comment);

	void enter(string step, string comment);
	void drive(string step, string duration, Riding riding_state, string comment);
	void send(string step, string x_cord, string y_cord, string id, string comment);

	void rotate(string step, string x_cord, string y_cord, string times, string item, string OrientationEnum, string comment = "");
	void build(string step, string x_cord, string y_cord, string item, string OrientationEnum, string comment = "");
	void take(string step, string x_cord, string y_cord, string amount, string item, string from, string building, string OrientationEnum, string comment = "");
	void put(string step, string x_cord, string y_cord, string amount, string item, string into, string building, string OrientationEnum, string comment = "");
	void recipe(string step, string x_cord, string y_cord, string item, string building, string OrientationEnum, string comment = "");
	void limit(string step, string x_cord, string y_cord, string amount, string from, string building, string OrientationEnum, string comment = "");
	void priority(string step, string x_cord, string y_cord, PriorityStruct _priority, string building, string OrientationEnum, string comment = "");
	void filter(string step, string x_cord, string y_cord, string item, string amount, string type, string building, string OrientationEnum, string comment = "");
	void drop(string step, string x_cord, string y_cord, string item, string building, string comment = "");
};
