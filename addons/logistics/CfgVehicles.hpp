class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class EventHandlers;
        class ModuleDescription;

        class AttributesBase
        {
            class Default;
            class Edit;
            class Combo;
            class Checkbox;
            class CheckboxNumber;
            class ModuleDescription;
            class Units;

            expression = "_this setVariable ['%s',_value];";
        };
    };
    class GVAR(moduleBase): Module_F {
        category = "KEKO";
        scope              = 1;
        scopeCurator       = 2;
        functionPriority   = 1;
        isGlobal           = 1;
        isTriggerActivated = 0;
        function = QEFUNC(common,dummy);
    };
    class GVAR(moduleBase3den): Module_F {
        category = "KEKO";
        scope              = 2;
        scopeCurator       = 1;
        functionPriority   = 1;
        isGlobal           = 1;
        isTriggerActivated = 0;
        function = QEFUNC(common,dummy);
    };

    class GVAR(moduleAddLogisticsMenu): GVAR(moduleBase) {
        displayName        = "Add Logistics Menu";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleAddLogisticsMenu);
        icon               = QPATHTOF(ui\icon_logistics.paa);
        curatorCanAttach   = 1;
    };
    class GVAR(moduleAddLogisticsMenu3den): GVAR(moduleBase3den) {
        displayName        = "Add Logistics Menu";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleAddLogisticsMenu3den);
        icon               = QPATHTOF(ui\icon_logistics.paa);
    };
    class keko_ModuleAddLogisticsMenu3den: GVAR(moduleAddLogisticsMenu3den) {
        displayName        = "(DEPRECATED - DO NOT USE) Add Logistics Menu";
        category           = QEGVAR(common,Deprecated);
        scope = 1;
        scopeCurator = 0;
    };
    class GVAR(moduleSpawnCrate): GVAR(moduleBase) {
        displayName        = "Spawn Crate";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleSpawnCrate);
        icon               = QPATHTOF(ui\icon_crate.paa);
    };
    class GVAR(moduleSupplyDrop): GVAR(moduleBase) {
        displayName        = "Supply Drop";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleSupplyDrop);
        icon               = QPATHTOF(ui\icon_paradrop.paa);
    };
    class GVAR(moduleHeliDrop): GVAR(moduleBase) {
        displayName        = "Heli Drop";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleHeliDrop);
        icon               = QPATHTOF(ui\icon_paradrop.paa);
    };
    class GVAR(moduleCustomLogistics3den): GVAR(moduleBase3den) {
        displayName        = "Custom Crates";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleCustomLogistics3den);
        icon                = QPATHTOF(ui\icon_crate.paa);
    };
    class GVAR(moduleUAVBase3den): GVAR(moduleBase3den) {
        displayName        = "UAV Supply Base";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleUAVBase3den);
        icon                = QPATHTOF(ui\icon_uav.paa);
    };
    class GVAR(moduleHeliEntry3den): GVAR(moduleBase3den) {
        displayName        = "Heli Entry";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleHeliEntry3den);
    };
    class GVAR(moduleHeliExit3den): GVAR(moduleBase3den) {
        displayName        = "Heli Exit";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleHeliExit3den);
    };
    class keko_ModuleCustomLogistics3den: GVAR(moduleCustomLogistics3den) {
        displayName        = "(DEPRECATED - DO NOT USE) Custom Crates";
        category           = QEGVAR(common,Deprecated);
        scope = 1;
        scopeCurator = 0;
    };
    class GVAR(moduleAddCrate): GVAR(moduleBase) {
        displayName        = "Add Crate";
        category           = QGVAR(Logistics);
        function           = QFUNC(moduleAddCrate);
        icon               = QPATHTOF(ui\icon_crate.paa);
        curatorCanAttach   = 1;
    };

    class Items_base_F;
    class Land_CanisterFuel_F: Items_base_F {
        ace_dragging_canDrag = 1;
        ace_dragging_dragPosition[] = {0, 0.5, 0};
        ace_dragging_dragDirection = 0;

        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = {0, 0.5, 1};
        ace_dragging_carryDirection = 0;

        ace_cargo_size = 1;
        ace_cargo_canLoad = 1;
    };
};
