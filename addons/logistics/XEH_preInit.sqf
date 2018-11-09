#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

[
	QGVAR(customLogistics), // key/reference variable
	"LIST", // type of setting
	["Logistics", "Enable/Disable logistics"], // name and tooltip
	"Kellerkompanie Logistics", // category
	[
		[0,1,2], // values
		["Disabled","Default","Custom"], // names
		1 // default index
	],
	1
] call cba_settings_fnc_init;


[
	QGVAR(accessLevel), // key/reference variable
	"LIST", // type of setting
	["Access Level: Logistics Menu", "Who may spawn crates? Zeus may always."], // name and tooltip
	"Kellerkompanie Logistics", // category
	[
		[
			ACCESS_EVERYONE,
			ACCESS_CORPORAL,
			ACCESS_SERGEANT,
			ACCESS_LIEUTENANT,
			ACCESS_ENGINEERS,
			ACCESS_JTAC,
			ACCESS_ZEUS
		],
		[
			"Everyone",
			"Corporal/FTL and up",
			"Sergeant/SQL and up",
			"Lead/Lt. and up",
			"Engineers only",
			"JTACs only",
			"Zeus only"
		], // names
		2 // default index
	],
	1
] call cba_settings_fnc_init;

[
	QGVAR(virtualHeliLogistics), // key/reference variable
	"LIST", // type of setting
	["Access Level: Virtual Heli Logistics", "Enable/Disable virtual heli logistics."], // name and tooltip
	"Kellerkompanie Logistics", // category
	[
		[
			ACCESS_EVERYONE,
			ACCESS_CORPORAL,
			ACCESS_SERGEANT,
			ACCESS_LIEUTENANT,
			ACCESS_UAVOPERATOR,
			ACCESS_JTAC,
			ACCESS_ZEUS
		],
		[
			"Everyone",
			"Corporal/FTL and up",
			"Sergeant/SQL and up",
			"Lead/Lt. and up",
			"UAV Operators only",
			"JTACs only",
			"Zeus only"
		], // names
		2 // default index
	],
	1
] call cba_settings_fnc_init;

[
	QGVAR(virtualUAVLogistics), // key/reference variable
	"LIST", // type of setting
	["Access Level: Virtual UAV Logistics", "Enable/Disable virtual UAV logistics."], // name and tooltip
	"Kellerkompanie Logistics", // category
	[
		[
			ACCESS_EVERYONE,
			ACCESS_CORPORAL,
			ACCESS_SERGEANT,
			ACCESS_LIEUTENANT,
			ACCESS_UAVOPERATOR,
			ACCESS_JTAC,
			ACCESS_ZEUS
		],
		[
			"Everyone",
			"Corporal/FTL and up",
			"Sergeant/SQL and up",
			"Lead/Lt. and up",
			"UAV Operators only",
			"JTACs only",
			"Zeus only"
		], // names
		2 // default index
	],
	1
] call cba_settings_fnc_init;

ADDON = true;
