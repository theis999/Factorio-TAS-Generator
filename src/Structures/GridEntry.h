#pragma once

#include <wx/string.h>

struct GridEntry
{
	wxString Step;
	wxString X;
	wxString Y;
	wxString Amount;
	wxString Item;
	wxString BuildingOrientation;
	wxString Modifiers;
	wxString Comment;
	
	//Alias'es'
	wxString& Recipe{Item}; // Item alias
	wxString& Technology{Item}; //Item alias
	wxString& Inventory{BuildingOrientation}; //Orientation alias
	wxString& Priority{BuildingOrientation}; //Orientation alias
};