#include "script_component.hpp"
// Original by ALIAS http://www.armaholic.com/page.php?id=34293

if (!isServer) exitWith {};

params ["_empSourceObject", "_empRange", "_hasVisualEffect", "_hasVisualEffectOnPlayer"];

if (_hasVisualEffect or _hasVisualEffectOnPlayer) then {
    [_empSourceObject, _hasVisualEffect, _hasVisualEffectOnPlayer] remoteExec [QFUNC(vizEffEMP), [0,-2] select isDedicated];
};

[_empSourceObject, _empRange] call FUNC(configObj);

if (GVAR(affectRadio)) then {
    [_empSourceObject, _empRange] call FUNC(affectRadios);
};

[] spawn {
    waitUntil {sleep 0.1; !isNil "special_launchers_emp"};
    [] call FUNC(empEffect);
};
