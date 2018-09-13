class CfgPatches
{
    class keko_persistency
    {
        units[] = {};
        requiredVersion = 1.80;
        requiredAddons[] = {
            "cba_main",
            "cba_settings",
            "cba_xeh",
            "extDB3",
            "keko_persistency_settings"};
        author = "Schwaggot";
        authorUrl = "http://kellerkompanie.com";
		    version = 1.0;
    };
};

class CfgFunctions
{
    class keko_persistency
    {
        tag = "keko_persistency";
        class persistency
        {
            file = "keko_persistency\functions";
            class savePlayerLoadout{};
            class loadPlayerLoadout{};
            class saveCrate{};
            class loadCrate{};
            class getContainerContent{};
            class setContainerContent{};
            class saveAllCrates {};
            class loadAllCrates {};

            class saveVehicle{};
            class loadVehicle{};
            class saveAllVehicles {};
            class loadAllVehicles {};

            class saveAllPlayers {};
            class loadAllPlayers {};
        };
    };
};

class Extended_PreInit_EventHandlers {
    class keko_persistency_xeh {
        init = "call compile preprocessFileLineNumbers '\keko_persistency\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers {
    class keko_persistency_xeh {
        init = "call compile preprocessFileLineNumbers '\keko_persistency\XEH_postInit.sqf'";
    };
};

class Extended_PreStart_EventHandlers {
    class keko_persistency_xeh {
        init = "call compile preprocessFileLineNumbers '\keko_persistency\XEH_preStart.sqf'";
    };
};