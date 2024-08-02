#include "Technology.h"

string Technology::Name() const
{
	return TechnologyNames[type];
}
string Technology::LuaName() const
{
	return TechnologyType_to_LuaName[type];
}

Technology Technology::MapStringToTech(const string str)
{
	Technology t{};
	if (!MapStringToTech(str, t)) throw "MapStringToTech(): Technology not found";
	return t;
}

Technology Technology::MapStringToTech(const wxString str)
{
	return MapStringToTech(str.ToStdString());
}

bool Technology::MapStringToTech(const string str, Technology& tech)
{
	auto mapped = map_TechnologyName_to_TechnologyType.find(str);
	if (mapped == map_TechnologyName_to_TechnologyType.end())
		return false;
	tech.type = mapped->second;
	return true;
}

bool Technology::MapStringToTech(const wxString str, Technology& tech)
{
	return MapStringToTech(str.ToStdString(), tech);
}
