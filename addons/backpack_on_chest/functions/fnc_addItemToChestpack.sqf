#include "script_component.hpp"

/*
 * Author: DerZade
 * Creates a new item and stores it in the soldier's chestpack. The item can also be a weapon or a magazine.
 * The item(s) won't be added, if adding them would cause an overflow of the backpack.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Item/magazine/weapon classname <STRING>
 * 2: Amount <NUMBER> (optional | default: 1)
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player,"FirstAidKit"] call keko_backpack_on_chest_fnc_addItemToChestpack;
 *
 * Public: No
 */
params ["_unit","_item",["_amount",1]];

//exit if there is not enough space left
if !([_unit,_item,_amount] call FUNC(canAddItemToChestpack)) exitWith {};

//exit if is magazine
if (isClass (configFile >> "CfgMagazines" >> _item)) exitWith {
     for "_i" from 1 to _amount do {
          [_unit,_item,(getNumber (configFile >> "CfgMagazines" >> _item >> "count"))] call FUNC(addMagToChestpack);
     };
};

private _var = _unit getVariable [QGVAR(chestpack), nil];

for "_i" from 1 to _amount do {
     (_var select 2) pushBack _item;
};

//update variable
_unit setVariable [QGVAR(chestpack), _var, true];