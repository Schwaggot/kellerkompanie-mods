// original version by Duda https://github.com/sethduda/AdvancedTowing

params ["_vehicle"];

private ["_cornerPoints","_rearCorner","_rearCorner2","_frontCorner","_frontCorner2","_rearHitchPoint"];
private ["_frontHitchPoint","_sideLeftPoint","_sideRightPoint"];

_cornerPoints = [_vehicle] call keko_advancedtowing_fnc_getCornerPoints;
_rearCorner = _cornerPoints select 0;
_rearCorner2 = _cornerPoints select 1;
_frontCorner = _cornerPoints select 2;
_frontCorner2 = _cornerPoints select 3;
_rearHitchPoint = ((_rearCorner vectorDiff _rearCorner2) vectorMultiply 0.5) vectorAdd  _rearCorner2;
_frontHitchPoint = ((_frontCorner vectorDiff _frontCorner2) vectorMultiply 0.5) vectorAdd  _frontCorner2;
[_frontHitchPoint,_rearHitchPoint];
