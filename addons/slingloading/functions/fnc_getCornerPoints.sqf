#include "script_component.hpp"

params ["_vehicle"];

// Correct width and length factor for air
private _widthFactor = 0.5;
private _lengthFactor = 0.5;
if(_vehicle isKindOf "Air") then {
	_widthFactor = 0.3;
};
if(_vehicle isKindOf "Helicopter") then {
	_widthFactor = 0.2;
	_lengthFactor = 0.45;
};

private _centerOfMass = getCenterOfMass _vehicle;
private _bbr = boundingBoxReal _vehicle;
private _p1 = _bbr select 0;
private _p2 = _bbr select 1;
private _maxWidth = abs ((_p2 select 0) - (_p1 select 0));
private _widthOffset = ((_maxWidth / 2) - abs ( _centerOfMass select 0 )) * _widthFactor;
private _maxLength = abs ((_p2 select 1) - (_p1 select 1));
private _lengthOffset = ((_maxLength / 2) - abs (_centerOfMass select 1 )) * _lengthFactor;
private _maxHeight = abs ((_p2 select 2) - (_p1 select 2));
private _heightOffset = _maxHeight/6;

private _rearCorner = [(_centerOfMass select 0) + _widthOffset, (_centerOfMass select 1) - _lengthOffset, (_centerOfMass select 2)+_heightOffset];
private _rearCorner2 = [(_centerOfMass select 0) - _widthOffset, (_centerOfMass select 1) - _lengthOffset, (_centerOfMass select 2)+_heightOffset];
private _frontCorner = [(_centerOfMass select 0) + _widthOffset, (_centerOfMass select 1) + _lengthOffset, (_centerOfMass select 2)+_heightOffset];
private _frontCorner2 = [(_centerOfMass select 0) - _widthOffset, (_centerOfMass select 1) + _lengthOffset, (_centerOfMass select 2)+_heightOffset];

[_rearCorner,_rearCorner2,_frontCorner,_frontCorner2];
