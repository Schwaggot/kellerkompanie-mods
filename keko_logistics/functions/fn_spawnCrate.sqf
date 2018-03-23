diag_log text "[KEKO] (logistics) spawnCrate";

_returnCrate = "";
if(keko_var_customLogistics == 2) then {
	params ["_position", "_crate_name"];

	diag_log text "[KEKO] (logistics) spawnCrate keko_var_customLogistics == 2";
	diag_log text format["[KEKO] (logistics) spawnCrate customCrates = %1", keko_var_logistics_customCrates];
	diag_log text format["[KEKO] (logistics) spawnCrate _crate_name = '%1'", _crate_name];

	_descapedString = [_crate_name, "%20", " "] call keko_loadout_fnc_replaceString;

	diag_log text format["[KEKO] (logistics) spawnCrate _descapedString = '%1'", _descapedString];

	{
		_entryName = _x select 0;
		_entryClass = _x select 1;
		_entryContents = _x select 2;

		diag_log text format["[KEKO] (logistics) spawnCrate iterating = %1 %2", _entryName, _entryClass];

		if(_entryName isEqualTo _descapedString) then {
			diag_log text format["[KEKO] (logistics) '%1' isEqualTo '%2'", _entryName, _descapedString];

			_crate = createVehicle [_entryClass, _position, [], 0, "CAN_COLLIDE"];
			_crate allowDamage false;
			[_crate] call keko_logistics_fnc_clearCargo;

			[_crate, _entryContents] call keko_logistics_fnc_fillCrate;

			diag_log text "[KEKO] (logistics) spawnCrate crate created";

			if(true) exitWith{_returnCrate = _crate;};
		};
	} forEach keko_var_logistics_customCrates select 0;
}
else {
	params ["_position", "_faction", "_crate"];

	diag_log text "[KEKO] (logistics) spawnCrate keko_var_customLogistics != 2";
	diag_log text format["[KEKO] (logistics) spawnCrate: %1 %2 %3", _position, _faction, _crate];

	_crateConfig = configFile >> "kekoFaction" >> _faction >> _crate;
	_cfgNames = getArray (_crateConfig >> "cfgName");

	// TODO choose based on side
	_cfgName = _cfgNames select 0;

	_inventory = getArray (_crateConfig >> "inventory");

	_crate = createVehicle [_cfgName,_position, [], 0, "CAN_COLLIDE"];
	_crate allowDamage false;
	[_crate] call keko_logistics_fnc_clearCargo;

	[_crate, _inventory] call keko_logistics_fnc_fillCrate;

	diag_log text "[KEKO] (logistics) spawnCrate crate created";

	if(true) exitWith{_returnCrate = _crate;};
};

//diag_log text "[KEKO] (logistics) spawnCrate returning";

_returnCrate