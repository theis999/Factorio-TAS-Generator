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
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/choice.h>
#include <wx/grid.h>
#include <wx/srchctrl.h>
#include <wx/clrpicker.h>
#include <wx/valtext.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
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
		wxMenu* menu_steptypes;
		wxMenuItem* steptypecolour_changer;
		wxMenu* menu_shortcuts;
		wxMenu* menu_goals;
		wxMenu* menu_loglevel;
		wxMenuItem* logging_savegame;
		wxMenuItem* logging_tech;
		wxMenuItem* logging_comment;
		wxMenu* menu_auto_close;
		wxMenu* menu_other;
		wxMenuItem* legacy_mining;
		wxMenuItem* intermediate_walk_towards;
		wxMenuItem* no_intermediate_walk;
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
		wxPanel* character_panel;
		wxRadioButton* rbtn_walk;
		wxRadioButton* rbtn_craft;
		wxRadioButton* rbtn_tech;
		wxRadioButton* rbtn_idle;
		wxRadioButton* rbtn_pick_up;
		wxRadioButton* rbtn_drop;
		wxRadioButton* rbtn_cancel_crafting;
		wxRadioButton* rbtn_mine;
		wxRadioButton* rbtn_throw;
		wxRadioButton* rbtn_shoot;
		wxRadioButton* rbtn_equip;
		wxRadioButton* rbtn_character_panel_hidden;
		wxPanel* building_panel;
		wxRadioButton* rbtn_take;
		wxRadioButton* rbtn_put;
		wxRadioButton* rbtn_build;
		wxRadioButton* rbtn_recipe;
		wxRadioButton* rbtn_limit;
		wxRadioButton* rbtn_filter;
		wxRadioButton* rbtn_priority;
		wxRadioButton* rbtn_launch;
		wxRadioButton* rbtn_rotate;
		wxRadioButton* rbtn_next;
		wxRadioButton* rbtn_building_panel_hidden;
		wxPanel* game_panel;
		wxRadioButton* rbtn_game_speed;
		wxRadioButton* rbtn_pause;
		wxRadioButton* rbtn_stop;
		wxRadioButton* rbtn_save;
		wxRadioButton* rbtn_never_idle;
		wxRadioButton* rbtn_keep_walking;
		wxRadioButton* rbtn_keep_on_path;
		wxRadioButton* rbtn_keep_crafting;
		wxRadioButton* rbtn_game_panel_hidden;
		wxPanel* auto_put_panel;
		wxCheckBox* check_furnace;
		wxCheckBox* check_burner;
		wxCheckBox* check_lab;
		wxCheckBox* check_recipe;
		wxPanel* step_modifier_panel;
		wxBoxSizer* sizer_no_order;
		wxCheckBox* modifier_no_order_checkbox;
		wxButton* modifier_no_order_button;
		wxBoxSizer* sizer_skip;
		wxCheckBox* modifier_skip_checkbox;
		wxButton* modifier_skip_button;
		wxCheckBox* modifier_wait_for_checkbox;
		wxBoxSizer* sizer_force;
		wxCheckBox* modifier_force_checkbox;
		wxButton* modifier_force_button;
		wxCheckBox* modifier_cancel_checkbox;
		wxCheckBox* modifier_split_checkbox;
		wxCheckBox* modifier_walk_towards_checkbox;
		wxCheckBox* modifier_all_checkbox;
		wxPanel* walk_panel;
		wxSpinCtrlDouble* walk_panel_increment_spin;
		wxPanel* walk_panel_grid_panel;
		wxButton* walk_panel_button_upleft;
		wxButton* walk_panel_button_up;
		wxButton* walk_panel_button_upright;
		wxButton* walk_panel_button_left;
		wxButton* walk_panel_button_right;
		wxButton* walk_panel_button_downleft;
		wxButton* walk_panel_button_down;
		wxButton* walk_panel_button_downright;
		wxAuiNotebook* main_book;
		wxPanel* template_panel;
		wxComboBox* cmb_choose_template;
		wxButton* btn_template_new;
		wxButton* btn_template_delete;
		wxButton* btn_template_add_step;
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
		wxStaticLine* m_staticline2;
		wxStaticText* label_template_x_offset;
		wxSpinCtrl* spin_x_offset;
		wxStaticText* label_template_y_offset;
		wxSpinCtrl* spin_y_offset;
		wxSpinCtrl* spin_template_iterator;
		wxChoice* choice_template_direction;
		wxGrid* grid_template;
		wxPanel* step_panel;
		wxSearchCtrl* step_search_ctrl;
		wxCheckBox* step_search_toggle_updown;
		wxButton* step_split_multibuild_button;
		wxColourPickerCtrl* step_colour_picker;
		wxCheckBox* steps_focus_checkbox;
		wxButton* btn_add_step;
		wxButton* btn_change_step;
		wxButton* btn_delete_step;
		wxButton* btn_move_up;
		wxButton* btn_move_down;
		wxGrid* grid_steps;
		ImportStepsPanel* import_steps_panel;
		wxButton* import_steps_into_steps_index_btn;
		wxSpinCtrl* import_steps_into_steps_ctrl;
		wxButton* import_steps_into_steps_btn;
		wxTextCtrl* import_steps_into_template_ctrl;
		wxButton* import_steps_into_template_btn;
		wxCheckBox* import_steps_clear_checkbox;
		wxTextCtrl* import_steps_text_import;
		wxPanel* reorder_panel;
		wxButton* reorder_reorder_button;
		wxCheckBox* reorder_text_input_clear_checkbox;
		wxButton* reorder_locator_button;
		wxTextCtrl* reorder_text_input;

		// Virtual event handlers, override them in your derived class
		virtual void OnApplicationClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnMenuNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChooseLocation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGenerateScript( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeSteptypeColoursMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCraftMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTechMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnIdleMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPickUpMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDropMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelCraftingMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMineMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnThrowMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShootMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEquipMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTakeMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPutMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBuildMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRecipeMenuChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLimitMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPriorityMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLaunchMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRotateMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGameSpeedMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPauseMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNeverIdleMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepWalkingMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepOnPathMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepCraftingMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeShortcutMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddAltMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeAltMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteAltMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveUpMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveUpAltMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveDownMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveDownAltMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSearchMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUndoMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRedoMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSteelAxeClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuGOTLAPClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAnyPercentClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSupplyChallengeClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoggingSavegameSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoggingTechSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoggingCommentSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuLogDebugSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuLogDevelopmentSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuLogReleaseSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseGenerateScriptClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseOpenClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseSaveClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAutoCloseSaveAsClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCraftChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTechChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnIdleChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPickUpChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDropChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelCraftingChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMineChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnThrowChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShootChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEquipChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTakeChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPutChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBuildChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRecipeChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLimitChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnfilterChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPriorityChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLaunchChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRotateChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNextChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGameSpeedChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPauseChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNeverIdleChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepWalkingChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepOnPathChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeepCraftingChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNoOrderClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNoOrderRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnSkipClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnForceClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSkipRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnUpLeftClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnUpClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnUpRightClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnLeftClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnRightClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnDownLeftClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnDownClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWalkPanelBtnDownRightClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMainBookPageChanged( wxAuiNotebookEvent& event ) { event.Skip(); }
		virtual void OnTemplateChosen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewTemplateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteTemplateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteTemplateRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnTemplateAddStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateChangeStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateDeleteStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateMoveUpClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateMoveDownClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateAddToStepsListClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateAddFromStepsListClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTemplateGridDoubleLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void OnTemplateGridRangeSelect( wxGridRangeSelectEvent& event ) { event.Skip(); }
		virtual void StepSeachOnCancelButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void StepSeachOnSearchButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void StepSeachOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void StepSeachOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSplitMultibuildClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSplitMultibuildRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnStepColourPickerColourChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void OnStepsFocusCheckbox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddStepRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnChangeStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeStepRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnDeleteStepClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteStepRightClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnMoveUpClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveUpFiveClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnMoveDownClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveDownFiveClicked( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnStepsGridCellChange( wxGridEvent& event ) { event.Skip(); }
		virtual void OnStepsGridRightClick( wxGridEvent& event ) { event.Skip(); }
		virtual void OnStepsGridEditorHidden( wxGridEvent& event ) { event.Skip(); }
		virtual void OnStepsGridEditorShown( wxGridEvent& event ) { event.Skip(); }
		virtual void OnStepsGridRangeSelect( wxGridRangeSelectEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsIndexBtnClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsIndexBtnRight( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsCtrl( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsCtrlEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoStepsBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoTemplateCtrlText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoTemplateCtrlEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsIntoTemplateBtnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportStepsTextUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReorderReorderButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReorderLocatorButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReorderTextUpdate( wxCommandEvent& event ) { event.Skip(); }


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
		wxListbook* sc_item_book;
		wxPanel* sc_panel_file;
		wxBoxSizer* sc_file_sizer;
		wxFlexGridSizer* sc_grid_sizer_file;
		wxPanel* sc_panel_script;
		wxBoxSizer* sc_script_sizer;
		wxFlexGridSizer* sc_grid_sizer_script;
		wxPanel* sc_panel_steptypes;
		wxBoxSizer* sc_steptypes_sizer;
		wxFlexGridSizer* sc_grid_sizer_steptypes;
		wxPanel* sc_panel_shortcuts;
		wxBoxSizer* sc_shortcuts_sizer;
		wxFlexGridSizer* sc_grid_sizer_shortcuts;
		wxPanel* sc_panel_goals;
		wxBoxSizer* sc_goal_sizer;
		wxFlexGridSizer* sc_grid_sizer_goals;
		wxPanel* sc_panel_auto;
		wxBoxSizer* sc_auto_sizer;
		wxFlexGridSizer* sc_grid_sizer_auto;
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

///////////////////////////////////////////////////////////////////////////////
/// Class StepTypeColoursDialog
///////////////////////////////////////////////////////////////////////////////
class StepTypeColoursDialog : public wxDialog
{
	private:

	protected:
		wxBoxSizer* StepTypeColoursDialog_sizer;
		wxStaticText* steptype_colour_label;
		wxListbook* steptype_colour_book;
		wxPanel* steptype_colour_character_panel;
		wxBoxSizer* stc_character_sizer;
		wxFlexGridSizer* stc_character_grid_sizer;
		wxPanel* steptype_colour_building_panel;
		wxBoxSizer* stc_building_sizer;
		wxFlexGridSizer* stc_building_grid_sizer;
		wxPanel* steptype_colour_game_panel;
		wxBoxSizer* stc_game_sizer;
		wxFlexGridSizer* stc_game_grid_sizer;

		// Virtual event handlers, override them in your derived class
		virtual void OnCloseStepTypeColoursChanger( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnInitStepTypeColoursDialog( wxInitDialogEvent& event ) { event.Skip(); }


	public:

		StepTypeColoursDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Step type colours"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxBORDER_RAISED|wxTAB_TRAVERSAL );

		~StepTypeColoursDialog();

};

