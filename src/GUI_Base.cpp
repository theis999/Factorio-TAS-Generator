///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-234-gd93c9fc0)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI_Base.h"

///////////////////////////////////////////////////////////////////////////

GUI_Base::GUI_Base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	main_menubar = new wxMenuBar( 0 );
	menu_file = new wxMenu();
	wxMenuItem* menu_file_new;
	menu_file_new = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("New") ) + wxT('\t') + wxT("CTRL+N"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menu_file_new );

	wxMenuItem* menu_file_open;
	menu_file_open = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Open") ) + wxT('\t') + wxT("CTRL+O"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menu_file_open );

	wxMenuItem* menu_file_save;
	menu_file_save = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menu_file_save );

	wxMenuItem* menu_file_save_as;
	menu_file_save_as = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Save As") ) + wxT('\t') + wxT("CTRL+SHIFT+S"), wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menu_file_save_as );

	wxMenuItem* menu_file_exit;
	menu_file_exit = new wxMenuItem( menu_file, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( menu_file_exit );

	main_menubar->Append( menu_file, wxT("File") );

	menu_script = new wxMenu();
	wxMenuItem* menu_script_choose_location;
	menu_script_choose_location = new wxMenuItem( menu_script, wxID_ANY, wxString( wxT("Choose Location") ) , wxEmptyString, wxITEM_NORMAL );
	menu_script->Append( menu_script_choose_location );

	wxMenuItem* menu_script_generate_script;
	menu_script_generate_script = new wxMenuItem( menu_script, wxID_ANY, wxString( wxT("Generate Script") ) + wxT('\t') + wxT("Alt+G"), wxEmptyString, wxITEM_NORMAL );
	menu_script->Append( menu_script_generate_script );

	wxMenuItem* menu_script_only_generate_steps;
	menu_script_only_generate_steps = new wxMenuItem( menu_script, wxID_ANY, wxString( wxT("Only Generate Steps File") ) , wxEmptyString, wxITEM_CHECK );
	menu_script->Append( menu_script_only_generate_steps );

	main_menubar->Append( menu_script, wxT("Script") );

	menu_shortcuts = new wxMenu();
	wxMenuItem* shortcut_changer;
	shortcut_changer = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Change shortcuts") ) , wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_changer );

	wxMenuItem* shortcut_craft;
	shortcut_craft = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Craft") ) + wxT('\t') + wxT("Ctrl+1"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_craft );

	wxMenuItem* shortcut_walk;
	shortcut_walk = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Walk") ) + wxT('\t') + wxT("Ctrl+2"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_walk );

	wxMenuItem* shortcut_game_speed;
	shortcut_game_speed = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Game Speed") ) + wxT('\t') + wxT("Ctrl+3"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_game_speed );

	wxMenuItem* shortcut_rotate;
	shortcut_rotate = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Rotate") ) + wxT('\t') + wxT("Ctrl+4"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_rotate );

	wxMenuItem* shortcut_recipe;
	shortcut_recipe = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Recipe") ) + wxT('\t') + wxT("Ctrl+5"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_recipe );

	wxMenuItem* shortcut_stop;
	shortcut_stop = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Stop") ) + wxT('\t') + wxT("Ctrl+6"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_stop );

	wxMenuItem* shortcut_mine;
	shortcut_mine = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Mine") ) + wxT('\t') + wxT("Alt+1"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_mine );

	wxMenuItem* shortcut_build;
	shortcut_build = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Build") ) + wxT('\t') + wxT("Alt+2"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_build );

	wxMenuItem* shortcut_tech;
	shortcut_tech = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Tech") ) + wxT('\t') + wxT("Alt+3"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_tech );

	wxMenuItem* shortcut_take;
	shortcut_take = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Take") ) + wxT('\t') + wxT("Alt+4"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_take );

	wxMenuItem* shortcut_put;
	shortcut_put = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Put") ) + wxT('\t') + wxT("Alt+5"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_put );

	wxMenuItem* shortcut_idle;
	shortcut_idle = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Idle") ) + wxT('\t') + wxT("Alt+6"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_idle );

	wxMenuItem* shortcut_priority;
	shortcut_priority = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Priority") ) + wxT('\t') + wxT("Shift+1"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_priority );

	wxMenuItem* shortcut_limit;
	shortcut_limit = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Limit") ) + wxT('\t') + wxT("Shift+2"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_limit );

	wxMenuItem* shortcut_filter;
	shortcut_filter = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Filter") ) + wxT('\t') + wxT("Shift+3"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_filter );

	wxMenuItem* shortcut_pick_up;
	shortcut_pick_up = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Pick Up") ) + wxT('\t') + wxT("Shift+4"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_pick_up );

	wxMenuItem* shortcut_drop;
	shortcut_drop = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Drop") ) + wxT('\t') + wxT("Shift+5"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_drop );

	wxMenuItem* shortcut_launch;
	shortcut_launch = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Launch") ) + wxT('\t') + wxT("Shift+6"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_launch );

	wxMenuItem* shortcut_Save;
	shortcut_Save = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("Alt+Q"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_Save );

	wxMenuItem* shortcut_pause;
	shortcut_pause = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Pause") ) + wxT('\t') + wxT("Alt+R"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_pause );

	wxMenuItem* shortcut_add_step;
	shortcut_add_step = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Add Step") ) + wxT('\t') + wxT("Alt+A"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_add_step );

	wxMenuItem* shortcut_change_step;
	shortcut_change_step = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Change Step") ) + wxT('\t') + wxT("Alt+C"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_change_step );

	wxMenuItem* shortcut_delete_step;
	shortcut_delete_step = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Delete Step") ) + wxT('\t') + wxT("Del"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_delete_step );

	wxMenuItem* shortcut_move_up;
	shortcut_move_up = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Move Up") ) + wxT('\t') + wxT("Alt+W"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_move_up );

	wxMenuItem* shortcut_move_down;
	shortcut_move_down = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Move Down") ) + wxT('\t') + wxT("Alt+S"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_move_down );

	wxMenuItem* shortcut_cancel_crafting;
	shortcut_cancel_crafting = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Cancel Crafting") ) + wxT('\t') + wxT("Shift+1"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_cancel_crafting );

	main_menubar->Append( menu_shortcuts, wxT("Shortcuts") );

	menu_goals = new wxMenu();
	wxMenuItem* goal_steelaxe;
	goal_steelaxe = new wxMenuItem( menu_goals, wxID_ANY, wxString( wxT("Steel Axe") ) , wxEmptyString, wxITEM_RADIO );
	menu_goals->Append( goal_steelaxe );
	goal_steelaxe->Check( true );

	wxMenuItem* goal_GOTLAP;
	goal_GOTLAP = new wxMenuItem( menu_goals, wxID_ANY, wxString( wxT("Getting On Track Like A Pro") ) , wxEmptyString, wxITEM_RADIO );
	menu_goals->Append( goal_GOTLAP );

	wxMenuItem* goal_any_percent;
	goal_any_percent = new wxMenuItem( menu_goals, wxID_ANY, wxString( wxT("Any %") ) , wxEmptyString, wxITEM_RADIO );
	menu_goals->Append( goal_any_percent );

	wxMenuItem* goal_debug;
	goal_debug = new wxMenuItem( menu_goals, wxID_ANY, wxString( wxT("Debug") ) , wxEmptyString, wxITEM_RADIO );
	menu_goals->Append( goal_debug );

	main_menubar->Append( menu_goals, wxT("Goal") );

	menu_auto_close = new wxMenu();
	wxMenuItem* auto_close_generate_script;
	auto_close_generate_script = new wxMenuItem( menu_auto_close, wxID_ANY, wxString( wxT("Generate Script") ) , wxEmptyString, wxITEM_CHECK );
	menu_auto_close->Append( auto_close_generate_script );
	auto_close_generate_script->Check( true );

	wxMenuItem* auto_close_open;
	auto_close_open = new wxMenuItem( menu_auto_close, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_CHECK );
	menu_auto_close->Append( auto_close_open );

	wxMenuItem* auto_close_save;
	auto_close_save = new wxMenuItem( menu_auto_close, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_CHECK );
	menu_auto_close->Append( auto_close_save );
	auto_close_save->Check( true );

	wxMenuItem* auto_close_save_as;
	auto_close_save_as = new wxMenuItem( menu_auto_close, wxID_ANY, wxString( wxT("Save As") ) , wxEmptyString, wxITEM_CHECK );
	menu_auto_close->Append( auto_close_save_as );

	main_menubar->Append( menu_auto_close, wxT("Auto-close") );

	this->SetMenuBar( main_menubar );

	detail_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mgr.AddPane( detail_panel, wxAuiPaneInfo() .Name( wxT("StepDetailPanel") ).Top() .Caption( wxT("Step detail") ).CloseButton( false ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( 1010,155 ) ).BottomDockable( false ).LeftDockable( false ).RightDockable( false ).Row( 1 ).BestSize( wxSize( 650,140 ) ).MinSize( wxSize( 650,120 ) ).Layer( 1 ) );

	wxBoxSizer* detail_sizer;
	detail_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxFlexGridSizer* detail_sizer_flex;
	detail_sizer_flex = new wxFlexGridSizer( 1, 3, 0, 0 );
	detail_sizer_flex->SetFlexibleDirection( wxBOTH );
	detail_sizer_flex->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	wxBoxSizer* detail_sizer_col1;
	detail_sizer_col1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* detail_sizer_X;
	detail_sizer_X = new wxBoxSizer( wxHORIZONTAL );

	detail_sizer_X->SetMinSize( wxSize( 10,10 ) );
	label_x_cord = new wxStaticText( detail_panel, wxID_ANY, wxT("X-Cord:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_x_cord->Wrap( -1 );
	detail_sizer_X->Add( label_x_cord, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	spin_x = new wxSpinCtrlDouble( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, -1e+06, 1e+06, 0.000000, 1 );
	spin_x->SetDigits( 3 );
	spin_x->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	detail_sizer_X->Add( spin_x, 0, wxALL, 5 );


	detail_sizer_col1->Add( detail_sizer_X, 1, 0, 5 );

	wxBoxSizer* detail_sizer_Y;
	detail_sizer_Y = new wxBoxSizer( wxHORIZONTAL );

	label_y_cord = new wxStaticText( detail_panel, wxID_ANY, wxT("Y-Cord:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_y_cord->Wrap( -1 );
	detail_sizer_Y->Add( label_y_cord, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	spin_y = new wxSpinCtrlDouble( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, -1e+06, 1e+06, 0, 1 );
	spin_y->SetDigits( 3 );
	detail_sizer_Y->Add( spin_y, 0, wxALL, 5 );


	detail_sizer_col1->Add( detail_sizer_Y, 1, 0, 5 );

	wxBoxSizer* detail_sizer_Amount;
	detail_sizer_Amount = new wxBoxSizer( wxHORIZONTAL );

	label_amount = new wxStaticText( detail_panel, wxID_ANY, wxT("Amount:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_amount->Wrap( -1 );
	detail_sizer_Amount->Add( label_amount, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	spin_amount = new wxSpinCtrl( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, 0, 1000000, 1 );
	detail_sizer_Amount->Add( spin_amount, 0, wxALL, 5 );


	detail_sizer_col1->Add( detail_sizer_Amount, 1, 0, 5 );

	wxBoxSizer* detail_sizer_Comment;
	detail_sizer_Comment = new wxBoxSizer( wxHORIZONTAL );

	label_comment = new wxStaticText( detail_panel, wxID_ANY, wxT("Comment:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_comment->Wrap( -1 );
	detail_sizer_Comment->Add( label_comment, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txt_comment = new wxTextCtrl( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
	detail_sizer_Comment->Add( txt_comment, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	detail_sizer_col1->Add( detail_sizer_Comment, 1, wxEXPAND, 5 );


	detail_sizer_flex->Add( detail_sizer_col1, 1, wxEXPAND, 5 );

	wxBoxSizer* detail_sizer_col2;
	detail_sizer_col2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* detail_sizer_ItemTech;
	detail_sizer_ItemTech = new wxBoxSizer( wxHORIZONTAL );

	label_item = new wxStaticText( detail_panel, wxID_ANY, wxT("Item:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_item->Wrap( -1 );
	detail_sizer_ItemTech->Add( label_item, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	cmb_item = new wxComboBox( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_SORT );
	cmb_item->SetMinSize( wxSize( 180,-1 ) );

	detail_sizer_ItemTech->Add( cmb_item, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	detail_sizer_col2->Add( detail_sizer_ItemTech, 1, 0, 5 );

	wxBoxSizer* detail_sizer_FromTo;
	detail_sizer_FromTo = new wxBoxSizer( wxHORIZONTAL );

	label_from_into = new wxStaticText( detail_panel, wxID_ANY, wxT("From:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_from_into->Wrap( -1 );
	detail_sizer_FromTo->Add( label_from_into, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	cmb_from_into = new wxComboBox( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_SORT );
	cmb_from_into->SetSelection( 0 );
	cmb_from_into->SetMinSize( wxSize( 180,-1 ) );

	detail_sizer_FromTo->Add( cmb_from_into, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	detail_sizer_col2->Add( detail_sizer_FromTo, 1, 0, 5 );

	wxBoxSizer* detail_sizer_Input;
	detail_sizer_Input = new wxBoxSizer( wxHORIZONTAL );

	label_input = new wxStaticText( detail_panel, wxID_ANY, wxT("Input:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_input->Wrap( -1 );
	detail_sizer_Input->Add( label_input, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString radio_inputChoices[] = { wxT("Left"), wxT("None"), wxT("Right") };
	int radio_inputNChoices = sizeof( radio_inputChoices ) / sizeof( wxString );
	radio_input = new wxRadioBox( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, radio_inputNChoices, radio_inputChoices, 3, wxRA_SPECIFY_COLS );
	radio_input->SetSelection( 1 );
	radio_input->SetFont( wxFont( 6, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	radio_input->SetMinSize( wxSize( 180,-1 ) );

	detail_sizer_Input->Add( radio_input, 0, wxLEFT|wxRIGHT, 5 );


	detail_sizer_col2->Add( detail_sizer_Input, 1, 0, 5 );

	wxBoxSizer* detail_sizer_Output;
	detail_sizer_Output = new wxBoxSizer( wxHORIZONTAL );

	label_output = new wxStaticText( detail_panel, wxID_ANY, wxT("Output:"), wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	label_output->Wrap( -1 );
	detail_sizer_Output->Add( label_output, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString radio_outputChoices[] = { wxT("Left"), wxT("None"), wxT("Right") };
	int radio_outputNChoices = sizeof( radio_outputChoices ) / sizeof( wxString );
	radio_output = new wxRadioBox( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, radio_outputNChoices, radio_outputChoices, 3, wxRA_SPECIFY_COLS );
	radio_output->SetSelection( 1 );
	radio_output->SetFont( wxFont( 6, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	radio_output->SetMinSize( wxSize( 180,-1 ) );

	detail_sizer_Output->Add( radio_output, 0, wxLEFT|wxRIGHT, 5 );


	detail_sizer_col2->Add( detail_sizer_Output, 1, wxEXPAND, 5 );


	detail_sizer_flex->Add( detail_sizer_col2, 1, wxEXPAND, 5 );

	wxBoxSizer* detail_sizer_col3;
	detail_sizer_col3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* detail_sizer_Orientation;
	detail_sizer_Orientation = new wxBoxSizer( wxHORIZONTAL );

	label_building_orientation = new wxStaticText( detail_panel, wxID_ANY, wxT("Building orientation:"), wxDefaultPosition, wxSize( 115,-1 ), wxALIGN_RIGHT );
	label_building_orientation->Wrap( -1 );
	detail_sizer_Orientation->Add( label_building_orientation, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	cmb_building_orientation = new wxComboBox( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0, NULL, 0 );
	cmb_building_orientation->SetToolTip( wxT("The orientation of the building. Inserters are reversed.") );

	detail_sizer_Orientation->Add( cmb_building_orientation, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	detail_sizer_col3->Add( detail_sizer_Orientation, 1, 0, 5 );

	wxBoxSizer* detail_sizer_Direction;
	detail_sizer_Direction = new wxBoxSizer( wxHORIZONTAL );

	label_direction_to_build = new wxStaticText( detail_panel, wxID_ANY, wxT("Build direction:"), wxDefaultPosition, wxSize( 115,-1 ), wxALIGN_RIGHT );
	label_direction_to_build->Wrap( -1 );
	detail_sizer_Direction->Add( label_direction_to_build, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	cmb_direction_to_build = new wxComboBox( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0, NULL, 0 );
	cmb_direction_to_build->SetToolTip( wxT("The direction to place the next building") );

	detail_sizer_Direction->Add( cmb_direction_to_build, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	detail_sizer_col3->Add( detail_sizer_Direction, 1, 0, 5 );

	wxBoxSizer* detail_sizer_Size;
	detail_sizer_Size = new wxBoxSizer( wxHORIZONTAL );

	label_building_size = new wxStaticText( detail_panel, wxID_ANY, wxT("Building size:"), wxDefaultPosition, wxSize( 115,-1 ), wxALIGN_RIGHT );
	label_building_size->Wrap( -1 );
	detail_sizer_Size->Add( label_building_size, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	spin_building_size = new wxSpinCtrl( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT|wxSP_ARROW_KEYS, 1, 10, 1 );
	spin_building_size->SetToolTip( wxT("Number of tiles the building is wide. Used for placing multiple buildings in a row.") );
	spin_building_size->SetMinSize( wxSize( 80,-1 ) );

	detail_sizer_Size->Add( spin_building_size, 0, wxALL, 5 );


	detail_sizer_col3->Add( detail_sizer_Size, 1, wxEXPAND, 5 );

	wxBoxSizer* detail_sizer_Buildings;
	detail_sizer_Buildings = new wxBoxSizer( wxHORIZONTAL );

	label_amount_of_buildings = new wxStaticText( detail_panel, wxID_ANY, wxT("Amount of Buildings:"), wxDefaultPosition, wxSize( 115,-1 ), wxALIGN_RIGHT );
	label_amount_of_buildings->Wrap( -1 );
	detail_sizer_Buildings->Add( label_amount_of_buildings, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	spin_building_amount = new wxSpinCtrl( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT|wxSP_ARROW_KEYS, 1, 250, 1 );
	spin_building_amount->SetToolTip( wxT("The number of buildings to place in a row") );
	spin_building_amount->SetMinSize( wxSize( 80,-1 ) );

	detail_sizer_Buildings->Add( spin_building_amount, 0, wxALL, 5 );


	detail_sizer_col3->Add( detail_sizer_Buildings, 1, wxEXPAND, 5 );


	detail_sizer_flex->Add( detail_sizer_col3, 1, wxEXPAND, 5 );


	detail_sizer->Add( detail_sizer_flex, 1, wxEXPAND, 5 );


	detail_panel->SetSizer( detail_sizer );
	detail_panel->Layout();
	detail_sizer->Fit( detail_panel );
	type_panel = new TypePanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxTAB_TRAVERSAL );
	m_mgr.AddPane( type_panel, wxAuiPaneInfo() .Name( wxT("StepTypePanel") ).Top() .Caption( wxT("Step type") ).CloseButton( false ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( 700,150 ) ).BottomDockable( false ).LeftDockable( false ).RightDockable( false ).Row( 1 ).BestSize( wxSize( 620,140 ) ).MinSize( wxSize( 620,120 ) ).Layer( 1 ) );

	wxBoxSizer* type_sizer;
	type_sizer = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* type_sizer_flex;
	type_sizer_flex = new wxFlexGridSizer( 3, 7, 15, 15 );
	type_sizer_flex->SetFlexibleDirection( wxBOTH );
	type_sizer_flex->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	wxBoxSizer* type_sizer_Take;
	type_sizer_Take = new wxBoxSizer( wxVERTICAL );

	rbtn_take = new wxRadioButton( type_panel, wxID_ANY, wxT("Take"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_take->SetToolTip( wxT("Makes the character take items from a container [chest, furnace, assembler, etc.] and put them into their inventory") );

	type_sizer_Take->Add( rbtn_take, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Take, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Put;
	type_sizer_Put = new wxBoxSizer( wxVERTICAL );

	rbtn_put = new wxRadioButton( type_panel, wxID_ANY, wxT("Put"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_put->SetToolTip( wxT("Makes the character put items from his inventory into a container [chest, furnace, assembler, etc.]") );

	type_sizer_Put->Add( rbtn_put, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Put, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_GameSpeed;
	type_sizer_GameSpeed = new wxBoxSizer( wxVERTICAL );

	rbtn_game_speed = new wxRadioButton( type_panel, wxID_ANY, wxT("Game Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_game_speed->SetToolTip( wxT("Changes the game speed to X%") );

	type_sizer_GameSpeed->Add( rbtn_game_speed, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_GameSpeed, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Craft;
	type_sizer_Craft = new wxBoxSizer( wxVERTICAL );

	rbtn_craft = new wxRadioButton( type_panel, wxID_ANY, wxT("Craft"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_craft->SetToolTip( wxT("Makes the character craft an item") );

	type_sizer_Craft->Add( rbtn_craft, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Craft, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Walk;
	type_sizer_Walk = new wxBoxSizer( wxVERTICAL );

	rbtn_walk = new wxRadioButton( type_panel, wxID_ANY, wxT("Walk"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_walk->SetToolTip( wxT("Makes the character walk to a point") );

	type_sizer_Walk->Add( rbtn_walk, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Walk, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Mine;
	type_sizer_Mine = new wxBoxSizer( wxVERTICAL );

	rbtn_mine = new wxRadioButton( type_panel, wxID_ANY, wxT("Mine"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_mine->SetToolTip( wxT("Makes the character mine an area, if there is a building, tree or rock they will remove that instead") );

	type_sizer_Mine->Add( rbtn_mine, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Mine, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Pause;
	type_sizer_Pause = new wxBoxSizer( wxVERTICAL );

	rbtn_pause = new wxRadioButton( type_panel, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_pause->SetToolTip( wxT("Pauses the game, when all previous tasks are completed. Same as /Pause in the console, the game can be continued with /Resume") );

	type_sizer_Pause->Add( rbtn_pause, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Pause, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Build;
	type_sizer_Build = new wxBoxSizer( wxVERTICAL );

	rbtn_build = new wxRadioButton( type_panel, wxID_ANY, wxT("Build"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_build->SetToolTip( wxT("Makes the character build an entity") );

	type_sizer_Build->Add( rbtn_build, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Build, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Recipe;
	type_sizer_Recipe = new wxBoxSizer( wxVERTICAL );

	rbtn_recipe = new wxRadioButton( type_panel, wxID_ANY, wxT("Recipe"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_recipe->SetToolTip( wxT("Makes the character change the recipe for a crafting machine") );

	type_sizer_Recipe->Add( rbtn_recipe, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Recipe, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Tech;
	type_sizer_Tech = new wxBoxSizer( wxVERTICAL );

	rbtn_tech = new wxRadioButton( type_panel, wxID_ANY, wxT("Tech"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_tech->SetToolTip( wxT("Adds a technologi to the research queue") );

	type_sizer_Tech->Add( rbtn_tech, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Tech, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Limit;
	type_sizer_Limit = new wxBoxSizer( wxVERTICAL );

	rbtn_limit = new wxRadioButton( type_panel, wxID_ANY, wxT("Limit"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_limit->SetToolTip( wxT("Makes the character limit a chest to X slots") );

	type_sizer_Limit->Add( rbtn_limit, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Limit, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Idle;
	type_sizer_Idle = new wxBoxSizer( wxVERTICAL );

	rbtn_idle = new wxRadioButton( type_panel, wxID_ANY, wxT("Idle"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_idle->SetToolTip( wxT("Makes the character do nothing for X ticks") );

	type_sizer_Idle->Add( rbtn_idle, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Idle, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Filter;
	type_sizer_Filter = new wxBoxSizer( wxVERTICAL );

	rbtn_filter = new wxRadioButton( type_panel, wxID_ANY, wxT("Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_filter->SetToolTip( wxT("Makes the character set the filter on either: a filter-inserter, a splitter or a slot in a car / train wagon") );

	type_sizer_Filter->Add( rbtn_filter, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Filter, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Stop;
	type_sizer_Stop = new wxBoxSizer( wxHORIZONTAL );

	rbtn_stop = new wxRadioButton( type_panel, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	type_sizer_Stop->Add( rbtn_stop, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Stop, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Priority;
	type_sizer_Priority = new wxBoxSizer( wxVERTICAL );

	rbtn_priority = new wxRadioButton( type_panel, wxID_ANY, wxT("Priority"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_priority->SetToolTip( wxT("Makes the character set the input and output priority on a splitter.\nNeeds to be applied before setting the filter on the splitter.") );

	type_sizer_Priority->Add( rbtn_priority, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Priority, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Rotate;
	type_sizer_Rotate = new wxBoxSizer( wxVERTICAL );

	rbtn_rotate = new wxRadioButton( type_panel, wxID_ANY, wxT("Rotate"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_rotate->SetToolTip( wxT("Makes the character rotate an entity X times.\nIf X is 3 then the entity is rotated once counter-clock-wise.") );

	type_sizer_Rotate->Add( rbtn_rotate, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Rotate, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_PickUp;
	type_sizer_PickUp = new wxBoxSizer( wxVERTICAL );

	rbtn_pick_up = new wxRadioButton( type_panel, wxID_ANY, wxT("Pick Up"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_pick_up->SetToolTip( wxT("Makes the character start to pick up items on the floor, same as pressing ( f )") );

	type_sizer_PickUp->Add( rbtn_pick_up, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_PickUp, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Drop;
	type_sizer_Drop = new wxBoxSizer( wxVERTICAL );

	rbtn_drop = new wxRadioButton( type_panel, wxID_ANY, wxT("Drop"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_drop->SetToolTip( wxT("Makes the character drop an item, same as pressing ( z )") );

	type_sizer_Drop->Add( rbtn_drop, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Drop, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Launch;
	type_sizer_Launch = new wxBoxSizer( wxVERTICAL );

	rbtn_launch = new wxRadioButton( type_panel, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_launch->SetToolTip( wxT("Makes the character launch a rocket from a rocket silo") );

	type_sizer_Launch->Add( rbtn_launch, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Launch, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Save;
	type_sizer_Save = new wxBoxSizer( wxVERTICAL );

	rbtn_save = new wxRadioButton( type_panel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_save->SetToolTip( wxT("Creates a save game named by the comment, the tas can only be continued from these save games.\nIn single player the save game name has the prefix autosave-") );

	type_sizer_Save->Add( rbtn_save, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_Save, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_CancelCrafting;
	type_sizer_CancelCrafting = new wxBoxSizer( wxVERTICAL );

	rbtn_cancel_crafting = new wxRadioButton( type_panel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_cancel_crafting->SetToolTip( wxT("Cancels items in the players crafting queue, \nreturning the ingredients to your hand") );

	type_sizer_CancelCrafting->Add( rbtn_cancel_crafting, 0, wxALL, 5 );


	type_sizer_flex->Add( type_sizer_CancelCrafting, 1, wxEXPAND, 5 );


	type_sizer->Add( type_sizer_flex, 1, wxEXPAND|wxLEFT|wxRIGHT, 15 );


	type_panel->SetSizer( type_sizer );
	type_panel->Layout();
	type_sizer->Fit( type_panel );
	auto_put_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mgr.AddPane( auto_put_panel, wxAuiPaneInfo() .Name( wxT("AutoPutPanel") ).Top() .Caption( wxT("Auto put") ).CloseButton( false ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( 300,150 ) ).BottomDockable( false ).LeftDockable( false ).RightDockable( false ).Row( 1 ).BestSize( wxSize( 200,140 ) ).MinSize( wxSize( 100,120 ) ).MaxSize( wxSize( 300,180 ) ).Layer( 1 ) );

	wxBoxSizer* auto_put_sizer;
	auto_put_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxFlexGridSizer* auto_put_flex;
	auto_put_flex = new wxFlexGridSizer( 4, 1, 5, 15 );
	auto_put_flex->SetFlexibleDirection( wxBOTH );
	auto_put_flex->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	check_furnace = new wxCheckBox( auto_put_panel, wxID_ANY, wxT("Furnace"), wxDefaultPosition, wxDefaultSize, 0 );
	check_furnace->SetValue(true);
	check_furnace->SetToolTip( wxT("Adds a step to put coal into stone and steel furnaces") );

	auto_put_flex->Add( check_furnace, 0, wxALL, 5 );

	check_burner = new wxCheckBox( auto_put_panel, wxID_ANY, wxT("Burner"), wxDefaultPosition, wxDefaultSize, 0 );
	check_burner->SetValue(true);
	check_burner->SetToolTip( wxT("Adds a step to put coal into Burner Mining Drills, Burner Inserters and Boilers") );

	auto_put_flex->Add( check_burner, 0, wxALL, 5 );

	check_lab = new wxCheckBox( auto_put_panel, wxID_ANY, wxT("Lab"), wxDefaultPosition, wxDefaultSize, 0 );
	check_lab->SetValue(true);
	check_lab->SetToolTip( wxT("Adds a step to put automation science into the Lab") );

	auto_put_flex->Add( check_lab, 0, wxALL, 5 );

	check_recipe = new wxCheckBox( auto_put_panel, wxID_ANY, wxT("Recipe"), wxDefaultPosition, wxDefaultSize, 0 );
	check_recipe->SetValue(true);
	check_recipe->SetToolTip( wxT("Add steps to put the items needed to craft that recipe") );

	auto_put_flex->Add( check_recipe, 0, wxALL, 5 );


	auto_put_sizer->Add( auto_put_flex, 1, wxLEFT|wxRIGHT, 5 );

	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );

	step_colour_picker = new wxColourPickerCtrl( auto_put_panel, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL );
	bSizer65->Add( step_colour_picker, 0, wxALL, 5 );


	auto_put_sizer->Add( bSizer65, 1, wxEXPAND, 5 );


	auto_put_panel->SetSizer( auto_put_sizer );
	auto_put_panel->Layout();
	auto_put_sizer->Fit( auto_put_panel );
	main_book = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_TAB_EXTERNAL_MOVE|wxAUI_NB_TAB_MOVE|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TOP|wxAUI_NB_WINDOWLIST_BUTTON|wxBORDER_RAISED );
	m_mgr.AddPane( main_book, wxAuiPaneInfo() .Name( wxT("DataBook") ).Center() .Caption( wxT("Book") ).CaptionVisible( false ).CloseButton( false ).MaximizeButton( true ).MinimizeButton( true ).PinButton( true ).Dock().Resizable().FloatingSize( wxDefaultSize ).Row( 2 ).MinSize( wxSize( 500,500 ) ).Layer( 2 ).CentrePane() );

	template_panel = new wxPanel( main_book, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5612;
	bSizer5612 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxVERTICAL );

	bSizer103->SetMinSize( wxSize( 612,-1 ) );
	wxBoxSizer* bSizer126;
	bSizer126 = new wxBoxSizer( wxHORIZONTAL );

	label_choose_template = new wxStaticText( template_panel, wxID_ANY, wxT("Template:"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	label_choose_template->Wrap( -1 );
	bSizer126->Add( label_choose_template, 0, wxALIGN_CENTER|wxALL, 5 );

	cmb_choose_template = new wxComboBox( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmb_choose_template->SetMinSize( wxSize( 195,-1 ) );

	bSizer126->Add( cmb_choose_template, 0, wxALIGN_CENTER|wxALL, 5 );

	btn_template_new = new wxButton( template_panel, wxID_ANY, wxT("New Template"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	bSizer126->Add( btn_template_new, 0, wxALL, 5 );

	btn_template_delete = new wxButton( template_panel, wxID_ANY, wxT("Delete Template"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	bSizer126->Add( btn_template_delete, 0, wxALL, 5 );


	bSizer103->Add( bSizer126, 1, wxALIGN_LEFT, 5 );

	wxBoxSizer* bSizer1002;
	bSizer1002 = new wxBoxSizer( wxHORIZONTAL );

	btn_template_change_step = new wxButton( template_panel, wxID_ANY, wxT("Change"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1002->Add( btn_template_change_step, 0, wxALL, 5 );

	btn_template_delete_step = new wxButton( template_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1002->Add( btn_template_delete_step, 0, wxALL, 5 );

	btn_template_move_up_step = new wxButton( template_panel, wxID_ANY, wxT("Move Up"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1002->Add( btn_template_move_up_step, 0, wxALL, 5 );

	btn_template_move_down_step = new wxButton( template_panel, wxID_ANY, wxT("Move Down"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1002->Add( btn_template_move_down_step, 0, wxALL, 5 );


	bSizer103->Add( bSizer1002, 1, wxALIGN_LEFT, 5 );


	bSizer102->Add( bSizer103, 1, 0, 5 );

	m_staticline51 = new wxStaticLine( template_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer102->Add( m_staticline51, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer1041;
	bSizer1041 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1051;
	bSizer1051 = new wxBoxSizer( wxHORIZONTAL );

	btn_template_add_to_steps_list = new wxButton( template_panel, wxID_ANY, wxT("Add to steps list"), wxDefaultPosition, wxSize( 125,-1 ), 0 );
	bSizer1051->Add( btn_template_add_to_steps_list, 0, wxALL, 5 );


	bSizer1041->Add( bSizer1051, 1, 0, 5 );

	wxBoxSizer* bSizer1061;
	bSizer1061 = new wxBoxSizer( wxHORIZONTAL );

	btn_template_add_from_steps_list = new wxButton( template_panel, wxID_ANY, wxT("Add from steps list"), wxDefaultPosition, wxSize( 125,-1 ), 0 );
	bSizer1061->Add( btn_template_add_from_steps_list, 0, wxALL, 5 );


	bSizer1041->Add( bSizer1061, 1, 0, 5 );


	bSizer102->Add( bSizer1041, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1042;
	bSizer1042 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1052;
	bSizer1052 = new wxBoxSizer( wxHORIZONTAL );

	label_template_amount_offset = new wxStaticText( template_panel, wxID_ANY, wxT("Amount-Offset:"), wxDefaultPosition, wxSize( 85,-1 ), 0 );
	label_template_amount_offset->Wrap( -1 );
	bSizer1052->Add( label_template_amount_offset, 0, wxALIGN_CENTER, 5 );

	spin_amount_offset = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, -10000, 10000, 0 );
	bSizer1052->Add( spin_amount_offset, 0, wxALL, 5 );


	bSizer1042->Add( bSizer1052, 1, 0, 5 );

	wxBoxSizer* bSizer1062;
	bSizer1062 = new wxBoxSizer( wxHORIZONTAL );

	label_template_amount_multiplier = new wxStaticText( template_panel, wxID_ANY, wxT("Amount-Multi:"), wxDefaultPosition, wxSize( 85,-1 ), 0 );
	label_template_amount_multiplier->Wrap( -1 );
	bSizer1062->Add( label_template_amount_multiplier, 0, wxALIGN_CENTER, 5 );

	spin_amount_multiplier = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, -10000, 10000, 0 );
	bSizer1062->Add( spin_amount_multiplier, 0, wxALL, 5 );


	bSizer1042->Add( bSizer1062, 1, 0, 5 );


	bSizer102->Add( bSizer1042, 0, 0, 5 );

	wxBoxSizer* bSizer104;
	bSizer104 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxHORIZONTAL );

	label_template_x_offset = new wxStaticText( template_panel, wxID_ANY, wxT("X-Offset:"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	label_template_x_offset->Wrap( -1 );
	bSizer105->Add( label_template_x_offset, 0, wxALIGN_CENTER, 5 );

	spin_x_offset = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, -10000, 10000, 0 );
	bSizer105->Add( spin_x_offset, 0, wxALL, 5 );


	bSizer104->Add( bSizer105, 1, 0, 5 );

	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer( wxHORIZONTAL );

	label_template_y_offset = new wxStaticText( template_panel, wxID_ANY, wxT("Y-Offset:"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	label_template_y_offset->Wrap( -1 );
	bSizer106->Add( label_template_y_offset, 0, wxALIGN_CENTER, 5 );

	spin_y_offset = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, -10000, 10000, 0 );
	bSizer106->Add( spin_y_offset, 0, wxALL, 5 );


	bSizer104->Add( bSizer106, 1, 0, 5 );


	bSizer102->Add( bSizer104, 0, 0, 5 );


	bSizer5612->Add( bSizer102, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer502;
	bSizer502 = new wxBoxSizer( wxVERTICAL );

	grid_template = new wxGrid( template_panel, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );

	// Grid
	grid_template->CreateGrid( 0, 10 );
	grid_template->EnableEditing( false );
	grid_template->EnableGridLines( true );
	grid_template->EnableDragGridSize( false );
	grid_template->SetMargins( 0, 0 );

	// Columns
	grid_template->SetColSize( 0, 75 );
	grid_template->SetColSize( 1, 59 );
	grid_template->SetColSize( 2, 59 );
	grid_template->SetColSize( 3, 50 );
	grid_template->SetColSize( 4, 150 );
	grid_template->SetColSize( 5, 70 );
	grid_template->SetColSize( 6, 70 );
	grid_template->SetColSize( 7, 50 );
	grid_template->SetColSize( 8, 60 );
	grid_template->SetColSize( 9, 140 );
	grid_template->EnableDragColMove( false );
	grid_template->EnableDragColSize( true );
	grid_template->SetColLabelValue( 0, wxT("Step") );
	grid_template->SetColLabelValue( 1, wxT("X-cord") );
	grid_template->SetColLabelValue( 2, wxT("Y-cord") );
	grid_template->SetColLabelValue( 3, wxT("Amount") );
	grid_template->SetColLabelValue( 4, wxT("Item") );
	grid_template->SetColLabelValue( 5, wxT("Orientation") );
	grid_template->SetColLabelValue( 6, wxT("Direction") );
	grid_template->SetColLabelValue( 7, wxT("Size") );
	grid_template->SetColLabelValue( 8, wxT("Buildings") );
	grid_template->SetColLabelValue( 9, wxT("Comment") );
	grid_template->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grid_template->EnableDragRowSize( false );
	grid_template->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grid_template->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	grid_template->SetMinSize( wxSize( 860,2500 ) );

	bSizer502->Add( grid_template, 0, wxALL|wxEXPAND, 5 );


	bSizer5612->Add( bSizer502, 1, wxEXPAND, 5 );


	template_panel->SetSizer( bSizer5612 );
	template_panel->Layout();
	bSizer5612->Fit( template_panel );
	main_book->AddPage( template_panel, wxT("Templates"), false, wxNullBitmap );
	step_panel = new wxPanel( main_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* step_panel_sizer;
	step_panel_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* step_panel_search_sizer;
	step_panel_search_sizer = new wxBoxSizer( wxHORIZONTAL );

	step_search_ctrl = new wxSearchCtrl( step_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	#ifndef __WXMAC__
	step_search_ctrl->ShowSearchButton( true );
	#endif
	step_search_ctrl->ShowCancelButton( true );
	step_panel_search_sizer->Add( step_search_ctrl, 0, wxALL, 5 );

	step_search_toggle_updown = new wxCheckBox( step_panel, wxID_ANY, wxT("Search up"), wxDefaultPosition, wxDefaultSize, 0 );
	step_search_toggle_updown->SetValue(true);
	step_panel_search_sizer->Add( step_search_toggle_updown, 0, wxALL, 9 );


	step_panel_sizer->Add( step_panel_search_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* step_panel_control_sizer;
	step_panel_control_sizer = new wxBoxSizer( wxHORIZONTAL );

	btn_add_step = new wxButton( step_panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	step_panel_control_sizer->Add( btn_add_step, 0, wxALIGN_CENTER|wxALL, 5 );

	btn_change_step = new wxButton( step_panel, wxID_ANY, wxT("Change"), wxDefaultPosition, wxDefaultSize, 0 );
	step_panel_control_sizer->Add( btn_change_step, 0, wxALL, 5 );

	btn_delete_step = new wxButton( step_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	step_panel_control_sizer->Add( btn_delete_step, 0, wxALL, 5 );

	btn_move_up = new wxButton( step_panel, wxID_ANY, wxT("Move Up"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_move_up->SetToolTip( wxT("Right-click to move 5 but be patient") );

	step_panel_control_sizer->Add( btn_move_up, 0, wxALL, 5 );

	btn_move_down = new wxButton( step_panel, wxID_ANY, wxT("Move Down"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_move_down->SetToolTip( wxT("Right-click to move 5 but be patient") );

	step_panel_control_sizer->Add( btn_move_down, 0, wxALL, 5 );


	step_panel_sizer->Add( step_panel_control_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* step_panel_grid_sizer;
	step_panel_grid_sizer = new wxBoxSizer( wxVERTICAL );

	grid_steps = new wxGrid( step_panel, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );

	// Grid
	grid_steps->CreateGrid( 0, 10 );
	grid_steps->EnableEditing( false );
	grid_steps->EnableGridLines( true );
	grid_steps->EnableDragGridSize( false );
	grid_steps->SetMargins( 0, 0 );

	// Columns
	grid_steps->SetColSize( 0, 75 );
	grid_steps->SetColSize( 1, 59 );
	grid_steps->SetColSize( 2, 59 );
	grid_steps->SetColSize( 3, 58 );
	grid_steps->SetColSize( 4, 150 );
	grid_steps->SetColSize( 5, 70 );
	grid_steps->SetColSize( 6, 70 );
	grid_steps->SetColSize( 7, 50 );
	grid_steps->SetColSize( 8, 60 );
	grid_steps->SetColSize( 9, 140 );
	grid_steps->EnableDragColMove( false );
	grid_steps->EnableDragColSize( true );
	grid_steps->SetColLabelValue( 0, wxT("Step") );
	grid_steps->SetColLabelValue( 1, wxT("X-cord") );
	grid_steps->SetColLabelValue( 2, wxT("Y-cord") );
	grid_steps->SetColLabelValue( 3, wxT("Amount") );
	grid_steps->SetColLabelValue( 4, wxT("Item") );
	grid_steps->SetColLabelValue( 5, wxT("Orientation") );
	grid_steps->SetColLabelValue( 6, wxT("Direction") );
	grid_steps->SetColLabelValue( 7, wxT("Size") );
	grid_steps->SetColLabelValue( 8, wxT("Buildings") );
	grid_steps->SetColLabelValue( 9, wxT("Comment") );
	grid_steps->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grid_steps->EnableDragRowSize( false );
	grid_steps->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance
	grid_steps->SetLabelTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	// Cell Defaults
	grid_steps->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	grid_steps->SetMinSize( wxSize( 860,2500 ) );

	step_panel_grid_sizer->Add( grid_steps, 0, wxALL|wxEXPAND, 5 );


	step_panel_sizer->Add( step_panel_grid_sizer, 1, wxEXPAND, 5 );


	step_panel->SetSizer( step_panel_sizer );
	step_panel->Layout();
	step_panel_sizer->Fit( step_panel );
	main_book->AddPage( step_panel, wxT("Steps"), true, wxNullBitmap );
	import_steps_panel = new ImportStepsPanel( main_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT("Import") );
	wxBoxSizer* import_steps_sizer;
	import_steps_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* import_steps_ctrl_sizer;
	import_steps_ctrl_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* import_steps_into_steps_sizer;
	import_steps_into_steps_sizer = new wxBoxSizer( wxVERTICAL );

	import_steps_into_steps_ctrl = new wxSpinCtrl( import_steps_panel, wxID_ANY, wxT("-1"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, -999999, 999999, -1 );
	import_steps_into_steps_ctrl->SetToolTip( wxT("Positive numbers places the imported steps in the step list from the top and negative numbers from the bottom.\nWith 0 being the top element and -1 being the bottom element.\nAnd -2 Inserting steps between last and second to last element.") );
	import_steps_into_steps_ctrl->SetMinSize( wxSize( 120,-1 ) );
	import_steps_into_steps_ctrl->SetMaxSize( wxSize( 120,-1 ) );

	import_steps_into_steps_sizer->Add( import_steps_into_steps_ctrl, 0, wxALL, 5 );

	import_steps_into_steps_btn = new wxButton( import_steps_panel, wxID_ANY, wxT("Into steps"), wxDefaultPosition, wxSize( 120,-1 ), 0 );
	import_steps_into_steps_btn->SetMinSize( wxSize( 120,-1 ) );
	import_steps_into_steps_btn->SetMaxSize( wxSize( 120,-1 ) );

	import_steps_into_steps_sizer->Add( import_steps_into_steps_btn, 0, wxALL, 5 );


	import_steps_ctrl_sizer->Add( import_steps_into_steps_sizer, 1, 0, 5 );

	wxBoxSizer* import_steps_into_template_sizer;
	import_steps_into_template_sizer = new wxBoxSizer( wxVERTICAL );

	import_steps_into_template_ctrl = new wxTextCtrl( import_steps_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 120,-1 ), wxTE_PROCESS_ENTER );
	#ifdef __WXGTK__
	if ( !import_steps_into_template_ctrl->HasFlag( wxTE_MULTILINE ) )
	{
	import_steps_into_template_ctrl->SetMaxLength( 45 );
	}
	#else
	import_steps_into_template_ctrl->SetMaxLength( 45 );
	#endif
	import_steps_into_template_ctrl->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	import_steps_into_template_ctrl->SetToolTip( wxT("Template name has to be at least 1 character long.\nTemplate name can only contain letters and numbers.\nTemplate name has to be unique") );
	import_steps_into_template_ctrl->SetMinSize( wxSize( 120,-1 ) );
	import_steps_into_template_ctrl->SetMaxSize( wxSize( 120,-1 ) );

	import_steps_into_template_ctrl->SetValidator( wxTextValidator( wxFILTER_ALPHANUMERIC, &import_steps_into_template_ctrl_validator ) );

	import_steps_into_template_sizer->Add( import_steps_into_template_ctrl, 0, wxALL, 5 );

	import_steps_into_template_btn = new wxButton( import_steps_panel, wxID_ANY, wxT("Create template"), wxDefaultPosition, wxSize( 120,-1 ), 0 );
	import_steps_into_template_btn->Enable( false );
	import_steps_into_template_btn->SetMinSize( wxSize( 120,-1 ) );
	import_steps_into_template_btn->SetMaxSize( wxSize( 120,-1 ) );

	import_steps_into_template_sizer->Add( import_steps_into_template_btn, 0, wxALL, 5 );


	import_steps_ctrl_sizer->Add( import_steps_into_template_sizer, 1, 0, 5 );

	import_steps_clear_checkbox = new wxCheckBox( import_steps_panel, wxID_ANY, wxT("Clear import"), wxDefaultPosition, wxDefaultSize, 0 );
	import_steps_clear_checkbox->SetValue(true);
	import_steps_clear_checkbox->SetToolTip( wxT("Clears the import text field on succesful insertion into Steps or creation of a template") );

	import_steps_ctrl_sizer->Add( import_steps_clear_checkbox, 0, wxALL, 5 );


	import_steps_sizer->Add( import_steps_ctrl_sizer, 1, 0, 5 );

	wxBoxSizer* import_steps_text_sizer;
	import_steps_text_sizer = new wxBoxSizer( wxVERTICAL );

	import_steps_text_sizer->SetMinSize( wxSize( -1,1200 ) );
	import_steps_text_import = new wxTextCtrl( import_steps_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxTE_MULTILINE|wxTE_NO_VSCROLL );
	import_steps_text_import->SetMinSize( wxSize( 450,600 ) );

	import_steps_text_sizer->Add( import_steps_text_import, 0, wxALL|wxEXPAND, 5 );


	import_steps_sizer->Add( import_steps_text_sizer, 1, wxEXPAND, 5 );


	import_steps_panel->SetSizer( import_steps_sizer );
	import_steps_panel->Layout();
	import_steps_sizer->Fit( import_steps_panel );
	main_book->AddPage( import_steps_panel, wxT("Import"), false, wxNullBitmap );


	m_mgr.Update();
	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUI_Base::OnApplicationClose ) );
	menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuNew ), this, menu_file_new->GetId());
	menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuOpen ), this, menu_file_open->GetId());
	menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuSave ), this, menu_file_save->GetId());
	menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuSaveAs ), this, menu_file_save_as->GetId());
	menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuExit ), this, menu_file_exit->GetId());
	menu_script->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnChooseLocation ), this, menu_script_choose_location->GetId());
	menu_script->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnGenerateScript ), this, menu_script_generate_script->GetId());
	menu_script->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnOnlyGenerateSteps ), this, menu_script_only_generate_steps->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnChangeShortcutMenuSelected ), this, shortcut_changer->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnCraftMenuSelected ), this, shortcut_craft->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnWalkMenuSelected ), this, shortcut_walk->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnGameSpeedMenuSelected ), this, shortcut_game_speed->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnRotateMenuSelected ), this, shortcut_rotate->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnRecipeMenuChosen ), this, shortcut_recipe->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnStopMenuSelected ), this, shortcut_stop->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMineMenuSelected ), this, shortcut_mine->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnBuildMenuSelected ), this, shortcut_build->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnTechMenuSelected ), this, shortcut_tech->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnTakeMenuSelected ), this, shortcut_take->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPutMenuSelected ), this, shortcut_put->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnIdleMenuSelected ), this, shortcut_idle->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPriorityMenuSelected ), this, shortcut_priority->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnLimitMenuSelected ), this, shortcut_limit->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnFilterMenuSelected ), this, shortcut_filter->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPickUpMenuSelected ), this, shortcut_pick_up->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnDropMenuSelected ), this, shortcut_drop->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnLaunchMenuSelected ), this, shortcut_launch->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnSaveMenuSelected ), this, shortcut_Save->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPauseMenuSelected ), this, shortcut_pause->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnAddMenuSelected ), this, shortcut_add_step->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnChangeMenuSelected ), this, shortcut_change_step->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnDeleteMenuSelected ), this, shortcut_delete_step->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMoveUpMenuSelected ), this, shortcut_move_up->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMoveDownMenuSelected ), this, shortcut_move_down->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnCancelCraftingMenuSelected ), this, shortcut_cancel_crafting->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuSteelAxeClicked ), this, goal_steelaxe->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuGOTLAPClicked ), this, goal_GOTLAP->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAnyPercentClicked ), this, goal_any_percent->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuDebugClicked ), this, goal_debug->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseGenerateScriptClicked ), this, auto_close_generate_script->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseOpenClicked ), this, auto_close_open->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseSaveClicked ), this, auto_close_save->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseSaveAsClicked ), this, auto_close_save_as->GetId());
	rbtn_take->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTakeChosen ), NULL, this );
	rbtn_put->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPutChosen ), NULL, this );
	rbtn_game_speed->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnGameSpeedChosen ), NULL, this );
	rbtn_craft->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCraftChosen ), NULL, this );
	rbtn_walk->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnWalkChosen ), NULL, this );
	rbtn_mine->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnMineChosen ), NULL, this );
	rbtn_pause->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPauseChosen ), NULL, this );
	rbtn_build->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnBuildChosen ), NULL, this );
	rbtn_recipe->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRecipeChosen ), NULL, this );
	rbtn_tech->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTechChosen ), NULL, this );
	rbtn_limit->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLimitChosen ), NULL, this );
	rbtn_idle->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnIdleChosen ), NULL, this );
	rbtn_filter->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnfilterChosen ), NULL, this );
	rbtn_stop->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnStopChosen ), NULL, this );
	rbtn_priority->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPriorityChosen ), NULL, this );
	rbtn_rotate->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRotateChosen ), NULL, this );
	rbtn_pick_up->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPickUpChosen ), NULL, this );
	rbtn_drop->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnDropChosen ), NULL, this );
	rbtn_launch->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLaunchChosen ), NULL, this );
	rbtn_save->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnSaveChosen ), NULL, this );
	rbtn_cancel_crafting->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCancelCraftingChosen ), NULL, this );
	step_colour_picker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUI_Base::OnStepColourPickerColourChanged ), NULL, this );
	cmb_choose_template->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUI_Base::OnTemplateChosen ), NULL, this );
	cmb_choose_template->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnTemplateText ), NULL, this );
	btn_template_new->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnNewTemplateClicked ), NULL, this );
	btn_template_delete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteTemplateClicked ), NULL, this );
	btn_template_change_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateChangeStepClicked ), NULL, this );
	btn_template_delete_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateDeleteStepClicked ), NULL, this );
	btn_template_move_up_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveUpClicked ), NULL, this );
	btn_template_move_down_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveDownClicked ), NULL, this );
	btn_template_add_to_steps_list->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddToStepsListClicked ), NULL, this );
	btn_template_add_from_steps_list->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddFromStepsListClicked ), NULL, this );
	grid_template->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUI_Base::OnTemplateGridDoubleLeftClick ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnCancelButton ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnSearchButton ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::StepSeachOnText ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::StepSeachOnTextEnter ), NULL, this );
	btn_add_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnAddStepClicked ), NULL, this );
	btn_add_step->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnAddStepRightClicked ), NULL, this );
	btn_change_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnChangeStepClicked ), NULL, this );
	btn_delete_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteStepClicked ), NULL, this );
	btn_move_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveUpClicked ), NULL, this );
	btn_move_up->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveUpFiveClicked ), NULL, this );
	btn_move_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveDownClicked ), NULL, this );
	btn_move_down->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveDownFiveClicked ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUI_Base::OnStepsGridDoubleLeftClick ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( GUI_Base::OnStepsGridRangeSelect ), NULL, this );
	import_steps_into_steps_ctrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_Base::OnImportStepsIntoStepsCtrl ), NULL, this );
	import_steps_into_steps_ctrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsCtrlEnter ), NULL, this );
	import_steps_into_steps_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsBtnClick ), NULL, this );
	import_steps_into_template_ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlText ), NULL, this );
	import_steps_into_template_ctrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlEnter ), NULL, this );
	import_steps_into_template_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateBtnClick ), NULL, this );
	import_steps_text_import->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsTextUpdate ), NULL, this );
}

GUI_Base::~GUI_Base()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUI_Base::OnApplicationClose ) );
	rbtn_take->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTakeChosen ), NULL, this );
	rbtn_put->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPutChosen ), NULL, this );
	rbtn_game_speed->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnGameSpeedChosen ), NULL, this );
	rbtn_craft->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCraftChosen ), NULL, this );
	rbtn_walk->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnWalkChosen ), NULL, this );
	rbtn_mine->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnMineChosen ), NULL, this );
	rbtn_pause->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPauseChosen ), NULL, this );
	rbtn_build->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnBuildChosen ), NULL, this );
	rbtn_recipe->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRecipeChosen ), NULL, this );
	rbtn_tech->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTechChosen ), NULL, this );
	rbtn_limit->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLimitChosen ), NULL, this );
	rbtn_idle->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnIdleChosen ), NULL, this );
	rbtn_filter->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnfilterChosen ), NULL, this );
	rbtn_stop->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnStopChosen ), NULL, this );
	rbtn_priority->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPriorityChosen ), NULL, this );
	rbtn_rotate->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRotateChosen ), NULL, this );
	rbtn_pick_up->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPickUpChosen ), NULL, this );
	rbtn_drop->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnDropChosen ), NULL, this );
	rbtn_launch->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLaunchChosen ), NULL, this );
	rbtn_save->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnSaveChosen ), NULL, this );
	rbtn_cancel_crafting->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCancelCraftingChosen ), NULL, this );
	step_colour_picker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUI_Base::OnStepColourPickerColourChanged ), NULL, this );
	cmb_choose_template->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUI_Base::OnTemplateChosen ), NULL, this );
	cmb_choose_template->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnTemplateText ), NULL, this );
	btn_template_new->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnNewTemplateClicked ), NULL, this );
	btn_template_delete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteTemplateClicked ), NULL, this );
	btn_template_change_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateChangeStepClicked ), NULL, this );
	btn_template_delete_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateDeleteStepClicked ), NULL, this );
	btn_template_move_up_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveUpClicked ), NULL, this );
	btn_template_move_down_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveDownClicked ), NULL, this );
	btn_template_add_to_steps_list->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddToStepsListClicked ), NULL, this );
	btn_template_add_from_steps_list->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddFromStepsListClicked ), NULL, this );
	grid_template->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUI_Base::OnTemplateGridDoubleLeftClick ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnCancelButton ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnSearchButton ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::StepSeachOnText ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::StepSeachOnTextEnter ), NULL, this );
	btn_add_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnAddStepClicked ), NULL, this );
	btn_add_step->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnAddStepRightClicked ), NULL, this );
	btn_change_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnChangeStepClicked ), NULL, this );
	btn_delete_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteStepClicked ), NULL, this );
	btn_move_up->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveUpClicked ), NULL, this );
	btn_move_up->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveUpFiveClicked ), NULL, this );
	btn_move_down->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveDownClicked ), NULL, this );
	btn_move_down->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveDownFiveClicked ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUI_Base::OnStepsGridDoubleLeftClick ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( GUI_Base::OnStepsGridRangeSelect ), NULL, this );
	import_steps_into_steps_ctrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_Base::OnImportStepsIntoStepsCtrl ), NULL, this );
	import_steps_into_steps_ctrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsCtrlEnter ), NULL, this );
	import_steps_into_steps_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsBtnClick ), NULL, this );
	import_steps_into_template_ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlText ), NULL, this );
	import_steps_into_template_ctrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlEnter ), NULL, this );
	import_steps_into_template_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateBtnClick ), NULL, this );
	import_steps_text_import->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsTextUpdate ), NULL, this );

	m_mgr.UnInit();

}

Shortcut_changer::Shortcut_changer( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );

	sc_vertical_sizer = new wxBoxSizer( wxVERTICAL );

	sc_help_label = new wxStaticText( this, wxID_ANY, wxT("HELP: \nThe input fields expect a keybinding -> [<modifierkey>+<key>]\nYou can have multiple modifier keys among [\"Alt\", \"Ctrl\", \"Shift\"] separated with +.\nYou can only have one key in uppercase.\nYou can use F keys like \"F1\".\n\nExamples: \nAlt+G\nCtrl+Shift+G\nCtrl+F1"), wxDefaultPosition, wxDefaultSize, 0 );
	sc_help_label->Wrap( -1 );
	sc_vertical_sizer->Add( sc_help_label, 0, wxALL|wxEXPAND, 5 );

	sc_grid_sizer = new wxGridSizer( 7, 4, 5, 5 );


	sc_vertical_sizer->Add( sc_grid_sizer, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* sc_control_sizer;
	sc_control_sizer = new wxBoxSizer( wxHORIZONTAL );

	sc_reset_button = new wxButton( this, wxID_ANY, wxT("Reset shortcuts"), wxDefaultPosition, wxDefaultSize, 0|wxBORDER_THEME );
	sc_control_sizer->Add( sc_reset_button, 0, wxALL, 5 );

	sc_save_button = new wxButton( this, wxID_ANY, wxT("Save shortcuts"), wxDefaultPosition, wxDefaultSize, 0|wxBORDER_THEME );
	sc_control_sizer->Add( sc_save_button, 0, wxALL, 5 );


	sc_vertical_sizer->Add( sc_control_sizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( sc_vertical_sizer );
	this->Layout();
	sc_vertical_sizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Shortcut_changer::OnCloseShortcutChanger ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( Shortcut_changer::OnInitDialogShortcutChanger ) );
	sc_reset_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Shortcut_changer::OnButtonClickSCReset ), NULL, this );
	sc_save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Shortcut_changer::OnButtonClickSCSave ), NULL, this );
}

Shortcut_changer::~Shortcut_changer()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Shortcut_changer::OnCloseShortcutChanger ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( Shortcut_changer::OnInitDialogShortcutChanger ) );
	sc_reset_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Shortcut_changer::OnButtonClickSCReset ), NULL, this );
	sc_save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Shortcut_changer::OnButtonClickSCSave ), NULL, this );

}

BaseForDialogProgress::BaseForDialogProgress( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxVERTICAL );

	m_panel7 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxVERTICAL );

	txt_dialog_text = new wxStaticText( m_panel7, wxID_ANY, wxT("Generating script"), wxDefaultPosition, wxDefaultSize, 0 );
	txt_dialog_text->Wrap( -1 );
	bSizer113->Add( txt_dialog_text, 0, wxALIGN_CENTER|wxALL, 5 );

	progress_bar = new wxGauge( m_panel7, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	progress_bar->SetValue( 0 );
	bSizer113->Add( progress_bar, 0, wxALL, 5 );


	bSizer112->Add( bSizer113, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxHORIZONTAL );

	btn_dialog_progress_done = new wxButton( m_panel7, wxID_ANY, wxT("Done"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_dialog_progress_done->Enable( false );

	bSizer114->Add( btn_dialog_progress_done, 1, wxALIGN_CENTER|wxALL, 5 );


	bSizer112->Add( bSizer114, 1, wxEXPAND, 5 );


	m_panel7->SetSizer( bSizer112 );
	m_panel7->Layout();
	bSizer112->Fit( m_panel7 );
	bSizer111->Add( m_panel7, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer111 );
	this->Layout();
	bSizer111->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	btn_dialog_progress_done->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseForDialogProgress::GenerateScriptOnClick ), NULL, this );
}

BaseForDialogProgress::~BaseForDialogProgress()
{
	// Disconnect Events
	btn_dialog_progress_done->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseForDialogProgress::GenerateScriptOnClick ), NULL, this );

}
