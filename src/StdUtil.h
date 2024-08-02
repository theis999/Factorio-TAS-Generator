#pragma once

#include <optional>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

#include "Shared functions/StringFunctions.h"

using std::optional;
using std::map;
using std::string;
using std::vector;
using std::unordered_map;


template <typename T>
map<string, T> convert_vector_to_enummap(vector<string> list)
{
	map<string, T> m{};

	for (int i = 0; i < list.size(); i++)
	{
		m.insert({list[i], (T)i});
	}

	return m;
}

const map<string, int> convert_vector_to_map(const vector<string> v);
