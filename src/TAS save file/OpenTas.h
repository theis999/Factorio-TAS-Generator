#pragma once

#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "..\Shared functions\Functions.h"

#include "..\Structures\Step.h"

#include "..\Data\utils.h"

#include "..\DialogProgressBar.h"

#include "TasFileConstants.h"

using std::string;
using std::vector;
using std::map;
using std::pair;

struct open_file_return_data
{
	bool success = false;
	string goal;
	vector<Step> steps;
	map<string, vector<Step>> template_map;
	string save_file_location;
	string generate_code_folder_location;

	wxGridBlockCoordsVector selected_rows;
	int import_into_row = -1;

	struct
	{
		bool generate_script = false,
			open = false,
			save = false,
			save_as = false;
	} auto_close;

	log_config logconfig;
	generate_config generateConfig;

	WarningsStatesCounters warnings_states_counters;
};

struct OpenTAS
{
	enum Category
	{
		Invalid,
		Group,
		Template
	};
} ;

class OpenTas
{
public:
	open_file_return_data* Open(DialogProgressBar* dialog_progress_bar, std::ifstream& file);

private:
	open_file_return_data return_data;

	vector<string> segments;

	vector<Building> buildingSnapshot;

	int total_lines = 0;
	int lines_processed = 0;

	void reset();

	bool extract_total_steps(std::ifstream& file);
	bool extract_goal(std::ifstream& file);
	OpenTAS::Category extract_steps(std::ifstream& file, DialogProgressBar* dialog_progress_bar);
	bool extract_groups(std::ifstream& file, DialogProgressBar* dialog_progress_bar);
	bool extract_templates(std::ifstream& file, DialogProgressBar* dialog_progress_bar);
	bool extract_save_location(std::ifstream& file);
	bool extract_script_location(std::ifstream& file);
	bool extract_auto_close(std::ifstream& file);
	bool extract_generate_config(std::ifstream& file);
	bool extract_log_config(std::ifstream & file);

	Step ReadStep(const size_t, int&, std::vector<string>::iterator);
	bool update_segment(std::ifstream& file);
};
