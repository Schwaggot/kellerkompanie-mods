#include "script_component.hpp"

params ["_player"];

switch (GVAR(classRestriction)) do {
    case 0: {true};
    case 1: {_player getVariable ["ACE_IsEngineer", 0] == 1};
    case 2: {_player getVariable ["ACE_IsEngineer", 0] == 2};
    case 3: {_player getVariable ["ACE_IsEngineer", 0] > 0};
    default {false};
};
