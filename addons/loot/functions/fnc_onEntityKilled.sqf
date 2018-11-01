#include "script_component.hpp"

params ["_unit"];

if !(local _unit) exitWith { _this remoteExecCall [QFUNC(onEntityKilled), _unit]; };

removeAllWeapons _unit;
removeAllAssignedItems _unit;
removeAllItems _unit;
clearMagazineCargo _unit;

private _uniform = uniformContainer _unit;
private _vest = vestContainer _unit;
private _backpack = backpackContainer _unit;

private _possiblecontainers = [_uniform, _vest, _backpack];

for "_i" from 0 to (floor random [0, 3, 6]) step 1 do {
	private _medicalItem = selectRandom ["ACE_fieldDressing","keko_medical_painkillers","ACE_tourniquet","ACE_quikclot","adv_aceSplint_splint","ACE_elasticBandage","ACE_packingBandage"];

	{
		private _itemAdded = false;
	    if ( !(isNull _x) ) then {
	        if ( _x canAdd [_medicalItem, 1] ) exitWith {
	            _x addItemCargoGlobal [_medicalItem, 1];
				_itemAdded = true;
	        };
	    };

		if(_itemAdded) exitWith {};
	} foreach _possiblecontainers;
};
