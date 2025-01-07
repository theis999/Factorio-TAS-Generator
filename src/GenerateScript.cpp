#pragma once

#include "GenerateScript.h"
#include <iostream>
#include <chrono>
#include <ctime>

#include "TAS save file/TasFileConstants.h"
#include "Item.h"

GenerateScript::GenerateScript(wxGrid* grid_steps) : grid_steps(grid_steps)
{
	reset();
}

void GenerateScript::reset()
{
	warning_state_counters = WarningsStatesCounters();
	ClearSteps();
}

// Get current date/time, format is yyyy-mm-dd hh:mm:ss
const std::string GenerateScript::currentDateTime()
{
	try
	{
		using namespace std::chrono;
		auto local = zoned_time{current_zone(), system_clock::now()};
		return std::format("{:%Y-%m-%d %H:%M:%S}", local).substr(0, 19);
	}
	catch (...) { return "0000-00-00 00:00:00"; }
}

void GenerateScript::ClearSteps()
{
	const string endl = "\n";

	total_steps = 1;
	step_list = "";
	std::stringstream ss (step_list);
	ss << "local step = {}" << endl
		<< endl;
	step_list = ss.str();
}

string GenerateScript::EndSteps()
{
	string last_step = "step[" + std::to_string(total_steps) + "] = {\"break\"}\n\n";
	const string return_line = "return step\n";
	return step_list + last_step + return_line;
}

void GenerateScript::UnexpectedError(DialogProgressBar* dialog_progress_bar, int i)
{
	wxMessageBox("Unexpected error on step "+std::to_string(i+1)+"\nPlease make an issue at our repository on github with step by step of what happened.\nhttps://github.com/MortenTobiasNielsen/Factorio-TAS-Generator", "Unexpected error");
	dialog_progress_bar->Close();
}

inline const char* const bool_to_string(bool b)
{
	return b ? "true" : "false";
}

void GenerateScript::AddVariableFile(string& folder_location, string& goal, log_config logconfig)
{
	using std::endl;
	std::ofstream saver;

	saver.open(folder_location + "\\variables.lua");

	saver << "--[[ GENERATED FILE - do not modify this file as it is controlled from the FTG GUI ]]" << endl << endl;
	
	saver << "GOAL" << " = \"" << goal << "\"" << endl;
	saver << "LOGLEVEL" << " = " << std::to_string(logconfig.level) << endl;
	saver << "PRINT_SAVEGAME" << " = " << bool_to_string(logconfig.savegame) << endl;
	saver << "PRINT_TECH" << " = " << bool_to_string(logconfig.tech) << endl;
	saver << "PRINT_COMMENT" << " = " << bool_to_string(logconfig.comment) << endl << endl;

	saver << "local tas_generator = {" << endl;
	saver << "\t" << "name = \"" << generator_thumbprint.name << "\"," << endl;
	saver << "\t" << "version = \"" << generator_thumbprint.version << "\"," << endl;
	saver << "\t" << "tas = {" << endl;
	saver << "\t" << "\t" << "name = \"" << name << "\"," << endl;
	saver << "\t" << "\t" << "timestamp = \"" << currentDateTime() << "\"," << endl;
	saver << "\t" << "}," << endl;
	saver << "}" << endl << endl;

	saver << "return tas_generator" << endl;

	saver.close();
}

void GenerateScript::AddInfoFile(string& folder_location)
{
	std::ofstream saver;

	saver.open(folder_location + "\\info.json");

	saver << "{";
	saver << "\n\t\"name\": \"" << folder_location.substr(folder_location.rfind("\\") + 1) << "\",";
	saver << "\n\t\"version\": \"" << generator_thumbprint.version << "\",";
	saver << "\n\t\"title\": \"" << folder_location.substr(folder_location.rfind("\\") + 1) << "\",";
	saver << "\n\t\"author\": \"" << "Theis" << "\",";
	saver << "\n\t\"factorio_version\": \"" << "2.0" << "\",";
	saver << "\n\t\"contact\": \"" << "https://github.com/theis999/Factorio-TAS-Generator/issues" << "\",";
	saver << "\n\t\"description\": \"" << "This run has been made with the help of Factorio TAS Generator" << "\"";
	saver << "\n}";

	saver.close();
}

void GenerateScript::PaintWarningStateChanged(string step, int counter)
{
	int row = std::stoi(step) - 1;
	grid_steps->SetCellBackgroundColour(row, 10, counter % 2 ? *wxRED : *wxGREEN);
}

void GenerateScript::PaintWalkStep(string step, bool straight, bool diagonal)
{
	int row = std::stoi(step) - 1;
	grid_steps->SetCellBackgroundColour(row, 10, straight ? "#AFBFBF" : diagonal ? "#BF9FBF" : "#FFFFFF");
}

void GenerateScript::generate(wxWindow* parent, DialogProgressBar* dialog_progress_bar, vector<Step> steps, string& folder_location, string goal, log_config logconfig)
{
	this->name = folder_location.substr(folder_location.find_last_of('\\') + 1);
	reset();

	if (folder_location == "")
	{
		wxDirDialog dlg(NULL, "Choose location to generate script", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

		if (dlg.ShowModal() == wxID_OK)
			folder_location = dlg.GetPath().ToStdString();
		else
			return;
	}

	if (!dialog_progress_bar)
	{
		dialog_progress_bar = new DialogProgressBar(parent, wxID_ANY, "Processing request");
	}

	dialog_progress_bar->set_text("Generating Script");
	dialog_progress_bar->set_button_enable(false);
	dialog_progress_bar->set_progress(0);
	dialog_progress_bar->Show();

	const size_t amountOfSteps = steps.size();

	string currentStepNumber = "";
	for (int i = 0; i < amountOfSteps; i++)
	{
		currentStepNumber = std::to_string(i + 1);
		Step currentStep = steps[i];

		if (i > 0 && i % 25 == 0)
		{
			dialog_progress_bar->set_progress(static_cast<float>(i) / static_cast<float>(amountOfSteps) * 100.0f - 1);
			wxYield();
		}

		if (steps[i].type == e_stop)
		{
			break;
		}

		TransferParameters(steps[i]);
		if (modifiers.skip) continue;
		switch (steps[i].type)
		{
			case e_game_speed:
				speed(currentStepNumber, amount, comment);
				break;

			case e_walk:
				walk(currentStepNumber, x_cord, y_cord, comment);
				break;

			case e_mine:
				if (amount == "All")
				{
					amount = "1000";
				}

				if (steps[i].BuildingIndex.has_value() == false)
				{
					mining(currentStepNumber, x_cord, y_cord, amount, "", "", false, comment);
					break;
				}

				SetBuildingAndOrientation(&steps[i]);

				mining(currentStepNumber, x_cord, y_cord, amount, building, build_orientation, true, comment);

				break;

			case e_rotate:
				if (steps[i].BuildingIndex.has_value() == false)
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				SetBuildingAndOrientation(&steps[i]);
				if (building == "N/A")
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				rotate(currentStepNumber, x_cord, y_cord, amount, building, build_orientation, comment);
				break;

			case e_craft:
				craft(currentStepNumber, amount == "All" ? "-1" : amount, item, comment);
				break;

			case e_cancel_crafting:
				cancel_crafting(currentStepNumber, amount == "All" ? "-1" : amount, item, comment);
				break;

			case e_tech:
				tech(currentStepNumber, item, comment);
				break;

			case e_build:
				build(currentStepNumber, x_cord, y_cord, item, build_orientation, comment);
				break;

			case e_take:
				SetBuildingAndOrientation(&steps[i]);

				from_into = GetInventoryTypeForEntity(steps[i].inventory, building);

				if (from_into == "Not Found")
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				take(currentStepNumber, x_cord, y_cord, amount == "All" ? "-1" : amount, item, from_into, building, build_orientation, comment);
				break;

			case e_put:
				SetBuildingAndOrientation(&steps[i]);

				from_into = GetInventoryTypeForEntity(steps[i].inventory, building);

				if (from_into == "Not Found")
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				put(currentStepNumber, x_cord, y_cord, amount == "All" ? "-1" : amount, item, from_into, building, build_orientation, comment);
				break;

			case e_recipe:
				if (steps[i].BuildingIndex.has_value() == false)
				{
					return;
				}

				SetBuildingAndOrientation(&steps[i]);

				recipe(currentStepNumber, x_cord, y_cord, item, building, build_orientation, comment);
				break;

			case e_pause:
				pause(currentStepNumber, comment);
				break;

			case e_limit:
				SetBuildingAndOrientation(&steps[i]);

				from_into = GetInventoryTypeForEntity(steps[i].inventory, building);

				if (from_into == "Not Found")
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				limit(currentStepNumber, x_cord, y_cord, amount, from_into, building, build_orientation, comment);
				break;

			case e_priority:
				if (steps[i].BuildingIndex.has_value() == false)
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				SetBuildingAndOrientation(&steps[i]);

				priority(currentStepNumber, x_cord, y_cord, steps[i].priority, building, build_orientation, comment);
				break;

			case e_filter:
				if (steps[i].BuildingIndex.has_value() == false)
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				SetBuildingAndOrientation(&steps[i]);

				filter(currentStepNumber, x_cord, y_cord, item, amount, check_input(building, splitter_list) ? "splitter" : "inserter", building, build_orientation, comment);
				break;

			case e_drop:
				building = "Item on ground";
				build_orientation = orientation_list[0];

				drop(currentStepNumber, x_cord, y_cord, item, building, comment);
				break;

			case e_pick_up:
				pick(currentStepNumber, amount, comment);
				break;

			case e_launch:
				launch(currentStepNumber, x_cord, y_cord, comment);
				break;

			case e_next:
				next(currentStepNumber, comment);
				break;

			case e_save:
				save(currentStepNumber, comment);
				break;

			case e_wait:
				wait(currentStepNumber, amount, comment);
				break;

			case e_never_idle:
				never_idle(currentStepNumber, comment);
				break;
			case e_keep_crafting:
				keep_crafting(currentStepNumber, comment);
				break;
			case e_keep_on_path:
				keep_on_path(currentStepNumber, comment);
				break;
			case e_keep_walking:
				keep_walking(currentStepNumber, comment);
				break;
			case e_shoot:
				shoot(currentStepNumber, x_cord, y_cord, amount, comment);
				break;
			case e_throw:
				_throw(currentStepNumber, x_cord, y_cord, item, comment);
				break;
			case e_equip:
				equip(currentStepNumber, amount, item, steps[i].inventory, comment);
				break;

			case e_enter:
				enter(currentStepNumber, comment);
				break;
			case e_drive:
				drive(currentStepNumber, amount, steps[i].riding, comment);
				break;
			case e_send:
				send(currentStepNumber, x_cord, y_cord, amount, comment);
				break;
		}
	}

	// If the file is send to another person the folder location won't exist and should be set to something else.
	namespace fs = std::filesystem;
	if (!fs::exists(folder_location))
	{
		wxDirDialog dlg(NULL, "Choose location to generate script", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

		if (dlg.ShowModal() == wxID_OK)
		{
			folder_location = dlg.GetPath().ToStdString();
		}
		else
		{
			return;
		}
	}

	//add locale directory
	fs::create_directories(folder_location + "\\locale\\en");

	bool exist = fs::exists("..\\Lua Files\\locale.cfg");
	string pre_fix = exist ? "..\\Lua Files\\" : "";

	fs::copy_file(pre_fix + "locale.cfg", folder_location + "\\locale\\en\\locale.cfg", fs::copy_options::update_existing);

	//copy lua files to tas mod if they are newer
	fs::copy_file(pre_fix + "control.lua", folder_location + "\\control.lua", fs::copy_options::update_existing);
	fs::copy_file(pre_fix + "settings.lua", folder_location + "\\settings.lua", fs::copy_options::update_existing);
	fs::copy_file(pre_fix + "goals.lua", folder_location + "\\goals.lua", fs::copy_options::update_existing);

	if (goal == scenario_supply_challenge_text)
	{
		fs::create_directories(folder_location + "\\scenarios\\supply");
		fs::create_directories(folder_location + "\\scenarios\\supply\\locale\\en");
		fs::copy_file(pre_fix + "scenarios\\supply\\blueprint.zip", folder_location + "\\scenarios\\supply\\blueprint.zip", fs::copy_options::update_existing);
		fs::copy_file(pre_fix + "scenarios\\supply\\control.lua", folder_location + "\\scenarios\\supply\\control.lua", fs::copy_options::update_existing);
		fs::copy_file(pre_fix + "scenarios\\supply\\description.json", folder_location + "\\scenarios\\supply\\description.json", fs::copy_options::update_existing);
		fs::copy_file(pre_fix + "scenarios\\supply\\image.png", folder_location + "\\scenarios\\supply\\image.png", fs::copy_options::update_existing);
		fs::copy_file(pre_fix + "scenarios\\supply\\locale\\en\\supply.cfg", folder_location + "\\scenarios\\supply\\locale\\en\\supply.cfg", fs::copy_options::update_existing);
	}

	AddVariableFile(folder_location, goal, logconfig);
	AddInfoFile(folder_location);

	std::ofstream saver;

	//generate step file
	saver.open(folder_location + "\\steps.lua");

	saver << EndSteps();

	saver.close();

	dialog_progress_bar->set_progress(100);
	dialog_progress_bar->Close();
}

void GenerateScript::SetBuildingAndOrientation(Step* step)
{
	if (step->inventory == Wreck)
	{
		building = inventory_types.wreck;
		return;
	}

	building = step->BuildingIndex.value().Name();
	build_orientation = orientation_list[step->orientation];
}

void GenerateScript::TransferParameters(Step& step)
{
	x_cord = to_string(step.X);
	y_cord = to_string(step.Y);
	amount = step.AmountLua();
	item = step.Item;
	build_orientation = orientation_list[step.orientation];
	comment = step.Comment;
	modifiers = {
		.no_order = step.Modifiers.no_order,
		.skip = step.Modifiers.skip,
		.wait_for = step.Modifiers.wait_for,
		.cancel_others = step.Modifiers.cancel_others,
		.split = step.Modifiers.split,
		.walk_towards = step.Modifiers.walk_towards,
		.all = step.Modifiers.all,
	};
}

string GenerateScript::convert_string(string input)
{
	std::for_each(input.begin(), input.end(), [](char& c)
 {
	 if (isspace(c))
	 {
		 c = '-';
	 }
	 c = ::tolower(c);
		});
	return input;
}

/// <summary>
/// Applies a translation to an item. Either the specific translation from map_translation or the common way
/// </summary>
string GenerateScript::check_item_name(string item)
{
	Item _item;
	if (Item::MapStringToItem(item, _item))
	{
		return Item::itemtype_to_luaname[_item.type];
	}
	else if (auto search = map_translation.find(item); search != map_translation.end())
	{
		return item = search->second;
	}
	else
	{
		return item = convert_string(item);
	}
}

string GenerateScript::signature(string step)
{
	return "step[" + std::to_string(total_steps) + "] = {{" + step + "}, ";
}

string GenerateScript::Comment(string comment)
{
	return comment == "" ? "" : ", comment = \"" + comment + "\"";
}

string GenerateScript::StepSignature(string step, string details, string comment = "")
{
	return signature(step) + details + Comment(comment) + modifiers.ToLua() + "}\n";
}

void GenerateScript::walk(string step, string x_cord, string y_cord, string comment)
{
	step_list += StepSignature(step, "\"walk\", {" + x_cord + ", " + y_cord + "}", comment);
	total_steps += 1;
}

void GenerateScript::mining(string step, string x_cord, string y_cord, string duration, string building_name, string OrientationEnum, bool is_building, string comment)
{ 
	step_list += StepSignature(step, "\"mine\", {" + x_cord + ", " + y_cord + "}, " + duration, comment);
	total_steps += 1;
}

void GenerateScript::craft(string step, string amount, string item, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "\"craft\", " + amount + ", \"" + item + "\"", comment);
	total_steps += 1;
};

void GenerateScript::cancel_crafting(string step, string amount, string item, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "\"cancel crafting\", " + amount + ", \"" + item + "\"", comment);
	total_steps += 1;
};

void GenerateScript::tech(string step, string tech_to_research, string comment)
{
	tech_to_research = convert_string(tech_to_research);

	if (auto search = map_translation_research.find(tech_to_research); search != map_translation_research.end())
	{
		tech_to_research = search->second;
	}

	step_list += StepSignature(step,"\"tech\", \"" + tech_to_research + "\"", comment);
	total_steps += 1;
}

void GenerateScript::speed(string step, string speed, string comment)
{
	step_list += StepSignature(step, "\"speed\", " + speed, comment);
	total_steps += 1;
}

void GenerateScript::pause(string step, string comment)
{
	step_list += StepSignature(step, "\"pause\"", comment);
	total_steps += 1;
}

void GenerateScript::never_idle(string step, string comment)
{
	PaintWarningStateChanged(step, warning_state_counters.never_idle++);
	step_list += StepSignature(step, "\"never idle\"", comment);
	total_steps += 1;
}

void GenerateScript::keep_walking(string step, string comment)
{
	PaintWarningStateChanged(step, warning_state_counters.keep_walking++);
	step_list += StepSignature(step, "\"keep walking\"", comment);
	total_steps += 1;
}

void GenerateScript::keep_on_path(string step, string comment) 
{
	PaintWarningStateChanged(step, warning_state_counters.keep_on_path++);
	step_list += StepSignature(step, "\"keep on path\"", comment);
	total_steps += 1;
}

void GenerateScript::keep_crafting(string step, string comment) 
{
	PaintWarningStateChanged(step, warning_state_counters.keep_crafting++);
	step_list += StepSignature(step, "\"keep crafting\"", comment);
	total_steps += 1;
}

void GenerateScript::launch(string step, string x_cord, string y_cord, string comment)
{
	step_list += StepSignature(step, "\"launch\", {" + x_cord + ", " + y_cord + "}", comment);
	total_steps += 1;
}

void GenerateScript::next(string step, string comment)
{
	step_list += StepSignature(step, "\"next\"", comment);
	total_steps += 1;
}

void GenerateScript::save(string step, string nameOfSaveGame)
{
	step_list += StepSignature(step, "\"save\", \"" + nameOfSaveGame + "\"");
	total_steps += 1;
}

void GenerateScript::wait(string step, string amount, string comment)
{
	step_list += StepSignature(step, "\"wait\", " + amount, comment);
	total_steps += 1;
}

void GenerateScript::pick(string step, string amount, string comment)
{
	step_list += StepSignature(step, "\"pick\", \"" + amount + "\"", comment);
	total_steps += 1;
}

void GenerateScript::shoot(string step, string x_cord, string y_cord, string amount, string comment)
{
	step_list += StepSignature(step, "\"shoot\", {" + x_cord + ", " + y_cord + "}, \"" + amount + "\"", comment);
	total_steps += 1;
}

void GenerateScript::_throw(string step, string x_cord, string y_cord, string item, string comment)
{
	step_list += StepSignature(step, "\"throw\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\"", comment);
	total_steps += 1;
}

void GenerateScript::equip(string step, string amount, string item, InventoryType inventory, string comment)
{
	step_list += StepSignature(step, "\"equip\", " + amount + ", \"" + check_item_name(item) + "\", \"" + inventory_types_list[inventory] + "\"", comment);
	total_steps += 1;
}

void GenerateScript::enter(string step, string comment)
{
	step_list += StepSignature(step, "\"enter\" ", comment);
	total_steps += 1;
}

void GenerateScript::drive(string step, string duration, Riding riding_state, string comment)
{
	step_list += StepSignature(step, "\"drive\", "+ duration +", " + riding_state.ToLua(), comment);
	total_steps += 1;
}

void GenerateScript::send(string step, string x_cord, string y_cord, string id, string comment)
{
	step_list += StepSignature(step, "\"send\", {" + x_cord + ", " + y_cord + "}," + id + ", ", comment);
	total_steps += 1;
}

void GenerateScript::rotate(string step, string x_cord, string y_cord, string times, string item, string OrientationEnum, string comment)
{
	if (std::stoi(times) == 3)
	{
		step_list += StepSignature(step, "\"rotate\", {" + x_cord + ", " + y_cord + "}, " + "true", comment);
		total_steps += 1;
	}
	else
	{
		step_list += StepSignature(step, "\"rotate\", {" + x_cord + ", " + y_cord + "}, " + "false", comment);
		total_steps += 1;
	}
}

void GenerateScript::build(string step, string x_cord, string y_cord, string item, string OrientationEnum, string comment)
{
	item = check_item_name(item);

	OrientationEnum = orientation_defines_list[MapStringToOrientation(OrientationEnum)];

	step_list += StepSignature(step, "\"build\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + OrientationEnum, comment);
	total_steps += 1;
};

void GenerateScript::take(string step, string x_cord, string y_cord, string amount, string item, string from, string building, string OrientationEnum, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "\"take\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + from, comment);
	total_steps += 1;
}

void GenerateScript::put(string step, string x_cord, string y_cord, string amount, string item, string into, string building, string OrientationEnum, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "\"put\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + into, comment);
	total_steps += 1;
}

void GenerateScript::recipe(string step, string x_cord, string y_cord, string item, string building, string OrientationEnum, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "\"recipe\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\"", comment);
	total_steps += 1;
}

void GenerateScript::limit(string step, string x_cord, string y_cord, string amount, string from, string building, string OrientationEnum, string comment)
{
	step_list += StepSignature(step, "\"limit\", {" + x_cord + ", " + y_cord + "}, " + amount + ", " + from, comment);
	total_steps += 1;
}

void GenerateScript::priority(string step, string x_cord, string y_cord, PriorityStruct _priority, string building, string OrientationEnum, string comment)
{
	priority_in = convert_string(Priority::Names[_priority.input]);
	priority_out = convert_string(Priority::Names[_priority.output]);
	step_list += StepSignature(step, "\"priority\", {" + x_cord + ", " + y_cord + "}, \"" + priority_in + "\", \"" + priority_out + "\"", comment);
	total_steps += 1;
}

void GenerateScript::filter(string step, string x_cord, string y_cord, string item, string amount, string type, string building, string OrientationEnum, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "\"filter\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ",  \"" + type + "\"", comment);
	total_steps += 1;
}

void GenerateScript::drop(string step, string x_cord, string y_cord, string item, string building, string comment)
{
	item = convert_string(item);

	step_list += StepSignature(step, "\"drop\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\"", comment);
	total_steps += 1;
}
