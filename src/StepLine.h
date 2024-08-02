#pragma once

#include <vector>
#include "Structures\Step.h"

using std::vector;

// Simple pair of a row number and Step
// Overloads comparison to the row number for easier sorting
struct StepLine
{
	int row;
	Step step;

	bool operator < (const StepLine& other) const
	{
		return row < other.row;
	}
	bool operator > (const StepLine& other) const
	{
		return row > other.row;
	}
};

// Simple pair of a starting row and a list of continues Steps
struct StepBlock
{
	int row;
	vector<Step> steps;
};

vector<StepBlock> static StepLineToStepBlock(vector<StepLine>& lines)
{
	vector<StepBlock> blocks{};
	int prev = -2;

	std::sort(lines.begin(), lines.end());
	for (auto& stepline : lines)
	{
		if (prev + 1 == stepline.row)
			blocks[blocks.size() - 1].steps.push_back(stepline.step);
		else
			blocks.push_back({stepline.row, {stepline.step}});
		prev = stepline.row;
	}

	return blocks;
}
