#include "script_component.hpp"

private _logic = _this select 0;

if !(isServer) exitWith {};

// get variables set in module
private _deathThreshold = parseNumber (_logic getVariable ["DeadThreshold", "2"]);
private _surrenderChance = parseNumber (_logic getVariable ["SurrenderChance", "0.6"]);

private _enemyNearbyInfluence = parseNumber (_logic getVariable ["EnemyNearbyInfluence", "2"]);
private _enemyNearbyRadius = parseNumber (_logic getVariable ["EnemyNearbyRadius", "10"]);
private _enemyNearbyFactor = parseNumber (_logic getVariable ["EnemyNearbyFactor", "0.25"]);

private _onKilledCodeString = _logic getVariable ["OnDeathCode", ""];
private _onSurrenderCodeString = _logic getVariable ["OnSurrenderCode", ""];
private _onInterrogatedCodeString = _logic getVariable ["OnInterrogateCode", ""];

// get synchronized units
private _syncedUnits = synchronizedObjects _logic;

{
    private _group = group _x;
    private _units = units _group;

    _group setVariable [QGVAR(initialUnitCount), count _units];
    _group setVariable [QGVAR(deathThreshold), _deathThreshold];
    _group setVariable [QGVAR(surrenderChance), _surrenderChance];

    _group setVariable [QGVAR(enemyNearbyInfluence), _enemyNearbyInfluence];
    _group setVariable [QGVAR(enemyNearbyRadius), _enemyNearbyRadius];
    _group setVariable [QGVAR(enemyNearbyFactor), _enemyNearbyFactor];

    _group setVariable [QGVAR(onKilledCode), _onKilledCodeString];
    _group setVariable [QGVAR(onSurrenderCode), _onSurrenderCodeString];
    _group setVariable [QGVAR(onInterrogateCode), _onInterrogatedCodeString];
    {
        _x setVariable [QGVAR(isObserved), true];
    } forEach _units;
} forEach _syncedUnits;

deleteVehicle _logic;
