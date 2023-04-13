#pragma once
#include <wx/string.h>
#include <wx/event.h>
#include <wx/grid.h>

#include <string>
#include <vector>
#include <tuple>

#include "Functions.h"

using std::string;
using std::vector;
using std::tuple;

struct Search
{
	static inline const vector<wxString> StepColumns = {"step", "x-cord", "y-cord", "units", "item", "orientation", "direction", "size", "amount", "comment"};

	static tuple<wxString, wxString> ExtractColon(const wxString& s);
	static tuple<vector<int>, wxString> HandleColon(const wxString& s);
	static vector<tuple<vector<int>, wxString>> HandleSearchString(wxCommandEvent& even);
	static bool TrySelectCurrent(wxGrid* grid, vector<tuple<vector<int>, wxString>> searchTerms, bool reverse);
	static bool TrySelectNext(wxCommandEvent& event, wxGrid* grid, vector<tuple<vector<int>, wxString>> searchTerms, bool reverse);
	static void FindCurrentOrNext(wxCommandEvent& event, wxGrid* grid, bool reverse);
	static void FindNext(wxCommandEvent& event, wxGrid* grid, bool reverse);
};