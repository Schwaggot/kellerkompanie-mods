#include "script_component.hpp"

params ["_logic"];

if(isServer) then {
    private _action = _logic getVariable ["Action",""];
    private _title = _logic getVariable ["Title",""];
    private _content = _logic getVariable ["Content",""];
    private _remove = _logic getVariable ["Remove",false];

    private _objects = synchronizedObjects _logic;
    {
        [_x, _action, _title, _content, _remove] call FUNC(addIntel);
    } forEach _objects;
};
