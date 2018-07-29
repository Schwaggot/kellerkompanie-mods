class CfgPatches
{
    class keko_faction_redneck
    {
        units[] = {
        	/* BLUFOR units */
    			"keko_redneck_indfor_soldier1",
          "keko_redneck_indfor_soldier2",
          "keko_redneck_indfor_soldier3",
          "keko_redneck_indfor_soldier4",
          "keko_redneck_indfor_soldier5",
          "keko_redneck_indfor_soldier6",
          "keko_redneck_indfor_soldier7",
          "keko_redneck_indfor_grenadier1",
          "keko_redneck_indfor_grenadier2",
          "keko_redneck_indfor_rifleman_at",
          "keko_redneck_indfor_minimi",
          "keko_redneck_indfor_m60",
          "keko_redneck_indfor_medic",
          "keko_redneck_indfor_sniper",
          "keko_redneck_indfor_sniper_sws",
          "keko_redneck_indfor_marksman",
          "keko_redneck_indfor_ftl",

          "keko_redneck_indfor_offroad",
          "keko_redneck_indfor_offroad_mg",
          "keko_redneck_indfor_jeep",
          "keko_redneck_indfor_jeep_mg",
          "keko_redneck_indfor_truck_cargo",
          "keko_redneck_indfor_quadbike",
          "keko_redneck_indfor_van_cargo",
          "keko_redneck_indfor_van_transport",
          "keko_redneck_indfor_humvee",
          "keko_redneck_indfor_suv",
          "keko_redneck_indfor_kamaz",
          "keko_redneck_indfor_yamaha",

          "keko_redneck_indfor_md500",
          "keko_redneck_indfor_orca",

          "keko_redneck_indfor_cessna",
          "keko_redneck_indfor_doppeldecker",

          "keko_redneck_indfor_mg_high",
          "keko_redneck_indfor_mg_low",
          "keko_redneck_indfor_mortar",
          "keko_redneck_indfor_antiair",

    			"keko_redneck_opfor_soldier1"
		    };
        weapons[] = {};
        requiredVersion = 1.80;
        requiredAddons[] = {
        	"A3_Characters_F_BLUFOR",
        	"A3_Characters_F_INDEP",
    			"A3_Characters_F_OPFOR",
    			"A3_Characters_F",
          "MU_core",
          "A3_Weapons_F",
          "A3_Air_F",
          "A3_Air_F_beta",
          "A3_Soft_F",
          "A3_Soft_F_Offroad_01",
          "A3_Static_F",
          "A3_boat_F"
        };
    		version = "1.0";
    		versionStr = "1.0";
    		author = "Schwaggot";
    		authorUrl = "http://kellerkompanie.com/";
    };
};

class cfgFactionClasses {
	class keko_faction_redneck_indfor {
		displayName = "Kellerkompanie Redneck";
		priority = 1;
		side = 2;
		icon = "\A3\data_f\cfgfactionclasses_ind_ca.paa";
		scopeCurator = 1;
	};
	class keko_faction_redneck_opfor {
		displayName = "Kellerkompanie Redneck";
		priority = 1;
		side = 0;
		icon = "\A3\data_f\cfgfactionclasses_opf_ca.paa";
		scopeCurator = 1;
	};
};

class CfgVehicleClasses {
	class keko_vehicleclass_redneck_indfor {
		displayName = "Men";
		priority = 2;
		scopeCurator = 1;
	};
	class keko_vehicleclass_redneck_opfor {
		displayName = "Men";
		priority = 2;
		scopeCurator = 1;
	};
};

#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"

class CfgFunctions {
	class keko_faction_redneck {
		tag = "keko_faction_redneck";
		class functions {
			file = "keko_faction_redneck\functions";
			class addRoleDescription;
		};
	};

};
