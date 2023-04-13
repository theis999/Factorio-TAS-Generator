#include "ShortcutChanger.h"

using json = nlohmann::json;

void ShortcutChanger::Build(wxMenuBar* menu)
{
	this->menu = menu;

	DefaultShortcuts();
	settings::setting s = settings::ReadSettingFile();
	
	for (auto& [menu, map] : state.shortcuts)
	{
		for (auto& [key, value] : map)
		{
			if (s.shortcuts[menu].contains(key))
				continue;
			else
				s.shortcuts[menu][key] = value;
		}
	}

	state = s;

	vector<std::tuple<wxGridSizer*, string, wxPanel*, wxSizer*> > grids = {
		{sc_grid_sizer_file, "File", sc_panel_file, sc_file_sizer},
		{sc_grid_sizer_script, "Script", sc_panel_script, sc_script_sizer},
		{sc_grid_sizer_shortcuts, "Shortcuts", sc_panel_shortcuts, sc_shortcuts_sizer},
		{sc_grid_sizer_goals, "Goal", sc_panel_goals, sc_goal_sizer},
		{sc_grid_sizer_auto, "Auto-close", sc_panel_auto, sc_auto_sizer},
	};

	for (auto&[grid, menu, panel, outer_sizer] : grids)
	{
		for (auto& [key, value] : state.shortcuts[menu])
		{
			wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
			wxStaticText* label = new wxStaticText(panel, wxID_ANY, wxString(key), wxDefaultPosition, wxSize(80, -1), 0);
			label->Wrap(60);
			sizer->Add(label, 0, wxALL, 5);
			wxTextCtrl* input = new wxTextCtrl(panel, wxID_ANY, wxString(std::string(value)), wxDefaultPosition, wxSize(100, -1), 0);
			mapCtrl.insert({key, input});
			sizer->Add(input, 0, wxALL, 5);
			grid->Add(sizer);
		};
		panel->SetSizerAndFit(outer_sizer);
	}
	//create grid entry for each shortcut
	
	this->SetSizerAndFit(sc_vertical_sizer);
}

void ShortcutChanger::DefaultShortcuts()
{
	for (int i = 0; i < menu->GetMenuCount(); i++) 
	{
		auto sub_menu = menu->GetMenu(i);
		auto menulabel = menu->GetMenuLabel(i).ToStdString();
		state.shortcuts[menulabel] = {};

		//iterate through the shortcut menu to get some default values
		for (auto a : sub_menu->GetMenuItems())
		{
			auto b = wxSplit(a->GetItemLabel(), wxT('\t'));
			if (b.empty()) continue;

			state.shortcuts[menulabel][b[0].ToStdString()] = b.size() > 1 ? b[1].ToStdString() : "";
		}
	}
}

void ShortcutChanger::OnCloseShortcutChanger(wxCloseEvent& event)
{
	settings::SaveSettingFile(&state);

	event.Skip();
}

void ShortcutChanger::OnInitDialogShortcutChanger(wxInitDialogEvent& event)
{
	event.Skip();
}

void ShortcutChanger::OnButtonClickSCReset(wxCommandEvent& event)
{
	DefaultShortcuts();
	for (auto&[menu, map] : state.shortcuts) {
		for (auto& [key, value] : map)
		{
			auto& a = value;
			wxTextCtrl* input = mapCtrl[key];
			input->SetValue(a);
		}
	}
	event.Skip();
}

void ShortcutChanger::OnButtonClickSCSave(wxCommandEvent& event)
{
	for (auto& [_menu, map] : state.shortcuts)
	{
		for (auto& [key, value] : map)
		{
			wxTextCtrl* input = mapCtrl[key];
			if (input == nullptr) continue;

			value = input->GetValue().ToStdString();
			for (int i = 0; i < menu->GetMenuCount(); i++)
			{
				auto sub_menu = menu->GetMenu(i);
				for (auto& a : sub_menu->GetMenuItems())
				{
					if (a->GetItemLabel().StartsWith(key))
					{
						a->SetItemLabel(key + wxT('\t') + input->GetValue());
					}
				}
			}
		}
	}
	event.Skip();
}

