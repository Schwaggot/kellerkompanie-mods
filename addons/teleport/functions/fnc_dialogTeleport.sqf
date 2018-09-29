#include "script_component.hpp"

params ["_teleporterName"];

TRACE_1("teleporting to marker", _teleporterName);

private _markerName = "keko_teleport_" + _teleporterName;
private _pos = getMarkerPos _markerName;

player allowDamage false;
titleText ["", "BLACK OUT", 2];
sleep 2;
titleText [format ["Du wirst nach %1 verlegt.", _teleporterName], "BLACK FADED"];
sleep 1;
player setPos _pos;
sleep 1;
titleFadeOut 2;
player allowDamage true;
