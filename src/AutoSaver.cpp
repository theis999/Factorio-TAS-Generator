#include "AutoSaver.h"
#include "Shared functions/Functions.h"

AutoSaver::AutoSaver() {}

void AutoSaver::Clear()
{
	autosave_data.clear();
}

void AutoSaver::Push(Command c)
{
	undo_stack.Push(c);
	autosave_data.push_back(c);

	if (autosave_data.size() >= undo_stack.CAPACITY && autosave_data.size() % 4 == 0)
		wxMessageBox("Please save as soon as possible.", "Autosave is exceeding capacity");
}

Command AutoSaver::Pop()
{
	if (!autosave_data.empty()) autosave_data.pop_back();
	return undo_stack.Pop();
}

Command AutoSaver::PopBack()
{
	auto item = undo_stack.PopBack();
	if (!item.empty()) autosave_data.push_back(item);
	return item;
}

bool AutoSaver::Autosave(wxWindow* parent, DialogProgressBar* dialog_progress_bar, string folder_location)
{
	int total_commands = autosave_data.size();
	int lines_processed = 0;

	if (!dialog_progress_bar) dialog_progress_bar = new DialogProgressBar(parent, wxID_ANY, "Processing request");

	dialog_progress_bar->set_text("Auto saving");
	dialog_progress_bar->set_button_enable(false);
	dialog_progress_bar->set_progress(0);
	dialog_progress_bar->Show();

	std::ofstream myfile;
	myfile.open(folder_location);

	myfile << total_commands_indicator << total_commands << std::endl;

	for (int i = 0; i < autosave_data.size(); i++)
	{
		auto& c = autosave_data[i];
		myfile << COMMAND << ";" << i << ";before;" << c.before.size() << ";after;" << c.after.size() << ";" << c.template_name <<";" << std::endl;

		myfile << BEFORE << std::endl;
		for (auto& stepline : c.before)
			myfile << stepline.row << ";" << stepline.step.ToString() << std::endl;

		myfile << AFTER << std::endl;
		for (auto& stepline : c.after)
			myfile << stepline.row << ";" << stepline.step.ToString() << std::endl;

		lines_processed++;

		if (lines_processed % 10 == 9)
		{
			dialog_progress_bar->set_progress(static_cast<float>(lines_processed) / static_cast<float>(total_commands) * 100.0f - 1);
			wxYield();
		}
	}

	myfile << std::endl;
	myfile.close();

	dialog_progress_bar->set_progress(100);
	dialog_progress_bar->Close();

	return true;
}

StepLine AutoSaver::read_StepLine(const size_t segment_size, vector<Building> buildingSnapshot, int& buildingsInSnapShot, std::vector<string>::iterator step_segments)
{
	Step step(invalidX, 0);

	if (step_segments[2] != "")
	{
		step.X = stod(step_segments[2]);
		step.OriginalX = step.X;
		step.Y = stod(step_segments[3]);
		step.OriginalY = step.Y;
	}

	step.amount = step_segments[4] == "" || step_segments[4] == "All" ? 0 : stoi(step_segments[4]);
	step.Item = Capitalize(step_segments[5], true);
	step.orientation = MapStringToOrientation(step_segments[6]);
	step.Direction = MapStringToOrientation(step_segments[7]);
	step.Size = step_segments[8] != "" ? stoi(step_segments[8]) : 1;
	step.Buildings = step_segments[9] != "" ? stoi(step_segments[9]) : 1;
	step.Comment = segment_size == step_segment_size || segment_size == step_segment_size_without_colour ? step_segments[10] : "";
	step.colour = segment_size == step_segment_size && step_segments[11] != "" ? wxColour(step_segments[11]) : wxNullColour;
	step.Modifiers.FromString(segment_size == step_segment_size ? step_segments[12] : "");

	step.type = ToStepType(step_segments[1]);
	switch (step.type)
	{
		case e_build:
			step.BuildingIndex = Building(step.X, step.Y, Building::Map_BuildingName_to_BuildingType[step.Item], step.orientation);
			if (buildingsInSnapShot > -1) buildingsInSnapShot = ProcessBuildStep(buildingSnapshot, buildingsInSnapShot, step);
			break;

		case e_mine:
			if (buildingsInSnapShot > -1) ProcessMiningStep(buildingSnapshot, buildingsInSnapShot, step);
			break;

		case e_priority:
			step.priority.FromString(step_segments[6]);

			// Only here to populate extra parameters in step. Actual validation will be done on script generation
			if (buildingsInSnapShot > -1) BuildingExists(buildingSnapshot, buildingsInSnapShot, step);
			break;

		case e_drive:
			step.riding.FromString(step_segments[6]);
			break;

		case e_limit:
		case e_put:
		case e_take:
			step.inventory = GetInventoryType(step_segments[6]);
			// Only here to populate extra parameters in step. Actual validation will be done on script generation
			if (buildingsInSnapShot > -1) BuildingExists(buildingSnapshot, buildingsInSnapShot, step);
			break;

		case e_recipe:
		case e_filter:
		case e_rotate:
		case e_launch:
			// Only here to populate extra parameters in step. Actual validation will be done on script generation
			if (buildingsInSnapShot > -1) BuildingExists(buildingSnapshot, buildingsInSnapShot, step);
			break;

		case e_equip:
			step.inventory = GetInventoryType(step_segments[6]);
			break;

		case e_game_speed:
			step.amount *= 100;
			break;

		default:
			break;
	}

	return {stoi(step_segments[0]), step};
}

bool AutoSaver::update_segment(std::ifstream& file)
{
	string line;
	string segment;
	std::stringstream data_line;

	if (std::getline(file, line))
	{
		data_line.str(line);

		segments.clear();
		segments.reserve(16);

		while (std::getline(data_line, segment, ';'))
		{
			segments.push_back(segment);
		}

		return true;
	}

	return false;
}

vector<Command> AutoSaver::OpenAutosave(std::ifstream& file, vector<Building> buildingSnapshot, int& buildingsInSnapShot)
{
	update_segment(file);
	//if (segments.size() < 2) return {};
	int total_lines = 1;
	//if (segments[0] == "Autosave_tag")
		//total_lines = std::stoi(segments[1]);

	Command current;
	bool is_after = false;
		
	while (update_segment(file))
	{
		const size_t segment_size = segments.size();
		if (segment_size > 0 && segments[0] == COMMAND)
		{
			current = Command{
				//.before = segment_size >= 4 ? vector<StepLine>(std::stoi(segments[3])) : vector<StepLine>(),
				//.after = segment_size >= 6 ? vector<StepLine>(std::stoi(segments[5])) : vector<StepLine>(),
				.template_name = segment_size >= 7 ? segments[6] : "",
			};
			autosave_data.push_back(current);
		}
		else if (segment_size > 0 && segments[0] == BEFORE)
		{
			is_after = false;
		}
		else if (segment_size > 0 && segments[0] == AFTER)
		{
			is_after = true;
		}
		else if (segment_size >= 10)
		{
			auto _buildingsInSnapShot = autosave_data.back().template_name == "" ? buildingsInSnapShot : -1;
			StepLine stepline = read_StepLine(segment_size, buildingSnapshot, _buildingsInSnapShot, segments.begin());
			if (is_after) autosave_data.back().after.push_back(stepline);
			else autosave_data.back().before.push_back(stepline);
		}
	}

	for (auto& item : autosave_data) undo_stack.Push(item);

	return autosave_data;
}
