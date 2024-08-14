#pragma once

#include "wx/wx.h"
#include "vector"
using std::vector;

class HighlightRowThread : public wxThread
{
public:
	int row; wxFrame* main;
	HighlightRowThread(int row, wxFrame* main);

	wxThread::ExitCode Entry();
};

class HighlightRowsThread : public wxThread
{
public:
	vector<int> rows; wxFrame* main;
	HighlightRowsThread(vector<int> rows, wxFrame* main);

	wxThread::ExitCode Entry();
};