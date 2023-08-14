#pragma once

#include <string>
#include <fstream>

#include "Building.h"
#include "StepType.h"
#include "Orientation.h"
#include "Priority.h"
#include "StepModifiers.h"

using std::string;
using std::ofstream;
using std::to_string;

struct StepParameters
{
	StepParameters(double InitialX, double InitialY);

	double X;
	double Y;
	double OriginalX;
	double OriginalY;
	int Size;
	int Buildings;
	int BuildingIndex;

	StepModifiers Modifiers;

	Orientation OrientationEnum;
	StepType type;

	string Amount;
	string Item;
	string FromInto;
	string Orientation;
	string Direction;
	PriorityStruct priority;
	string Comment;
	string Colour;

	void Reset();
	void Next();

	string ToString();

	bool operator==(const Building& toCompare);
	bool operator==(const StepParameters& toCompare);
};