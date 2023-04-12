#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "GUI_Base.h"
#include "Settings.h"

/// <summary>
/// Class to handle changing shortcuts. Shortcuts are found in the 3rd menu point
/// </summary>
class ShortcutChanger : public Shortcut_changer
{
public:
	ShortcutChanger(wxWindow* parent,
        wxWindowID id = wxID_ANY, 
        const wxString& title = wxT("Change shortcuts"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxCAPTION | wxCLOSE_BOX | wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP | wxBORDER_DEFAULT) : Shortcut_changer(parent, id, title, pos, size, style) {}
    ~ShortcutChanger() {}

    /// <summary>
    /// Builds the dialog box using the shortcut menu and settings file
    /// </summary>
    /// <param name="menu_shortcuts">Pointer to the shortcut menu, used to strip both their label and keybinding</param>
    void Build(wxMenuBar* menu_shortcuts);

    wxMenuBar* menu;
    std::map<std::string, wxTextCtrl*> mapCtrl = {};
    settings::setting state;

    /// <summary>
    /// Used after building the GUI to update shortcuts from the settings file
    /// </summary>
    /// <param name="menu_shortcuts">The shortcut menu where the keybinds should be updated</param>
    static inline void UpdateShortcutsFromFile(wxMenu* menu_shortcuts)
    {
        try
        {
            settings::setting s = settings::ReadSettingFile();
            // For each shortcut in the settings file
            for (auto& [_menu, map] : s.shortcuts)
            {
                for (auto& [key, value] : map)
                {
                    for (auto& a : menu_shortcuts->GetMenuItems())
                    {
                        // Try to find a matching menu point
                        if (a->GetItemLabel().StartsWith(key))
                        {
                            // If one is found
                            // Change the last part of the label containing the shortcut
                            // Which incidentally also updates the keybind
                            a->SetItemLabel(key + wxT('\t') + value);
                        }
                    }
                }
            }
        } catch (...) { } // ignore all errors
    }

protected:
    //Create state json from the shortcut menu
    void DefaultShortcuts();

    //Event handler for closing the dialog, where the json state gets saved in settings file
    void OnCloseShortcutChanger(wxCloseEvent& event);

    void OnInitDialogShortcutChanger(wxInitDialogEvent& event);
    
    //Event handler for clicking reset. Resetting the input fields to the state json. 
    void OnButtonClickSCReset(wxCommandEvent& event);
    //Event handler for clicking the save button. Saving the values of the input fields to the state json and updates shortcut keybinds.
    void OnButtonClickSCSave(wxCommandEvent& event);
};
