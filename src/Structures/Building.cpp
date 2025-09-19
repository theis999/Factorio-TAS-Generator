#include "Building.h"

Building::Building(double x, double y, BuildingType _type, Orientation _orientation) : 
	X(x), Y(y), type(_type), orientation(_orientation) { }
Building::Building(double x) : 
	X(x) { }
Building::Building() :
	Building(0) { }

string Building::Name() const
{
	return BuildingNames[type];
}
string Building::LuaName() const
{
	return BuildingLuaNames[type];
}
