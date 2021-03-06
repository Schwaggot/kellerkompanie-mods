#include "script_component.hpp"

params ["_vehicle"];

private _slingLoadPointsArray = [];
private _cornerPoints = [_vehicle] call FUNC(getCornerPoints);
private _frontCenterPoint = (((_cornerPoints select 2) vectorDiff (_cornerPoints select 3)) vectorMultiply 0.5) vectorAdd (_cornerPoints select 3);
private _rearCenterPoint = (((_cornerPoints select 0) vectorDiff (_cornerPoints select 1)) vectorMultiply 0.5) vectorAdd (_cornerPoints select 1);
private _rearCenterPoint = ((_frontCenterPoint vectorDiff _rearCenterPoint) vectorMultiply 0.2) vectorAdd _rearCenterPoint;
private _frontCenterPoint = ((_rearCenterPoint vectorDiff _frontCenterPoint) vectorMultiply 0.2) vectorAdd _frontCenterPoint;
private _middleCenterPoint = ((_frontCenterPoint vectorDiff _rearCenterPoint) vectorMultiply 0.5) vectorAdd _rearCenterPoint;
private _vehicleUnitVectorUp = vectorNormalized (vectorUp _vehicle);

private _slingLoadPointHeightOffset = 0;
{
    if(_vehicle isKindOf (_x select 0)) then {
        _slingLoadPointHeightOffset = (_x select 1);
    };
} forEach GVAR(SlingLoadPointClassHeightOffset);

private _slingLoadPoints = [];
{
    private _modelPoint = _x;
    private _modelPointASL = AGLToASL (_vehicle modelToWorldVisual _modelPoint);
    private _surfaceIntersectStartASL = _modelPointASL vectorAdd ( _vehicleUnitVectorUp vectorMultiply -5 );
    private _surfaceIntersectEndASL = _modelPointASL vectorAdd ( _vehicleUnitVectorUp vectorMultiply 5 );

    // Determine if the surface intersection line crosses below ground level
    // If if does, move surfaceIntersectStartASL above ground level (lineIntersectsSurfaces
    // doesn't work if starting below ground level for some reason
    // See: https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection

    private _la = ASLToAGL _surfaceIntersectStartASL;
    private _lb = ASLToAGL _surfaceIntersectEndASL;

    if(_la select 2 < 0 && _lb select 2 > 0) then {
        private _n = [0,0,1];
        private _p0 = [0,0,0.1];
        private _l = (_la vectorFromTo _lb);
        if((_l vectorDotProduct _n) != 0) then {
            private _d = ( ( _p0 vectorAdd ( _la vectorMultiply -1 ) ) vectorDotProduct _n ) / (_l vectorDotProduct _n);
            _surfaceIntersectStartASL = AGLToASL ((_l vectorMultiply _d) vectorAdd _la);
        };
    };

    private _surfaces = lineIntersectsSurfaces [_surfaceIntersectStartASL, _surfaceIntersectEndASL, objNull, objNull, true, 100];
    private _intersectionASL = [];
    {
        private _intersectionObject = _x select 2;
        if(_intersectionObject == _vehicle) exitWith {
            _intersectionASL = _x select 0;
        };
    } forEach _surfaces;
    if(count _intersectionASL > 0) then {
        _intersectionASL = _intersectionASL vectorAdd (( _surfaceIntersectStartASL vectorFromTo _surfaceIntersectEndASL ) vectorMultiply (_slingLoadPointHeightOffset select (count _slingLoadPoints)));
        _slingLoadPoints pushBack (_vehicle worldToModelVisual (ASLToAGL _intersectionASL));
    } else {
        _slingLoadPoints pushBack [];
    };
} forEach [_frontCenterPoint, _middleCenterPoint, _rearCenterPoint];

if(count (_slingLoadPoints select 1) > 0) then {
    _slingLoadPointsArray pushBack [_slingLoadPoints select 1];
    if(count (_slingLoadPoints select 0) > 0 && count (_slingLoadPoints select 2) > 0 ) then {
        if( ((_slingLoadPoints select 0) distance (_slingLoadPoints select 2)) > 3 ) then {
            _slingLoadPointsArray pushBack [_slingLoadPoints select 0,_slingLoadPoints select 2];
            if( ((_slingLoadPoints select 0) distance (_slingLoadPoints select 1)) > 3 ) then {
                _slingLoadPointsArray pushBack [_slingLoadPoints select 0,_slingLoadPoints select 1,_slingLoadPoints select 2];
            };
        };
    };
};
_slingLoadPointsArray;
