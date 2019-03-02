class FactionFIA: FactionBase {
	name = "[Minimal] FIA - Freedom and Independence Alliance";
	logisticsHelicopter = "I_Heli_light_03_unarmed_F";

	#include "WeaponsFIA.hpp"

	class role: role {
		Lead = "Lead";
		Command = "Command";
		SQL = "Squad Leader";
		Sergeant = "Sergeant";
		FTL = "Fire Team Leader";
		Doctor = "Doctor";
		Medic = "Medic";
		Rifleman = "Rifleman";
		RiflemanAT = "Rifleman Anti-Tank";
		Grenadier = "Grenadier";
		LMG = "Light Machine Gunner";
		LMGAsst = "Light Machine Gunner Asst.";
		MMG = "Medium Machine Gunner";
		MMGAsst = "Medium Machine Gunner Asst.";
		Marksman = "Marksman";
		EOD = "Explosive Specialist";
		Engineer = "Engineer";
		Driver = "Driver/Crewman";
		HeliPilot = "Helicopter Pilot";
		Sniper = "Sniper";
		Spotter = "Spotter";
	};

	class uniform: uniform {
		Default[] = {
				"U_IG_Guerilla1_1",
				"U_IG_Guerilla2_1",
				"U_IG_Guerilla2_3",
				"U_IG_Guerilla2_2",
				"U_IG_Guerilla3_1",
				"U_IG_Guerrilla_6_1"
			};
		Lead[] = { "U_IG_leader" };
		Sniper[] = { "U_B_FullGhillie_sard" };
		Spotter[] = { "U_I_FullGhillie_ard" };
	};

	class uniformInventory: uniformInventory {
		Default[] = {
				{ 15, "ACE_fieldDressing" },
				{ 1, "ACE_morphine" },
				{ 2, "ACE_tourniquet" },
				{ 1, "ACE_Flashlight_XL50" }
			};
	};

	class vest: vest {
		Default[] = {
				"V_Chestrig_oli",
				"V_BandollierB_oli",
				"V_Chestrig_blk",
				"V_TacVest_blk",
				"V_BandollierB_blk",
				"V_BandollierB_khk"
			};
		HeliPilot[] = { "V_TacVest_blk" };
		Sniper[] = { "V_Chestrig_khk" };
		Spotter[] = { "V_Chestrig_rgr" };
	};

	class backpack: backpack {
		Lead[] = { "TFAR_rt1523g" };
		SQL[] = { "TFAR_rt1523g" };
		Doctor[] = { "B_Kitbag_rgr" };
		Medic[] = { "B_Kitbag_rgr" };
		RiflemanAT[] = { "B_TacticalPack_blk" };
		LMG[] = { "B_TacticalPack_blk" };
		LMGAsst[] = { "B_TacticalPack_blk" };
		MMG[] = { "B_TacticalPack_blk" };
		MMGAsst[] = { "B_TacticalPack_blk" };
		EOD[] = { "B_Carryall_oli" };
		Engineer[] = { "B_Carryall_oli" };
		Sniper[] = { "B_AssaultPack_cbr" };
		Spotter[] = { "B_AssaultPack_cbr" };
	};

	class backpackInventory: backpackInventory {
		Lead[] = {
				{ 6, "UGL_FlareWhite_F" },
				{ 3, "UGL_FlareGreen_F" },
				{ 3, "UGL_FlareRed_F" }
			};
		SQL[] = {
				{ 6, "UGL_FlareWhite_F" },
				{ 3, "UGL_FlareGreen_F" },
				{ 3, "UGL_FlareRed_F" }
			};
		Doctor = KEKO_LOADOUT_DOCTOR_DEFAULT_BACKPACK_INVENTORY;
		Medic = KEKO_LOADOUT_MEDIC_DEFAULT_BACKPACK_INVENTORY;
		RiflemanAT[] = { { 2, RAT_MAG } };
		EOD = KEKO_LOADOUT_EOD_DEFAULT_BACKPACK_INVENTORY;
		Engineer = KEKO_LOADOUT_ENGINEER_DEFAULT_BACKPACK_INVENTORY;
		Sniper[] = { { 2, "ACE_salineIV_500" }, { 6, "adv_aceSplint_splint" } };
		Spotter[] = {
				{ 1, "ACE_surgicalKit" },
				{ 1, "ACE_EntrenchingTool" },
				{ 2, "ACE_salineIV" },
				{ 20, "ACE_quikclot" },
				{ 1, "ACE_ATragMX" },
				{ 1, "ACE_Kestrel4500" },
				{ 1, "ACE_Tripod" },
				{ 1, "ACE_SpottingScope" },
				{ 14, "ACE_fieldDressing" }
			};
	};

	class helmet: helmet {
		Default[] = {
				"H_Shemag_olive",
				"H_Booniehat_khk",
				"H_Bandanna_khk",
				"H_Cap_oli",
				"H_Watchcap_camo",
				"H_Watchcap_blk"
			};
		HeliPilot[] = { "H_Cap_marshal" };
		Sniper[] = { "H_HelmetSpecB" };
		Spotter[] = { "H_HelmetSpecB" };
	};

	class primary: primary {
		Default[] = { keko_W_A3_Mk20C };
		Lead[] = { keko_W_A3_Mk20_GL, keko_W_A3_TRG21_GL };
		SQL[] = { keko_W_A3_Mk20_GL, keko_W_A3_TRG21_GL };
		FTL[] = { keko_W_A3_Mk20_GL, keko_W_A3_TRG21_GL };
		Grenadier[] = { keko_W_A3_Mk20_GL, keko_W_A3_TRG21_GL };
		LMG[] = { keko_W_A3_Mk200 };
		MMG[] = { keko_W_A3_MMG };
		Marksman[] = { keko_W_A3_DMR };
		Sniper[] = { keko_W_A3_GM6_CSAT };
		Spotter[] = { keko_W_A3_DMR_SILENCED };
	};

	class secondary: secondary {
		Default[] = { keko_W_M1911 };
		Sniper[] = { keko_W_M1911 };
		Spotter[] = { keko_W_M1911 };
	};

	class launcher: launcher {
		RiflemanAT[] = { keko_W_RPG32 };
	};

};
