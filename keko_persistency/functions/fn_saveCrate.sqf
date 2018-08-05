if(keko_settings_persistency_enabled == 0) exitWith{diag_log text "[KEKO] (persistency) saveCrate: persistency disabled, exiting!"; false};
if(keko_settings_persistency_key == "") exitWith{diag_log text "[KEKO] (persistency) saveCrate: persistency key not set, exiting!"; false};

params ["_crate"];

_crateID = _crate getVariable ["keko_persistency_crateID", -1];
_crateClass = typeOf _crate;
_cratePosition = getPos _crate;
_crateOrientation = getDir _crate;

_crateSerialization = _crate call keko_persistency_fnc_getContainerContent;
_crateItems = _crateSerialization select 0;
_crateMagazines = _crateSerialization select 1;
_crateWeapons = _crateSerialization select 2;
_crateContainers = _crateSerialization select 3;

diag_log text format["[KEKO] (persistency) saveCrate _crateID=%1 _crateClass=%2 _cratePosition=%3", _crateID, _crateClass, _cratePosition];

if(_crateID == -1) then {
	// crate does not exist yet, create new and store CrateID
	_ret = call compile ("extDB3" callExtension format [ "0:keko_persistency:addCrate:%1:%2:%3:%4:%5:%6:%7:%8",
		keko_settings_persistency_key,
		_crateClass,
		_cratePosition,
		_crateOrientation,
		_crateItems,
		_crateMagazines,
		_crateWeapons,
		_crateContainers]);
	diag_log text format["[KEKO] (persistency) addCrate returns: %1", _ret];

	if ((_ret select 0) == 1) then {
		_crateID = ((_ret select 1) select 0);
		diag_log text format["[KEKO] (persistency) crate was created with CrateID %1", _crateID];
		_crate setVariable ["keko_persistency_crateID", _crateID];
		true
	} else {
		diag_log text format["[KEKO] (persistency) creation of crate was unsucessful :("];
		false
	};


} else {
	// crate already exists, update information
	_ret = "extDB3" callExtension format [ "1:keko_persistency:updateCrate:%1:%2:%3:%4:%5:%6:%7:%8:%9",
		keko_settings_persistency_key,
		_crateClass,
		_cratePosition,
		_crateOrientation,
		_crateItems,
		_crateMagazines,
		_crateWeapons,
		_crateContainers,
		_crateID];

	diag_log text format["[KEKO] (persistency) updateCrate returns: %1", _ret];
	true
};
