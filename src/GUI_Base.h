///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-234-gd93c9fc0)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include "TypePanel.h"
#include "ImportStepsPanel.h"
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/radiobox.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/clrpicker.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <wx/srchctrl.h>
#include <wx/valtext.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/dialog.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUI_Base
///////////////////////////////////////////////////////////////////////////////
class GUI_Base : public wxFrame
{
	private:

	protected:
		wxMenuBar* main_menubar;
		wxMenu* menu_file;
		wxMenu* menu_script;
		wxMenu* menu_shortcuts;
		wxMenu* menu_goals;
		wxMenu* menu_auto_close;
		wxPanel* detail_panel;
		wxStaticText* label_x_cord;
		wxSpinCtrlDouble* spin_x;
		wxStaticText* label_y_cord;
		wxSpinCtrlDouble* spin_y;
		wxStaticText* label_amount;
		wxSpinCtrl* spin_amount;
		wxStaticText* label_comment;
		wxTextCtrl* txt_comment;
		wxStaticText* label_item;
		wxComboBox* cmb_item;
		wxStaticText* label_from_into;
		wxComboBox* cmb_from_into;
		wxStaticText* label_input;
		wxRadioBox* radio_input;
		wxStaticText* label_output;
		wxRadioBox* radio_output;
		wxStaticText* label_building_orientation;
		wxComboBox* cmb_building_orientation;
		wxStaticText* label_direction_to_build;
		wxComboBox* cmb_direction_to_build;
		wxStaticText* label_building_size;
		wxSpinCtrl* spin_building_size;
		wxStaticText* label_amount_of_buildings;
		wxSpinCtrl* spin_building_amount;
		TypePanel* type_panel;
		wxRadioButton* rbtn_take;
		wxRadioButton* rbtn_put;
		wxRadioButton* rbtn_game_speed;
		wxRadioButton* rbtn_craft;
		wxRadioButton* rbtn_walk;
		wxRadioButton* rbtn_mine;
		wxRadioButton* rbtn_pause;
		wxRadioButton* rbtn_build;
		wxRadioButton* rbtn_recipe;
		wxRadioButton* rbtn_tech;
		wxRadioButton* rbtn_limit;
		wxRadioButton* rbtn_idle;
		wxRadioButton* rbtn_filter;
		wxRadioButton* rbtn_stop;
		wxRadioButton* rbtn_priority;
		wxRadioButton* rbtn_rotate;
		wxRadioButton* rbtn_pick_up;
		wxRadioButton* rbtn_drop;
		wxRadioButton* rbtn_launch;
		wxRadioButton* rbtn_save;
		wxRadioButton* rbtn_cancel_crafting;
		wxPanel* auto_put_panel;
		wxCheckBox* check_furnace;
		wxCheckBox* check_burner;
		wxCheckBox* check_lab;
		wxCheckBox* check_recipe;
		wxColourPickerCtrl* step_colour_picker;
		wxAuiNotebook* main_book;
		wxPanel* template_panel;
		wxStaticText* label_choose_template;
		wxComboBox* cmb_choose_template;
		wxButton* btn_template_new;
		wxButton* btn_template_delete;
		wxButton* btn_template_change_step;
		wxButton* btn_template_delete_step;
		wxButton* btn_template_move_up_step;
		wxButton* btn_template_move_down_step;
		wxStaticLine* m_staticline51;
		wxButton* btn_template_add_to_steps_list;
		wxButton* btn_template_add_from_steps_list;
		wxStaticText* label_template_amount_offset;
		wxSpinCtrl* spin_amount_offset;
		wxStaticText* label_template_amount_multiplier;
		wxSpinCtrl* spin_amount_multiplier;
		wxStaticText* label_template_x_offset;
		wxSpinCtrl* spin_x_offset;
		wxStaticText* label_template_y_offset;
		wxSpinCtrl* spin_y_offset;
		wxGrid* grid_template;
		wxPanel* step_panel;
		wxSearchCtrl* step_search_ctrl;
		wxCheckBox* step_search_toggle_updown;
		wxButton* btn_add_step;
		wxButton* btn_change_step;
		wxButton* btn_delete_step;
		wxButton* btn_move_up;
		wxButton* btn_move_down;
		wxGrid* grid_steps;
		ImportStepsPanel* import_steps_panel;
		wxSpinCtrl* import_steps_into_steps_ctrl;
		wxButton* import_steps_into_steps_btn;
		wxTextCtrl* import_steps_into_template_ctrl;
		wxButton* import_steps_into_template_btn;
		wxCheckBox* import_steps_clear_checkbox;
		wxTextCtrl* import_steps_text_import;

		// Virtual event handlers, override them in your derived class
		virtual void OnApplicationClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnMenuNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChooseLocation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGenerateScript( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOnlyGenerateSteps( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeShortcutMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCraftMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGameSpeedMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRotateMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRecipeMenuChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMineMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBuildMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTechMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTakeMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPutMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnIdleMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPriorityMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLimitMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPickUpMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDropMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLaunchMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPauseMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveUpMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveDownMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelCraftingMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSteelAxeClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuGOTLAPClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAnyPercentClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuDebugClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseGenerateScriptClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseOpenClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseSaveClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseSaveAsClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTakeChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPutChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGameSpeedChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCraftChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMineChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPauseChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBuildChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRecipeChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTechChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLimitChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnIdleChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnfilterChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPriorityChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRotateChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPickUpChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDropChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLaunchChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelCraftingChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStepColourPickerColourChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void OnTemplateChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewTemplateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteTemplateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateChangeStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateDeleteStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateMoveUpClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateMoveDownClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateAddToStepsListClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateAddFromStepsListClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateGridDoubleLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void StepSeachOnCancelButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void StepSeachOnSearchButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void StepSeachOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void StepSeachOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddStepRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnChangeStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveUpClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveUpFiveClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnMoveDownClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveDownFiveClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnStepsGridDoubleLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void OnStepsGridRangeSelect( wxGridRangeSelectEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsCtrl( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsCtrlEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoTemplateCtrlText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoTemplateCtrlEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoTemplateBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsTextUpdate( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString import_steps_into_template_ctrl_validator;

		GUI_Base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Factorio TAS Generator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1840,1080 ), long style = wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		wxAuiManager m_mgr;

		~GUI_Base();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Shortcut_changer
///////////////////////////////////////////////////////////////////////////////
class Shortcut_changer : public wxDialog
{
	private:

	protected:
		wxBoxSizer* sc_vertical_sizer;
		wxStaticText* sc_help_label;
		wxGridSizer* sc_grid_sizer;
		wxButton* sc_reset_button;
		wxButton* sc_save_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCloseShortcutChanger( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnInitDialogShortcutChanger( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnButtonClickSCReset( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClickSCSave( wxCommandEvent& event ) { event.Skip(); }


	public:

		Shortcut_changer( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Change shortcuts"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSTAY_ON_TOP|wxBORDER_RAISED|wxTAB_TRAVERSAL );

		~Shortcut_changer();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseForDialogProgress
///////////////////////////////////////////////////////////////////////////////
class BaseForDialogProgress : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel7;
		wxStaticText* txt_dialog_text;
		wxGauge* progress_bar;
		wxButton* btn_dialog_progress_done;

		// Virtual event handlers, override them in your derived class
		virtual void GenerateScriptOnClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseForDialogProgress( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Generating Script"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~BaseForDialogProgress();

};

