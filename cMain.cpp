#include "cMain.h"
#include "utils.h"
#include "Functions.h"
#include <fstream>

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_MENU(10001, cMain::OnMenuNew)
EVT_MENU(10002, cMain::OnMenuOpen)
EVT_MENU(10003, cMain::OnMenuSave)
EVT_MENU(10004, cMain::OnMenuExit)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Factorio GUI", wxPoint(30, 30), wxSize(1200, 1000)) {

	all_items.resize(item_logistics.size() + item_production.size() + item_intermediates.size() + item_combat.size());
	all_items.insert(all_items.end(), item_logistics.begin(), item_logistics.end());
	all_items.insert(all_items.end(), item_production.begin(), item_production.end());
	all_items.insert(all_items.end(), item_intermediates.begin(), item_intermediates.end());
	all_items.insert(all_items.end(), item_combat.begin(), item_combat.end());

	static const std::vector<std::string> all_items_const(all_items);

	list_task_num = 0;
	list_buildings_num = 0;
	file_location = "C:\\Users\\MTNie\\AppData\\Roaming\\Factorio\\mods\\Speed_run_0.0.1\\tasksV2.lua"; // this needs to be set by the user - most likely in open or save - a save as might also be needed

	//Add a menu bar
	m_MenuBar = new wxMenuBar();
	this->SetMenuBar(m_MenuBar);

	// add menu for file operations
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(10001, "New");
	menuFile->Append(10002, "Open");
	menuFile->Append(10003, "Save");
	menuFile->Append(10004, "Exit");

	// add file menu to menu bar
	m_MenuBar->Append(menuFile, "File");

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer(wxHORIZONTAL);

	bSizer23->SetMinSize(wxSize(10, 10));
	label_x_cord = new wxStaticText(this, wxID_ANY, wxT("X-Cord:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	label_x_cord->Wrap(-1);
	bSizer23->Add(label_x_cord, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	txt_x_cord = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, -1), 0);
	bSizer23->Add(txt_x_cord, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


	bSizer30->Add(bSizer23, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer(wxHORIZONTAL);

	label_y_cord = new wxStaticText(this, wxID_ANY, wxT("Y-Cord:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	label_y_cord->Wrap(-1);
	bSizer28->Add(label_y_cord, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	txt_y_cord = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, -1), 0);
	bSizer28->Add(txt_y_cord, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


	bSizer30->Add(bSizer28, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer(wxVERTICAL);


	bSizer36->Add(0, 0, 1, wxEXPAND, 5);


	bSizer30->Add(bSizer36, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer(wxVERTICAL);


	bSizer49->Add(0, 0, 1, wxEXPAND, 5);


	bSizer30->Add(bSizer49, 1, wxEXPAND, 5);


	bSizer37->Add(bSizer30, 1, wxEXPAND, 5);


	bSizer19->Add(bSizer37, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer(wxHORIZONTAL);

	label_item_category = new wxStaticText(this, wxID_ANY, wxT("Item Category:"), wxDefaultPosition, wxSize(-1, 25), wxALIGN_RIGHT);
	label_item_category->Wrap(-1);
	label_item_category->SetMinSize(wxSize(80, -1));

	bSizer31->Add(label_item_category, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	cmb_item_category = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmb_item_category->SetMinSize(wxSize(150, -1));

	bSizer31->Add(cmb_item_category, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


	bSizer24->Add(bSizer31, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer(wxHORIZONTAL);

	label_item = new wxStaticText(this, wxID_ANY, wxT("Item:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	label_item->Wrap(-1);
	label_item->SetMinSize(wxSize(80, -1));

	bSizer35->Add(label_item, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	cmb_item = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmb_item->SetMinSize(wxSize(150, -1));

	bSizer35->Add(cmb_item, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


	bSizer24->Add(bSizer35, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer(wxHORIZONTAL);

	label_amount = new wxStaticText(this, wxID_ANY, wxT("Amount:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	label_amount->Wrap(-1);
	label_amount->SetMinSize(wxSize(80, -1));

	bSizer34->Add(label_amount, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	txt_amount = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	txt_amount->SetMinSize(wxSize(150, -1));

	bSizer34->Add(txt_amount, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


	bSizer24->Add(bSizer34, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer(wxVERTICAL);


	bSizer47->Add(0, 0, 1, wxEXPAND, 5);


	bSizer24->Add(bSizer47, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer(wxVERTICAL);


	bSizer24->Add(bSizer48, 1, wxEXPAND, 5);


	bSizer20->Add(bSizer24, 1, wxEXPAND, 5);


	bSizer19->Add(bSizer20, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer(wxHORIZONTAL);

	label_building_direction = new wxStaticText(this, wxID_ANY, wxT("Building Direction"), wxDefaultPosition, wxDefaultSize, 0);
	label_building_direction->Wrap(-1);
	bSizer58->Add(label_building_direction, 0, wxALL, 5);

	cmb_building_direction = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	bSizer58->Add(cmb_building_direction, 0, wxALL, 5);


	bSizer57->Add(bSizer58, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer(wxHORIZONTAL);

	label_direction_to_build = new wxStaticText(this, wxID_ANY, wxT("Direction to Build"), wxDefaultPosition, wxDefaultSize, 0);
	label_direction_to_build->Wrap(-1);
	bSizer59->Add(label_direction_to_build, 0, wxALL, 5);

	cmb_direction_to_build = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	bSizer59->Add(cmb_direction_to_build, 0, wxALL, 5);


	bSizer57->Add(bSizer59, 1, wxEXPAND, 5);


	bSizer19->Add(bSizer57, 1, wxEXPAND, 5);


	bSizer19->Add(50, 0, 1, wxEXPAND, 5);

	wxStaticBoxSizer* Tasks;
	Tasks = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Tasks")), wxVERTICAL);

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer(wxVERTICAL);

	rbtn_walk = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Walk"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer15->Add(rbtn_walk, 0, wxALL, 5);


	bSizer6->Add(bSizer15, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer(wxVERTICAL);

	rbtn_mine = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Mine"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer12->Add(rbtn_mine, 0, wxALL, 5);


	bSizer6->Add(bSizer12, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer(wxVERTICAL);

	rbtn_game_speed = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Game Speed"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer17->Add(rbtn_game_speed, 0, wxALL, 5);


	bSizer6->Add(bSizer17, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer(wxVERTICAL);

	rbtn_filter = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Filter"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer65->Add(rbtn_filter, 0, wxALL, 5);


	bSizer6->Add(bSizer65, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer(wxVERTICAL);

	rbtn_launch = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer39->Add(rbtn_launch, 0, wxALL, 5);


	bSizer6->Add(bSizer39, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer(wxVERTICAL);

	rbtn_priority = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Priority"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer42->Add(rbtn_priority, 0, wxALL, 5);


	bSizer6->Add(bSizer42, 1, wxEXPAND, 5);


	bSizer18->Add(bSizer6, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer(wxVERTICAL);

	rbtn_craft = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Craft"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer14->Add(rbtn_craft, 0, wxALL, 5);


	bSizer7->Add(bSizer14, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer(wxVERTICAL);

	rbtn_build = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Build"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer16->Add(rbtn_build, 0, wxALL, 5);


	bSizer7->Add(bSizer16, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer(wxVERTICAL);

	rbtn_recipe = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Recipe"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer64->Add(rbtn_recipe, 0, wxALL, 5);


	bSizer7->Add(bSizer64, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer(wxVERTICAL);

	rbtn_tech = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Tech"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer63->Add(rbtn_tech, 0, wxALL, 5);


	bSizer7->Add(bSizer63, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer(wxVERTICAL);

	rbtn_limit = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Limit"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer40->Add(rbtn_limit, 0, wxALL, 5);


	bSizer7->Add(bSizer40, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer431;
	bSizer431 = new wxBoxSizer(wxVERTICAL);

	rbtn_transfer = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Transfer"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer431->Add(rbtn_transfer, 0, wxALL, 5);


	bSizer7->Add(bSizer431, 1, wxEXPAND, 5);


	bSizer18->Add(bSizer7, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxVERTICAL);

	rbtn_fuel = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Fuel"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer8->Add(rbtn_fuel, 0, wxALL, 5);


	bSizer5->Add(bSizer8, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	rbtn_take = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Take"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(rbtn_take, 0, wxALL, 5);


	bSizer5->Add(bSizer9, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer(wxVERTICAL);

	rbtn_put = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Put"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(rbtn_put, 0, wxALL, 5);


	bSizer5->Add(bSizer11, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer(wxVERTICAL);

	rbtn_rotate = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Rotate"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer13->Add(rbtn_rotate, 0, wxALL, 5);


	bSizer5->Add(bSizer13, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer(wxVERTICAL);

	rbtn_pick_up = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Pick Up"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer41->Add(rbtn_pick_up, 0, wxALL, 5);


	bSizer5->Add(bSizer41, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer441;
	bSizer441 = new wxBoxSizer(wxVERTICAL);

	rbtn_drop = new wxRadioButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Drop"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer441->Add(rbtn_drop, 0, wxALL, 5);


	bSizer5->Add(bSizer441, 1, wxEXPAND, 5);


	bSizer18->Add(bSizer5, 1, wxEXPAND, 5);

	m_staticline2 = new wxStaticLine(Tasks->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer18->Add(m_staticline2, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer(wxHORIZONTAL);

	btn_add_task = new wxButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Add Task"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer56->Add(btn_add_task, 0, wxALIGN_CENTER | wxALL, 5);

	btn_delete_task = new wxButton(Tasks->GetStaticBox(), wxID_ANY, wxT("Delete Task"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer56->Add(btn_delete_task, 0, wxALL, 5);


	bSizer18->Add(bSizer56, 1, wxALIGN_CENTER, 5);


	Tasks->Add(bSizer18, 1, wxEXPAND, 5);


	bSizer19->Add(Tasks, 1, wxEXPAND, 5);


	bSizer19->Add(10000, 0, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer19, 1, wxEXPAND, 5);

	m_staticline14 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer1->Add(m_staticline14, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer(wxVERTICAL);

	bSizer45->SetMinSize(wxSize(400, -1));
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer(wxVERTICAL);

	bSizer76->SetMinSize(wxSize(400, -1));
	label_buildings = new wxStaticText(this, wxID_ANY, wxT("Buildings"), wxDefaultPosition, wxDefaultSize, 0);
	label_buildings->Wrap(-1);
	bSizer76->Add(label_buildings, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer45->Add(bSizer76, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer(wxVERTICAL);

	bSizer77->SetMinSize(wxSize(400, -1));
	wxBoxSizer* bSizer501;
	bSizer501 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer5811;
	bSizer5811 = new wxBoxSizer(wxVERTICAL);

	m_staticText161 = new wxStaticText(this, wxID_ANY, wxT("X,Y-cord"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText161->Wrap(-1);
	bSizer5811->Add(m_staticText161, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer501->Add(bSizer5811, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* bSizer5911;
	bSizer5911 = new wxBoxSizer(wxVERTICAL);

	m_staticText171 = new wxStaticText(this, wxID_ANY, wxT("Item"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText171->Wrap(-1);
	bSizer5911->Add(m_staticText171, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer501->Add(bSizer5911, 1, wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer(wxVERTICAL);

	m_staticText191 = new wxStaticText(this, wxID_ANY, wxT("Building Direction"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText191->Wrap(50);
	bSizer611->Add(m_staticText191, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer501->Add(bSizer611, 1, wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer(wxVERTICAL);

	m_staticText34 = new wxStaticText(this, wxID_ANY, wxT("Recipe"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText34->Wrap(-1);
	bSizer80->Add(m_staticText34, 0, wxALIGN_CENTER, 5);


	bSizer501->Add(bSizer80, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer(wxVERTICAL);

	m_staticText35 = new wxStaticText(this, wxID_ANY, wxT("Filter"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText35->Wrap(-1);
	bSizer81->Add(m_staticText35, 0, wxALIGN_CENTER, 5);


	bSizer501->Add(bSizer81, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer(wxVERTICAL);

	m_staticText36 = new wxStaticText(this, wxID_ANY, wxT("Priority"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText36->Wrap(-1);
	bSizer82->Add(m_staticText36, 0, wxALIGN_CENTER, 5);


	bSizer501->Add(bSizer82, 1, wxALIGN_CENTER, 5);


	bSizer77->Add(bSizer501, 1, wxEXPAND, 5);


	bSizer45->Add(bSizer77, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer(wxVERTICAL);

	list_buildings = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	list_buildings->SetMinSize(wxSize(400, 2500));

	bSizer78->Add(list_buildings, 0, wxALL, 5);


	bSizer45->Add(bSizer78, 1, wxEXPAND, 5);


	bSizer43->Add(bSizer45, 1, wxEXPAND, 5);


	bSizer43->Add(50, 0, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer(wxVERTICAL);

	bSizer44->SetMinSize(wxSize(400, -1));
	wxBoxSizer* bSizer491;
	bSizer491 = new wxBoxSizer(wxVERTICAL);

	label_task_list = new wxStaticText(this, wxID_ANY, wxT("Task list"), wxDefaultPosition, wxDefaultSize, 0);
	label_task_list->Wrap(-1);
	bSizer491->Add(label_task_list, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer44->Add(bSizer491, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer(wxVERTICAL);

	m_staticText37 = new wxStaticText(this, wxID_ANY, wxT("Task"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText37->Wrap(-1);
	bSizer83->Add(m_staticText37, 0, wxALIGN_CENTER, 5);


	bSizer50->Add(bSizer83, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* bSizer581;
	bSizer581 = new wxBoxSizer(wxVERTICAL);

	m_staticText16 = new wxStaticText(this, wxID_ANY, wxT("X,Y-cord"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText16->Wrap(-1);
	bSizer581->Add(m_staticText16, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer50->Add(bSizer581, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* bSizer591;
	bSizer591 = new wxBoxSizer(wxVERTICAL);

	m_staticText17 = new wxStaticText(this, wxID_ANY, wxT("Item"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText17->Wrap(-1);
	bSizer591->Add(m_staticText17, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer50->Add(bSizer591, 1, wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer(wxVERTICAL);

	m_staticText18 = new wxStaticText(this, wxID_ANY, wxT("Amount"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText18->Wrap(-1);
	bSizer60->Add(m_staticText18, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer50->Add(bSizer60, 1, wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer(wxVERTICAL);

	m_staticText19 = new wxStaticText(this, wxID_ANY, wxT("Building Direction"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText19->Wrap(50);
	bSizer61->Add(m_staticText19, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer50->Add(bSizer61, 1, wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer(wxVERTICAL);

	m_staticText20 = new wxStaticText(this, wxID_ANY, wxT("Direction to Build"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText20->Wrap(50);
	bSizer62->Add(m_staticText20, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer50->Add(bSizer62, 1, wxALIGN_CENTER_VERTICAL, 5);


	bSizer44->Add(bSizer50, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer481;
	bSizer481 = new wxBoxSizer(wxVERTICAL);

	list_tasks = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	list_tasks->SetMinSize(wxSize(400, 2500));

	bSizer481->Add(list_tasks, 0, wxALL, 5);


	bSizer44->Add(bSizer481, 1, wxEXPAND, 5);


	bSizer43->Add(bSizer44, 1, wxEXPAND, 5);


	bSizer43->Add(10000, 0, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer43, 1, wxEXPAND, 5);


	bSizer1->Add(0, 1000, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);


	// Connect Events
	cmb_item_category->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(cMain::OnItemCategorySelected), NULL, this);
	cmb_building_direction->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(cMain::OnBuildingDirectionSelected), NULL, this);
	cmb_direction_to_build->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(cMain::OnDirectionToBuildSelected), NULL, this);
	rbtn_walk->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnWalkChosen), NULL, this);
	rbtn_mine->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnMineChosen), NULL, this);
	rbtn_game_speed->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnGameSpeedChosen), NULL, this);
	rbtn_filter->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnfilterChosen), NULL, this);
	rbtn_launch->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnLaunchChosen), NULL, this);
	rbtn_priority->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnPriorityChosen), NULL, this);
	rbtn_craft->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnCraftChosen), NULL, this);
	rbtn_build->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnBuildChosen), NULL, this);
	rbtn_recipe->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnRecipeChosen), NULL, this);
	rbtn_tech->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnTechChosen), NULL, this);
	rbtn_limit->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnLimitChosen), NULL, this);
	rbtn_transfer->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnTransferChosen), NULL, this);
	rbtn_fuel->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnFuelChosen), NULL, this);
	rbtn_take->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnTakeChosen), NULL, this);
	rbtn_put->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnPutChosen), NULL, this);
	rbtn_rotate->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnRotateChosen), NULL, this);
	rbtn_pick_up->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnPickUpChosen), NULL, this);
	rbtn_drop->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(cMain::OnDropChosen), NULL, this);
	btn_add_task->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnAddTaskClicked), NULL, this);
	btn_delete_task->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnDeleteTaskClicked), NULL, this);
	list_buildings->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(cMain::OnBuildingsListKeyDown), NULL, this);
	list_buildings->Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(cMain::OnBuildingsListDoubleClicked), NULL, this);
	list_tasks->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(cMain::OnTasksListKeyDown), NULL, this);
	list_tasks->Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(cMain::OnTasksListDoubleClicked), NULL, this);


	// set walk as default value and disable inputs not used
	rbtn_walk->SetValue(true);
	choose_enabled_parameters(true, true, false, false, false, false, false);

	cmb_building_direction->Clear();
	cmb_direction_to_build->Clear();
	for (auto it = build_directions.begin(); it < build_directions.end(); it++) {
		cmb_building_direction->Append(*it);
		cmb_direction_to_build->Append(*it);

	}
	cmb_building_direction->SetValue(*build_directions.begin());
	cmb_direction_to_build->SetValue(*build_directions.begin());

	/*list_tasks->Insert("X,Y-cord   Amount   Item   Building    Direction", list_task_num);
	list_task_num += 1;
	list_tasks->Insert("                          Direction	    to build", list_task_num);*/
}

void cMain::OnMineChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, true, false, false, false, false);
}

void cMain::OnRotateChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, true, false, false, false, false);
}

void cMain::OnCraftChosen(wxCommandEvent& event) {
	choose_enabled_parameters(false, false, true, true, true, false, false);

	populate_comboboxes(item_categories, item_logistics);
}

void cMain::OnWalkChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, false, false, false, false, false);
}

void cMain::OnBuildChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, true, true, true, true, true);

	populate_comboboxes(item_categories, item_logistics);
}

void cMain::OnGameSpeedChosen(wxCommandEvent& event) {
	choose_enabled_parameters(false, false, true, false, false, false, false);
}

void cMain::OnFuelChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, true, false, true, false, false);

	populate_comboboxes(item_categories_fuel, item_fuels);
}

void cMain::OnTakeChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, true, true, true, false, false);

	populate_comboboxes(item_categories, item_logistics);
}

void cMain::OnPutChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, true, true, true, false, false);

	populate_comboboxes(item_categories, item_logistics);
}

void cMain::OnfilterChosen(wxCommandEvent& event) {
}

void cMain::OnRecipeChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, false, true, true, false, false);

	populate_comboboxes(item_categories, item_logistics);
}

void cMain::OnTechChosen(wxCommandEvent& event) {
	choose_enabled_parameters(false, false, false, true, true, false, false);
}

void cMain::OnLaunchChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, false, false, false, false, false);
}

void cMain::OnPriorityChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, false, true, true, false, false);
}

void cMain::OnLimitChosen(wxCommandEvent& event) {
	choose_enabled_parameters(true, true, true, false, false, false, false);
}

void cMain::OnTransferChosen(wxCommandEvent& event) {

}

void cMain::OnPickUpChosen(wxCommandEvent& event) {
}

void cMain::OnDropChosen(wxCommandEvent& event) {
}

void cMain::update_task_list(std::string task, std::string x_cord, std::string y_cord, std::string item, std::string amount, std::string building_direction, std::string direction_to_build, int index) {
	
	list_tasks->Insert( (task + " - " + x_cord + "," + y_cord + " - " + item + " - " + amount + " - " + building_direction, " - " + direction_to_build), index + 1);

	/*if (text != "") {
		int index = list_tasks->GetSelection();
		list_tasks->Insert("Task " + std::to_string(list_task_num + 1) + ": Game speed - " + txt_amount->GetValue(), index + 1);
		list_task_num += 1;
	} else {
		list_tasks->Insert("Task " + std::to_string(list_task_num + 1) + ": Game speed - " + txt_amount->GetValue(), list_task_num);
		list_task_num += 1;
	}*/
	list_task_num += 1;
}

void cMain::OnAddTaskClicked(wxCommandEvent& event) {
	if (rbtn_game_speed->GetValue()) {
		amount = std::to_string(wxAtoi(txt_amount->GetValue()));
		if (std::stof(amount) < 0.01) {
			speed(std::to_string(0.01));
		} else {
			speed(amount);
		}

		std::string text = list_tasks->GetStringSelection().ToStdString();

		if (text != "") {
			int index = list_tasks->GetSelection();
			update_task_list("Game Speed", not_relevant, );
		} else {
			list_tasks->Insert("Task " + std::to_string(list_task_num + 1) + ": Game speed - " + txt_amount->GetValue(), list_task_num);
			list_task_num += 1;
		}

		/*if (text != "") {
			int index = list_tasks->GetSelection();
			list_tasks->Insert("Task " + std::to_string(list_task_num + 1) + ": Game speed - " + txt_amount->GetValue(), index + 1);
			list_task_num += 1;
		} else {
			list_tasks->Insert("Task " + std::to_string(list_task_num + 1) + ": Game speed - " + txt_amount->GetValue(), list_task_num);
			list_task_num += 1;
		}*/

	

	} else if (rbtn_walk->GetValue()) {
		
		x_cord = wxAtof(txt_x_cord->GetValue());
		y_cord = wxAtof(txt_y_cord->GetValue());

		walk(x_cord, y_cord);

	} else if (rbtn_craft->GetValue()) {
		amount = wxAtoi(txt_amount->GetValue());
		item = cmb_item->GetValue().ToStdString();

		if (check_item(item, all_items)) {
			item = convert_string(item);
			craft(amount, item);
		} else {
			wxMessageBox("The item chosen is not valid - please try again", "Please use the item dropdown menu");
		}

		

	} else if (rbtn_fuel->GetValue()) {
		x_cord = wxAtof(txt_x_cord->GetValue());
		y_cord = wxAtof(txt_y_cord->GetValue());

		amount = wxAtoi(txt_amount->GetValue());
		if (amount < 1) {
			amount = -1;
		}
		
		item = cmb_item->GetValue().ToStdString();

		if (check_item(item, item_fuels)) {
			item = convert_string(item);
			fill_fuel(x_cord, y_cord, amount, item);
		} else {
			wxMessageBox("The item chosen is not a valid fuel - please try again", "Please use the item dropdown menu");
		}		
	}
	event.Skip();
}

void cMain::OnItemCategorySelected(wxCommandEvent& event) {
	if (cmb_item_category->GetValue() == "Logistics") {
		cmb_item->Clear();
		for (auto it = item_logistics.begin(); it < item_logistics.end(); it++) {
			cmb_item->Append(*it);
		}
		cmb_item->SetValue(*item_logistics.begin());

	} else if (cmb_item_category->GetValue() == "Production") {
		cmb_item->Clear();
		for (auto it = item_production.begin(); it < item_production.end(); it++) {
			cmb_item->Append(*it);
		}
		cmb_item->SetValue(*item_production.begin());

	} else if (cmb_item_category->GetValue() == "Intermediates") {
		cmb_item->Clear();
		for (auto it = item_intermediates.begin(); it < item_intermediates.end(); it++) {
			cmb_item->Append(*it);
		}
		cmb_item->SetValue(*item_intermediates.begin());

	} else if (cmb_item_category->GetValue() == "Combat") {
		cmb_item->Clear();
		for (auto it = item_combat.begin(); it < item_combat.end(); it++) {
			cmb_item->Append(*it);
		}
		cmb_item->SetValue(*item_combat.begin());
	}
}

void cMain::OnBuildingsListDoubleClicked(wxCommandEvent& event) {
}

void cMain::OnTasksListDoubleClicked(wxCommandEvent& event) {
	std::string text = list_tasks->GetStringSelection().ToStdString();

	if (text != "") {
		int index = list_tasks->GetSelection();
		list_buildings->Insert(list_tasks->GetString(index), list_buildings_num);
	}
}

void cMain::OnTasksListKeyDown(wxKeyEvent& event) {
}

void cMain::OnBuildingsListKeyDown(wxKeyEvent& event) {
}

void cMain::OnBuildingDirectionSelected(wxCommandEvent& event) {
	// It seems that this is not needed
}

void cMain::OnDirectionToBuildSelected(wxCommandEvent& event) {
	// It seems that this is not needed
}

void cMain::OnDeleteTaskClicked(wxCommandEvent& event) {
}

void cMain::OnMenuNew(wxCommandEvent& evt) {

}

void cMain::OnMenuOpen(wxCommandEvent& evt) {

}

void cMain::OnMenuSave(wxCommandEvent& evt) {
	std::ofstream myfile;
	myfile.open(file_location);

	myfile << end_tasks();;

	myfile.close();
}

void cMain::OnMenuExit(wxCommandEvent& evt) {
	Close();
	evt.Skip();
}

void cMain::choose_enabled_parameters(bool x_cord, bool y_cord, bool amount, bool item_category, bool item, bool building_direction, bool direction_to_build) {
	txt_x_cord->Enable(x_cord);
	txt_y_cord->Enable(y_cord);
	txt_amount->Enable(amount);
	cmb_item_category->Enable(item_category);
	cmb_item->Enable(item);
	cmb_building_direction->Enable(building_direction);
	cmb_direction_to_build->Enable(direction_to_build);
}

void cMain::populate_comboboxes(std::vector<std::string> item_category, std::vector<std::string> item) {
	cmb_item_category->Clear();
	for (auto it = item_category.begin(); it < item_category.end(); it++) {
		cmb_item_category->Append(*it);
	}
	cmb_item_category->SetValue(*item_category.begin());

	cmb_item->Clear();
	for (auto it = item.begin(); it < item.end(); it++) {
		cmb_item->Append(*it);
	}
	cmb_item->SetValue(*item.begin());
}
