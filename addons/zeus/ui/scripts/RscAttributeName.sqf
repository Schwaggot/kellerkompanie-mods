#include "script_component.hpp"

#define IDC_RSCATTRIBUTENAME_VALUE    118379

params["_mode", "_params", "_entity"];

switch _mode do
{
    case "onLoad":
    {
        private _display = _params select 0;
        private _ctrlValue = _display displayctrl IDC_RSCATTRIBUTENAME_VALUE;
        _ctrlValue ctrlsettext name _entity;
    };
    case "confirmed":
    {
        private _display = _params select 0;
        private _ctrlValue = _display displayctrl IDC_RSCATTRIBUTENAME_VALUE;
        private _text = ctrltext _ctrlValue;
        if (_text != name _entity) then
        {
            private _curatorSelected = ["man"] call FUNC(getCuratorSelected);
            {
                [_x, _text] remoteExecCall ["setName", 0, _x];
                if (["common"] call FUNC(isACELoaded)) then { [_x] call ace_common_fnc_setName; };
            } forEach (_curatorSelected select {alive _x});
        };
    };
    case "onUnload": {};
};
