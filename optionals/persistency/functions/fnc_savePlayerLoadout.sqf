#include "script_component.hpp"

EXIT_IF_PERSISTENCY_DISABLED;
EXIT_IF_KEY_INVALID;
if (GVAR(playersEnabled) == 0) exitWith{WARNING("savePlayerLoadout: persistency for players is disabled, exiting!"); false};

params ["_playerUnit"];

if !(isPlayer _playerUnit) exitWith {
	WARNING("savePlayerLoadout: not a player, exiting!");
	false
};

private _playerUID = getPlayerUID _playerUnit;
private _playerName = name _playerUnit;

if (_playerUID find "HC" >= 0) exitWith {
	WARNING("savePlayerLoadout: HC detected, exiting!");
	false
};

private _loadout = getUnitLoadout _playerUnit;
private _medicClass = _playerUnit getVariable ["ace_medical_medicClass", 0];
private _engineerClass = _playerUnit getVariable ["ACE_isEngineer", 0];
private _rank = rank _playerUnit;
private _position = getPos _playerUnit;

TRACE_2("savePlayerLoadout", _playerUID, _playerName);

private _ret = "extDB3" callExtension format [ "1:keko_persistency:setPlayerLoadout:%1:%2:%3:%4:%5:%6:%7:%8",
	GVAR(key),
	_playerUID,
	_playerName,
	_loadout,
	_medicClass,
	_engineerClass,
	_rank,
	_position];

TRACE_1("savePlayerLoadout", _ret);

true
