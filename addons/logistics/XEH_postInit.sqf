#include "script_component.hpp"

// Initialize crates
if (isNil QGVAR(crates)) then {
    GVAR(crates) = [];
} else {
    WARNING_1("%1 was already defined before executing XEH_postInit", QGVAR(crates));
};

if (hasInterface) then {
    call FUNC(addConfigCrates);

    // UAV and Helo actions are directly dependent on the crates being initialized
    if(GVAR(virtualHeliLogistics) > ACCESS_DISABLED) then {
        if (isNil QGVAR(heliEntryPoint)) then {
            systemChat "[KEKO] (Logistics) WARNING: Heli Logistics enabled but no entry point set! Falling back to [0, 0].";
        };
        if (isNil QGVAR(heliExitPoint)) then {
            systemChat "[KEKO] (Logistics) WARNING: Heli Logistics enabled but no exit point set! Falling back to [0, 0].";
        };

        private _isJTAC = player isKindOf QEGVAR(faction_generic,blufor_jtac) || player isKindOf QEGVAR(faction_generic,indfor_jtac) || player isKindOf QEGVAR(faction_generic,opfor_jtac);
        if ([player,GVAR(virtualHeliLogistics)] call FUNC(hasAccess) || _isJTAC) then {
            [{time > 0}, {
                player call FUNC(addVirtualHeliLogisticActions);
            }] call CBA_fnc_waitUntilAndExecute;
        };
    };

    if(GVAR(virtualUAVLogistics) > ACCESS_DISABLED) then {
        if (isNil QGVAR(uavSupplyBase)) then {
            systemChat "[KEKO] (Logistics) WARNING: Virtual UAV Logistics enabled but no supply base set! UAV supply not available.";
        } else {
            if ([player,GVAR(virtualUAVLogistics)] call FUNC(hasAccess)) then {
                [{time > 0}, {
                    player call FUNC(addVirtualUAVLogisticActions);
                }] call CBA_fnc_waitUntilAndExecute;
            };
        };
    };
}
