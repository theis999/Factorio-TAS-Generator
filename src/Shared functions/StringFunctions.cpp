#include "StringFunctions.h"

using std::tolower;

string to_lower(const string str)
{
	string r_str = str;
	for (int i = 0; i < str.size(); i++)
		r_str[i] = tolower(str[i]);
	return r_str;
}

bool is_number(const std::string& str)
{
	for (auto s : str)
	{
		if (!std::isdigit(s))
		{
			return false;
		}
	}

	return true;
}
