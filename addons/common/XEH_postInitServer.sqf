#include "script_component.hpp"

// according to BIKI this should set the maximum viewDistance at server
setViewDistance 10000;

//stops the blabbering of AI units and players
{_x setVariable ["BIS_noCoreConversations", true, true]} count allUnits;

//removes notification and bird of all curators:
{ _x setVariable ["birdType",""]; _x setVariable ["showNotification",false]; [_x, [-1, -2, 2]] call bis_fnc_setCuratorVisionModes; nil;} count allCurators;

//deletes empty groups via MissionEventHandler
GVAR(emptyGroupsDeleter) = addMissionEventHandler ["EntityKilled", {private _grp = group (_this select 0);if ( count (units _grp) == 0 ) then { deleteGroup _grp };}];

//for good measure add CBA per frame handler as well
[
    {
        {
            if ((units _x) isEqualTo []) then {[_x] call CBA_fnc_deleteEntity};
        } forEach allGroups;
    },
    1800
] call CBA_fnc_addPerFrameHandler;
