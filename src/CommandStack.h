#pragma once
#include <vector>
#include <string>

#include "StepLine.h"

using std::vector;
using std::string;

struct Command
{
	vector<StepLine> before = {};
	vector<StepLine> after = {};
	string template_name = ""; // The name of the template or empty for steps grid

	bool empty()
	{
		return before.empty() && after.empty();
	}
};

class CommandStack
{
public:
	static inline const int CAPACITY = 128;
private:
	
	Command buffer[CAPACITY] = {};
	int head = 0, tail = 0, hair = 0;

public:
	CommandStack() {}

	void Clear();
	void Push(Command command);
	Command Pop();
	Command PopBack();
};
