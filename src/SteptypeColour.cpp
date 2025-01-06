#include <wx/clrpicker.h>

#include "Structures\StepType.h"

#include "SteptypeColour.h"
#include "Settings.h"

using json = nlohmann::json;

SteptypeColourHandler::SteptypeColourHandler(wxWindow* parent, wxGrid* steps, wxGrid* templates, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) :
	StepTypeColoursDialog(parent, id, title, pos, size, style)
{
	this->grids = {steps, templates};

	SteptypeToColour.resize(StepNames.size() + 1);
	DefaultColours();
	for (auto& [stepname, colour] : state.colours)
	{
		SteptypeToColour[ToStepType(stepname)] = sColour(colour);
	}
}

SteptypeColourHandler::~SteptypeColourHandler()
{
	for (auto& [name, picker] : mapCtrl)
	{
		picker->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(SteptypeColourHandler::OnSteptypeColoursPickerColourChanged), NULL, this);
	}
}

void SteptypeColourHandler::OnSteptypeColoursPickerColourChanged(wxColourPickerEvent& event)
{
	StepType type = e_stop;
	wxColour colour = wxColour("Black");

	for (auto& [stepname, picker] : mapCtrl)
	{
		if (picker == event.GetEventObject())
		{
			colour = picker->GetColour();
			type = ToStepType(stepname);
			SteptypeToColour[type] = sColour(colour);

			state.colours.insert_or_assign(stepname, colour.GetAsString());
			break;
		}
	}
	
	wxString stepname = wxString(StepNames[type]);
	for (auto grid : grids)
	{
		const int size = grid->GetNumberRows();
		for (int i = 0; i < size; i++)
		{
			auto value = grid->GetCellValue(i, 0);
			if (value == stepname)
			{
				grid->SetCellBackgroundColour(i, 0, colour);
			}
		}
	}
	
}

void SteptypeColourHandler::Build()
{
	DefaultColours();
	settings::setting s = settings::ReadSettingFile();

	for (auto& [stepname, colour] : state.colours)
	{
		if (s.colours.contains(stepname))
		{
			state.colours[stepname] = s.colours[stepname];
		}
	}

	enum gridtypes
	{
		unknown, Character, Building, Game
	};

	vector<std::tuple<wxGridSizer*, string, wxPanel*, wxSizer*, gridtypes> > grids = {
		{stc_character_grid_sizer, "Character", steptype_colour_character_panel, stc_character_sizer, Character},
		{stc_building_grid_sizer, "Building", steptype_colour_building_panel, stc_building_sizer, Building},
		{stc_game_grid_sizer, "Game", steptype_colour_game_panel, stc_game_sizer, Game}
	};

	vector<gridtypes> steptypeToGridtype{unknown};
	{
		steptypeToGridtype.resize(StepNames.size() + 1);

		steptypeToGridtype[e_stop] = Game;
		steptypeToGridtype[e_game_speed] = Game;
		steptypeToGridtype[e_pause] = Game;
		steptypeToGridtype[e_save] = Game;
		steptypeToGridtype[e_never_idle] = Game;
		steptypeToGridtype[e_keep_walking] = Game;
		steptypeToGridtype[e_keep_on_path] = Game;
		steptypeToGridtype[e_keep_crafting] = Game;

		steptypeToGridtype[e_build] = Building;
		steptypeToGridtype[e_recipe] = Building;
		steptypeToGridtype[e_limit] = Building;
		steptypeToGridtype[e_filter] = Building;
		steptypeToGridtype[e_rotate] = Building;
		steptypeToGridtype[e_priority] = Building;
		steptypeToGridtype[e_put] = Building;
		steptypeToGridtype[e_take] = Building;	
		steptypeToGridtype[e_launch] = Building;
		steptypeToGridtype[e_next] = Building;

		steptypeToGridtype[e_walk] = Character;
		steptypeToGridtype[e_mine] = Character;
		steptypeToGridtype[e_tech] = Character;
		steptypeToGridtype[e_drop] = Character;
		steptypeToGridtype[e_pick_up] = Character;
		steptypeToGridtype[e_craft] = Character;
		steptypeToGridtype[e_idle] = Character;
		steptypeToGridtype[e_cancel_crafting] = Character;
		steptypeToGridtype[e_shoot] = Character;
		steptypeToGridtype[e_equip] = Character;
		steptypeToGridtype[e_throw] = Character;
	}

	for (auto& [grid, menu, panel, outer_sizer, gridtype] : grids)
	{
		for (auto& [stepname, colour] : state.colours)
		{
			if (steptypeToGridtype[ToStepType(stepname)] != gridtype) continue; //paging

			wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
			wxStaticText* label = new wxStaticText(panel, wxID_ANY, wxString(stepname), wxDefaultPosition, wxSize(80, -1), wxALIGN_RIGHT);
			label->Wrap(75);
			sizer->Add(label, 0, wxALL, 5);
			wxColourPickerCtrl* input = new wxColourPickerCtrl(panel, wxID_ANY, wxColour(std::string(colour)), wxDefaultPosition, wxSize(70, -1), wxCLRP_DEFAULT_STYLE | wxCLRP_SHOW_LABEL);
			input->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(SteptypeColourHandler::OnSteptypeColoursPickerColourChanged), NULL, this);
			mapCtrl.insert({stepname, input});
			sizer->Add(input, 0, wxALL, 5);
			grid->Add(sizer);
		};
		panel->SetSizerAndFit(outer_sizer);
	}

	this->SetSizerAndFit(StepTypeColoursDialog_sizer);
}

void SteptypeColourHandler::DefaultColours()
{
	state.colours = {};
	for (int i = 0; i < StepNames.size(); i++)
	{
		state.colours[StepNames[i]] = DefaultColour(StepType(i)).GetAsString();
	}
}

void SteptypeColourHandler::OnCloseStepTypeColoursChanger(wxCloseEvent& event)
{
	settings::setting setting = settings::ReadSettingFile();
	setting.colours = state.colours;
	settings::SaveSettingFile(&setting);

	event.Skip();
}

void SteptypeColourHandler::OnInitStepTypeColoursDialog(wxInitDialogEvent& event)
{
	event.Skip();
}
