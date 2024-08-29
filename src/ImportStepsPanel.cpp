#pragma once
#include "cMain.h"

#include "Shared functions\Functions.h"

#include "Data\utils.h"

using std::string;
using std::stod;
using std::stoi;

/* ImportStepsPanel variables:
	ImportStepsPanel* import_steps_panel;
	wxTextCtrl* import_steps_text_import;
	wxSpinCtrl* import_steps_into_steps_ctrl;
	wxButton* import_steps_into_steps_btn;
	wxTextCtrl* import_steps_into_template_ctrl;
	wxButton* import_steps_into_template_btn;
	wxCheckBox* import_steps_clear_checkbox;

	wxString import_steps_into_template_ctrl_validator;
*/

bool ImportStepsPanel::update_segment()
{
	std::string line;
	std::string segment;
	std::stringstream data_line;

	if (std::getline(data, line, data.widen('\n')))
	{
		data_line.str(line);

		segments = {};

		while (std::getline(data_line, segment, ';'))
		{
			segments.push_back(segment);
		}

		return true;
	}

	return false;
}

bool ImportStepsPanel::extract_steps(wxString steps_text, vector<Step>& steps, vector<Building> buildingSnapshot, int buildings_in_snap_shot)
{
	buildingsInSnapShot = buildings_in_snap_shot;
	int counter = 0;
	data = {};
	data.str(steps_text.ToStdString());
	while (update_segment())
	{
		counter++;
		if (segments.size() != step_segment_size &&
			segments.size() != step_segment_size_without_colour &&
			segments.size() != step_segment_size_without_comment_and_colour)
		{
			wxMessageBox("It was not possible to read line ["+ std::to_string(counter) + "] as it only contained [" + std::to_string(segments.size()) + "] semicolons", "Text import error");
			return false;
		}

		Step step(invalidX, 0);

		int size = segments.size();
		if (size < 1) continue;
		
		step.OriginalX = step.X = size >= 1 && segments[1] != "" ? stod(segments[1]) : 0;
		step.OriginalY = step.Y = size >= 2 && segments[2] != "" ? stod(segments[2]) : 0;
		step.amount = size >= 3 && segments[3] != "" ? segments[3] == "All" ? 0 : stoi(segments[3]) : 0;
		step.Item = size >= 4 && segments[4] != "" ? Capitalize(segments[4], true) : "";
		step.orientation = MapStringToOrientation(size >= 5 ? segments[5] : "");
		step.Direction = MapStringToOrientation(size >= 6 ? segments[6] : "");
		step.Size = size >= 7 && segments[7] != "" ? stoi(segments[7]) : 1;
		step.Buildings = size >= 8 && segments[8] != "" ? stoi(segments[8]) : 1;
		step.Comment = size >= 9 ? segments[9] : "";
		step.colour = size >= 10 && segments[10] != "" ? wxColour(segments[10]) : wxNullColour;
		step.Modifiers.FromString(size >= 11 && segments[11] != "" ? segments[11] : "");

		try
		{
			step.type = ToStepType(segments[0]);
		}
		catch (...)
		{
			wxMessageBox("It was not possible to read line [" + std::to_string(counter) + "] as the command token [" + segments[0] + "] doesn't match any commands", "Text import conversion error");
			return false;
		}

		switch (step.type )
		{
			[[likely]] case e_build:
				step.BuildingIndex = Building::Map_BuildingName_to_BuildingType[step.Item];
				buildingsInSnapShot = ProcessBuildStep(buildingSnapshot, buildingsInSnapShot, step);
				break;

			case e_mine:
				ProcessMiningStep(buildingSnapshot, buildingsInSnapShot, step);
				break;

			case e_priority:
				step.priority.FromString(segments[5]);

				// Only here to populate extra parameters in step. Actual validation will be done on script generation
				BuildingExists(buildingSnapshot, buildingsInSnapShot, step);
				break;

			case e_recipe: [[fallthrough]];
			case e_filter: [[fallthrough]];
			case e_rotate: [[fallthrough]];
			case e_launch:
				// Only here to populate extra parameters in step. Actual validation will be done on script generation
				BuildingExists(buildingSnapshot, buildingsInSnapShot, step);
				break;

			case e_limit: [[fallthrough]];
			[[likely]] case e_put: [[fallthrough]];
			[[likely]] case e_take:
				step.inventory = GetInventoryType(segments[5]);
				// Only here to populate extra parameters in step. Actual validation will be done on script generation
				BuildingExists(buildingSnapshot, buildingsInSnapShot, step);
				break;
			case e_equip:
				step.inventory = GetInventoryType(segments[5]);
				break;
			default:
				break;
		}

		steps.push_back(step);
	}

	return true;
}

void cMain::OnImportStepsIntoStepsIndexBtnClicked(wxCommandEvent& event)
{
	auto rows = grid_steps->GetSelectedRows();
	if (rows.IsEmpty()) return;
	auto row = rows.front();

	if (row != import_steps_into_steps_ctrl->GetValue())
	{
		import_steps_into_steps_ctrl->SetValue(row);
		if (is_started)
		{
			auto t = new HighlightInputControlChangedThread({import_steps_into_steps_ctrl});
			t->Run();
		}
	}
}

void cMain::OnImportStepsIntoStepsIndexBtnRight(wxMouseEvent& event)
{
	auto rows = grid_steps->GetSelectedRows();
	if (rows.IsEmpty()) return;
	auto row = rows.Last();
	auto totalRows = grid_steps->GetNumberRows();

	if (row - totalRows != import_steps_into_steps_ctrl->GetValue())
	{
		import_steps_into_steps_ctrl->SetValue(row - totalRows);
		if (is_started)
		{
			auto t = new HighlightInputControlChangedThread({import_steps_into_steps_ctrl});
			t->Run();
		}
	}
}

void cMain::OnImportStepsTextUpdate(wxCommandEvent& event)
{
	if (import_steps_text_import->IsEmpty())
	{
		import_steps_into_steps_btn->Enable(false);
		import_steps_into_template_btn->Enable(false);
	}
	else
	{
		int row = import_steps_into_steps_ctrl->GetValue();
		int rows = grid_steps->GetNumberRows();
		if (row >= 0 && row <= rows)
		{
			import_steps_into_steps_ctrl->SetBackgroundColour(wxColour("Window"));
			import_steps_into_steps_btn->Enable(!import_steps_text_import->IsEmpty());
		}
		else if (row < 0 && -row <= rows + 1)
		{
			import_steps_into_steps_ctrl->SetBackgroundColour(wxColour("Window"));
			import_steps_into_steps_btn->Enable(!import_steps_text_import->IsEmpty());
		}
		else
		{
			import_steps_into_steps_ctrl->SetBackgroundColour(wxColour("Red"));
			import_steps_into_steps_btn->Enable(false);
		}
		validateTemplateName();
	}
}

void cMain::OnImportStepsIntoStepsCtrl(wxSpinEvent& event)
{
	int row = import_steps_into_steps_ctrl->GetValue();
	int rows = grid_steps->GetNumberRows();
	if (row >= 0 && row <= rows)
	{
		import_steps_into_steps_ctrl->SetBackgroundColour(wxColour("Window"));
		import_steps_into_steps_btn->Enable(!import_steps_text_import->IsEmpty());
	}
	else if (row < 0 && -row <= rows+1)
	{
		import_steps_into_steps_ctrl->SetBackgroundColour(wxColour("Window"));
		import_steps_into_steps_btn->Enable(!import_steps_text_import->IsEmpty());
	}
	else
	{
		import_steps_into_steps_ctrl->SetBackgroundColour(wxColour("Red"));
		import_steps_into_steps_btn->Enable(false);
	}
}

void cMain::OnImportStepsIntoStepsCtrlEnter(wxCommandEvent& event)
{
	if (import_steps_into_steps_btn->IsEnabled()) OnImportStepsIntoStepsBtnClick(event);
	else event.Skip();
}

void cMain::OnImportStepsIntoStepsBtnClick(wxCommandEvent& event)
{
	// validate steps
	wxString steps_text = import_steps_text_import->GetValue();
	vector<Step> steps = {};

	// import steps
	int row = import_steps_into_steps_ctrl->GetValue();
	int rows = grid_steps->GetNumberRows();
	int start = row >= 0 ? row : rows + row + 1;

	if (!import_steps_panel->extract_steps(steps_text, steps, BuildingsSnapShot, GenerateBuildingSnapShot(start))) return;

	grid_steps->InsertRows(start, steps.size());

	Command change;

	for (int i = 0; i < steps.size(); i++)
	{
		change.after.push_back({start + i, steps[i]});
		GridEntry gridEntry = PrepareStepForGrid(&steps[i]);

		PopulateGrid(grid_steps, start + i, &gridEntry);

		BackgroundColorUpdate(grid_steps, start + i, steps[i]);
	}

	StepGridData.insert(StepGridData.begin() + start, steps.begin(), steps.end());

	if (import_steps_clear_checkbox->IsChecked()) import_steps_text_import->Clear();

	autosaver.Push(change);
	no_changes = false;

	wxYield();
	vector<int> highlight_rows = {};
	for (int i = 0; i < steps.size(); i++)
		highlight_rows.push_back(start + i);
	if (is_started)
	{
		HighlightRowsThread* t = new HighlightRowsThread(highlight_rows, this);
		t->Run();
	}
}

bool cMain::validateTemplateName()
{
	wxValidator* validator = import_steps_into_template_ctrl->GetValidator();
	validator->TransferFromWindow();
	if (!validator->Validate(this) && !import_steps_into_template_ctrl_validator.empty())
	{
		import_steps_into_template_btn->Enable(false);
		import_steps_into_template_ctrl->SetForegroundColour(wxColour("Red"));
		return false;
	}
	std::string text = import_steps_into_template_ctrl_validator.ToStdString();

	for (auto& template_name : template_choices)
	{
		if (equals_ignore_case(template_name.ToStdString(), text))
		{
			import_steps_into_template_btn->Enable(false);
			import_steps_into_template_ctrl->SetForegroundColour(wxColour("Red"));
			return false;
		}
		else continue;
	}
	
	import_steps_into_template_ctrl->SetForegroundColour(wxColour("Window"));
	import_steps_into_template_btn->Enable(!import_steps_text_import->IsEmpty());
	return true;
}

void cMain::OnImportStepsIntoTemplateCtrlText(wxCommandEvent& event)
{
	validateTemplateName();
}

void cMain::OnImportStepsIntoTemplateCtrlEnter(wxCommandEvent& event)
{
	if (!validateTemplateName()) return;

	std::vector<Building> buildingSnapshot{};
	buildingSnapshot.clear();
	buildingSnapshot.reserve(1000);
	for (int i = 0; i < buildingSnapshot.capacity(); i++)
	{
		buildingSnapshot.emplace_back(invalidX);
	}

	// validate steps
	vector<Step> steps = {};
	if (!import_steps_panel->extract_steps(import_steps_text_import->GetValue(), steps, BuildingsSnapShot, 0)) return;

	// create template
	std::string name = import_steps_into_template_ctrl_validator.ToStdString();
	cmb_choose_template->Clear();
	template_choices.Add(name);
	template_choices.Sort();
	cmb_choose_template->Append(template_choices);
	cmb_choose_template->SetValue(name);
	cmb_choose_template->AutoComplete(template_choices);

	Command change{.template_name = name};

	auto a = template_map.insert(std::pair<std::string, std::vector<Step>>(name, steps) );
	for (int i = 0; i < steps.size(); i++) 
	{
		change.after.push_back({i, steps[i]});
	}

	UpdateTemplateGrid(template_map[name]);

	if (import_steps_clear_checkbox->IsChecked()) import_steps_text_import->Clear();

	import_steps_into_template_btn->Enable(false);
	import_steps_into_template_ctrl->SetForegroundColour(wxColour("Red"));

	autosaver.Push(change);
	no_changes = false;
}

void cMain::OnImportStepsIntoTemplateBtnClick(wxCommandEvent& event)
{
	OnImportStepsIntoTemplateCtrlEnter(event);
}
