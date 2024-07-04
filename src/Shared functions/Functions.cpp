#pragma once

#include "Functions.h"
#include <sstream>
#include <ranges>

bool check_input(const string& item, const vector<string>& all_items)
{
	for (int i = 0; i < all_items.size(); i++)
	{
		if (item.length() != all_items[i].length())
		{
			continue;
		}

		for (int j = 0; j < item.length(); j++)
		{
			if (item[j] != all_items[i][j])
			{
				break;
			}

			if (j == item.length() - 1)
			{
				return true;
			}
		}
	}

	return false;
}

void find_coordinates(std::string& x_cord, std::string& y_cord, std::string& direction, std::string& building_size)
{
	if (direction == "north" || direction == "North")
	{
		y_cord = std::to_string(std::stof(y_cord) - std::stof(building_size));

	}
	else if (direction == "south" || direction == "South")
	{
		y_cord = std::to_string(std::stof(y_cord) + std::stof(building_size));

	}
	else if (direction == "east" || direction == "East")
	{
		x_cord = std::to_string(std::stof(x_cord) + std::stof(building_size));

	}
	else if (direction == "west" || direction == "West")
	{
		x_cord = std::to_string(std::stof(x_cord) - std::stof(building_size));
	}
}

string Capitalize(const std::string& stringToCapitalize, const bool isItem)
{
	if (stringToCapitalize.empty()) return stringToCapitalize;
	std::string capitalizedString = stringToCapitalize;
	const int stringLength = capitalizedString.length();

	capitalizedString[0] = std::toupper(stringToCapitalize[0]);
	for (int i = 1; i < stringLength; ++i)
	{
		capitalizedString[i] = tolower(stringToCapitalize[i]);
	}

	if (isItem && stringLength > 3 && capitalizedString.substr(stringLength - 3, 3) == "mk2")
	{
		capitalizedString[stringLength - 3] = 'M';
		capitalizedString[stringLength - 2] = 'K';
		capitalizedString[stringLength - 1] = '2';
	}

	return capitalizedString;
}

string Capitalize(const wxString& stringToCapitalize, const bool isItem)
{
	if (stringToCapitalize == "")
	{
		return "";
	}

	return Capitalize(stringToCapitalize.ToStdString(), isItem);
}

static bool ichar_equals(char a, char b)
{
	return std::tolower(static_cast<unsigned char>(a)) ==
		std::tolower(static_cast<unsigned char>(b));
}

bool equals_ignore_case(const std::string_view& lhs, const std::string_view& rhs)
{
	return std::ranges::equal(lhs , rhs, ichar_equals);
}

bool starts_with_ignore_case(const std::string& base, const std::string& start)
{
	if (base.size() < start.size()) return false;
	for (int i = 0; i < start.size(); i++)
		if (toupper(base[i]) != toupper(start[i]))
			return false;
	return true;
}

bool starts_with_ignore_case(const wxString& base, const wxString& start)
{
	if (base.size() < start.size()) return false;
	for (int i = 0; i < start.size(); i++)
		if (toupper(base[i]) != toupper(start[i]))
			return false;
	return true;
}

bool starts_with_ignore_case_anyword(const wxString& base, const wxString& start)
{
	if (base.size() < start.size()) return false;
	if (start.Contains(" ")) return starts_with_ignore_case(base, start);
	vector<wxString> base_parts = Split(base, ' ');
	for (wxString part : base_parts)
	{
		if (starts_with_ignore_case(part, start))
			return true;
	}
	return false;
}

vector<string> get_keys(map<string, vector<Step>> map)
{
	vector<string> keys;
	for (std::map<string, vector<Step>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		keys.push_back(it->first);
	}

	return keys;
}

int ProcessBuildStep(vector<Building>& buildings, int buildingsInSnapShot, Step& step)
{
	buildings[buildingsInSnapShot].X = step.X;
	buildings[buildingsInSnapShot].Y = step.Y;
	buildings[buildingsInSnapShot].type = (Building::BuildingType) step.BuildingIndex.value().type;
	buildings[buildingsInSnapShot].orientation = step.orientation;
	buildingsInSnapShot++;

	if (step.Buildings == 1)
	{
		return buildingsInSnapShot;
	}

	for (int i = 1; i < step.Buildings; i++)
	{
		step.Next();
		
		buildings[buildingsInSnapShot].X = step.X;
		buildings[buildingsInSnapShot].Y = step.Y;
		buildings[buildingsInSnapShot].type = (Building::BuildingType)step.BuildingIndex.value().type;
		buildings[buildingsInSnapShot].orientation = step.orientation;
		buildingsInSnapShot++;
	}

	step.Reset();
	return buildingsInSnapShot;
}

void ProcessMiningStep(vector<Building>& buildings, int buildingsInSnapShot, Step& step)
{
	for (int i = 0; i < buildingsInSnapShot; i++)
	{
		if (step == buildings[i])
		{
			if (step.Modifiers.split ||
				step.Modifiers.skip ||
				Capitalize(step.Comment) == "Split")
			{
				return;
			}

			step.BuildingIndex = buildings[i];
			buildings[i].X = -0.4523543; // Invalidate the building
			return;
		}
	}
}

bool BuildingExists(vector<Building>& buildings, int buildingsInSnapShot, Step& step)
{
	int buildingsFound = 0;
	Orientation firstOrientation = North;

	for (int i = 0; i < step.Buildings; i++)
	{
		for (int j = buildingsInSnapShot - 1; j > -1; j--)
		{
			if (step == buildings[j])
			{
				if (buildingsFound == 0)
				{
					firstOrientation = buildings[j].orientation;
				}

				buildingsFound++;
				step.BuildingIndex = buildings[j];
				break;
			}
		}

		if (buildingsFound == step.Buildings)
		{
			step.Reset();
			step.orientation = firstOrientation;
			return true;
		}

		step.Next();
	}

	step.Reset();
	step.BuildingIndex = {};
	return false;
}

void PopulateGrid(wxGrid* grid, int row, GridEntry* gridEntry)
{
	grid->SetCellValue(row, 0, gridEntry->Step);
	grid->SetCellValue(row, 1, gridEntry->X);
	grid->SetCellValue(row, 2, gridEntry->Y);
	grid->SetCellValue(row, 3, gridEntry->Amount);
	grid->SetCellValue(row, 4, gridEntry->Item);
	grid->SetCellValue(row, 5, gridEntry->BuildingOrientation);
	grid->SetCellValue(row, 6, gridEntry->Modifiers);
	grid->SetCellValue(row, 7, gridEntry->DirectionToBuild);
	grid->SetCellValue(row, 8, gridEntry->BuildingSize);
	grid->SetCellValue(row, 9, gridEntry->AmountOfBuildings);
	grid->SetCellValue(row, 10, gridEntry->Comment);
}

bool StringContainsAny(const wxString& str, const string& chars)
{
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < chars.size(); j++)
		{
			if (str[i] == str[j])
			{
				return true;
			}

		}
	}

	return false;
}

vector<wxString> Split(const string& s, char delim)
{
	vector<wxString> result;
	stringstream ss(s);
	string item;

	while (std::getline(ss, item, delim))
	{
		result.push_back(item);
	}
	if (result.empty()) result.push_back(s);
	return result;
}

vector<wxString> Split(const wxString& s, char delim)
{
	return Split(s.ToStdString(), delim);
}

bool ListContains(wxArrayString* list, wxString str)
{
	for (int i = 0; i < list->GetCount(); i++)
	{
		if (list->Item(i) == str) return true;
	}
	return false;
}
