#pragma once

#include "HighlighterThreads.h"
#include "cMain.h"

HighlightRowThread::HighlightRowThread(int _row, wxFrame* _main)
{
	row = _row; main = _main;
}

wxThread::ExitCode HighlightRowThread::Entry()
{
	cMain* m = (cMain*)main;
	bool select = m->HighlightRow(row);
	Sleep(100);
	m->HighlightRowUndo(row, select);
	return 0;
}

HighlightRowsThread::HighlightRowsThread(vector<int> _rows, wxFrame* _main)
{
	main = _main; rows = _rows;
}

wxThread::ExitCode HighlightRowsThread::Entry()
{
	Sleep(50);
	cMain* m = (cMain*)main;
	vector<bool> selected{};
	for (auto row : rows)
		selected.push_back(m->HighlightRow(row));
	Sleep(100);
	for (int i = 0; i < rows.size(); i++)
		m->HighlightRowUndo(rows[i], selected[i]);
	return 0;
}

void cMain::HighlightRowUndo(int row, bool select)
{
	wxColour c = wxColour("Window");
	for (int i = 0; i < 11; i++)
	{
		grid_steps->SetCellBackgroundColour(row, i, c);
	}
	BackgroundColorUpdate(grid_steps, row, StepGridData[row]);
	if (select) grid_steps->SelectRow(row, true);
	grid_steps->ForceRefresh();
}
bool cMain::HighlightRow(int row)
{
	wxColour c = wxColour("Green");
	for (int i = 0; i < 11; i++)
	{
		grid_steps->SetCellBackgroundColour(row, i, c);
		
	}
	grid_steps->ForceRefresh();
	bool select = grid_steps->IsInSelection(row, 0);
	if (select) grid_steps->DeselectRow(row);
	return select;
}

HighlightInputControlChangedThread::HighlightInputControlChangedThread(vector<wxControl*> _ctrls)
{
	ctrls = _ctrls;
}

wxThread::ExitCode HighlightInputControlChangedThread::Entry()
{
	for (auto ctrl : ctrls)
	{
		ctrl->SetForegroundColour(wxColour("Green"));
		ctrl->Refresh();
	}
	Sleep(250);
	for (auto ctrl : ctrls)
	{
		ctrl->SetForegroundColour(wxColour("Window"));
		ctrl->Refresh();
	}
	return 0;
}
