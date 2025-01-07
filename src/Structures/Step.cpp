#include "Step.h"

#include "ParameterChoices.h"

#include <format>

Step::Step(double InitialX, double InitialY)
{
	X = InitialX;
	Y = InitialY;
}

string Step::AmountLua()
{
	if (type == e_game_speed)
		return to_string(static_cast<float>(amount < 1 ? 1 : amount) / 100.0);
	else if (amount <= 0)
	{
		if (type == e_rotate || type == e_wait || type == e_pick_up)
			return "1";
		else if (type == e_mine)
			return "1000";
		else
			return "-1";
	}
	else return to_string(amount);
}

string Step::AmountGrid()
{
	if (type == e_game_speed) return std::format("{}%", amount);
	if (type == e_equip && amount < 1) return "None";
	if (amount < 1) return "All";

	return to_string(amount);
}

string Step::ToString()
{
	const string string_end = ";" + Comment + ";" + colour.GetAsString().ToStdString() + ";" + Modifiers.ToString() + ";";
	const string steptype = StepNames[type];
	const int params = listStepTypeToParameterChoices[type];
	switch (type)
	{
		case e_game_speed:
			return steptype + ";" + ";" + ";" + to_string(amount / 100) + ";" + ";" + string_end;

		case e_limit:
			return steptype + ";" + to_string(X) + ";" + to_string(Y) + ";" + to_string(amount) + ";" + ";" + "Chest" + ";" + string_end;

		case e_rotate:
			return steptype + ";" + to_string(X) + ";" + to_string(Y) + ";" + to_string(amount) + ";" + Item + ";" + string_end;

		case e_mine:
			return steptype + ";" + to_string(X) + ";" + to_string(Y) + ";" + to_string(amount) + ";" + Item + ";" + string_end;

		case e_priority:
			return steptype + ";" + to_string(X) + ";" + to_string(Y) + ";" + ";" + ";" + priority.ToString() + ";" + string_end;

		case e_drive:
				return steptype + ";;;" + to_string(amount) + ";;" + riding.ToString() + string_end;
		
		default:
			return std::format("{};{};{};{};{};{}{}",
				steptype,
				params & choice_bit_vector::x_coordinate ? to_string(X) : "",
				params & choice_bit_vector::y_coordinate ? to_string(Y) : "",
				params & choice_bit_vector::amount ? to_string(amount) : "",
				params & choice_bit_vector::item ? Item : "",

				params & choice_bit_vector::from_to ? inventory_types_list[inventory] : 
					params & choice_bit_vector::building_orientation ? orientation_list[orientation] : "",
		
				string_end);
	}
}

bool Step::operator==(const Building& toCompare)
{
	if (toCompare.X == X && toCompare.Y == Y)
	{
		BuildingIndex = toCompare.type;
		orientation = toCompare.orientation;
		return true;
	}

	return false;
}

bool Step::operator==(const Step& toCompare)
{
	if (toCompare.X != X && toCompare.Y != Y)
	{
		return false;
	}

	if (toCompare.X == X && toCompare.Y == Y)
	{
		return true;
	}

	return false;
}
