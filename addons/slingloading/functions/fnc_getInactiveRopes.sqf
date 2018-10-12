#include "script_component.hpp"

/*
 Constructs an array of all inactive rope indexes and position labels (e.g. [[rope index,"Front"],[rope index,"Rear"]])
 for a specified vehicle
*/

params ["_vehicle"];

private ["_inactiveRopes","_existingRopes","_ropeLabelSets","_ropeIndex","_totalExistingRopes","_ropeLabels"];

_inactiveRopes = [];
_existingRopes = _vehicle getVariable [QGVAR(Ropes),[]];
_ropeLabelSets = [["Center"],["Front","Rear"],["Front","Center","Rear"]];
_ropeIndex = 0;
_totalExistingRopes = count _existingRopes;
{
	if(count _x == 0) then {
		_ropeLabels = _ropeLabelSets select (_totalExistingRopes - 1);
		_inactiveRopes pushBack [_ropeIndex,_ropeLabels select _ropeIndex];
	};
	_ropeIndex = _ropeIndex + 1;
} forEach _existingRopes;
_inactiveRopes;
