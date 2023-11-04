#include "cMain.h"

void cMain::TemplatePageStartup()
{
	btn_template_add_to_steps_list->SetLabel(L"Export ⭲");
	btn_template_add_from_steps_list->SetLabel(L"Import ⭰");
}

#pragma region TemplateControl
void cMain::ClearTemplateGrid(bool disable)
{
	if (grid_template->GetNumberRows() > 0)
		grid_template->DeleteRows(0, grid_template->GetNumberRows());

	if (disable)
	{
		auto e = wxGridRangeSelectEvent();
		OnTemplateGridRangeSelect(e);
	}

	spin_template_iterator->SetValue(0);
	choice_template_direction->SetSelection(0);
}

void cMain::UpdateTemplateGrid(vector<Step>& steps)
{
	ClearTemplateGrid(false);
	grid_template->InsertRows(0, steps.size());
	for (int i = 0; i < steps.size(); i++)
	{
		GridEntry gridEntry = PrepareStepForGrid(&steps[i]);
		PopulateGrid(grid_template, i, &gridEntry);
		BackgroundColorUpdate(grid_template, i, steps[i]);
	}
}

void cMain::OnTemplateChosen(wxCommandEvent& event)
{
	UpdateTemplateGrid(template_map[cmb_choose_template->GetValue().ToStdString()]);
}

void cMain::OnTemplateText(wxCommandEvent& event)
{
	auto name = cmb_choose_template->GetValue().ToStdString();
	auto list = template_map.find(name);
	if (list == template_map.end())
	{
		ClearTemplateGrid();
		btn_template_new->Enable(!name.empty());
		btn_template_delete->Disable();
		btn_template_add_from_steps_list->Disable();
		btn_template_add_step->Disable();
	}
	else
	{
		UpdateTemplateGrid(list->second);
		btn_template_new->Disable();
		btn_template_delete->Enable();
		btn_template_add_from_steps_list->Enable();
		btn_template_add_step->Enable();
	}
}

void cMain::OnNewTemplateClicked(wxCommandEvent& event)
{
	int rowCount = cmb_choose_template->GetCount();
	string name = cmb_choose_template->GetValue().ToStdString();

	if (name == "")
	{
		wxMessageBox("Please write a template name", "Template name cannot be blank");
		cmb_choose_template->SetFocus();
		return;
	}

	auto find_template = template_map.find(cmb_choose_template->GetValue().ToStdString());
	if (find_template != template_map.end())
	{
		wxMessageBox("Template names have to be unique - please write a new name in the Choose Template field", "Template names should be unique");
		cmb_choose_template->SetFocus();
		return;
	}

	template_choices.Add(name);
	template_choices.Sort();

	cmb_choose_template->Clear();
	cmb_choose_template->Append(template_choices);
	cmb_choose_template->SetValue(name);
	cmb_choose_template->AutoComplete(template_choices);

	vector<Step> template_list = {};
	UpdateTemplateGrid(template_list);
	template_map.insert(pair<string, vector<Step>>(name, template_list));

	btn_template_add_from_steps_list->Enable();
	btn_template_add_step->Enable();

	no_changes = false;
}

void cMain::OnDeleteTemplate(bool force)
{
	auto name = cmb_choose_template->GetValue().ToStdString();
	auto steps = template_map.find(name);

	if (steps == template_map.end())
	{
		return;
	}
	else if (!force && wxMessageBox("Are you sure you want to delete this template?", "Delete template", wxICON_QUESTION | wxYES_NO, this) != wxYES)
	{
		return;
	}

	Command change{.template_name = name};
	for (int i = 0; i < steps->second.size(); i++)
		change.before.push_back({i, steps->second[i]});

	template_map.erase(name);
	template_choices.Remove(name);

	cmb_choose_template->Clear();
	cmb_choose_template->Append(template_choices);
	cmb_choose_template->AutoComplete(template_choices);

	if (template_choices.size())
	{
		cmb_choose_template->SetValue(*template_choices.begin());
		auto e = wxCommandEvent{};
		OnTemplateChosen(e);
	}
	else
	{
		ClearTemplateGrid();
	}

	stack.Push(change);
	no_changes = false;
}
void cMain::OnDeleteTemplateRightClicked(wxMouseEvent& event)
{
	OnDeleteTemplate(true);
}
void cMain::OnDeleteTemplateClicked(wxCommandEvent& event)
{
	OnDeleteTemplate(false);
}
#pragma endregion TemplateControl

#pragma region StepControl
void cMain::OnTemplateAddStepClicked(wxCommandEvent& event)
{
	auto step = ExtractStep();
	const int row = grid_template->IsSelection() ? *grid_template->GetSelectedRows().begin() : grid_template->GetNumberRows();
	
	grid_template->InsertRows(row);
	GridEntry gridEntry = PrepareStepForGrid(&step);
	PopulateGrid(grid_template, row, &gridEntry);
	BackgroundColorUpdate(grid_template, row, step);

	string key = cmb_choose_template->GetValue().ToStdString();
	vector<Step> list = template_map[key]; 
	list.insert(list.begin() + row, step);
	template_map[key] = list;

	Command change{.template_name = key};
	change.after.push_back({row, step});

	stack.Push(change);
	no_changes = false;
}

void cMain::OnTemplateChangeStepClicked(wxCommandEvent& event)
{
	auto step = ExtractStep();
	auto name = cmb_choose_template->GetValue().ToStdString();
	Command change{.template_name = name};
	auto template_list = template_map.find(name);
	
	if (template_list == template_map.end())
	{
		return;
	}
	
	
	change.before.push_back({*grid_template->GetSelectedRows().begin(), template_list->second[*grid_template->GetSelectedRows().begin()]}); // could cause issues if no rows are selected as that is first checked in ChangeRow

	if (!ChangeRow(grid_template, step))
	{
		return;
	}

	auto rowNum = *grid_template->GetSelectedRows().begin();
	change.after.push_back({rowNum, step});
	template_map[name][rowNum] = step;
	stack.Push(change);
	no_changes = false;
}

void cMain::OnTemplateDeleteStepClicked(wxCommandEvent& event)
{
	if (wxMessageBox("Are you sure you want to delete this template step?", "Delete template step", wxICON_QUESTION | wxYES_NO, this) != wxYES)
	{
		return;
	}

	DeleteRow(grid_template, cmb_choose_template, template_map);
}

void cMain::TemplateMoveRow(wxGrid* grid, wxComboBox* cmb, bool move_up, map<string, vector<Step>>& map)
{
	if (!grid->IsSelection() || !grid->GetSelectedRows().begin())
	{
		wxMessageBox("Please select one or more rows to move", "Select row");
	}

	string map_name = cmb->GetValue().ToStdString();
	Command change{.template_name = map_name};
	int move_by;
	auto blocks = grid->GetSelectedRowBlocks();

	{	// truncate 'move_by' to fit within the grid
		move_by = move_up ? -1 : 1;
		auto exceeed_top_row = blocks.front().GetTopRow() + move_by < 0;
		auto exceeed_bottom_row = blocks.back().GetBottomRow() + move_by >= grid->GetNumberRows();

		move_by = move_up ?
			(exceeed_top_row ?
				-blocks.front().GetTopRow() : move_by) :
			(exceeed_bottom_row ?
				grid->GetNumberRows() - blocks.back().GetBottomRow() - 1 : move_by);

		if (move_by == 0) return;
	}
	auto& data_list = map[map_name];
	for (const auto& block : blocks)
	{
		for (int i = block.GetTopRow(); i <= block.GetBottomRow(); i++)
		{
			change.before.push_back({i, data_list[i]});
			change.after.push_back({i + move_by, data_list[i]});
		}
	}

	UndoRedo(grid, data_list, StepLineToStepBlock(change.after), StepLineToStepBlock(change.before));
	stack.Push(change);
	no_changes = false;
}

void cMain::OnTemplateMoveUpClicked(wxCommandEvent& event)
{
	TemplateMoveRow(grid_template, cmb_choose_template, true, template_map);
}

void cMain::OnTemplateMoveDownClicked(wxCommandEvent& event)
{
	TemplateMoveRow(grid_template, cmb_choose_template, false, template_map);
}
#pragma endregion StepControl

#pragma region othercontrol
void cMain::OnTemplateAddFromStepsListClicked(wxCommandEvent& event)
{
	UpdateMapWithNewSteps(grid_template, cmb_choose_template, template_map);
}

void cMain::OnTemplateAddToStepsListClicked(wxCommandEvent& event)
{
	if (spin_amount_offset->GetValue() != 0 && spin_amount_multiplier->GetValue() != 0)
	{
		//wxMessageBox("Please either use units-offset or units-multiplier", "Invalid use of template attributes");
		//return;
	}

	int moveTo = grid_steps->GetNumberRows();

	if (grid_steps->IsSelection())
	{
		if (!grid_steps->GetSelectedRows().begin())
		{
			wxMessageBox("Please either select row(s) or nothing", "Step list selection not valid");
			return;
		}

		moveTo = *grid_steps->GetSelectedRows().begin();
	}

	auto list = template_map[cmb_choose_template->GetValue().ToStdString()]; 
	auto rows_ = grid_template->GetSelectedRows();
	if (rows_.IsEmpty()) 
		for (int i = 0; i < grid_template->GetNumberRows(); i++) 
			rows_.Add(i);

	const int dir = choice_template_direction->GetSelection();
	int iterator = spin_template_iterator->GetValue();
	if (iterator == 0) 
		iterator = 1;
	else 
		spin_template_iterator->SetValue(iterator + 1);

	const int x_off = spin_x_offset->GetValue() * iterator,
		y_off = spin_y_offset->GetValue() * iterator;
	const int amount_off = spin_amount_offset->GetValue(),
		amount_multiplier = spin_amount_multiplier->GetValue();

	Command change{};
	for (const auto row : rows_)
	{
		Step step = list[row];

		TemplateAlterStep(step, dir, x_off, y_off, amount_off, amount_multiplier);

		change.after.push_back({moveTo, step});
		UpdateStepGrid(moveTo++, &step);
	}

	stack.Push(change);
	no_changes = false;
}

enum template_direction_choice
{
	Normal = 0,
	Left = 1,
	Reverse = 2,
	Right = 3,
};
pair<double, double> transform(double x, double y, template_direction_choice dir)
{
	switch (dir)
	{
		case Normal: return {x, y};
		case Left: return {y, -x};
		case Reverse: return {-x, -y};
		case Right: return {-y, x};
		
		default: return {x, y};
	}
}
Orientation tranform(Orientation o, template_direction_choice dir)
{
	switch (dir)
	{
		case Normal: return o;
		case Left: return (Orientation)(o + 3 % 4);
		case Reverse: return (Orientation)(o + 2 % 4);
		case Right: return (Orientation)(o + 1 % 4);

		default: return o;
	}
}

void cMain::TemplateAlterStep(Step& step, const int direction, int x_off, int y_off, int amount_off, int amount_multi)
{
	if (step.amount != 0)
	{
		step.amount = step.amount * amount_multi + amount_off;
	}

	auto param = listStepTypeToParameterChoices[step.type];
	if (param & building_orientation)
		step.orientation = tranform(step.orientation, (template_direction_choice)direction);
	
	step.Direction = tranform(step.Direction, (template_direction_choice)direction);

	if (step.X == invalidX) return;
	
	auto [x,y] = transform(step.X + x_off, step.Y + y_off, (template_direction_choice)direction);
	step.X = step.OriginalX = x;
	step.Y = step.OriginalY = y;
}
#pragma endregion othercontrol

#pragma region grid
void cMain::OnTemplateGridDoubleLeftClick(wxGridEvent& event)
{
	auto gridEntry = ExtractGridEntry(grid_template, event.GetRow());

	UpdateParameters(&gridEntry, event);
}

void cMain::OnTemplateGridRangeSelect(wxGridRangeSelectEvent& event)
{
	auto rows = grid_template->GetSelectedRows();
	if (rows.size() < 1)
	{
		btn_template_change_step->Disable();
		btn_template_delete_step->Disable();
		btn_template_move_down_step->Disable();
		btn_template_move_up_step->Disable();
		btn_template_add_to_steps_list->Enable(grid_template->GetNumberRows() > 0);
	}
	else if (rows.size() == 1)
	{
		btn_template_change_step->Enable();
		btn_template_delete_step->Enable();
		btn_template_move_down_step->Enable();
		btn_template_move_up_step->Enable();
		btn_template_add_to_steps_list->Enable();
	}
	else
	{
		btn_template_change_step->Disable();
		btn_template_delete_step->Enable();
		btn_template_move_down_step->Enable();
		btn_template_move_up_step->Enable();
		btn_template_add_to_steps_list->Enable();
	}
}
#pragma endregion grid
