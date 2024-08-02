#pragma once

#include "cMain.h"

int cMain::HandleFocusMode_FindLastSaveStep(const int from)
{
	for (int i = from - 1; i >= 0; i--)
	{
		if (StepGridData[i].type == StepType::e_save && !StepGridData[i].Modifiers.skip)
			return i;
	}
	return 0;
}

void cMain::HandleFocusMode_HideSteps(const int to, const bool changed, const int row_count)
{
	if (to > 1)
	{
		grid_steps->BeginBatch();
		{
			for (int i = 0; i < to; i++)
			{
				grid_steps->HideRow(i);
				if (changed && i % 800 == 799)
				{
					grid_steps->EndBatch();
					this->Update();
					grid_steps->BeginBatch();
				}
			}
		}
		grid_steps->EndBatch();
	}

	for (int i = to; i < row_count; i++)
		grid_steps->ShowRow(i);
}

void cMain::HandleFocusMode_ShowSteps(const bool changed, const int row_count)
{
	grid_steps->BeginBatch();
	{
		for (int i = 0; i < row_count; i++)
		{
			grid_steps->ShowRow(i);
			if (changed && i % 800 == 799)
			{
				grid_steps->GoToCell(row_count - 1, 0);
				grid_steps->EndBatch();
				this->Update();
				grid_steps->BeginBatch();
			}
		}
	}
	grid_steps->EndBatch();
}

void cMain::HandleFocusMode(bool checked, bool changed)
{
	const int row_count = grid_steps->GetNumberRows();

	if (checked)
	{
		int last_save = HandleFocusMode_FindLastSaveStep(HandleFocusMode_FindLastSaveStep(row_count));
		HandleFocusMode_HideSteps(last_save, changed, row_count);
	}
	else
	{
		HandleFocusMode_ShowSteps(changed, row_count);
	}
}

void cMain::OnStepsFocusCheckbox(wxCommandEvent& event)
{
	const int row_count = grid_steps->GetNumberRows();
	auto selectedRows = grid_steps->GetSelectedRows();
	const int first_row_index = grid_steps->IsSelection() ? selectedRows[0] : row_count - 1;

	steps_focus_checkbox->Disable();
	{
		HandleFocusMode(event.IsChecked(), true);
		if (first_row_index != -1)
		{
			grid_steps->GoToCell(row_count - 1, 0);
			grid_steps->GoToCell(first_row_index - (first_row_index > 4 ? 3 : 0), 0); // move the grid to first selected row
		}
	}
	steps_focus_checkbox->Enable();
}
