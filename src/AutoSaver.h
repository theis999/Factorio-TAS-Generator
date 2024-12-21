#pragma once

#include "CommandStack.h"
#include "TAS save file/SaveTas.h"

class AutoSaver
{
public:
	AutoSaver();

	// Clears the autosave list, without impacting the undo stack. Used when saving FTG
	void Clear(); 
	
	// Pushes a new change to both the autosave list and undo stack
	void Push(Command); 
	// Removes the most recent element in the autosave list and pops the undo stack
	Command Pop();

	// Redos the undo stack and puts the new redone element onto the autosave list
	Command PopBack(); 
	
	// Generates a autosave file
	bool Autosave(
		wxWindow* parent,
		DialogProgressBar* dialog_progress_bar,
		string folder_location
	);

	// Opens a autosavefile and returns its content
	vector<Command> OpenAutosave(std::ifstream& file, vector<Building> buildingSnapshot, int& buildingsInSnapShot);

	const string COMMAND = "Command", 
		BEFORE = "Before", 
		AFTER = "After";


private:
	// Reads a line of segments assuming it is StepLine
	StepLine read_StepLine(const size_t segment_size, vector<Building> buildingSnapshot, int& buildingsInSnapShot, std::vector<string>::iterator step_segments);
	
	// Reads a line of text and puts elements separated by ; into the segments list
	bool update_segment(std::ifstream& file);
	vector<string> segments; // Storage for reading the autosave list

	// The autosave list, used to generate a autosave file
	vector<Command> autosave_data = vector<Command>();
	
	// The undo redo structure, used to undo or redo changes
	CommandStack undo_stack;
};
