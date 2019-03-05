#include "script_component.hpp"

class CfgPatches {
    class ADDON    {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(modulePersistencyBlacklist3den),
            QGVAR(moduleSelectivePersistency3den),
            QGVAR(moduleManualLoad),
            QGVAR(moduleManualSave),
            QGVAR(moduleEnablePersistency)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "cba_main",
            "3den",
            "A3_Modules_F",
            "A3_Modules_F_Curator"};
        author = ECSTRING(common,Schwaggot);
        authors[] = {"Schwaggot"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
