#pragma once

#include <string>

using std::string;

static const int step_segment_size = 12;
static const int step_segment_size_without_colour = 11;
static const int step_segment_size_without_comment_and_colour = 10;
static const int step_segment_size_without_comment_and_colour_and_modifiers = 9;
static const int group_segment_size = 11;
static const int group_segment_size_without_comment = 10;
static const int template_segment_size = 13;
static const int template_segment_size_without_colour = 12;
static const int template_segment_size_without_comment_and_colour = 11;
static const int template_segment_size_without_comment_and_colour_and_modifiers = 10;

static const string total_steps_indicator = "Total lines:";
static const string total_commands_indicator = "Total commands:";
static const string goal_indicator = "Goal:";
static const string steps_indicator = "Steps:";
static const string save_groups_indicator = "Groups:";
static const string save_templates_indicator = "Templates:";
static const string save_file_indicator = "Save file location:";
static const string code_file_indicator = "Step folder location:";
static const string auto_close_indicator = "Auto close settings:";
static const string import_into_row_indicator = "Import into:";
static const string logging_indicator = "logging";
static const string generate_indicator = "generate settings";

static const string auto_close_generate_script_text = "Generate Script";
static const string auto_close_open_text = "Open";
static const string auto_close_save_text = "Save";
static const string auto_close_save_as_text = "Save As";

static const string goal_steelaxe_text = "Steel Axe";
static const string goal_GOTLAP_text = "Getting On Track Like A Pro";
static const string goal_any_percent_text = "Any%", goal_any_percent_text_old = "Any %";
static const string scenario_supply_challenge_text = "Supply challenge";
static const string goal_debug_text = "Debug";