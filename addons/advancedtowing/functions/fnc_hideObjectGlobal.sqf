// original version by Duda https://github.com/sethduda/AdvancedTowing
#include "script_component.hpp"

params ["_obj"];

if( _obj isKindOf "Land_Can_V2_F" ) then {
  hideObjectGlobal _obj;
};
