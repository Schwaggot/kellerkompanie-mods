// Original Version by [RFT] Bridge.J http://responseforcetempest.com
#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

[
	"keko_settings_punch_enabled", // key/reference variable
	"LIST", // type of setting
	["Knock People Unconscious", "Enable/Disable Knock People Unconscious"], // name and tooltip
	"Kellerkompanie Punch", // category
	[
		[1,0], // values
		["Enabled","Disabled"], // names
		0 // default index
	],
	1
] call cba_settings_fnc_init;

#include "\a3\editor_f\Data\Scripts\dikCodes.h";

["Kellerkompanie", "keko_punch", "Punch", {[player] call keko_punch_fnc_punchTarget}, {}, [DIK_HOME, [false,false,false]]] call cba_fnc_addKeybind;

ADDON = true;