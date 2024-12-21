#pragma once

#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "..\Structures\Step.h"
#include "..\DialogProgressBar.h"

#include "..\Data\utils.h"

#include "TasFileConstants.h"

using std::string;
using std::vector;
using std::map;

class SaveTas
{
public:
	bool Save(
		wxWindow* parent,
		DialogProgressBar* dialog_progress_bar,
		bool save_as,
		vector<bool> auto_list,
		vector<Step> steps,
		map<string, vector<Step>> templates,
		string folder_location,
		string folder_location_generate,
		string goal,
		log_config logconfig,
		wxGridBlockCoordsVector selected_rows,
		int import_into_row,
		bool set_last_location = true
	);

private:
	inline const char* const bool_to_string(bool b);
};
