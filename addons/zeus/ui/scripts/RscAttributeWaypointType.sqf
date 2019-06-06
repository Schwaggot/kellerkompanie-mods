#include "script_component.hpp"

#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"

params["_mode", "_params", "_entity"];

switch _mode do {
    case "onLoad": {
        private _display = _params select 0;
        private _ctrlValue = _display displayctrl IDC_RSCATTRIBUTEWAYPOINTTYPE_VALUE;

        if (isnull waypointattachedvehicle _entity) then {
            _ctrlValue ctrladdeventhandler ["toolboxSelChanged",{with uinamespace do {RscAttributeWaypointType_value = _this select 1}}];
            private _names = getarray (configfile >> "RscAttributeWaypointType" >> "controls" >> "Value" >> "names");

            //--- Select current waypoint type
            private _type = _entity call bis_fnc_scriptedWaypointType;
            if (_type == "") then {_type = waypointtype _entity;};
            {
                if (_type == _x) exitwith {_ctrlValue lbsetcursel _foreachindex;};
            } foreach _names;
        } else {
            _ctrlValue ctrlshow false;
            _ctrlValue ctrlenable false;
            private _ctrlBackground = _display displayctrl IDC_RSCATTRIBUTEWAYPOINTTYPE_BACKGROUND;
            _ctrlBackground ctrlsettext "Cannot set type of an attached waypoint";
        };
    };
    case "lbSelChanged": {
        private _display = _params select 0;
        private _ctrlValue = _display displayctrl IDC_RSCATTRIBUTEWAYPOINTTYPE_VALUE;
    };
    case "confirmed": {
        private _display = _params select 0;
        private _ctrlValue = _display displayctrl IDC_RSCATTRIBUTEWAYPOINTTYPE_VALUE;
        private _valueID = uinamespace getvariable ["RscAttributeWaypointType_value",0];
        private _values = getarray (configfile >> "RscAttributeWaypointType" >> "controls" >> "Value" >> "names");
        if (_valueID < count _values) then {
            private _value = _values select _valueID;
            private _valueConfig = [_value,configfile] call bis_fnc_configpath;
            if (isclass _valueConfig) then {
                private _curatorSelectedWPs = ["wp"] call FUNC(getCuratorSelected);
                {
                    _x setwaypointtype "SCRIPTED";
                    _x setwaypointscript gettext (_valueConfig >> "file");
                } forEach _curatorSelectedWPs;
            } else {
                if (_value == waypointtype _entity) exitWith {};
                private _curatorSelectedWPs = ["wp"] call FUNC(getCuratorSelected);
                {
                    _x setwaypointtype _value;
                } forEach _curatorSelectedWPs;
            };
        };
    };
    case "onUnload": {
        RscAttributeWaypointType_value = nil;
    };
};
