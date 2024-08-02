#include "StdUtil.h"

struct Riding
{
	enum Acceleration
	{
		nothing,
		accelerating,
		breaking,
		reversing,
	};

	static inline const vector<string> AccelerationNames = {
		"Idle",
		"Accel",
		"Break",
		"Back",
	};

	static inline const vector<string> AccelerationLua = {
		"defines.riding.acceleration.nothing",
		"defines.riding.acceleration.accelerating",
		"defines.riding.acceleration.braking",
		"defines.riding.acceleration.reversing",
	};

	enum Direction
	{
		left, 
		straight, 
		right,
	};

	static inline const vector<string> DirectionNames = {
		"Left",
		"None",
		"Right",
	};

	static inline const vector<string> DirectionLua = {
		"defines.riding.direction.left",
		"defines.riding.direction.straight",
		"defines.riding.direction.right",
	};

	Acceleration acceleration = Acceleration::nothing;
	Direction direction = Direction::straight;

	static inline map<string, Acceleration> MapStringToAcceleration = convert_vector_to_enummap<Acceleration>(AccelerationNames);
	static inline map<string, Direction> MapStringToDirection = convert_vector_to_enummap<Direction>(DirectionNames);

	string ToString() const
	{
		return AccelerationNames[acceleration] + "," + DirectionNames[direction];
	}
	string ToLua() const
	{
		return AccelerationLua[acceleration] + ", " + DirectionLua[direction];
	}

	bool FromString(string str)
	{
		size_t pos = str.find(',');

		auto acc = MapStringToAcceleration.find(str.substr(0, pos));
		auto dir = MapStringToDirection.find(str.substr(pos + 1, str.size()));

		if (acc != Riding::MapStringToAcceleration.end() &&
			dir != Riding::MapStringToDirection.end())
		{
			acceleration = acc->second;
			direction = dir->second;
			return true;
		}

		return false;
	}
};
