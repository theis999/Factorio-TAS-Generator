///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-16-g4b3fa447)
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

	main_menubar->Append( menu_script, wxT("Script") );

	menu_steptypes = new wxMenu();
	steptypecolour_changer = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Change colours") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( steptypecolour_changer );

	menu_steptypes->AppendSeparator();

	wxMenuItem* shortcut_walk;
	shortcut_walk = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Walk") ) + wxT('\t') + wxT("Ctrl+2"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_walk );

	wxMenuItem* shortcut_craft;
	shortcut_craft = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Craft") ) + wxT('\t') + wxT("Ctrl+1"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_craft );

	wxMenuItem* shortcut_tech;
	shortcut_tech = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Tech") ) + wxT('\t') + wxT("Alt+3"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_tech );

	wxMenuItem* shortcut_idle;
	shortcut_idle = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Idle") ) + wxT('\t') + wxT("Alt+6"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_idle );

	wxMenuItem* shortcut_pick_up;
	shortcut_pick_up = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Pick Up") ) + wxT('\t') + wxT("Shift+4"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_pick_up );

	wxMenuItem* shortcut_drop;
	shortcut_drop = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Drop") ) + wxT('\t') + wxT("Shift+5"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_drop );

	wxMenuItem* shortcut_cancel_crafting;
	shortcut_cancel_crafting = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Cancel Crafting") ) + wxT('\t') + wxT("Shift+1"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_cancel_crafting );

	wxMenuItem* shortcut_mine;
	shortcut_mine = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Mine") ) + wxT('\t') + wxT("Alt+1"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_mine );

	wxMenuItem* shortcut_throw;
	shortcut_throw = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Throw") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_throw );

	wxMenuItem* shortcut_shoot;
	shortcut_shoot = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Shoot") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_shoot );

	wxMenuItem* shortcut_equip;
	shortcut_equip = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Equip") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_equip );

	menu_steptypes->AppendSeparator();

	wxMenuItem* shortcut_take;
	shortcut_take = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Take") ) + wxT('\t') + wxT("Alt+4"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_take );

	wxMenuItem* shortcut_put;
	shortcut_put = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Put") ) + wxT('\t') + wxT("Alt+5"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_put );

	wxMenuItem* shortcut_build;
	shortcut_build = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Build") ) + wxT('\t') + wxT("Alt+2"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_build );

	wxMenuItem* shortcut_recipe;
	shortcut_recipe = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Recipe") ) + wxT('\t') + wxT("Ctrl+5"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_recipe );

	wxMenuItem* shortcut_limit;
	shortcut_limit = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Limit") ) + wxT('\t') + wxT("Shift+2"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_limit );

	wxMenuItem* shortcut_filter;
	shortcut_filter = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Filter") ) + wxT('\t') + wxT("Shift+3"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_filter );

	wxMenuItem* shortcut_priority;
	shortcut_priority = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Priority") ) + wxT('\t') + wxT("Shift+1"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_priority );

	wxMenuItem* shortcut_launch;
	shortcut_launch = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Launch") ) + wxT('\t') + wxT("Shift+6"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_launch );

	wxMenuItem* shortcut_rotate;
	shortcut_rotate = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Rotate") ) + wxT('\t') + wxT("Ctrl+4"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_rotate );

	menu_steptypes->AppendSeparator();

	wxMenuItem* shortcut_game_speed;
	shortcut_game_speed = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Game Speed") ) + wxT('\t') + wxT("Ctrl+3"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_game_speed );

	wxMenuItem* shortcut_pause;
	shortcut_pause = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Pause") ) + wxT('\t') + wxT("Alt+R"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_pause );

	wxMenuItem* shortcut_stop;
	shortcut_stop = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Stop") ) + wxT('\t') + wxT("Ctrl+6"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_stop );

	wxMenuItem* shortcut_save;
	shortcut_save = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("Alt+Q"), wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_save );

	wxMenuItem* shortcut_never_idle;
	shortcut_never_idle = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Never idle") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_never_idle );

	wxMenuItem* shortcut_keep_walking;
	shortcut_keep_walking = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Keep walking") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_keep_walking );

	wxMenuItem* shortcut_keep_on_path;
	shortcut_keep_on_path = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Keep on path") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_keep_on_path );

	wxMenuItem* shortcut_keep_crafting;
	shortcut_keep_crafting = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Keep crafting") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_keep_crafting );

	menu_steptypes->AppendSeparator();

	wxMenuItem* shortcut_enter_exit;
	shortcut_enter_exit = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Enter exit vehicle") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_enter_exit );

	wxMenuItem* shortcut_drive;
	shortcut_drive = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Drive vehicle") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_drive );

	wxMenuItem* shortcut_send;
	shortcut_send = new wxMenuItem( menu_steptypes, wxID_ANY, wxString( wxT("Send train") ) , wxEmptyString, wxITEM_NORMAL );
	menu_steptypes->Append( shortcut_send );

	main_menubar->Append( menu_steptypes, wxT("Step types") );

	menu_shortcuts = new wxMenu();
	wxMenuItem* shortcut_changer;
	shortcut_changer = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Change shortcuts") ) , wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_changer );

	menu_shortcuts->AppendSeparator();

	wxMenuItem* shortcut_add_step;
	shortcut_add_step = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Add Step") ) + wxT('\t') + wxT("Alt+A"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_add_step );

	wxMenuItem* shortcut_add_step_alt;
	shortcut_add_step_alt = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Add Step Under") ) + wxT('\t') + wxT("Ctrl+A"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_add_step_alt );

	wxMenuItem* shortcut_change_step;
	shortcut_change_step = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Change Step") ) + wxT('\t') + wxT("Alt+C"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_change_step );

	wxMenuItem* shortcut_change_step_alt;
	shortcut_change_step_alt = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Change Step Force") ) + wxT('\t') + wxT("Ctrl+Alt+C"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_change_step_alt );

	wxMenuItem* shortcut_delete_step;
	shortcut_delete_step = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Delete Step") ) + wxT('\t') + wxT("Del"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_delete_step );

	wxMenuItem* shortcut_delete_step_alt;
	shortcut_delete_step_alt = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Delete Step Force") ) + wxT('\t') + wxT("Ctrl+Del"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_delete_step_alt );

	wxMenuItem* shortcut_move_up;
	shortcut_move_up = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Move Up") ) + wxT('\t') + wxT("Alt+W"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_move_up );

	wxMenuItem* shortcut_move_up_alt;
	shortcut_move_up_alt = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Move Up 5") ) , wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_move_up_alt );

	wxMenuItem* shortcut_move_down;
	shortcut_move_down = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Move Down") ) + wxT('\t') + wxT("Alt+S"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_move_down );

	wxMenuItem* shortcut_move_down_alt;
	shortcut_move_down_alt = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Move Down 5") ) , wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_move_down_alt );

	wxMenuItem* shortcut_search;
	shortcut_search = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Search") ) + wxT('\t') + wxT("Ctrl+F"), wxT("Finds the nearest searchbox and focuses on it"), wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_search );

	wxMenuItem* shortcut_undo;
	shortcut_undo = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Undo") ) + wxT('\t') + wxT("Ctrl+Z"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_undo );

	wxMenuItem* shortcut_redo;
	shortcut_redo = new wxMenuItem( menu_shortcuts, wxID_ANY, wxString( wxT("Redo") ) + wxT('\t') + wxT("Ctrl+Y"), wxEmptyString, wxITEM_NORMAL );
	menu_shortcuts->Append( shortcut_redo );

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
	goal_any_percent = new wxMenuItem( menu_goals, wxID_ANY, wxString( wxT("Any%") ) , wxEmptyString, wxITEM_RADIO );
	menu_goals->Append( goal_any_percent );

	wxMenuItem* scenario_supply_challenge;
	scenario_supply_challenge = new wxMenuItem( menu_goals, wxID_ANY, wxString( wxT("Supply challenge") ) , wxEmptyString, wxITEM_RADIO );
	menu_goals->Append( scenario_supply_challenge );

	main_menubar->Append( menu_goals, wxT("Goal") );

	menu_loglevel = new wxMenu();
	logging_savegame = new wxMenuItem( menu_loglevel, wxID_ANY, wxString( wxT("Print savegame") ) , wxEmptyString, wxITEM_CHECK );
	menu_loglevel->Append( logging_savegame );
	logging_savegame->Check( true );

	logging_tech = new wxMenuItem( menu_loglevel, wxID_ANY, wxString( wxT("Print tech") ) , wxT("Print changes to the research queue to the console"), wxITEM_CHECK );
	menu_loglevel->Append( logging_tech );
	logging_tech->Check( true );

	logging_comment = new wxMenuItem( menu_loglevel, wxID_ANY, wxString( wxT("Print comment") ) , wxT("Print step comments to the console"), wxITEM_CHECK );
	menu_loglevel->Append( logging_comment );
	logging_comment->Check( true );

	menu_loglevel->AppendSeparator();

	wxMenuItem* loglevel_debug;
	loglevel_debug = new wxMenuItem( menu_loglevel, wxID_ANY, wxString( wxT("Debug") ) , wxT("This is geared towards Debugging. Where all messages are printed to console."), wxITEM_RADIO );
	menu_loglevel->Append( loglevel_debug );

	wxMenuItem* loglevel_development;
	loglevel_development = new wxMenuItem( menu_loglevel, wxID_ANY, wxString( wxT("Development") ) , wxT("This is geared towards TAS Development. Where some messages are printed to the console and some are filtered out."), wxITEM_RADIO );
	menu_loglevel->Append( loglevel_development );
	loglevel_development->Check( true );

	wxMenuItem* loglevel_release;
	loglevel_release = new wxMenuItem( menu_loglevel, wxID_ANY, wxString( wxT("Release") ) , wxT("This is geared towards TAS Release. Where almost all messages are filtered out, except critical errors."), wxITEM_RADIO );
	menu_loglevel->Append( loglevel_release );

	main_menubar->Append( menu_loglevel, wxT("Log level") );

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

	menu_other = new wxMenu();
	legacy_mining = new wxMenuItem( menu_other, wxID_ANY, wxString( wxT("Legacy mining") ) , wxT("Legacy mining is 1 tick slower."), wxITEM_CHECK );
	menu_other->Append( legacy_mining );

	intermediate_walk_towards = new wxMenuItem( menu_other, wxID_ANY, wxString( wxT("Walk towards on intermediate walk") ) , wxT("Adds modifier \"walk towards\" on intermediate walk steps.\nWhich should generally make those walk steps faster to perform."), wxITEM_CHECK );
	menu_other->Append( intermediate_walk_towards );
	intermediate_walk_towards->Check( true );

	no_intermediate_walk = new wxMenuItem( menu_other, wxID_ANY, wxString( wxT("Always force") ) , wxT("Removes sanity checks for distance and therefor intermediate walk steps."), wxITEM_CHECK );
	menu_other->Append( no_intermediate_walk );

	main_menubar->Append( menu_other, wxT("Other") );

	this->SetMenuBar( main_menubar );

	type_panel = new TypePanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxBORDER_NONE|wxTAB_TRAVERSAL );
	m_mgr.AddPane( type_panel, wxAuiPaneInfo() .Name( wxT("StepTypePanel") ).Top() .Caption( wxT("Step type") ).CloseButton( false ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( 720,150 ) ).BottomDockable( false ).LeftDockable( false ).RightDockable( false ).Row( 2 ).BestSize( wxSize( 720,140 ) ).MinSize( wxSize( 710,120 ) ).Layer( 1 ) );

	wxBoxSizer* type_sizer;
	type_sizer = new wxBoxSizer( wxHORIZONTAL );

	character_panel = new wxPanel( type_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 5, 3, 5, 5 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	rbtn_walk = new wxRadioButton( character_panel, wxID_ANY, wxT("Walk"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_walk->SetToolTip( wxT("Makes the character walk to a point") );

	fgSizer4->Add( rbtn_walk, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_craft = new wxRadioButton( character_panel, wxID_ANY, wxT("Craft"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_craft->SetToolTip( wxT("Makes the character craft an item") );

	fgSizer4->Add( rbtn_craft, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_tech = new wxRadioButton( character_panel, wxID_ANY, wxT("Tech"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_tech->SetToolTip( wxT("Adds a technologi to the research queue") );

	fgSizer4->Add( rbtn_tech, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_idle = new wxRadioButton( character_panel, wxID_ANY, wxT("Idle"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_idle->SetToolTip( wxT("Makes the character do nothing for X ticks") );

	fgSizer4->Add( rbtn_idle, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_pick_up = new wxRadioButton( character_panel, wxID_ANY, wxT("Pick Up"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_pick_up->SetToolTip( wxT("Makes the character start to pick up items on the floor, same as pressing ( f )") );

	fgSizer4->Add( rbtn_pick_up, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_drop = new wxRadioButton( character_panel, wxID_ANY, wxT("Drop"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_drop->SetToolTip( wxT("Makes the character drop an item, same as pressing ( z )") );

	fgSizer4->Add( rbtn_drop, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_cancel_crafting = new wxRadioButton( character_panel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_cancel_crafting->SetToolTip( wxT("Cancels items in the players crafting queue, \nreturning the ingredients to your hand") );

	fgSizer4->Add( rbtn_cancel_crafting, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_mine = new wxRadioButton( character_panel, wxID_ANY, wxT("Mine"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_mine->SetToolTip( wxT("Makes the character mine an area, if there is a building, tree or rock they will remove that instead") );

	fgSizer4->Add( rbtn_mine, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_throw = new wxRadioButton( character_panel, wxID_ANY, wxT("Throw"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_throw->SetToolTip( wxT("Makes the character throw a grenade or combat robot, at the target location.") );

	fgSizer4->Add( rbtn_throw, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_shoot = new wxRadioButton( character_panel, wxID_ANY, wxT("Shoot"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_shoot->SetToolTip( wxT("Makes the character shoot at a target for Amount ticks") );

	fgSizer4->Add( rbtn_shoot, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_equip = new wxRadioButton( character_panel, wxID_ANY, wxT("Equip"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_equip->SetToolTip( wxT("Makes the character equip a weapon, ammo or armor.\n\nDrawing items from the characters main inventory, and potentially returning them there too.\n\nThis is a set typed action, so if you Equip 3 firearm magazine into a slot where there are 5 firearm magazine items, then it will return 2.\n") );

	fgSizer4->Add( rbtn_equip, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_character_panel_hidden = new wxRadioButton( character_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_character_panel_hidden->SetValue( true );
	rbtn_character_panel_hidden->Hide();

	fgSizer4->Add( rbtn_character_panel_hidden, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	character_panel->SetSizer( fgSizer4 );
	character_panel->Layout();
	fgSizer4->Fit( character_panel );
	type_sizer->Add( character_panel, 1, wxALL|wxEXPAND, 5 );

	building_panel = new wxPanel( type_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 4, 3, 5, 5 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* type_sizer_Take;
	type_sizer_Take = new wxBoxSizer( wxVERTICAL );

	rbtn_take = new wxRadioButton( building_panel, wxID_ANY, wxT("Take"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_take->SetToolTip( wxT("Makes the character take items from a container [chest, furnace, assembler, etc.] and put them into their inventory") );

	type_sizer_Take->Add( rbtn_take, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Take, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Put;
	type_sizer_Put = new wxBoxSizer( wxVERTICAL );

	rbtn_put = new wxRadioButton( building_panel, wxID_ANY, wxT("Put"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_put->SetToolTip( wxT("Makes the character put items from his inventory into a container [chest, furnace, assembler, etc.]") );

	type_sizer_Put->Add( rbtn_put, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Put, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Build;
	type_sizer_Build = new wxBoxSizer( wxVERTICAL );

	rbtn_build = new wxRadioButton( building_panel, wxID_ANY, wxT("Build"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_build->SetToolTip( wxT("Makes the character build an entity") );

	type_sizer_Build->Add( rbtn_build, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Build, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Recipe;
	type_sizer_Recipe = new wxBoxSizer( wxVERTICAL );

	rbtn_recipe = new wxRadioButton( building_panel, wxID_ANY, wxT("Recipe"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_recipe->SetToolTip( wxT("Makes the character change the recipe for a crafting machine") );

	type_sizer_Recipe->Add( rbtn_recipe, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Recipe, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Limit;
	type_sizer_Limit = new wxBoxSizer( wxVERTICAL );

	rbtn_limit = new wxRadioButton( building_panel, wxID_ANY, wxT("Limit"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_limit->SetToolTip( wxT("Makes the character limit a chest to X slots") );

	type_sizer_Limit->Add( rbtn_limit, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Limit, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Filter;
	type_sizer_Filter = new wxBoxSizer( wxVERTICAL );

	rbtn_filter = new wxRadioButton( building_panel, wxID_ANY, wxT("Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_filter->SetToolTip( wxT("Makes the character set the filter on either: a filter-inserter, a splitter or a slot in a car / train wagon") );

	type_sizer_Filter->Add( rbtn_filter, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Filter, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Priority;
	type_sizer_Priority = new wxBoxSizer( wxVERTICAL );

	rbtn_priority = new wxRadioButton( building_panel, wxID_ANY, wxT("Priority"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_priority->SetToolTip( wxT("Makes the character set the input and output priority on a splitter.\nNeeds to be applied before setting the filter on the splitter.") );

	type_sizer_Priority->Add( rbtn_priority, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Priority, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Launch;
	type_sizer_Launch = new wxBoxSizer( wxVERTICAL );

	rbtn_launch = new wxRadioButton( building_panel, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_launch->SetToolTip( wxT("Makes the character launch a rocket from a rocket silo") );

	type_sizer_Launch->Add( rbtn_launch, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Launch, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Rotate;
	type_sizer_Rotate = new wxBoxSizer( wxVERTICAL );

	rbtn_rotate = new wxRadioButton( building_panel, wxID_ANY, wxT("Rotate"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_rotate->SetToolTip( wxT("Makes the character rotate an entity X times.\nIf X is 3 then the entity is rotated once counter-clock-wise.") );

	type_sizer_Rotate->Add( rbtn_rotate, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer5->Add( type_sizer_Rotate, 1, wxEXPAND, 5 );

	rbtn_next = new wxRadioButton( building_panel, wxID_ANY, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( rbtn_next, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_building_panel_hidden = new wxRadioButton( building_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_building_panel_hidden->SetValue( true );
	rbtn_building_panel_hidden->Hide();

	fgSizer5->Add( rbtn_building_panel_hidden, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	building_panel->SetSizer( fgSizer5 );
	building_panel->Layout();
	fgSizer5->Fit( building_panel );
	type_sizer->Add( building_panel, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	game_panel = new wxPanel( type_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 5, 2, 5, 5 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* type_sizer_GameSpeed;
	type_sizer_GameSpeed = new wxBoxSizer( wxVERTICAL );

	rbtn_game_speed = new wxRadioButton( game_panel, wxID_ANY, wxT("Game Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_game_speed->SetToolTip( wxT("Changes the game speed to X%") );

	type_sizer_GameSpeed->Add( rbtn_game_speed, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer6->Add( type_sizer_GameSpeed, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Pause;
	type_sizer_Pause = new wxBoxSizer( wxVERTICAL );

	rbtn_pause = new wxRadioButton( game_panel, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_pause->SetToolTip( wxT("Pauses the game, when all previous tasks are completed. Same as /Pause in the console, the game can be continued with /Resume") );

	type_sizer_Pause->Add( rbtn_pause, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer6->Add( type_sizer_Pause, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Stop;
	type_sizer_Stop = new wxBoxSizer( wxHORIZONTAL );

	rbtn_stop = new wxRadioButton( game_panel, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_stop->SetToolTip( wxT("Stops the generator from processing further. Effectively marking this as the end of the TAS instead of using the end of the file.") );

	type_sizer_Stop->Add( rbtn_stop, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer6->Add( type_sizer_Stop, 1, wxEXPAND, 5 );

	wxBoxSizer* type_sizer_Save;
	type_sizer_Save = new wxBoxSizer( wxVERTICAL );

	rbtn_save = new wxRadioButton( game_panel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_save->SetToolTip( wxT("Creates a save game named by the comment, the tas can only be continued from these save games.\nIn single player the save game name has the prefix autosave-") );

	type_sizer_Save->Add( rbtn_save, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	fgSizer6->Add( type_sizer_Save, 1, wxEXPAND, 5 );

	rbtn_never_idle = new wxRadioButton( game_panel, wxID_ANY, wxT("Never Idle"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_never_idle->SetToolTip( wxT("Toggles that the TAS that it should execute a step in every tick.\nIf it can't it will raise a warning through the console so you can improve the script.") );

	fgSizer6->Add( rbtn_never_idle, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_keep_walking = new wxRadioButton( game_panel, wxID_ANY, wxT("Keep Walking"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_keep_walking->SetToolTip( wxT("Toggles that the TAS should never stand still in one spot.\nIf it can't it will raise a warning through the console so you can improve the script.") );

	fgSizer6->Add( rbtn_keep_walking, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_keep_on_path = new wxRadioButton( game_panel, wxID_ANY, wxT("Keep on Path"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_keep_on_path->SetToolTip( wxT("Toggles that the TAS should stay on pathing, such stone-path or concrete.\nIf it can't it will raise a warning through the console so you can improve the script.\n\nThis uses simple detection of: character speed > base speed. So it will be inaccurate if the speed is modified in other ways than tiles.") );

	fgSizer6->Add( rbtn_keep_on_path, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_keep_crafting = new wxRadioButton( game_panel, wxID_ANY, wxT("Keep Crafting"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_keep_crafting->SetToolTip( wxT("Toggles that the TAS should keep the handcrafting queued active.\nIf it can't it will raise a warning through the console so you can improve the script.") );

	fgSizer6->Add( rbtn_keep_crafting, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_game_panel_hidden = new wxRadioButton( game_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_game_panel_hidden->SetValue( true );
	rbtn_game_panel_hidden->Hide();

	fgSizer6->Add( rbtn_game_panel_hidden, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	game_panel->SetSizer( fgSizer6 );
	game_panel->Layout();
	fgSizer6->Fit( game_panel );
	type_sizer->Add( game_panel, 1, wxEXPAND | wxALL, 5 );

	vehicle_panel = new wxPanel( type_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 5, 1, 5, 5 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	rbtn_enter_exit = new wxRadioButton( vehicle_panel, wxID_ANY, wxT("Enter"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_enter_exit->SetToolTip( wxT("Toggles between enter & exit vehicle.\nIf in proximity to the vehicle the character will enter it.\nIf inside a vehicle, the character will exit it.") );

	fgSizer61->Add( rbtn_enter_exit, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_drive = new wxRadioButton( vehicle_panel, wxID_ANY, wxT("Drive"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_drive->SetToolTip( wxT("Change the acceleration and direction of the vehicle your character is inside. ei driving.\n") );

	fgSizer61->Add( rbtn_drive, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_send = new wxRadioButton( vehicle_panel, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_send->Hide();
	rbtn_send->SetToolTip( wxT("Send a train anywhere on the map a temporary stop") );

	fgSizer61->Add( rbtn_send, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	rbtn_vehicle_panel_hidden = new wxRadioButton( vehicle_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rbtn_vehicle_panel_hidden->SetValue( true );
	rbtn_vehicle_panel_hidden->Hide();

	fgSizer61->Add( rbtn_vehicle_panel_hidden, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	vehicle_panel->SetSizer( fgSizer61 );
	vehicle_panel->Layout();
	fgSizer61->Fit( vehicle_panel );
	type_sizer->Add( vehicle_panel, 1, wxEXPAND | wxALL, 5 );


	type_panel->SetSizer( type_sizer );
	type_panel->Layout();
	type_sizer->Fit( type_panel );
	detail_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mgr.AddPane( detail_panel, wxAuiPaneInfo() .Name( wxT("StepDetailPanel") ).Top() .Caption( wxT("Step detail") ).CloseButton( false ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( 1010,155 ) ).BottomDockable( false ).LeftDockable( false ).RightDockable( false ).Row( 2 ).BestSize( wxSize( 650,140 ) ).MinSize( wxSize( 650,120 ) ).Layer( 1 ) );

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

	wxString radio_accelerationChoices[] = { wxT("Idle"), wxT("Accel"), wxT("Break"), wxT("Back") };
	int radio_accelerationNChoices = sizeof( radio_accelerationChoices ) / sizeof( wxString );
	radio_acceleration = new wxRadioBox( detail_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, radio_accelerationNChoices, radio_accelerationChoices, 4, wxRA_SPECIFY_COLS );
	radio_acceleration->SetSelection( 1 );
	radio_acceleration->SetFont( wxFont( 6, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	radio_acceleration->Hide();
	radio_acceleration->SetToolTip( wxT("Specifies vehicle momentum") );
	radio_acceleration->SetMinSize( wxSize( 180,-1 ) );

	detail_sizer_Input->Add( radio_acceleration, 0, wxLEFT|wxRIGHT, 5 );


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
	step_modifier_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mgr.AddPane( step_modifier_panel, wxAuiPaneInfo() .Name( wxT("ModifiersPanel") ).Top() .Caption( wxT("Modifiers") ).CloseButton( false ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( 295,159 ) ).BottomDockable( false ).LeftDockable( false ).RightDockable( false ).Row( 2 ).BestSize( wxSize( 290,140 ) ).MinSize( wxSize( 290,120 ) ).MaxSize( wxSize( 290,180 ) ).Layer( 1 ) );

	wxBoxSizer* step_modifier_panel_sizer;
	step_modifier_panel_sizer = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* step_modifier_flex;
	step_modifier_flex = new wxFlexGridSizer( 0, 3, 5, 5 );
	step_modifier_flex->SetFlexibleDirection( wxBOTH );
	step_modifier_flex->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	sizer_no_order = new wxBoxSizer( wxVERTICAL );

	modifier_no_order_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("No order"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_no_order_checkbox->Enable( false );
	modifier_no_order_checkbox->SetToolTip( wxT("Specifies that this step is part of a block of steps that can be executed in any order.\n\nThis allows the TAS to optimize the step's execution order.") );

	sizer_no_order->Add( modifier_no_order_checkbox, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	modifier_no_order_button = new wxButton( step_modifier_panel, wxID_ANY, wxT("No order"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_no_order_button->Hide();
	modifier_no_order_button->SetToolTip( wxT("Specifies that these steps are part of a block of steps that can be executed in any order.\n\nThis allows the TAS to optimize the step's execution order.") );

	sizer_no_order->Add( modifier_no_order_button, 0, 0, 5 );


	step_modifier_flex->Add( sizer_no_order, 1, wxEXPAND, 5 );

	sizer_skip = new wxBoxSizer( wxVERTICAL );

	modifier_skip_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("Skip"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_skip_checkbox->SetToolTip( wxT("Tells the generator to skip over this step. Allowing you to plan steps without them being executed.") );

	sizer_skip->Add( modifier_skip_checkbox, 0, wxALL, 5 );

	modifier_skip_button = new wxButton( step_modifier_panel, wxID_ANY, wxT("Skip"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_skip_button->Hide();
	modifier_skip_button->SetToolTip( wxT("Tells the generator to skip over these steps. Allowing you to plan steps without them being executed.") );

	sizer_skip->Add( modifier_skip_button, 0, 0, 5 );


	step_modifier_flex->Add( sizer_skip, 1, wxEXPAND, 5 );

	modifier_wait_for_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("Wait for"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_wait_for_checkbox->Enable( false );
	modifier_wait_for_checkbox->SetToolTip( wxT("Waits for completion before proceeding.\n\nFor Set Recipe this means it won't proceed before the assembler is not crafting.\nFor Crafting this means it won't proceed before the crafting queue is empty.") );

	step_modifier_flex->Add( modifier_wait_for_checkbox, 0, wxALL, 5 );

	sizer_force = new wxBoxSizer( wxVERTICAL );

	modifier_force_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("Force"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_force_checkbox->SetToolTip( wxT("Tells the generator to not check if the character can reach the entity. This prevents intermediate walk steps which can mess up your execution but it can also leave your character stranded on a step that cannot be executed.") );

	sizer_force->Add( modifier_force_checkbox, 0, wxALL, 5 );

	modifier_force_button = new wxButton( step_modifier_panel, wxID_ANY, wxT("Force"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_force_button->Hide();
	modifier_force_button->SetToolTip( wxT("Tells the generator to ignore distance calculations for these steps.") );

	sizer_force->Add( modifier_force_button, 0, 0, 5 );


	step_modifier_flex->Add( sizer_force, 1, wxEXPAND, 5 );

	modifier_cancel_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("Cancel others"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_cancel_checkbox->Enable( false );
	modifier_cancel_checkbox->SetToolTip( wxT("Cancels anything else in your crafting queue or research queue, before adding the new item.") );

	step_modifier_flex->Add( modifier_cancel_checkbox, 0, wxALL, 5 );

	modifier_split_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("Split"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_split_checkbox->Enable( false );
	modifier_split_checkbox->SetToolTip( wxT("Tells the generator that the mining step is incomplete so the building is not removed from the map. Allowing you to still interact with it.") );

	step_modifier_flex->Add( modifier_split_checkbox, 0, wxALL, 5 );

	modifier_walk_towards_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("Walk towards"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_walk_towards_checkbox->Enable( false );
	modifier_walk_towards_checkbox->SetToolTip( wxT("This simplifies walking - by saying that the direction is important not the destination.\nAllowing the next walk command to be executed before the TAS reaches the destination.") );

	step_modifier_flex->Add( modifier_walk_towards_checkbox, 0, wxALL, 5 );

	modifier_all_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("All"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_all_checkbox->Enable( false );
	modifier_all_checkbox->SetToolTip( wxT("This allows you take all items from the specific inventory. Ignoring item type and amount.") );

	step_modifier_flex->Add( modifier_all_checkbox, 0, wxALL, 5 );

	sizer_vehicle = new wxBoxSizer( wxVERTICAL );

	modifier_vehicle_checkbox = new wxCheckBox( step_modifier_panel, wxID_ANY, wxT("Vehicle"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_vehicle_checkbox->SetToolTip( wxT("Tells the generator that this step is associated with a vehicle instead of building.\nThe generator will then not attempt to match the step with a building.\n\nThis will also tell the TAS controller to be lenient when matching the entity with a 5 tile search radius.") );

	sizer_vehicle->Add( modifier_vehicle_checkbox, 0, wxALL, 5 );

	modifier_vehicle_button = new wxButton( step_modifier_panel, wxID_ANY, wxT("Vehicle"), wxDefaultPosition, wxDefaultSize, 0 );
	modifier_vehicle_button->Hide();
	modifier_vehicle_button->SetToolTip( wxT("Tells the generator that this step is associated with a vehicle instead of building.\nThe generator will then not attempt to match the step with a building.\n\nThis will also tell the TAS controller to be lenient when matching the entity with a 5 tile search radius.") );

	sizer_vehicle->Add( modifier_vehicle_button, 0, 0, 5 );


	step_modifier_flex->Add( sizer_vehicle, 1, wxEXPAND, 5 );


	step_modifier_panel_sizer->Add( step_modifier_flex, 1, wxALL|wxEXPAND, 5 );


	step_modifier_panel->SetSizer( step_modifier_panel_sizer );
	step_modifier_panel->Layout();
	step_modifier_panel_sizer->Fit( step_modifier_panel );
	walk_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mgr.AddPane( walk_panel, wxAuiPaneInfo() .Top() .Caption( wxT("Walk") ).PinButton( true ).Dock().Resizable().FloatingSize( wxSize( 96,179 ) ).Row( 2 ).BestSize( wxSize( 80,140 ) ).MinSize( wxSize( 80,140 ) ).MaxSize( wxSize( 80,140 ) ).Layer( 1 ) );

	wxBoxSizer* walk_panel_sizer;
	walk_panel_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* walk_panel_control_sizer;
	walk_panel_control_sizer = new wxBoxSizer( wxHORIZONTAL );


	walk_panel_control_sizer->Add( 0, 0, 1, wxEXPAND, 5 );

	walk_panel_increment_spin = new wxSpinCtrlDouble( walk_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT|wxSP_ARROW_KEYS, 0.001, 9.999, 1, 0.5 );
	walk_panel_increment_spin->SetDigits( 3 );
	walk_panel_increment_spin->SetToolTip( wxT("Increment value for how big each walk step is from your current position.") );
	walk_panel_increment_spin->SetMaxSize( wxSize( 60,-1 ) );

	walk_panel_control_sizer->Add( walk_panel_increment_spin, 0, wxALIGN_BOTTOM|wxALL, 5 );


	walk_panel_sizer->Add( walk_panel_control_sizer, 1, wxEXPAND, 5 );

	walk_panel_grid_panel = new wxPanel( walk_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxGridSizer* walk_panel_grid_sizer;
	walk_panel_grid_sizer = new wxGridSizer( 3, 3, 0, 0 );

	walk_panel_button_upleft = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("↖"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_upleft->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_upleft->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_upleft, 0, wxALL, 5 );

	walk_panel_button_up = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("↑"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_up->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_up->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_up, 0, wxALL, 5 );

	walk_panel_button_upright = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("↗"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_upright->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_upright->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_upright, 0, wxALL, 5 );

	walk_panel_button_left = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("←"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_left->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_left->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_left, 0, wxALL, 5 );


	walk_panel_grid_sizer->Add( 22, 22, 1, 0, 5 );

	walk_panel_button_right = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("→"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_right->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_right->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_right, 0, wxALL, 5 );

	walk_panel_button_downleft = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("↙"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_downleft->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_downleft->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_downleft, 0, wxALL, 5 );

	walk_panel_button_down = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("↓"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_down->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_down->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_down, 0, wxALL, 5 );

	walk_panel_button_downright = new wxButton( walk_panel_grid_panel, wxID_ANY, wxT("↘"), wxDefaultPosition, wxDefaultSize, 0 );
	walk_panel_button_downright->SetMinSize( wxSize( 22,22 ) );
	walk_panel_button_downright->SetMaxSize( wxSize( 22,22 ) );

	walk_panel_grid_sizer->Add( walk_panel_button_downright, 0, wxALL, 5 );


	walk_panel_grid_panel->SetSizer( walk_panel_grid_sizer );
	walk_panel_grid_panel->Layout();
	walk_panel_grid_sizer->Fit( walk_panel_grid_panel );
	walk_panel_sizer->Add( walk_panel_grid_panel, 1, wxALIGN_CENTER|wxALL, 5 );


	walk_panel->SetSizer( walk_panel_sizer );
	walk_panel->Layout();
	walk_panel_sizer->Fit( walk_panel );
	main_book = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_TAB_EXTERNAL_MOVE|wxAUI_NB_TAB_MOVE|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TOP|wxAUI_NB_WINDOWLIST_BUTTON|wxBORDER_RAISED );
	m_mgr.AddPane( main_book, wxAuiPaneInfo() .Name( wxT("DataBook") ).Center() .Caption( wxT("Book") ).CaptionVisible( false ).CloseButton( false ).MaximizeButton( true ).MinimizeButton( true ).PinButton( true ).Dock().Resizable().FloatingSize( wxDefaultSize ).Row( 2 ).MinSize( wxSize( 500,500 ) ).Layer( 2 ).CentrePane() );

	import_steps_panel = new ImportStepsPanel( main_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT("Import") );
	wxBoxSizer* import_steps_sizer;
	import_steps_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* import_steps_ctrl_sizer;
	import_steps_ctrl_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* import_steps_into_steps_sizer;
	import_steps_into_steps_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );

	import_steps_into_steps_index_btn = new wxButton( import_steps_panel, wxID_ANY, wxT("C"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxBU_EXACTFIT|wxBORDER_NONE );
	import_steps_into_steps_index_btn->SetToolTip( wxT("Copy current row index from the Steps panel into number box\n - Left click to import before the selected step\n - Right click to import after the selected step") );
	import_steps_into_steps_index_btn->SetMinSize( wxSize( 25,25 ) );

	bSizer71->Add( import_steps_into_steps_index_btn, 0, wxBOTTOM|wxLEFT|wxTOP, 4 );

	import_steps_into_steps_ctrl = new wxSpinCtrl( import_steps_panel, wxID_ANY, wxT("-1"), wxDefaultPosition, wxSize( 121,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, -999999, 999999, -1 );
	import_steps_into_steps_ctrl->SetToolTip( wxT("Positive numbers places the imported steps in the step list from the top and negative numbers from the bottom.\nWith 0 being the top element and -1 being the bottom element.\nAnd -2 Inserting steps between last and second to last element.") );
	import_steps_into_steps_ctrl->SetMinSize( wxSize( 121,-1 ) );
	import_steps_into_steps_ctrl->SetMaxSize( wxSize( 121,-1 ) );

	bSizer71->Add( import_steps_into_steps_ctrl, 0, wxBOTTOM|wxRIGHT|wxTOP, 5 );


	import_steps_into_steps_sizer->Add( bSizer71, 1, wxEXPAND, 5 );

	import_steps_into_steps_btn = new wxButton( import_steps_panel, wxID_ANY, wxT("Into steps"), wxDefaultPosition, wxSize( 145,-1 ), 0 );
	import_steps_into_steps_btn->SetMinSize( wxSize( 145,-1 ) );
	import_steps_into_steps_btn->SetMaxSize( wxSize( 145,-1 ) );

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
	import_steps_text_import = new wxTextCtrl( import_steps_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxTE_MULTILINE );
	import_steps_text_import->SetMinSize( wxSize( 450,600 ) );

	import_steps_text_sizer->Add( import_steps_text_import, 0, wxALL|wxEXPAND, 5 );


	import_steps_sizer->Add( import_steps_text_sizer, 1, wxEXPAND, 5 );


	import_steps_panel->SetSizer( import_steps_sizer );
	import_steps_panel->Layout();
	import_steps_sizer->Fit( import_steps_panel );
	main_book->AddPage( import_steps_panel, wxT("Import"), false, wxNullBitmap );
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
	step_search_ctrl->SetToolTip( wxT("Search for a step.\n\n( ; ) Semicolon to have multiple search terms [ term1; term2; term3 ].\n( : ) Colon to specify column [ column:term ].") );

	step_panel_search_sizer->Add( step_search_ctrl, 0, wxALL, 5 );

	step_search_toggle_updown = new wxCheckBox( step_panel, wxID_ANY, wxT("Search up"), wxDefaultPosition, wxSize( 72,20 ), 0 );
	step_search_toggle_updown->SetValue(true);
	step_panel_search_sizer->Add( step_search_toggle_updown, 0, wxALL, 7 );

	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );

	step_colour_picker = new wxColourPickerCtrl( step_panel, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ), wxDefaultPosition, wxSize( 85,25 ), wxCLRP_DEFAULT_STYLE|wxCLRP_SHOW_LABEL );
	step_colour_picker->SetToolTip( wxT("Select a number of rows to set the colour on them.\nThe colour is automaticly matches the first row of the selected area.") );

	bSizer65->Add( step_colour_picker, 0, wxALL, 5 );


	step_panel_search_sizer->Add( bSizer65, 1, wxEXPAND, 5 );

	steps_focus_checkbox = new wxCheckBox( step_panel, wxID_ANY, wxT("Focus"), wxDefaultPosition, wxDefaultSize, 0 );
	steps_focus_checkbox->SetToolTip( wxT("Focuses the list on steps on the last segments.\nBy hidding every step before the second to last save step.") );

	step_panel_search_sizer->Add( steps_focus_checkbox, 0, wxALL, 5 );


	step_panel_sizer->Add( step_panel_search_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* step_panel_control_sizer;
	step_panel_control_sizer = new wxBoxSizer( wxHORIZONTAL );

	btn_add_step = new wxButton( step_panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_add_step->SetToolTip( wxT("Adds a new step to the list above the selected area.\nRight click: Add the step under the selected area instead.\n\nIf no rows are selected then it will be placed at the end of the list.\n") );

	step_panel_control_sizer->Add( btn_add_step, 0, wxALIGN_CENTER|wxALL, 5 );

	btn_change_step = new wxButton( step_panel, wxID_ANY, wxT("Change"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_change_step->SetToolTip( wxT("Changes the currently selected step to the input.\nRight click: ignore warnings.") );

	step_panel_control_sizer->Add( btn_change_step, 0, wxALL, 5 );

	btn_delete_step = new wxButton( step_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_delete_step->SetToolTip( wxT("Deletes the selected step or steps.\nRight click: ignore warnings.") );

	step_panel_control_sizer->Add( btn_delete_step, 0, wxALL, 5 );

	btn_move_up = new wxButton( step_panel, wxID_ANY, wxT("Move Up"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_move_up->SetToolTip( wxT("Moves the step up.\nRight click: move 5 but be patient") );

	step_panel_control_sizer->Add( btn_move_up, 0, wxALL, 5 );

	btn_move_down = new wxButton( step_panel, wxID_ANY, wxT("Move Down"), wxDefaultPosition, wxSize( 85,-1 ), 0 );
	btn_move_down->SetToolTip( wxT("Moves the step down.\nRight click: move 5 but be patient") );

	step_panel_control_sizer->Add( btn_move_down, 0, wxALL, 5 );


	step_panel_sizer->Add( step_panel_control_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* step_panel_grid_sizer;
	step_panel_grid_sizer = new wxBoxSizer( wxVERTICAL );

	grid_steps = new wxGrid( step_panel, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );

	// Grid
	grid_steps->CreateGrid( 0, 11 );
	grid_steps->EnableEditing( true );
	grid_steps->EnableGridLines( true );
	grid_steps->EnableDragGridSize( false );
	grid_steps->SetMargins( 0, 0 );

	// Columns
	grid_steps->SetColSize( 0, 75 );
	grid_steps->SetColSize( 1, 49 );
	grid_steps->SetColSize( 2, 49 );
	grid_steps->SetColSize( 3, 58 );
	grid_steps->SetColSize( 4, 140 );
	grid_steps->SetColSize( 5, 70 );
	grid_steps->SetColSize( 6, 80 );
	grid_steps->SetColSize( 7, 70 );
	grid_steps->SetColSize( 8, 50 );
	grid_steps->SetColSize( 9, 60 );
	grid_steps->SetColSize( 10, 112 );
	grid_steps->EnableDragColMove( false );
	grid_steps->EnableDragColSize( true );
	grid_steps->SetColLabelValue( 0, wxT("Step") );
	grid_steps->SetColLabelValue( 1, wxT("X-cord") );
	grid_steps->SetColLabelValue( 2, wxT("Y-cord") );
	grid_steps->SetColLabelValue( 3, wxT("Amount") );
	grid_steps->SetColLabelValue( 4, wxT("Item") );
	grid_steps->SetColLabelValue( 5, wxT("Orientation") );
	grid_steps->SetColLabelValue( 6, wxT("Modifier") );
	grid_steps->SetColLabelValue( 7, wxT("Direction") );
	grid_steps->SetColLabelValue( 8, wxT("Size") );
	grid_steps->SetColLabelValue( 9, wxT("Buildings") );
	grid_steps->SetColLabelValue( 10, wxT("Comment") );
	grid_steps->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grid_steps->EnableDragRowSize( false );
	grid_steps->SetRowLabelSize( 60 );
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
	reorder_panel = new wxPanel( main_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* reorder_sizer;
	reorder_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* reorder_control_sizer;
	reorder_control_sizer = new wxBoxSizer( wxHORIZONTAL );

	reorder_reorder_button = new wxButton( reorder_panel, wxID_ANY, wxT("Reorder"), wxDefaultPosition, wxDefaultSize, 0 );
	reorder_reorder_button->Enable( false );
	reorder_reorder_button->SetToolTip( wxT("This will re-order a no-order block to align with current execution.\n\nIt works by first creating a block of steps with no-order enabled. \nThen execute them through a TAS run. \nThen run the console command \"/reorder\" and copy the text to the input below. \n\nWhen using this functionality, each multibuild step will be unrolled and each rotation will be unrolled. After that the steps will be matched with the resulting order, which then replaces them.") );

	reorder_control_sizer->Add( reorder_reorder_button, 0, wxALL, 5 );

	wxBoxSizer* reorder_control_checkbox_sizer;
	reorder_control_checkbox_sizer = new wxBoxSizer( wxHORIZONTAL );

	reorder_text_input_clear_checkbox = new wxCheckBox( reorder_panel, wxID_ANY, wxT("Clear reorder"), wxDefaultPosition, wxDefaultSize, 0 );
	reorder_text_input_clear_checkbox->SetValue(true);
	reorder_text_input_clear_checkbox->SetToolTip( wxT("Clears the text below after clicking on the Reorder button.") );

	reorder_control_checkbox_sizer->Add( reorder_text_input_clear_checkbox, 0, wxALL, 5 );


	reorder_control_sizer->Add( reorder_control_checkbox_sizer, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* reorder_locator_sizer;
	reorder_locator_sizer = new wxBoxSizer( wxHORIZONTAL );


	reorder_locator_sizer->Add( 375, 0, 1, wxEXPAND, 5 );

	reorder_locator_button = new wxButton( reorder_panel, wxID_ANY, wxT("Locate"), wxDefaultPosition, wxDefaultSize, 0 );
	reorder_locator_button->Enable( false );
	reorder_locator_button->SetToolTip( wxT("Finds the no-order block in the step list, helping you visualize that you are changing the correct block.") );

	reorder_locator_sizer->Add( reorder_locator_button, 0, wxALL, 5 );


	reorder_control_sizer->Add( reorder_locator_sizer, 1, wxEXPAND, 5 );


	reorder_sizer->Add( reorder_control_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* reorder_input_sizer;
	reorder_input_sizer = new wxBoxSizer( wxHORIZONTAL );

	reorder_input_sizer->SetMinSize( wxSize( -1,1200 ) );
	reorder_text_input = new wxTextCtrl( reorder_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxTE_MULTILINE );
	reorder_text_input->SetToolTip( wxT("This will re-order a no-order block to align with current execution.\n\nIt works by first creating a block of steps with no-order enabled. \nThen execute them through a TAS run. \nThen run the console command \"/reorder\" and copy the text to the input below. \n\nWhen using this functionality, each multibuild step will be unrolled and each rotation will be unrolled. After that the steps will be matched with the resulting order, which then replaces them.") );
	reorder_text_input->SetMinSize( wxSize( 450,600 ) );

	reorder_input_sizer->Add( reorder_text_input, 1, wxALL|wxEXPAND, 5 );


	reorder_sizer->Add( reorder_input_sizer, 1, wxEXPAND, 5 );


	reorder_panel->SetSizer( reorder_sizer );
	reorder_panel->Layout();
	reorder_sizer->Fit( reorder_panel );
	main_book->AddPage( reorder_panel, wxT("Reorder"), false, wxNullBitmap );
	template_panel = new wxPanel( main_book, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* template_sizer;
	template_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* template_control_sizer;
	template_control_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* template_control_left_sizer;
	template_control_left_sizer = new wxBoxSizer( wxVERTICAL );

	template_control_left_sizer->SetMinSize( wxSize( 500,-1 ) );
	wxBoxSizer* template_template_control_sizer;
	template_template_control_sizer = new wxBoxSizer( wxHORIZONTAL );

	cmb_choose_template = new wxComboBox( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmb_choose_template->SetToolTip( wxT("Use to select and load a template,\nOr to specify the name of a new template.") );
	cmb_choose_template->SetMinSize( wxSize( 245,-1 ) );

	template_template_control_sizer->Add( cmb_choose_template, 0, wxALIGN_CENTER|wxALL, 5 );

	btn_template_new = new wxButton( template_panel, wxID_ANY, wxT("New"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	btn_template_new->SetToolTip( wxT("Create a new template with name from box on the left. ") );

	template_template_control_sizer->Add( btn_template_new, 0, wxALL, 5 );

	btn_template_delete = new wxButton( template_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	btn_template_delete->SetToolTip( wxT("Delete this template and it's content.") );

	template_template_control_sizer->Add( btn_template_delete, 0, wxALL, 5 );


	template_control_left_sizer->Add( template_template_control_sizer, 1, wxALIGN_LEFT, 5 );

	wxBoxSizer* template_step_control_sizer;
	template_step_control_sizer = new wxBoxSizer( wxHORIZONTAL );

	btn_template_add_step = new wxButton( template_panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_template_add_step->SetToolTip( wxT("Adds a step using the step detail panel to this template.") );

	template_step_control_sizer->Add( btn_template_add_step, 0, wxALL, 5 );

	btn_template_change_step = new wxButton( template_panel, wxID_ANY, wxT("Change"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_template_change_step->SetToolTip( wxT("Update the select template step using inputs from the details panel.") );

	template_step_control_sizer->Add( btn_template_change_step, 0, wxALL, 5 );

	btn_template_delete_step = new wxButton( template_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_template_delete_step->SetToolTip( wxT("Delete the selected template steps from this template.") );

	template_step_control_sizer->Add( btn_template_delete_step, 0, wxALL, 5 );

	btn_template_move_up_step = new wxButton( template_panel, wxID_ANY, wxT("Up"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_template_move_up_step->SetToolTip( wxT("Move this template step one row up.") );

	template_step_control_sizer->Add( btn_template_move_up_step, 0, wxALL, 5 );

	btn_template_move_down_step = new wxButton( template_panel, wxID_ANY, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_template_move_down_step->SetToolTip( wxT("Move this template step one row down.") );

	template_step_control_sizer->Add( btn_template_move_down_step, 0, wxALL, 5 );


	template_control_left_sizer->Add( template_step_control_sizer, 1, wxALIGN_LEFT, 5 );


	template_control_sizer->Add( template_control_left_sizer, 1, 0, 5 );

	m_staticline51 = new wxStaticLine( template_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	template_control_sizer->Add( m_staticline51, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* template_import_export_sizer;
	template_import_export_sizer = new wxBoxSizer( wxVERTICAL );

	btn_template_add_to_steps_list = new wxButton( template_panel, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	btn_template_add_to_steps_list->SetToolTip( wxT("Moves a range of steps from the steps panel into this template.") );

	template_import_export_sizer->Add( btn_template_add_to_steps_list, 0, wxALL, 5 );

	btn_template_add_from_steps_list = new wxButton( template_panel, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	btn_template_add_from_steps_list->SetToolTip( wxT("Moves the selected range of template steps or all template steps from this template into the steps page. Using the transformations on the right.") );

	template_import_export_sizer->Add( btn_template_add_from_steps_list, 0, wxALL, 5 );


	template_control_sizer->Add( template_import_export_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* template_amount_sizer;
	template_amount_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1052;
	bSizer1052 = new wxBoxSizer( wxHORIZONTAL );

	label_template_amount_offset = new wxStaticText( template_panel, wxID_ANY, wxT("Offset:"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	label_template_amount_offset->Wrap( -1 );
	bSizer1052->Add( label_template_amount_offset, 0, wxALIGN_CENTER, 5 );

	spin_amount_offset = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, -10000, 10000, 0 );
	spin_amount_offset->SetToolTip( wxT("Used to specify an amount off-set to the whole range of exported steps.\nThis is applied after multiplication.") );

	bSizer1052->Add( spin_amount_offset, 0, wxALL, 5 );


	template_amount_sizer->Add( bSizer1052, 1, 0, 5 );

	wxBoxSizer* bSizer1062;
	bSizer1062 = new wxBoxSizer( wxHORIZONTAL );

	label_template_amount_multiplier = new wxStaticText( template_panel, wxID_ANY, wxT("Multiplier:"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	label_template_amount_multiplier->Wrap( -1 );
	bSizer1062->Add( label_template_amount_multiplier, 0, wxALIGN_CENTER, 5 );

	spin_amount_multiplier = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, 0, 100, 1 );
	spin_amount_multiplier->SetToolTip( wxT("Used to specify an amount multiplication to the whole range of exported steps.\nThis is applied before offset.") );

	bSizer1062->Add( spin_amount_multiplier, 0, wxALL, 5 );


	template_amount_sizer->Add( bSizer1062, 1, 0, 5 );


	template_control_sizer->Add( template_amount_sizer, 0, 0, 5 );

	m_staticline2 = new wxStaticLine( template_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	template_control_sizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* template_coordinate_sizer;
	template_coordinate_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxHORIZONTAL );

	label_template_x_offset = new wxStaticText( template_panel, wxID_ANY, wxT("X:"), wxDefaultPosition, wxSize( 15,-1 ), 0 );
	label_template_x_offset->Wrap( -1 );
	bSizer105->Add( label_template_x_offset, 0, wxALIGN_CENTER, 5 );

	spin_x_offset = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 65,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, -1000000, 1000000, 0 );
	spin_x_offset->SetToolTip( wxT("X coordinate offset") );

	bSizer105->Add( spin_x_offset, 0, wxALL, 5 );


	template_coordinate_sizer->Add( bSizer105, 1, 0, 5 );

	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer( wxHORIZONTAL );

	label_template_y_offset = new wxStaticText( template_panel, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxSize( 15,-1 ), 0 );
	label_template_y_offset->Wrap( -1 );
	bSizer106->Add( label_template_y_offset, 0, wxALIGN_CENTER, 5 );

	spin_y_offset = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 65,-1 ), wxALIGN_RIGHT|wxSP_ARROW_KEYS, -1000000, 1000000, 0 );
	spin_y_offset->SetToolTip( wxT("Y coordinate offset") );

	bSizer106->Add( spin_y_offset, 0, wxALL, 5 );


	template_coordinate_sizer->Add( bSizer106, 1, 0, 5 );


	template_control_sizer->Add( template_coordinate_sizer, 0, 0, 5 );

	wxBoxSizer* template_advanced_sizer;
	template_advanced_sizer = new wxBoxSizer( wxVERTICAL );

	spin_template_iterator = new wxSpinCtrl( template_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 68,-1 ), wxSP_ARROW_KEYS, 0, 99, 0 );
	spin_template_iterator->SetToolTip( wxT("Coordinate offset multiplier (X,Y) when using Export.\nCalculated: (X,Y) + offset * multiplier\n\nThis will auto increment when using Export.\nSet to 0 to not increment this will be interpreted as a multiplier of 1.") );

	template_advanced_sizer->Add( spin_template_iterator, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	wxString choice_template_directionChoices[] = { wxT("Normal"), wxT("Left"), wxT("Reverse"), wxT("Right") };
	int choice_template_directionNChoices = sizeof( choice_template_directionChoices ) / sizeof( wxString );
	choice_template_direction = new wxChoice( template_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, choice_template_directionNChoices, choice_template_directionChoices, 0 );
	choice_template_direction->SetSelection( 0 );
	choice_template_direction->SetToolTip( wxT("Rotational transformation for Export.\nEach rotation transform the export template 90 degrees from the normal axis.\n\nCalculated: ( (X,Y) + offset * multiplier ) * v90degree") );

	template_advanced_sizer->Add( choice_template_direction, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );


	template_control_sizer->Add( template_advanced_sizer, 1, 0, 5 );


	template_sizer->Add( template_control_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* template_grid_sizer;
	template_grid_sizer = new wxBoxSizer( wxVERTICAL );

	grid_template = new wxGrid( template_panel, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );

	// Grid
	grid_template->CreateGrid( 0, 11 );
	grid_template->EnableEditing( false );
	grid_template->EnableGridLines( true );
	grid_template->EnableDragGridSize( false );
	grid_template->SetMargins( 0, 0 );

	// Columns
	grid_template->SetColSize( 0, 75 );
	grid_template->SetColSize( 1, 49 );
	grid_template->SetColSize( 2, 49 );
	grid_template->SetColSize( 3, 50 );
	grid_template->SetColSize( 4, 150 );
	grid_template->SetColSize( 5, 70 );
	grid_template->SetColSize( 6, 60 );
	grid_template->SetColSize( 7, 70 );
	grid_template->SetColSize( 8, 50 );
	grid_template->SetColSize( 9, 60 );
	grid_template->SetColSize( 10, 139 );
	grid_template->EnableDragColMove( false );
	grid_template->EnableDragColSize( true );
	grid_template->SetColLabelValue( 0, wxT("Step") );
	grid_template->SetColLabelValue( 1, wxT("X-cord") );
	grid_template->SetColLabelValue( 2, wxT("Y-cord") );
	grid_template->SetColLabelValue( 3, wxT("Amount") );
	grid_template->SetColLabelValue( 4, wxT("Item") );
	grid_template->SetColLabelValue( 5, wxT("Orientation") );
	grid_template->SetColLabelValue( 6, wxT("Modifiers") );
	grid_template->SetColLabelValue( 7, wxT("Direction") );
	grid_template->SetColLabelValue( 8, wxT("Size") );
	grid_template->SetColLabelValue( 9, wxT("Buildings") );
	grid_template->SetColLabelValue( 10, wxT("Comment") );
	grid_template->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grid_template->EnableDragRowSize( false );
	grid_template->SetRowLabelSize( 60 );
	grid_template->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grid_template->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	grid_template->SetMinSize( wxSize( 860,2500 ) );

	template_grid_sizer->Add( grid_template, 0, wxALL|wxEXPAND, 5 );


	template_sizer->Add( template_grid_sizer, 1, wxEXPAND, 5 );


	template_panel->SetSizer( template_sizer );
	template_panel->Layout();
	template_sizer->Fit( template_panel );
	main_book->AddPage( template_panel, wxT("Templates"), false, wxNullBitmap );


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
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnChangeSteptypeColoursMenuSelected ), this, steptypecolour_changer->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnWalkMenuSelected ), this, shortcut_walk->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnCraftMenuSelected ), this, shortcut_craft->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnTechMenuSelected ), this, shortcut_tech->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnIdleMenuSelected ), this, shortcut_idle->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPickUpMenuSelected ), this, shortcut_pick_up->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnDropMenuSelected ), this, shortcut_drop->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnCancelCraftingMenuSelected ), this, shortcut_cancel_crafting->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMineMenuSelected ), this, shortcut_mine->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnThrowMenuSelected ), this, shortcut_throw->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnShootMenuSelected ), this, shortcut_shoot->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnEquipMenuSelected ), this, shortcut_equip->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnTakeMenuSelected ), this, shortcut_take->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPutMenuSelected ), this, shortcut_put->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnBuildMenuSelected ), this, shortcut_build->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnRecipeMenuChosen ), this, shortcut_recipe->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnLimitMenuSelected ), this, shortcut_limit->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnFilterMenuSelected ), this, shortcut_filter->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPriorityMenuSelected ), this, shortcut_priority->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnLaunchMenuSelected ), this, shortcut_launch->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnRotateMenuSelected ), this, shortcut_rotate->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnGameSpeedMenuSelected ), this, shortcut_game_speed->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnPauseMenuSelected ), this, shortcut_pause->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnStopMenuSelected ), this, shortcut_stop->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnSaveMenuSelected ), this, shortcut_save->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnNeverIdleMenuSelected ), this, shortcut_never_idle->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepWalkingMenuSelected ), this, shortcut_keep_walking->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepOnPathMenuSelected ), this, shortcut_keep_on_path->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepCraftingMenuSelected ), this, shortcut_keep_crafting->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnEnterExitMenuSelected ), this, shortcut_enter_exit->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnDriveMenuSelected ), this, shortcut_drive->GetId());
	menu_steptypes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnSendMenuSelected ), this, shortcut_send->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnChangeShortcutMenuSelected ), this, shortcut_changer->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnAddMenuSelected ), this, shortcut_add_step->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnAddAltMenuSelected ), this, shortcut_add_step_alt->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnChangeMenuSelected ), this, shortcut_change_step->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnChangeAltMenuSelected ), this, shortcut_change_step_alt->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnDeleteMenuSelected ), this, shortcut_delete_step->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnDeleteAltMenuSelected ), this, shortcut_delete_step_alt->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMoveUpMenuSelected ), this, shortcut_move_up->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMoveUpAltMenuSelected ), this, shortcut_move_up_alt->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMoveDownMenuSelected ), this, shortcut_move_down->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMoveDownAltMenuSelected ), this, shortcut_move_down_alt->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnSearchMenuSelected ), this, shortcut_search->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnUndoMenuSelected ), this, shortcut_undo->GetId());
	menu_shortcuts->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnRedoMenuSelected ), this, shortcut_redo->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuSteelAxeClicked ), this, goal_steelaxe->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuGOTLAPClicked ), this, goal_GOTLAP->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAnyPercentClicked ), this, goal_any_percent->GetId());
	menu_goals->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuSupplyChallengeClicked ), this, scenario_supply_challenge->GetId());
	menu_loglevel->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnLoggingSavegameSelected ), this, logging_savegame->GetId());
	menu_loglevel->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnLoggingTechSelected ), this, logging_tech->GetId());
	menu_loglevel->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnLoggingCommentSelected ), this, logging_comment->GetId());
	menu_loglevel->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuLogDebugSelected ), this, loglevel_debug->GetId());
	menu_loglevel->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuLogDevelopmentSelected ), this, loglevel_development->GetId());
	menu_loglevel->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuLogReleaseSelected ), this, loglevel_release->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseGenerateScriptClicked ), this, auto_close_generate_script->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseOpenClicked ), this, auto_close_open->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseSaveClicked ), this, auto_close_save->GetId());
	menu_auto_close->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_Base::OnMenuAutoCloseSaveAsClicked ), this, auto_close_save_as->GetId());
	rbtn_walk->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnWalkChosen ), NULL, this );
	rbtn_craft->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCraftChosen ), NULL, this );
	rbtn_tech->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTechChosen ), NULL, this );
	rbtn_idle->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnIdleChosen ), NULL, this );
	rbtn_pick_up->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPickUpChosen ), NULL, this );
	rbtn_drop->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnDropChosen ), NULL, this );
	rbtn_cancel_crafting->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCancelCraftingChosen ), NULL, this );
	rbtn_mine->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnMineChosen ), NULL, this );
	rbtn_throw->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnThrowChosen ), NULL, this );
	rbtn_shoot->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnShootChosen ), NULL, this );
	rbtn_equip->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnEquipChosen ), NULL, this );
	rbtn_take->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTakeChosen ), NULL, this );
	rbtn_put->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPutChosen ), NULL, this );
	rbtn_build->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnBuildChosen ), NULL, this );
	rbtn_recipe->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRecipeChosen ), NULL, this );
	rbtn_limit->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLimitChosen ), NULL, this );
	rbtn_filter->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnfilterChosen ), NULL, this );
	rbtn_priority->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPriorityChosen ), NULL, this );
	rbtn_launch->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLaunchChosen ), NULL, this );
	rbtn_rotate->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRotateChosen ), NULL, this );
	rbtn_next->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnNextChosen ), NULL, this );
	rbtn_game_speed->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnGameSpeedChosen ), NULL, this );
	rbtn_pause->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPauseChosen ), NULL, this );
	rbtn_stop->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnStopChosen ), NULL, this );
	rbtn_save->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnSaveChosen ), NULL, this );
	rbtn_never_idle->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnNeverIdleChosen ), NULL, this );
	rbtn_keep_walking->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepWalkingChosen ), NULL, this );
	rbtn_keep_on_path->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepOnPathChosen ), NULL, this );
	rbtn_keep_crafting->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepCraftingChosen ), NULL, this );
	rbtn_enter_exit->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnEnterExitChosen ), NULL, this );
	rbtn_drive->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnDriveChosen ), NULL, this );
	rbtn_send->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnSendChosen ), NULL, this );
	modifier_no_order_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnNoOrderClicked ), NULL, this );
	modifier_no_order_button->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnNoOrderRightClicked ), NULL, this );
	modifier_skip_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnSkipClicked ), NULL, this );
	modifier_force_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnForceClicked ), NULL, this );
	modifier_force_button->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnForceRightClicked ), NULL, this );
	modifier_vehicle_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnVehicleClicked ), NULL, this );
	modifier_vehicle_button->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnVehicleRightClicked ), NULL, this );
	walk_panel_button_upleft->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnUpLeftClicked ), NULL, this );
	walk_panel_button_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnUpClicked ), NULL, this );
	walk_panel_button_upright->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnUpRightClicked ), NULL, this );
	walk_panel_button_left->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnLeftClicked ), NULL, this );
	walk_panel_button_right->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnRightClicked ), NULL, this );
	walk_panel_button_downleft->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnDownLeftClicked ), NULL, this );
	walk_panel_button_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnDownClicked ), NULL, this );
	walk_panel_button_downright->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnDownRightClicked ), NULL, this );
	main_book->Connect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED, wxAuiNotebookEventHandler( GUI_Base::OnMainBookPageChanged ), NULL, this );
	import_steps_into_steps_index_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsIndexBtnClicked ), NULL, this );
	import_steps_into_steps_index_btn->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnImportStepsIntoStepsIndexBtnRight ), NULL, this );
	import_steps_into_steps_ctrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_Base::OnImportStepsIntoStepsCtrl ), NULL, this );
	import_steps_into_steps_ctrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsCtrlEnter ), NULL, this );
	import_steps_into_steps_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsBtnClick ), NULL, this );
	import_steps_into_template_ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlText ), NULL, this );
	import_steps_into_template_ctrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlEnter ), NULL, this );
	import_steps_into_template_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateBtnClick ), NULL, this );
	import_steps_text_import->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsTextUpdate ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnCancelButton ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnSearchButton ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::StepSeachOnText ), NULL, this );
	step_search_ctrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::StepSeachOnTextEnter ), NULL, this );
	step_colour_picker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUI_Base::OnStepColourPickerColourChanged ), NULL, this );
	steps_focus_checkbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_Base::OnStepsFocusCheckbox ), NULL, this );
	btn_add_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnAddStepClicked ), NULL, this );
	btn_add_step->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnAddStepRightClicked ), NULL, this );
	btn_change_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnChangeStepClicked ), NULL, this );
	btn_change_step->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnChangeStepRightClicked ), NULL, this );
	btn_delete_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteStepClicked ), NULL, this );
	btn_delete_step->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnDeleteStepRightClicked ), NULL, this );
	btn_move_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveUpClicked ), NULL, this );
	btn_move_up->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveUpFiveClicked ), NULL, this );
	btn_move_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveDownClicked ), NULL, this );
	btn_move_down->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveDownFiveClicked ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( GUI_Base::OnStepsGridCellChange ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( GUI_Base::OnStepsGridRightClick ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_EDITOR_HIDDEN, wxGridEventHandler( GUI_Base::OnStepsGridEditorHidden ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( GUI_Base::OnStepsGridEditorShown ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( GUI_Base::OnStepsGridRightClick ), NULL, this );
	grid_steps->Connect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( GUI_Base::OnStepsGridRangeSelect ), NULL, this );
	reorder_reorder_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnReorderReorderButtonClicked ), NULL, this );
	reorder_locator_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnReorderLocatorButtonClicked ), NULL, this );
	reorder_text_input->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnReorderTextUpdate ), NULL, this );
	cmb_choose_template->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUI_Base::OnTemplateChosen ), NULL, this );
	cmb_choose_template->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnTemplateText ), NULL, this );
	btn_template_new->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnNewTemplateClicked ), NULL, this );
	btn_template_delete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteTemplateClicked ), NULL, this );
	btn_template_delete->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnDeleteTemplateRightClicked ), NULL, this );
	btn_template_add_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddStepClicked ), NULL, this );
	btn_template_change_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateChangeStepClicked ), NULL, this );
	btn_template_delete_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateDeleteStepClicked ), NULL, this );
	btn_template_move_up_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveUpClicked ), NULL, this );
	btn_template_move_down_step->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveDownClicked ), NULL, this );
	btn_template_add_to_steps_list->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddToStepsListClicked ), NULL, this );
	btn_template_add_from_steps_list->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddFromStepsListClicked ), NULL, this );
	grid_template->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUI_Base::OnTemplateGridDoubleLeftClick ), NULL, this );
	grid_template->Connect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( GUI_Base::OnTemplateGridRangeSelect ), NULL, this );
}

GUI_Base::~GUI_Base()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUI_Base::OnApplicationClose ) );
	rbtn_walk->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnWalkChosen ), NULL, this );
	rbtn_craft->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCraftChosen ), NULL, this );
	rbtn_tech->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTechChosen ), NULL, this );
	rbtn_idle->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnIdleChosen ), NULL, this );
	rbtn_pick_up->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPickUpChosen ), NULL, this );
	rbtn_drop->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnDropChosen ), NULL, this );
	rbtn_cancel_crafting->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnCancelCraftingChosen ), NULL, this );
	rbtn_mine->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnMineChosen ), NULL, this );
	rbtn_throw->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnThrowChosen ), NULL, this );
	rbtn_shoot->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnShootChosen ), NULL, this );
	rbtn_equip->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnEquipChosen ), NULL, this );
	rbtn_take->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnTakeChosen ), NULL, this );
	rbtn_put->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPutChosen ), NULL, this );
	rbtn_build->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnBuildChosen ), NULL, this );
	rbtn_recipe->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRecipeChosen ), NULL, this );
	rbtn_limit->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLimitChosen ), NULL, this );
	rbtn_filter->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnfilterChosen ), NULL, this );
	rbtn_priority->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPriorityChosen ), NULL, this );
	rbtn_launch->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnLaunchChosen ), NULL, this );
	rbtn_rotate->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnRotateChosen ), NULL, this );
	rbtn_next->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnNextChosen ), NULL, this );
	rbtn_game_speed->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnGameSpeedChosen ), NULL, this );
	rbtn_pause->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnPauseChosen ), NULL, this );
	rbtn_stop->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnStopChosen ), NULL, this );
	rbtn_save->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnSaveChosen ), NULL, this );
	rbtn_never_idle->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnNeverIdleChosen ), NULL, this );
	rbtn_keep_walking->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepWalkingChosen ), NULL, this );
	rbtn_keep_on_path->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepOnPathChosen ), NULL, this );
	rbtn_keep_crafting->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnKeepCraftingChosen ), NULL, this );
	rbtn_enter_exit->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnEnterExitChosen ), NULL, this );
	rbtn_drive->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnDriveChosen ), NULL, this );
	rbtn_send->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_Base::OnSendChosen ), NULL, this );
	modifier_no_order_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnNoOrderClicked ), NULL, this );
	modifier_no_order_button->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnNoOrderRightClicked ), NULL, this );
	modifier_skip_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnSkipClicked ), NULL, this );
	modifier_force_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnForceClicked ), NULL, this );
	modifier_force_button->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnForceRightClicked ), NULL, this );
	modifier_vehicle_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnVehicleClicked ), NULL, this );
	modifier_vehicle_button->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnVehicleRightClicked ), NULL, this );
	walk_panel_button_upleft->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnUpLeftClicked ), NULL, this );
	walk_panel_button_up->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnUpClicked ), NULL, this );
	walk_panel_button_upright->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnUpRightClicked ), NULL, this );
	walk_panel_button_left->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnLeftClicked ), NULL, this );
	walk_panel_button_right->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnRightClicked ), NULL, this );
	walk_panel_button_downleft->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnDownLeftClicked ), NULL, this );
	walk_panel_button_down->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnDownClicked ), NULL, this );
	walk_panel_button_downright->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnWalkPanelBtnDownRightClicked ), NULL, this );
	main_book->Disconnect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED, wxAuiNotebookEventHandler( GUI_Base::OnMainBookPageChanged ), NULL, this );
	import_steps_into_steps_index_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsIndexBtnClicked ), NULL, this );
	import_steps_into_steps_index_btn->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnImportStepsIntoStepsIndexBtnRight ), NULL, this );
	import_steps_into_steps_ctrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_Base::OnImportStepsIntoStepsCtrl ), NULL, this );
	import_steps_into_steps_ctrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsCtrlEnter ), NULL, this );
	import_steps_into_steps_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoStepsBtnClick ), NULL, this );
	import_steps_into_template_ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlText ), NULL, this );
	import_steps_into_template_ctrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateCtrlEnter ), NULL, this );
	import_steps_into_template_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnImportStepsIntoTemplateBtnClick ), NULL, this );
	import_steps_text_import->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnImportStepsTextUpdate ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnCancelButton ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler( GUI_Base::StepSeachOnSearchButton ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::StepSeachOnText ), NULL, this );
	step_search_ctrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_Base::StepSeachOnTextEnter ), NULL, this );
	step_colour_picker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUI_Base::OnStepColourPickerColourChanged ), NULL, this );
	steps_focus_checkbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_Base::OnStepsFocusCheckbox ), NULL, this );
	btn_add_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnAddStepClicked ), NULL, this );
	btn_add_step->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnAddStepRightClicked ), NULL, this );
	btn_change_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnChangeStepClicked ), NULL, this );
	btn_change_step->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnChangeStepRightClicked ), NULL, this );
	btn_delete_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteStepClicked ), NULL, this );
	btn_delete_step->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnDeleteStepRightClicked ), NULL, this );
	btn_move_up->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveUpClicked ), NULL, this );
	btn_move_up->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveUpFiveClicked ), NULL, this );
	btn_move_down->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnMoveDownClicked ), NULL, this );
	btn_move_down->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUI_Base::OnMoveDownFiveClicked ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( GUI_Base::OnStepsGridCellChange ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( GUI_Base::OnStepsGridRightClick ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_EDITOR_HIDDEN, wxGridEventHandler( GUI_Base::OnStepsGridEditorHidden ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( GUI_Base::OnStepsGridEditorShown ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( GUI_Base::OnStepsGridRightClick ), NULL, this );
	grid_steps->Disconnect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( GUI_Base::OnStepsGridRangeSelect ), NULL, this );
	reorder_reorder_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnReorderReorderButtonClicked ), NULL, this );
	reorder_locator_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnReorderLocatorButtonClicked ), NULL, this );
	reorder_text_input->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnReorderTextUpdate ), NULL, this );
	cmb_choose_template->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUI_Base::OnTemplateChosen ), NULL, this );
	cmb_choose_template->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUI_Base::OnTemplateText ), NULL, this );
	btn_template_new->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnNewTemplateClicked ), NULL, this );
	btn_template_delete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnDeleteTemplateClicked ), NULL, this );
	btn_template_delete->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( GUI_Base::OnDeleteTemplateRightClicked ), NULL, this );
	btn_template_add_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddStepClicked ), NULL, this );
	btn_template_change_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateChangeStepClicked ), NULL, this );
	btn_template_delete_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateDeleteStepClicked ), NULL, this );
	btn_template_move_up_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveUpClicked ), NULL, this );
	btn_template_move_down_step->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateMoveDownClicked ), NULL, this );
	btn_template_add_to_steps_list->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddToStepsListClicked ), NULL, this );
	btn_template_add_from_steps_list->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_Base::OnTemplateAddFromStepsListClicked ), NULL, this );
	grid_template->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUI_Base::OnTemplateGridDoubleLeftClick ), NULL, this );
	grid_template->Disconnect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( GUI_Base::OnTemplateGridRangeSelect ), NULL, this );

	m_mgr.UnInit();

}

Shortcut_changer::Shortcut_changer( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );

	sc_vertical_sizer = new wxBoxSizer( wxVERTICAL );

	sc_help_label = new wxStaticText( this, wxID_ANY, wxT("HELP: \nThe input fields expect a keybinding -> [<modifierkey>+<key>]\nYou can have multiple modifier keys among [\"Alt\", \"Ctrl\", \"Shift\"] separated with +.\nYou can only have one key in uppercase.\nYou can use F keys like \"F1\".\n\nExamples: \nAlt+G\nCtrl+Shift+G\nCtrl+F1"), wxDefaultPosition, wxDefaultSize, 0 );
	sc_help_label->Wrap( -1 );
	sc_vertical_sizer->Add( sc_help_label, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxVERTICAL );

	sc_item_book = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_DEFAULT|wxBORDER_RAISED|wxBORDER_THEME );
	sc_item_book->SetMinSize( wxSize( 800,340 ) );
	sc_item_book->SetMaxSize( wxSize( 1500,700 ) );

	sc_panel_file = new wxPanel( sc_item_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sc_file_sizer = new wxBoxSizer( wxVERTICAL );

	sc_grid_sizer_file = new wxFlexGridSizer( 0, 3, 5, 5 );
	sc_grid_sizer_file->SetFlexibleDirection( wxBOTH );
	sc_grid_sizer_file->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	sc_file_sizer->Add( sc_grid_sizer_file, 1, wxEXPAND, 5 );


	sc_panel_file->SetSizer( sc_file_sizer );
	sc_panel_file->Layout();
	sc_file_sizer->Fit( sc_panel_file );
	sc_item_book->AddPage( sc_panel_file, wxT("File"), false );
	sc_panel_script = new wxPanel( sc_item_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sc_script_sizer = new wxBoxSizer( wxVERTICAL );

	sc_grid_sizer_script = new wxFlexGridSizer( 0, 3, 5, 5 );
	sc_grid_sizer_script->SetFlexibleDirection( wxBOTH );
	sc_grid_sizer_script->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	sc_script_sizer->Add( sc_grid_sizer_script, 1, wxEXPAND, 5 );


	sc_panel_script->SetSizer( sc_script_sizer );
	sc_panel_script->Layout();
	sc_script_sizer->Fit( sc_panel_script );
	sc_item_book->AddPage( sc_panel_script, wxT("Script"), false );
	sc_panel_steptypes = new wxPanel( sc_item_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sc_steptypes_sizer = new wxBoxSizer( wxVERTICAL );

	sc_grid_sizer_steptypes = new wxFlexGridSizer( 0, 3, 5, 5 );
	sc_grid_sizer_steptypes->SetFlexibleDirection( wxBOTH );
	sc_grid_sizer_steptypes->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	sc_steptypes_sizer->Add( sc_grid_sizer_steptypes, 1, wxEXPAND, 5 );


	sc_panel_steptypes->SetSizer( sc_steptypes_sizer );
	sc_panel_steptypes->Layout();
	sc_steptypes_sizer->Fit( sc_panel_steptypes );
	sc_item_book->AddPage( sc_panel_steptypes, wxT("Step types"), false );
	sc_panel_shortcuts = new wxPanel( sc_item_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sc_shortcuts_sizer = new wxBoxSizer( wxVERTICAL );

	sc_grid_sizer_shortcuts = new wxFlexGridSizer( 0, 3, 5, 5 );
	sc_grid_sizer_shortcuts->SetFlexibleDirection( wxBOTH );
	sc_grid_sizer_shortcuts->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	sc_shortcuts_sizer->Add( sc_grid_sizer_shortcuts, 1, wxEXPAND, 5 );


	sc_panel_shortcuts->SetSizer( sc_shortcuts_sizer );
	sc_panel_shortcuts->Layout();
	sc_shortcuts_sizer->Fit( sc_panel_shortcuts );
	sc_item_book->AddPage( sc_panel_shortcuts, wxT("Shortcuts"), true );
	sc_panel_goals = new wxPanel( sc_item_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sc_goal_sizer = new wxBoxSizer( wxVERTICAL );

	sc_grid_sizer_goals = new wxFlexGridSizer( 0, 3, 5, 5 );
	sc_grid_sizer_goals->SetFlexibleDirection( wxBOTH );
	sc_grid_sizer_goals->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	sc_goal_sizer->Add( sc_grid_sizer_goals, 1, wxEXPAND, 5 );


	sc_panel_goals->SetSizer( sc_goal_sizer );
	sc_panel_goals->Layout();
	sc_goal_sizer->Fit( sc_panel_goals );
	sc_item_book->AddPage( sc_panel_goals, wxT("Goals"), false );
	sc_panel_auto = new wxPanel( sc_item_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sc_auto_sizer = new wxBoxSizer( wxVERTICAL );

	sc_grid_sizer_auto = new wxFlexGridSizer( 0, 3, 5, 5 );
	sc_grid_sizer_auto->SetFlexibleDirection( wxBOTH );
	sc_grid_sizer_auto->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	sc_auto_sizer->Add( sc_grid_sizer_auto, 1, wxEXPAND, 5 );


	sc_panel_auto->SetSizer( sc_auto_sizer );
	sc_panel_auto->Layout();
	sc_auto_sizer->Fit( sc_panel_auto );
	sc_item_book->AddPage( sc_panel_auto, wxT("Auto put"), false );
	#ifdef __WXGTK__ // Small icon style not supported in GTK
	wxListView* sc_item_bookListView = sc_item_book->GetListView();
	long sc_item_bookFlags = sc_item_bookListView->GetWindowStyleFlag();
	if( sc_item_bookFlags & wxLC_SMALL_ICON )
	{
		sc_item_bookFlags = ( sc_item_bookFlags & ~wxLC_SMALL_ICON ) | wxLC_ICON;
	}
	sc_item_bookListView->SetWindowStyleFlag( sc_item_bookFlags );
	#endif

	bSizer72->Add( sc_item_book, 1, wxALL|wxEXPAND, 5 );


	sc_vertical_sizer->Add( bSizer72, 1, wxEXPAND, 5 );

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

StepTypeColoursDialog::StepTypeColoursDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	StepTypeColoursDialog_sizer = new wxBoxSizer( wxVERTICAL );

	steptype_colour_label = new wxStaticText( this, wxID_ANY, wxT("label"), wxDefaultPosition, wxDefaultSize, 0 );
	steptype_colour_label->Wrap( -1 );
	steptype_colour_label->Hide();

	StepTypeColoursDialog_sizer->Add( steptype_colour_label, 0, wxALL, 5 );

	steptype_colour_book = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxSize( 600,600 ), wxLB_DEFAULT );
	steptype_colour_book->SetMinSize( wxSize( 430,200 ) );
	steptype_colour_book->SetMaxSize( wxSize( 1200,1000 ) );

	steptype_colour_character_panel = new wxPanel( steptype_colour_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	stc_character_sizer = new wxBoxSizer( wxVERTICAL );

	stc_character_grid_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	stc_character_grid_sizer->SetFlexibleDirection( wxBOTH );
	stc_character_grid_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	stc_character_sizer->Add( stc_character_grid_sizer, 1, wxEXPAND, 5 );


	steptype_colour_character_panel->SetSizer( stc_character_sizer );
	steptype_colour_character_panel->Layout();
	stc_character_sizer->Fit( steptype_colour_character_panel );
	steptype_colour_book->AddPage( steptype_colour_character_panel, wxT("Character"), false );
	steptype_colour_building_panel = new wxPanel( steptype_colour_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	stc_building_sizer = new wxBoxSizer( wxVERTICAL );

	stc_building_grid_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	stc_building_grid_sizer->SetFlexibleDirection( wxBOTH );
	stc_building_grid_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	stc_building_sizer->Add( stc_building_grid_sizer, 1, wxEXPAND, 5 );


	steptype_colour_building_panel->SetSizer( stc_building_sizer );
	steptype_colour_building_panel->Layout();
	stc_building_sizer->Fit( steptype_colour_building_panel );
	steptype_colour_book->AddPage( steptype_colour_building_panel, wxT("Building"), false );
	steptype_colour_game_panel = new wxPanel( steptype_colour_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	stc_game_sizer = new wxBoxSizer( wxVERTICAL );

	stc_game_grid_sizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	stc_game_grid_sizer->SetFlexibleDirection( wxBOTH );
	stc_game_grid_sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	stc_game_sizer->Add( stc_game_grid_sizer, 1, wxEXPAND, 5 );


	steptype_colour_game_panel->SetSizer( stc_game_sizer );
	steptype_colour_game_panel->Layout();
	stc_game_sizer->Fit( steptype_colour_game_panel );
	steptype_colour_book->AddPage( steptype_colour_game_panel, wxT("Game"), false );
	#ifdef __WXGTK__ // Small icon style not supported in GTK
	wxListView* steptype_colour_bookListView = steptype_colour_book->GetListView();
	long steptype_colour_bookFlags = steptype_colour_bookListView->GetWindowStyleFlag();
	if( steptype_colour_bookFlags & wxLC_SMALL_ICON )
	{
		steptype_colour_bookFlags = ( steptype_colour_bookFlags & ~wxLC_SMALL_ICON ) | wxLC_ICON;
	}
	steptype_colour_bookListView->SetWindowStyleFlag( steptype_colour_bookFlags );
	#endif

	StepTypeColoursDialog_sizer->Add( steptype_colour_book, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( StepTypeColoursDialog_sizer );
	this->Layout();
	StepTypeColoursDialog_sizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( StepTypeColoursDialog::OnCloseStepTypeColoursChanger ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( StepTypeColoursDialog::OnInitStepTypeColoursDialog ) );
}

StepTypeColoursDialog::~StepTypeColoursDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( StepTypeColoursDialog::OnCloseStepTypeColoursChanger ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( StepTypeColoursDialog::OnInitStepTypeColoursDialog ) );

}
