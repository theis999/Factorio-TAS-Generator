#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

struct StepModifiers
{
	// Fields
	bool no_order = false,
		skip = false,
		wait_for = false,
		force = false,
		cancel_others = false,
		split = false,
		walk_towards = false,
		all = false,
		vehicle = false;

private:
	static const struct
	{
		const string NO_ORDER = "no order",
			SKIP = "skip",
			WAIT_FOR = "wait for",
			FORCE = "force",
			CANCEL_OTHERS = "cancel others",
			SPLIT = "split",
			WALK_TOWARDS = "walk towards",
			ALL = "all",
			VEHICLE = "vehicle";
	} inline StepModifiersLookupString;

	static inline const vector<const string*> StepModifiersLookupStrings = {
		& StepModifiersLookupString.NO_ORDER,
		& StepModifiersLookupString.SKIP,
		& StepModifiersLookupString.WAIT_FOR,
		& StepModifiersLookupString.FORCE,
		& StepModifiersLookupString.CANCEL_OTHERS,
		& StepModifiersLookupString.SPLIT,
		& StepModifiersLookupString.WALK_TOWARDS,
		& StepModifiersLookupString.ALL,
		& StepModifiersLookupString.VEHICLE,
	};

	inline const vector<bool> ToVector()
	{
		return {
			no_order,
			skip,
			wait_for,
			force,
			cancel_others,
			split,
			walk_towards,
			all,
			vehicle,
		};
	}

	inline const vector<bool*> ToPointerVector()
	{
		return {
			&no_order,
			&skip,
			&wait_for,
			&force,
			&cancel_others,
			&split,
			&walk_towards,
			&all,
			&vehicle,
		};
	}

public:
	/// <summary>Sets the values using a string as input</summary>
	/// <param name="str">Input string containing any number of LookupStrings</param>
	inline void FromString(string str)
	{
		if (str.empty()) 
		{ // fast => set everything to false
			no_order = skip = wait_for = force = cancel_others = split = walk_towards = all = vehicle = false;
		}
		
		auto data = ToPointerVector();
		for (int i = 0; i < StepModifiersLookupStrings.size(); i++)
			*data[i] = str.find(*StepModifiersLookupStrings[i]) != std::string::npos;
		
	}

	/// <summary>Converts the modifiers to a string in the format => "" | "<modifier>" | "<modifier>, (recursion)"</summary>
	inline const string ToString()
	{
		auto data = ToVector();
		string output = ""; output.reserve(15*7); // Guessed max length 15 * 7 modifiers

		for (int i = 0; i < StepModifiersLookupStrings.size(); i++)
			if (data[i])
				output +=  *StepModifiersLookupStrings[i] + ", ";

		return output.ends_with(' ') ?
			output.substr(0, output.size() - 2) : // remove last ", "
			output;
	}

	inline const string ToLua()
	{
		string output = ", "; output.reserve(21 * 4 + 2); // Guessed max length 21 times 4 modifiers

		output += cancel_others ? " cancel = true," : "";
		output += no_order ? " no_order = true," : "";
		output += wait_for ? " wait_for = true," : "";
		output += walk_towards ? " walk_towards = true," : "";
		output += all ? " all = true," : "";
		output += vehicle ? " vehicle = true," : "";
		/* Rest are not included since they are not relevant in lua
		//output += skip ? " skip = true," : "";
		//output += force ? " force = true," : "";
		//output += split ? " split = true," : "";
		*/
		return output.size() < 3 ? "" : output;
	}
};
