#include "script_component.hpp"

params ["", "_faction", "_role"];

private _customLoadout = _faction isEqualTo "kekoCustom";

if(_customLoadout) then {
	[_role, _faction] call FUNC(applyCustomLoadout);
};

if (_customLoadout) exitWith{};


player enableSimulation false;

private _role_config = configFile >> "kekoFaction" >> _faction >> _role;
private _weaponCfg = getText (configFile >> "kekoFaction" >> _faction >> "weaponCfg");
private _weapon_config = configFile >> "kekoFaction" >> _faction >> _weaponCfg;

private _uniform = getArray (_role_config >> "uniform");
private _uniformInventory = getArray (_role_config >> "uniformInventory");
private _vest = getArray (_role_config >> "vest");
private _vestInventory = getArray (_role_config >> "vestInventory");
private _backpack = getArray (_role_config >> "backpack");
private _backpackInventory = getArray (_role_config >> "backpackInventory");
private _helmet = getArray (_role_config >> "helmet");

private _medicClass = getNumber (_role_config >> "medicClass");
private _engineerClass = getNumber (_role_config >> "engineerClass");
private _rank = getText (_role_config >> "rank");

private _primary = getArray (_role_config >> "primary");
private _secondary = getArray (_role_config >> "secondary");
private _launcher = getArray (_role_config >> "launcher");

private _items = getArray (_role_config >> "items");

private _goggles = getArray (_role_config >> "goggles");

private _optics = getArray (_role_config >> "optics");


removeAllWeapons player;
removeAllItems player;
removeAllAssignedItems player;
removeUniform player;
removeVest player;
removeBackpack player;
removeHeadgear player;
removeGoggles player;

player setVariable ["ace_medical_medicClass", _medicClass, true];
player setVariable ["ACE_isEngineer", _engineerClass, true];

if(rank player isEqualTo "PRIVATE") then {
	player setUnitRank _rank;
};

if(count _uniform != 0) then {
	private _random_uniform = selectRandom _uniform;
	//_random_uniform = [_random_uniform] call keko_fnc_replaceKeyword;
	player forceAddUniform _random_uniform;
};

if(count _vest != 0) then {
	private _random_vest = selectRandom _vest;
	//_random_vest = [_random_vest] call keko_fnc_replaceKeyword;
	player addVest _random_vest;
};

if(count _backpack != 0) then {
	private _random_backpack = selectRandom _backpack;
	//_random_backpack = [_random_backpack] call keko_fnc_replaceKeyword;
	player addBackpack _random_backpack;
};

/* Workaround for Mods adding Medikits and Firstaidkits to Uniforms, Backpacks etc.*/
clearAllItemsFromBackpack player;

if(count _uniform != 0) then {
	if(count _uniformInventory != 0) then {
		{
			for "_i" from 1 to (_x select 0) do {
				private _item = _x select 1;
				//_item = [_item] call keko_fnc_replaceKeyword;
				player addItemToUniform _item;
			};
		} forEach _uniformInventory;
	};
};

if(count _vest != 0) then {
	if(count _vestInventory != 0) then {
		{
			for "_i" from 1 to (_x select 0) do {
				private _item = _x select 1;
				//_item = [_item] call keko_fnc_replaceKeyword;
				player addItemToVest _item;
			};
		} forEach _vestInventory;

		if(GVAR(giveGps) == 3) then {
			player addItemToVest "ACE_microDAGR";
		};
	};
};

if(count _backpack != 0) then {
	if(count _backpackInventory != 0) then {
		{
			for "_i" from 1 to (_x select 0) do {
				private _item = _x select 1;
				//_item = [_item] call keko_fnc_replaceKeyword;
				player addItemToBackpack _item;
			};
		} forEach _backpackInventory;
	};
};



if(count _helmet != 0) then {
	private _random_helmet = selectRandom _helmet;
	//_random_helmet = [_random_helmet] call keko_fnc_replaceKeyword;
	player addHeadgear _random_helmet;
};


if(count _primary != 0) then {
	private _randomPrimaryEntry = selectRandom _primary;
	private _primaryCfg = _weapon_config >> _randomPrimaryEntry;

	private _primary_cfgName = getText (_primaryCfg >> "cfgName");
	private _primary_items = getArray (_primaryCfg >> "items");
	private _primary_magazines = getArray (_primaryCfg >> "magazines");
	private _primary_uglMagazines = getArray (_primaryCfg >> "uglMagazines");

	player addWeapon _primary_cfgName;

	if(count _primary_items != 0) then {
		{
			private _item = _x;
			//_item = [_item] call keko_fnc_replaceKeyword;
			player addPrimaryWeaponItem _item;
		} forEach _primary_items;
	};

	if(count _primary_magazines != 0) then {
		private _item = _primary_magazines select 0;
		//_item = [_item] call keko_fnc_replaceKeyword;
		player addItemToVest _item;
	};

	if(count _primary_uglMagazines != 0) then {
		private _item = _primary_uglMagazines select 0;
		//_item = [_item] call keko_fnc_replaceKeyword;
		player addItemToVest _item;
	};
};

if(count _secondary != 0) then {
	private _randomSecondaryEntry = selectRandom _secondary;
	private _secondaryCfg = _weapon_config >> _randomSecondaryEntry;

	private _secondary_cfgName = getText (_secondaryCfg >> "cfgName");
	private _secondary_items = getArray (_secondaryCfg >> "items");
	private _secondary_magazines = getArray (_secondaryCfg >> "magazines");

	player addWeapon _secondary_cfgName;

	if(count _secondary_items != 0) then {
		{
			private _item = _x;
			//_item = [_x] call keko_fnc_replaceKeyword;
			player addHandgunItem _item;
		} forEach _secondary_items;
	};

	if(count _secondary_magazines != 0) then {
		private _item = _secondary_magazines select 0;
		//_item = [_item] call keko_fnc_replaceKeyword;
		player addItemToUniform _item;
	};
};

if(count _launcher != 0) then {
	private _randomLauncherEntry = selectRandom _launcher;
	private _launcherCfg = _weapon_config >> _randomLauncherEntry;

	private _launcher_cfgName = getText (_launcherCfg >> "cfgName");
	private _launcher_items = getArray (_launcherCfg >> "items");
	private _launcher_magazines = getArray (_launcherCfg >> "magazines");

	player addWeapon _launcher_cfgName;

	if(count _launcher_items != 0) then {
		{
			private _item = _x;
			//_item = [_x] call keko_fnc_replaceKeyword;
			player addSecondaryWeaponItem _item;
		} forEach _launcher_items;
	};

	if(count _launcher_magazines != 0) then {
		private _item = _launcher_magazines select 0;
		//_item = [_item] call keko_fnc_replaceKeyword;
		player addItemToBackpack _item;
	};
};


if(count _goggles != 0) then {
	private _random_goggles = selectRandom _goggles;
	//_random_goggles = [_random_goggles] call keko_fnc_replaceKeyword;
	player addGoggles _random_goggles;
};

if(count _optics != 0) then {
	private _random_optics = selectRandom _optics;
	//_random_optics = [_random_optics] call keko_fnc_replaceKeyword;
	player addWeapon _random_optics;
};

// add compass/map, nvg etc. based on mission's preset
call FUNC(addPresetItems);

if(count _items != 0) then {
	{
		player linkItem _x;
	} forEach _items;
};

player enableSimulation true;

if !(weaponLowered player) then {
	player action ["WeaponOnBack", player];
};

// let TFAR initialize
// sleep 3;

// give radio
if (GVAR(giveRadio) > 0) then {
	switch (GVAR(giveRadio)) do {
		case 1: {
			//Verstellbare für alle
			switch (side player) do {
				case west: {
					player linkItem "TFAR_anprc152";
				};
				case east: {
					player linkItem "TFAR_fadak";
				};
				case independent: {
					player linkItem "TFAR_anprc148jem";
				};
				default {};
			};
		};
		case 2: {
			//Verstellbare für Führungspos, sonst Personal
			if ( (rank player) in ["SERGEANT","LIEUTENANT","CAPTAIN","MAJOR","COLONEL"] ) then {
				switch (side player) do {
					case west: {
						player linkItem "TFAR_anprc152";
					};
					case east: {
						player linkItem "TFAR_fadak";
					};
					case independent: {
						player linkItem "TFAR_anprc148jem";
					};
					default {};
				};
			} else {
				switch (side player) do {
					case west: {
						player linkItem "TFAR_rf7800str";
					};
					case east: {
						player linkItem "TFAR_pnr1000a";
					};
					case independent: {
						player linkItem "TFAR_anprc154";
					};
					default {};
				};
			};
		};
		case 3: {
			//Nur für Führungspos
			if ( (rank player) in ["SERGEANT","LIEUTENANT","CAPTAIN","MAJOR","COLONEL"] ) then {
				switch (side player) do {
					case west: {
						player linkItem "TFAR_anprc152";
					};
					case east: {
						player linkItem "TFAR_fadak";
					};
					case independent: {
						player linkItem "TFAR_anprc148jem";
					};
					default {};
				};
			};
		};
		default {};
	};
};

[QGVAR(onLoadoutFinished)] call CBA_fnc_localEvent;

[player] spawn FUNC(setChannels);
