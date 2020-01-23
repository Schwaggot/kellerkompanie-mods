#include "script_component.hpp"

/*
 * Author: DerZade
 * Adds a chestpack to a unit. If a unit already has one, the old chestpack will be ignored and will be deleted completely.
 *
 * Arguments:
 * 0: Unit  <OBJECT>
 * 1: Backpack Classnam <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player,"B_Kitbag_rgr"] call keko_backpack_on_chest_fnc_addChestpack;
 *
 * Public: No
 */
params ["_unit","_chestpackClass"];

//add HandleDisconnect-EH on server if not done yet
if !(missionNamespace getVariable [QGVAR(HDCEHadded),false]) then {
     [[[],{addMissionEventHandler ["HandleDisconnect",FUNC(EHHandleDisconnect)];}],"BIS_fnc_call",false] call BIS_fnc_MP;
     GVAR(HDCEHadded) = true;
     publicVariable QGVAR(HDCEHadded);
};

//delete existing chestpack, if there is one
if ([_unit] call FUNC(chestpack) != "") then {
     [_unit] call FUNC(removeChestpack);
};

//add EHs
private _getInID = _unit addEventHandler ["GetInMan", FUNC(EHGetIn)];
private _getOutID = _unit addEventHandler ["GetOutMan", FUNC(EHGetOut)];
private _animID = _unit addEventHandler ["AnimDone", FUNC(EHAnimDone)];
private _killedID = _unit addEventHandler ["Killed", FUNC(EHKilled)];

//create chestpack itself
private _chestpack = createSimpleObject [_chestpackClass, getPos _unit];

[_unit, "forceWalk", "BackpackOnChest", true] call ace_common_fnc_statusEffect_set;

//set variable
_unit setVariable [QGVAR(chestpack), [[_chestpackClass,_chestpack],[_getInID,_getOutID,_animID,_killedID],[],[]],true];

//execute vehicle shit
if !(vehicle _unit isEqualTo _unit) then {
    [_unit, "", vehicle _unit] call FUNC(EHGetIn);
} else {
    [_unit, "", objNull] call FUNC(EHGetOut);
};
