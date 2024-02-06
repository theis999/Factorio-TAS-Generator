#pragma once

#include <wx/colour.h>

#include <string>
#include <optional>

#include "Building.h"
#include "StepType.h"
#include "Orientation.h"
#include "Priority.h"
#include "StepModifiers.h"

#include "../Data/Inventory.h"

using std::string;
using std::to_string;
using std::optional;

struct Step
{
	Step(double InitialX, double InitialY);

	double X;
	double Y;
	double OriginalX;
	double OriginalY;

	int Size = 1;
	int Buildings = 1;
	optional<Building> BuildingIndex{};

	StepModifiers Modifiers;

	StepType type = e_stop;
	InventoryType inventory = Input;

	/* Amount: unsigned int
	* 0 is used for All
	* Filter: 1 <= amount <= 5
	* Idle, rotate, pickup: amount >= 1
	* Rotate: amount == 3, implies reverse rotation
	* Game speed have amount in percentage */
	int amount = 0;
	string Item;
	Orientation orientation = North;
	Orientation Direction = North;
	PriorityStruct priority;
	string Comment;
	wxColour colour;

	string AmountLua();
	string AmountGrid();

	void Reset();
	void Next();

	string ToString();

	bool operator==(const Building& toCompare);
	bool operator==(const Step& toCompare);
};
