#include "script_component.hpp"

params ["_player"];

private _crates = [];
if(GVAR(customLogistics) == 2) then {
	_crates = [["Kisten", GVAR(customCrates)]];
}
else {
	_crates = getArray (configFile >> "kekoFaction" >> EGVAR(loadout,loadoutFaction) >> "crates");
};

private _action = [QGVAR(supplyDrop), "Call Supply Drop", QPATHTOF(ui\icon_paradrop), {}, {true}] call ace_interact_menu_fnc_createAction;;
[_player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;

private _i = 0;
{
	private _section_crates = _x select 1;
	{
		private _crateName = "";
		private _action = [];
		if(GVAR(customLogistics) == 2) then {
			_crateName = _x select 0;

			private _actionName = format ["keko_logistics_supplyDrop_%1", _i];
			private _actionTitle = format ["%1", _crateName];
			private _actionStatement = compile (format ["[getPos _player, '%1'] call keko_logistics_fnc_heliDrop;", _crateName]);
			_action = [_actionName, _actionTitle, QPATHTOF(ui\icon_paradrop), _actionStatement, {true}] call ace_interact_menu_fnc_createAction;
		}
		else {
			_crateName = getText (configFile >> "kekoFaction" >> EGVAR(loadout,loadoutFaction) >> _x >> "name");
			private _crateCfg = EGVAR(loadout,loadoutFaction);

			private _actionName = format ["keko_logistics_supplyDrop_%1", _i];
			private _actionTitle = format ["%1", _crateName];
			private _actionStatement = compile (format ["[getPos _player, '%1', '%2'] call keko_logistics_fnc_heliDrop;", _crateCfg, _x]);
			_action = [_actionName, _actionTitle, QPATHTOF(ui\icon_paradrop), _actionStatement, {true}] call ace_interact_menu_fnc_createAction;
		};

		[_player, 1, ["ACE_SelfActions", QGVAR(supplyDrop)], _action] call ace_interact_menu_fnc_addActionToObject;
		
		_i = _i + 1;
	} forEach _section_crates;
} forEach _crates;
