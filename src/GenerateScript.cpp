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
	player_x_cord = 0.0f;
	player_y_cord = 0.0f;
	target_x_cord = 0.0f;
	target_y_cord = 0.0f;
	x_building_size = 0.0f;
	y_building_size = 0.0f;
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
	saver << "\n\t\"author\": \"" << "DunRaider" << "\",";
	saver << "\n\t\"factorio_version\": \"" << "1.1" << "\",";
	saver << "\n\t\"contact\": \"" << "" << "\",";
	saver << "\n\t\"description\": \"" << "This run has been made with the help of Factorio TAS Generator" << "\"";
	saver << "\n}";

	saver.close();
}

void GenerateScript::PaintWarningStateChanged(string step, int counter)
{
	int row = std::stoi(step) - 1;
	grid_steps->SetCellBackgroundColour(row, 10, counter % 2 ? *wxRED : *wxGREEN);
}

void GenerateScript::PaintIntermediateWalk(string step, bool paint)
{
	int row = std::stoi(step) - 1;
	grid_steps->SetCellBackgroundColour(row, 10, paint ? *wxCYAN : *wxWHITE);
}

void GenerateScript::PaintWalkStep(string step, bool straight, bool diagonal)
{
	int row = std::stoi(step) - 1;
	grid_steps->SetCellBackgroundColour(row, 10, straight ? "#AFBFBF" : diagonal ? "#BF9FBF" : "#FFFFFF");
}

void GenerateScript::generate(wxWindow* parent, DialogProgressBar* dialog_progress_bar, vector<Step> steps, string& folder_location, bool auto_close, string goal, log_config logconfig)
{
	this->name = folder_location.substr(folder_location.find_last_of('\\') + 1);
	reset();

	if (folder_location == "")
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

	if (!dialog_progress_bar)
	{
		dialog_progress_bar = new DialogProgressBar(parent, wxID_ANY, "Processing request");
	}

	dialog_progress_bar->set_text("Generating Script");
	dialog_progress_bar->set_button_enable(false);
	dialog_progress_bar->set_progress(0);
	dialog_progress_bar->Show();

	const size_t amountOfSteps = steps.size();

	string currentStep = "";
	for (int i = 0; i < amountOfSteps; i++)
	{
		currentStep = std::to_string(i + 1);

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
				speed(currentStep, amount, comment);
				break;

			case e_walk:
				walk(currentStep, "1", x_cord, y_cord, comment);
				break;

			case e_mine:
				if (amount == "All")
				{
					amount = "1000";
				}

				if (steps[i].BuildingIndex.has_value() == false)
				{
					mining(currentStep, x_cord, y_cord, amount, "", "", false, comment);
					break;
				}

				SetBuildingAndOrientation(&steps[i]);

				mining(currentStep, x_cord, y_cord, amount, building, build_orientation, true, comment);

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

				row_rotate(currentStep, x_cord, y_cord, amount, building, build_orientation, direction_to_build, amount_of_buildings, building_size, comment);
				break;

			case e_craft:
				craft(currentStep, amount == "All" ? "-1" : amount, item, comment);
				break;

			case e_cancel_crafting:
				cancel_crafting(currentStep, amount == "All" ? "-1" : amount, item, comment);
				break;

			case e_tech:
				tech(currentStep, item, comment);
				break;

			case e_build:
				row_build(currentStep, x_cord, y_cord, item, build_orientation, direction_to_build, amount_of_buildings, building_size, comment);
				break;

			case e_take:
				SetBuildingAndOrientation(&steps[i]);

				from_into = GetInventoryTypeForEntity(steps[i].inventory, building);

				if (from_into == "Not Found")
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				row_take(currentStep, x_cord, y_cord, amount == "All" ? "-1" : amount, item, from_into, direction_to_build, amount_of_buildings, building_size, building, build_orientation, comment);
				break;

			case e_put:
				SetBuildingAndOrientation(&steps[i]);

				from_into = GetInventoryTypeForEntity(steps[i].inventory, building);

				if (from_into == "Not Found")
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				row_put(currentStep, x_cord, y_cord, amount == "All" ? "-1" : amount, item, from_into, direction_to_build, amount_of_buildings, building_size, building, build_orientation, comment);
				break;

			case e_recipe:
				if (steps[i].BuildingIndex.has_value() == false)
				{
					return;
				}

				SetBuildingAndOrientation(&steps[i]);

				row_recipe(currentStep, x_cord, y_cord, item, direction_to_build, building_size, amount_of_buildings, building, build_orientation, comment);
				break;

			case e_pause:
				pause(currentStep, comment);
				break;

			case e_limit:
				SetBuildingAndOrientation(&steps[i]);

				from_into = GetInventoryTypeForEntity(steps[i].inventory, building);

				if (from_into == "Not Found")
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				row_limit(currentStep, x_cord, y_cord, amount, from_into, direction_to_build, amount_of_buildings, building_size, building, build_orientation, comment);
				break;

			case e_priority:
				if (steps[i].BuildingIndex.has_value() == false)
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				SetBuildingAndOrientation(&steps[i]);

				row_priority(currentStep, x_cord, y_cord, steps[i].priority, direction_to_build, amount_of_buildings, building_size, building, build_orientation, comment);
				break;

			case e_filter:
				if (steps[i].BuildingIndex.has_value() == false && steps[i].Modifiers.vehicle == false)
				{
					UnexpectedError(dialog_progress_bar, i);
					return;
				}

				SetBuildingAndOrientation(&steps[i]);

				row_filter(currentStep, x_cord, y_cord, item, amount, check_input(building, splitter_list) ? "splitter" : "inserter", direction_to_build, amount_of_buildings, building_size, building, build_orientation, comment);
				break;

			case e_drop:
				building = "Item on ground";
				build_orientation = orientation_list[0];

				drop(currentStep, "1", x_cord, y_cord, item, building, comment);
				break;

			case e_pick_up:
				if (comment.find("COMP:") != string::npos)
				{
					comment.erase(0, 5);
					vector<string> parameters = {};

					size_t pos = 0;
					while ((pos = comment.find(':')) != std::string::npos)
					{
						parameters.push_back(comment.substr(0, pos));
						comment.erase(0, pos + 1);
					}

					row_pick_compatibility(currentStep, parameters[0], parameters[1], parameters[2], parameters[3], parameters[4]);

					break;
				}

				pick(currentStep, amount, comment);
				break;

			case e_launch:
				launch(currentStep, x_cord, y_cord, comment);
				break;

			case e_next:
				next(currentStep, comment);
				break;

			case e_save:
				save(currentStep, comment);
				break;

			case e_idle:
				idle(currentStep, amount, comment);
				break;

			case e_never_idle:
				never_idle(currentStep, comment);
				break;
			case e_keep_crafting:
				keep_crafting(currentStep, comment);
				break;
			case e_keep_on_path:
				keep_on_path(currentStep, comment);
				break;
			case e_keep_walking:
				keep_walking(currentStep, comment);
				break;
			case e_shoot:
				shoot(currentStep, x_cord, y_cord, amount, comment);
				break;
			case e_throw:
				_throw(currentStep, x_cord, y_cord, item, comment);
				break;
			case e_equip:
				equip(currentStep, amount, item, steps[i].inventory, comment);
				break;

			case e_enter:
				enter(currentStep, comment);
				break;
			case e_drive:
				drive(currentStep, amount, steps[i].riding, comment);
				break;
			case e_send:
				send(currentStep, x_cord, y_cord, amount, comment);
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
	if (auto_close)
	{
		dialog_progress_bar->Close();
	}
	else
	{
		dialog_progress_bar->set_button_enable(true);
	}
}

void GenerateScript::SetBuildingAndOrientation(Step* step)
{
	if (step->inventory == Wreck)
	{
		building = inventory_types.wreck;
		return;
	}
	else if (step->Modifiers.vehicle)
	{
		building = "vehicle";
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
	direction_to_build = orientation_list[step.Direction];
	building_size = to_string(step.Size);
	amount_of_buildings = to_string(step.Buildings);
	comment = step.Comment;
	modifiers = {
		.no_order = step.Modifiers.no_order,
		.skip = step.Modifiers.skip,
		.wait_for = step.Modifiers.wait_for,
		.force = step.Modifiers.force,
		.cancel_others = step.Modifiers.cancel_others,
		.split = step.Modifiers.split,
		.walk_towards = step.Modifiers.walk_towards,
		.all = step.Modifiers.all,
		.vehicle = step.Modifiers.vehicle,
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

void GenerateScript::check_mining_distance(string step, string action, string x_cord, string y_cord)
{
	std::vector<float> coordinates;

	if (last_walking_comment == "old")
	{
		static const float buffer = 0.50f;
		static const float max_distance = 2.7f;

		float min_x_edge = std::stof(x_cord) - 0.5f;
		float max_x_edge = std::stof(x_cord) + 0.5f;
		float min_y_edge = std::stof(y_cord) - 0.5f;
		float max_y_edge = std::stof(y_cord) + 0.5f;

		coordinates = find_walk_location(min_x_edge, max_x_edge, min_y_edge, max_y_edge, buffer, max_distance);
	}
	else
	{
		static const float buffer = 0.15f;
		static const float max_distance = 3.0f;

		float min_x_edge = std::stof(x_cord);
		float max_x_edge = std::stof(x_cord);
		float min_y_edge = std::stof(y_cord);
		float max_y_edge = std::stof(y_cord);

		coordinates = find_walk_location(min_x_edge, max_x_edge, min_y_edge, max_y_edge, buffer, max_distance);
	}

	if (!(modifiers.force || modifiers.vehicle) && (player_x_cord != coordinates[0] || player_y_cord != coordinates[1]))
	{
		walk(step, action, std::to_string(coordinates[0]), std::to_string(coordinates[1]), last_walking_comment);
		PaintIntermediateWalk(step);
		modifiers.walk_towards = false;
	}
	else
	{
		PaintIntermediateWalk(step, false);
	}
}

void GenerateScript::check_interact_distance(string step, string action, string x_cord, string y_cord, string building_name, string OrientationEnum)
{
	float buffer = 0.06f;

	//if comment is "old" then use old map and buffer = 0.37 until a comment of new
	if (last_walking_comment == "old")
	{
		x_building_size = old_building_size_list.find(building_name)->second[0];
		y_building_size = old_building_size_list.find(building_name)->second[1];

		buffer = 0.37f;
	}
	else
	{
		x_building_size = building_size_list.find(building_name)->second[0];
		y_building_size = building_size_list.find(building_name)->second[1];
	}

	static const float max_distance = 10.0f; //Default build distance

	float x_target = std::stof(x_cord);
	float y_target = std::stof(y_cord);

	float min_x_edge = x_target;
	float max_x_edge = x_target;
	float min_y_edge = y_target;
	float max_y_edge = y_target;

	if (OrientationEnum == "North" || OrientationEnum == "South")
	{
		min_x_edge -= (x_building_size / 2);
		max_x_edge += (x_building_size / 2);
		min_y_edge -= (y_building_size / 2);
		max_y_edge += (y_building_size / 2);
	}
	else
	{
		min_x_edge -= (y_building_size / 2);
		max_x_edge += (y_building_size / 2);
		min_y_edge -= (x_building_size / 2);
		max_y_edge += (x_building_size / 2);
	}

	std::vector<float> coordinates = find_walk_location(min_x_edge, max_x_edge, min_y_edge, max_y_edge, buffer, max_distance);

	if (!(modifiers.force || modifiers.vehicle) && (player_x_cord != coordinates[0] || player_y_cord != coordinates[1]))
	{
		walk(step, action, std::to_string(coordinates[0]), std::to_string(coordinates[1]), last_walking_comment);
		PaintIntermediateWalk(step);
		modifiers.walk_towards = false;
	}
	else
	{
		PaintIntermediateWalk(step, false);
	}
}

double GenerateScript::find_min_distance(float& new_x_cord, float& new_y_cord)
{
	return std::pow(std::pow(std::abs(target_x_cord - new_x_cord), 2) + std::pow(std::abs(target_y_cord - new_y_cord), 2), 0.5);
}

std::vector<float> GenerateScript::find_walk_location(float& min_x_edge, float& max_x_edge, float& min_y_edge, float& max_y_edge, const float& buffer, const float& max_distance)
{

	static const float delta_distance = 0.01f;
	static const float not_to_close = 0.15f;

	float new_x_cord = player_x_cord;
	float new_y_cord = player_y_cord;

	if (new_x_cord < min_x_edge - not_to_close)
	{
		if (new_y_cord < min_y_edge - not_to_close)
		{
			// Top left
			target_x_cord = min_x_edge + buffer;
			target_y_cord = min_y_edge + buffer;

			while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
			{
				if (new_x_cord < min_x_edge - not_to_close && new_y_cord < min_y_edge - not_to_close)
				{
					new_x_cord += delta_distance;
					new_y_cord += delta_distance;
				}
				else if (new_x_cord < min_x_edge - not_to_close)
				{
					new_x_cord += delta_distance;
				}
				else
				{
					new_y_cord += delta_distance;
				}
			}
		}
		else if (new_y_cord > max_y_edge + not_to_close)
		{
			// bottom left
			target_x_cord = min_x_edge + buffer;
			target_y_cord = max_y_edge - buffer;

			while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
			{
				if (new_x_cord < min_x_edge - not_to_close && new_y_cord > max_y_edge + not_to_close)
				{
					new_x_cord += delta_distance;
					new_y_cord -= delta_distance;
				}
				else if (new_x_cord < min_x_edge - not_to_close)
				{
					new_x_cord += delta_distance;
				}
				else
				{
					new_y_cord -= delta_distance;
				}
			}
		}
		else
		{
			// Mid left
			target_x_cord = min_x_edge + buffer;
			target_y_cord = new_y_cord;

			while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
			{
				new_x_cord += delta_distance;
			}
		}
	}
	else if (new_x_cord > max_x_edge + not_to_close)
	{
		if (new_y_cord < min_y_edge - not_to_close)
		{
			// Top right
			target_x_cord = max_x_edge - buffer;
			target_y_cord = min_y_edge + buffer;

			while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
			{
				if (new_x_cord > max_x_edge + not_to_close && new_y_cord < min_y_edge - not_to_close)
				{
					new_x_cord -= delta_distance;
					new_y_cord += delta_distance;
				}
				else if (new_x_cord > max_x_edge + not_to_close)
				{
					new_x_cord -= delta_distance;
				}
				else
				{
					new_y_cord += delta_distance;
				}
			}
		}
		else if (new_y_cord > max_y_edge + not_to_close)
		{
			// bottom right
			target_x_cord = max_x_edge - buffer;
			target_y_cord = max_y_edge - buffer;

			while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
			{
				if (new_x_cord > max_x_edge + not_to_close && new_y_cord > max_y_edge + not_to_close)
				{
					new_x_cord -= delta_distance;
					new_y_cord -= delta_distance;
				}
				else if (new_x_cord > max_x_edge + not_to_close)
				{
					new_x_cord -= delta_distance;
				}
				else
				{
					new_y_cord -= delta_distance;
				}
			}
		}
		else
		{
			// Mid right
			target_x_cord = max_x_edge - buffer;
			target_y_cord = new_y_cord;

			while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
			{
				new_x_cord -= delta_distance;
			}
		}
	}
	else if (new_y_cord < min_y_edge - not_to_close)
	{
		// Mid top
		target_x_cord = new_x_cord;
		target_y_cord = min_y_edge + buffer;

		while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
		{
			new_y_cord += delta_distance;
		}
	}
	else if (new_y_cord > max_y_edge + not_to_close)
	{
		// Mid bottom
		target_x_cord = new_x_cord;
		target_y_cord = max_y_edge - buffer;

		while (find_min_distance(new_x_cord, new_y_cord) > max_distance)
		{
			new_y_cord -= delta_distance;
		}
	}

	return {new_x_cord, new_y_cord};
}

string GenerateScript::signature(string step, string action)
{
	return "step[" + std::to_string(total_steps) + "] = {{" + step + "," + action + "}, ";
}

string GenerateScript::Comment(string comment)
{
	return comment == "" ? "" : ", comment = \"" + comment + "\"";
}

string GenerateScript::StepSignature(string step, string action, string details, string comment = "")
{
	return signature(step, action) + details + Comment(comment) + modifiers.ToLua() + "}\n";
}

void GenerateScript::walk(string step, string action, string x_cord, string y_cord, string comment)
{
	if (comment == "old" || comment == "Old")
	{
		last_walking_comment = convert_string(comment);
	}
	else if (comment == "new" || comment == "New")
	{
		last_walking_comment = "";
	}
	else if (comment == "Never Stop" || comment == "Use All Ticks")
	{
		// Do nothing.
	}
	else if (comment != "")
	{
		last_walking_comment = comment;
	}

	string stateOfX = "different_x";
	string stateOfY = "different_y";
	bool sameXorY = false;
	bool diagonal = false;

	if (player_x_cord == std::stof(x_cord))
	{
		stateOfX = "same_x"; 
		sameXorY = true;
	}

	if (player_y_cord == std::stof(y_cord))
	{
		stateOfY = "same_y"; 
		sameXorY = true;
	}

	if (round(abs(player_x_cord - std::stof(x_cord)) * 1000) / 1000 == round(abs(player_y_cord - std::stof(y_cord)) * 1000) / 1000)
	{
		stateOfX = "diagonal";
		stateOfY = "diagonal";
		diagonal = true;
	}

	if (action == "1")
	{
		PaintWalkStep(step, sameXorY, diagonal);
	}


	step_list += StepSignature(step, action, "\"walk\", {" + x_cord + ", " + y_cord + "}, \"" + last_walking_comment + "\", \"" + stateOfX + "\", \"" + stateOfY + "\"", comment);
	player_x_cord = std::stof(x_cord);
	player_y_cord = std::stof(y_cord);
	total_steps += 1;
}

void GenerateScript::mining(string step, string x_cord, string y_cord, string duration, string building_name, string OrientationEnum, bool is_building, string comment)
{ 
	// Mine the coordinates without checking distance if the user have added Override in the comment - this is mostly useful for removing wreckage. 
	if (modifiers.force || modifiers.vehicle)
	{
		step_list += StepSignature(step, "1", "\"mine\", {" + x_cord + ", " + y_cord + "}, " + duration, comment);
		total_steps += 1;
		PaintIntermediateWalk(step, false);
		return;
	}
	else if (comment == "Override")
	{
		step_list += StepSignature(step, "1", "\"mine\", {" + x_cord + ", " + y_cord + "}, " + duration, "");
		total_steps += 1;
		PaintIntermediateWalk(step, false);
		return;
	}

	if (is_building)
	{
		check_interact_distance(step, "1", x_cord, y_cord, building_name, OrientationEnum);
	}
	else
	{
		check_mining_distance(step, "1", x_cord, y_cord);
	}

	step_list += StepSignature(step, "1", "\"mine\", {" + x_cord + ", " + y_cord + "}, " + duration, comment);
	total_steps += 1;
}

void GenerateScript::craft(string step, string amount, string item, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "1", "\"craft\", " + amount + ", \"" + item + "\"", comment);
	total_steps += 1;
};

void GenerateScript::cancel_crafting(string step, string amount, string item, string comment)
{
	item = check_item_name(item);

	step_list += StepSignature(step, "1", "\"cancel crafting\", " + amount + ", \"" + item + "\"", comment);
	total_steps += 1;
};

void GenerateScript::tech(string step, string tech_to_research, string comment)
{
	tech_to_research = convert_string(tech_to_research);

	if (auto search = map_translation_research.find(tech_to_research); search != map_translation_research.end())
	{
		tech_to_research = search->second;
	}

	step_list += StepSignature(step, "1", "\"tech\", \"" + tech_to_research + "\"", comment);
	total_steps += 1;
}

void GenerateScript::speed(string step, string speed, string comment)
{
	step_list += StepSignature(step, "1", "\"speed\", " + speed, comment);
	total_steps += 1;
}

void GenerateScript::pause(string step, string comment)
{
	step_list += StepSignature(step, "1", "\"pause\"", comment);
	total_steps += 1;
}

void GenerateScript::never_idle(string step, string comment)
{
	PaintWarningStateChanged(step, warning_state_counters.never_idle++);
	step_list += StepSignature(step, "1", "\"never idle\"", comment);
	total_steps += 1;
}

void GenerateScript::keep_walking(string step, string comment)
{
	PaintWarningStateChanged(step, warning_state_counters.keep_walking++);
	step_list += StepSignature(step, "1", "\"keep walking\"", comment);
	total_steps += 1;
}

void GenerateScript::keep_on_path(string step, string comment) 
{
	PaintWarningStateChanged(step, warning_state_counters.keep_on_path++);
	step_list += StepSignature(step, "1", "\"keep on path\"", comment);
	total_steps += 1;
}

void GenerateScript::keep_crafting(string step, string comment) 
{
	PaintWarningStateChanged(step, warning_state_counters.keep_crafting++);
	step_list += StepSignature(step, "1", "\"keep crafting\"", comment);
	total_steps += 1;
}

void GenerateScript::launch(string step, string x_cord, string y_cord, string comment)
{
	step_list += StepSignature(step, "1", "\"launch\", {" + x_cord + ", " + y_cord + "}", comment);
	total_steps += 1;
}

void GenerateScript::next(string step, string comment)
{
	step_list += StepSignature(step, "1", "\"next\"", comment);
	total_steps += 1;
}

void GenerateScript::save(string step, string nameOfSaveGame)
{
	step_list += StepSignature(step, "1", "\"save\", \"" + nameOfSaveGame + "\"");
	total_steps += 1;
}

void GenerateScript::idle(string step, string amount, string comment)
{
	step_list += StepSignature(step, "1", "\"idle\", " + amount, comment);
	total_steps += 1;
}

void GenerateScript::pick(string step, string amount, string comment)
{
	step_list += StepSignature(step, "1", "\"pick\", \"" + amount + "\"", comment);
	total_steps += 1;
}

void GenerateScript::shoot(string step, string x_cord, string y_cord, string amount, string comment)
{
	step_list += StepSignature(step, "1", "\"shoot\", {" + x_cord + ", " + y_cord + "}, \"" + amount + "\"", comment);
	total_steps += 1;
}

void GenerateScript::_throw(string step, string x_cord, string y_cord, string item, string comment)
{
	step_list += StepSignature(step, "1", "\"throw\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\"", comment);
	total_steps += 1;
}

void GenerateScript::equip(string step, string amount, string item, InventoryType inventory, string comment)
{
	step_list += StepSignature(step, "1", "\"equip\", " + amount + ", \"" + check_item_name(item) + "\", \"" + inventory_types_list[inventory] + "\"", comment);
	total_steps += 1;
}

void GenerateScript::enter(string step, string comment)
{
	step_list += StepSignature(step, "1", "\"enter\" ", comment);
	total_steps += 1;
}

void GenerateScript::drive(string step, string duration, Riding riding_state, string comment)
{
	step_list += StepSignature(step, "1", "\"drive\", "+ duration +", " + riding_state.ToLua(), comment);
	total_steps += 1;
}

void GenerateScript::send(string step, string x_cord, string y_cord, string id, string comment)
{
	step_list += StepSignature(step, "1", "\"send\", {" + x_cord + ", " + y_cord + "}," + id + ", ", comment);
	total_steps += 1;
}

void GenerateScript::rotate(string step, string action, string x_cord, string y_cord, string times, string item, string OrientationEnum, string comment)
{
	check_interact_distance(step, action, x_cord, y_cord, item, OrientationEnum);

	if (std::stoi(times) == 3)
	{
		step_list += StepSignature(step, action, "\"rotate\", {" + x_cord + ", " + y_cord + "}, " + "true", comment);
		total_steps += 1;
	}
	else
	{
		step_list += StepSignature(step, action, "\"rotate\", {" + x_cord + ", " + y_cord + "}, " + "false", comment);
		total_steps += 1;
	}
}

void GenerateScript::row_rotate(string step, string x_cord, string y_cord, string times, string item, string OrientationEnum, string direction, string number_of_buildings, string building_size, string comment)
{
	int action = 1; //action iterator
	const int times_c = stoi(times); //constant rotation amount
	int times_i = times_c; //rotation amount iterator

	if (times_i == 3)
	{
		rotate(step, std::to_string(action++), x_cord, y_cord, times, item, OrientationEnum, comment);
	}
	else
	{
		while (times_i-- > 0)
		{
			rotate(step, std::to_string(action++), x_cord, y_cord, "1", item, OrientationEnum, comment);
		}
	}

	for (int i = 1; i < stoi(number_of_buildings); i++)
	{
		times_i = times_c;
		find_coordinates(x_cord, y_cord, direction, building_size);

		if (times_i == 3)
		{
			rotate(step, std::to_string(action++), x_cord, y_cord, times, item, OrientationEnum);
		}
		else
		{
			while (times_i-- > 0)
			{
				rotate(step, std::to_string(action++), x_cord, y_cord, "1", item, OrientationEnum);
			}
		}
	}
}

void GenerateScript::build(string step, string action, string x_cord, string y_cord, string item, string OrientationEnum, string comment)
{
	if (modifiers.force || comment == "Override")
	{
		PaintIntermediateWalk(step, false);
	}
	else
	{
		check_interact_distance(step, action, x_cord, y_cord, item, OrientationEnum);
	}


	item = check_item_name(item);

	OrientationEnum = orientation_defines_list[MapStringToOrientation(OrientationEnum)];

	step_list += StepSignature(step, action, "\"build\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + OrientationEnum, comment);
	total_steps += 1;
};

void GenerateScript::row_build(string step, string x_cord, string y_cord, string item, string OrientationEnum, string direction, string number_of_buildings, string building_size, string comment)
{

	build(step, "1", x_cord, y_cord, item, OrientationEnum, comment);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		build(step, std::to_string(i + 1), x_cord, y_cord, item, OrientationEnum);
	}
}

void GenerateScript::take(string step, string action, string x_cord, string y_cord, string amount, string item, string from, string building, string OrientationEnum, string comment)
{
	if (modifiers.force || modifiers.vehicle)
	{
		item = check_item_name(item);
		step_list += StepSignature(step, action, "\"take\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + from, comment);
		total_steps += 1;
		PaintIntermediateWalk(step, false);
		return; 
	}
	else if (comment == "Override")
	{
		item = check_item_name(item);
		step_list += StepSignature(step, action, "\"take\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + from, "");
		total_steps += 1;
		PaintIntermediateWalk(step, false);
		return;
	}

	if (OrientationEnum == "Wreck")
	{
		check_interact_distance(step, action, x_cord, y_cord, OrientationEnum, "North");
	}
	else
	{
		check_interact_distance(step, action, x_cord, y_cord, building, OrientationEnum);
	}

	item = check_item_name(item);

	step_list += StepSignature(step, action, "\"take\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + from, comment);
	total_steps += 1;
}

void GenerateScript::row_take(string step, string x_cord, string y_cord, string amount, string item, string from, string direction, string number_of_buildings, string building_size, string building, string OrientationEnum, string comment)
{
	take(step, "1", x_cord, y_cord, amount, item, from, building, OrientationEnum, comment);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		take(step, std::to_string(i + 1), x_cord, y_cord, amount, item, from, building, OrientationEnum);
	}
}

void GenerateScript::put(string step, string action, string x_cord, string y_cord, string amount, string item, string into, string building, string OrientationEnum, string comment)
{
	if (modifiers.force || modifiers.vehicle)
	{
		item = check_item_name(item);
		step_list += StepSignature(step, action, "\"put\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + into, comment);
		total_steps += 1;
		PaintIntermediateWalk(step, false);
		return;
	}
	else if (comment == "Override")
	{
		item = check_item_name(item);
		step_list += StepSignature(step, action, "\"put\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + into, "");
		total_steps += 1;
		PaintIntermediateWalk(step, false);
		return;
	}

	if (OrientationEnum == "Wreck")
	{
		check_interact_distance(step, action, x_cord, y_cord, OrientationEnum, "North");
	}
	else
	{
		check_interact_distance(step, action, x_cord, y_cord, building, OrientationEnum);
	}

	item = check_item_name(item);

	step_list += StepSignature(step, action, "\"put\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ", " + into, comment);
	total_steps += 1;
}

void GenerateScript::row_put(string step, string x_cord, string y_cord, string amount, string item, string from, string direction, string number_of_buildings, string building_size, string building, string OrientationEnum, string comment)
{
	put(step, "1", x_cord, y_cord, amount, item, from, building, OrientationEnum, comment);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		put(step, std::to_string(i + 1), x_cord, y_cord, amount, item, from, building, OrientationEnum);
	}
}

void GenerateScript::recipe(string step, string action, string x_cord, string y_cord, string item, string building, string OrientationEnum, string comment)
{
	if (modifiers.force || comment == "Override")
	{
		PaintIntermediateWalk(step, false);
	}
	else
	{
		check_interact_distance(step, action, x_cord, y_cord, building, OrientationEnum);
	}


	item = check_item_name(item);

	step_list += StepSignature(step, action, "\"recipe\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\"", comment);
	total_steps += 1;
}

void GenerateScript::row_recipe(string step, string x_cord, string y_cord, string item, string direction, string building_size, string number_of_buildings, string building, string OrientationEnum, string comment)
{
	recipe(step, "1", x_cord, y_cord, item, building, OrientationEnum, comment);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		recipe(step, std::to_string(i + 1), x_cord, y_cord, item, building, OrientationEnum);
	}
}

void GenerateScript::limit(string step, string action, string x_cord, string y_cord, string amount, string from, string building, string OrientationEnum, string comment)
{
	check_interact_distance(step, action, x_cord, y_cord, building, OrientationEnum);

	step_list += StepSignature(step, action, "\"limit\", {" + x_cord + ", " + y_cord + "}, " + amount + ", " + from, comment);
	total_steps += 1;
}

void GenerateScript::row_limit(string step, string x_cord, string y_cord, string amount, string from, string direction, string number_of_buildings, string building_size, string building, string OrientationEnum, string comment)
{
	limit(step, "1", x_cord, y_cord, amount, from, building, OrientationEnum, comment);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		limit(step, std::to_string(i + 1), x_cord, y_cord, amount, from, building, OrientationEnum);
	}
}

void GenerateScript::priority(string step, string action, string x_cord, string y_cord, string priority_in, string priority_out, string building, string OrientationEnum, string comment)
{
	check_interact_distance(step, action, x_cord, y_cord, building, OrientationEnum);

	step_list += StepSignature(step, action, "\"priority\", {" + x_cord + ", " + y_cord + "}, \"" + priority_in + "\", \"" + priority_out + "\"", comment);
	total_steps += 1;
}

void GenerateScript::row_priority(string step, string x_cord, string y_cord, PriorityStruct _priority, string direction, string number_of_buildings, string building_size, string building, string OrientationEnum, string comment)
{
	priority_in = convert_string(Priority::Names[_priority.input]);
	priority_out = convert_string(Priority::Names[_priority.output]);

	priority(step, "1", x_cord, y_cord, priority_in, priority_out, building, OrientationEnum, comment);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		priority(step, std::to_string(i + 1), x_cord, y_cord, priority_in, priority_out, building, OrientationEnum);;
	}
}

void GenerateScript::filter(string step, string action, string x_cord, string y_cord, string item, string amount, string type, string building, string OrientationEnum, string comment)
{
	check_interact_distance(step, action, x_cord, y_cord, building, OrientationEnum);

	item = check_item_name(item);

	step_list += StepSignature(step, action, "\"filter\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\", " + amount + ",  \"" + type + "\"", comment);
	total_steps += 1;
}

void GenerateScript::row_filter(string step, string x_cord, string y_cord, string item, string amount, string type, string direction, string number_of_buildings, string building_size, string building, string OrientationEnum, string comment)
{
	filter(step, "1", x_cord, y_cord, item, amount, type, building, OrientationEnum, comment);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		filter(step, std::to_string(i + 1), x_cord, y_cord, item, amount, type, building, OrientationEnum);
	}
}

void GenerateScript::drop(string step, string action, string x_cord, string y_cord, string item, string building, string comment)
{
	check_interact_distance(step, action, x_cord, y_cord, building, "North");

	item = convert_string(item);

	step_list += StepSignature(step, action, "\"drop\", {" + x_cord + ", " + y_cord + "}, \"" + item + "\"", comment);
	total_steps += 1;
}

void GenerateScript::pick_compatibility(std::string step, std::string action, std::string x_cord, std::string y_cord)
{
	walk(step, action, x_cord, y_cord, last_walking_comment);
	step_list += signature(step, action) + "\"pick\", {" + x_cord + ", " + y_cord + "}}\n";
	total_steps += 1;
}

void GenerateScript::row_pick_compatibility(std::string step, std::string x_cord, std::string y_cord, std::string direction, std::string number_of_buildings, std::string building_size)
{
	pick_compatibility(step, "1", x_cord, y_cord);

	for (int i = 1; i < std::stof(number_of_buildings); i++)
	{
		find_coordinates(x_cord, y_cord, direction, building_size);

		pick_compatibility(step, std::to_string(i + 1), x_cord, y_cord);
	}
}
