class CfgFunctions {
    class ADDON {
        tag = "ace_medical";
        class ace_medical {
            class actionRemoveTourniquet {
                file = QPATHTOF(functions\fnc_actionRemoveTourniquet.sqf);
            };
            class itemCheck {
                file = QPATHTOF(functions\fnc_itemCheck.sqf);
            };
            class useItem {
                file = QPATHTOF(functions\fnc_useItem.sqf);
            };
        };
    };
};
