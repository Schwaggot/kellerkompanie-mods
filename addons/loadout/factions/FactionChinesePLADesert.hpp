class FactionChinesePLADesert: FactionBase {
	name = "[Main] Chinese PLA (Desert)";
	logisticsHelicopter = "VME_PLA_Mi17";

	#include "WeaponsChinesePLA.hpp"

	class uniform: uniform {
		Default[] = { "PLA_CombatUniform_HM_SB", "PLA_CombatUniform_HM_SBCB" };
		Lead[] = { "PLA_CombatUniform_HM_SW", "PLA_CombatUniform_HM_SWCB" };
		Sniper[] = { "U_B_FullGhillie_sard" };
	};

	class uniformInventory: uniformInventory {
		Sniper[] = {
				{ 1, "ACE_ATragMX" },
				{ 10, "ACE_quikclot" },
				{ 1, "ACE_Flashlight_MX991" },
				{ 1, "ACE_IR_Strobe_Item" },
				{ 1, "ACE_Kestrel4500" },
				{ 1, "ACE_MapTools" },
				{ 1, "ACE_microDAGR" },
				{ 2, "ACE_morphine" },
				{ 3, "ACE_tourniquet" },
				{ 1, "ACE_surgicalKit" },
				{ 1, "ACE_RangeCard" },
				{ 2, "ACE_epinephrine" },
				{ 1, "ACE_salineIV" },
				{ 8, "ACE_fieldDressing" }
			};
	};

	class vest: vest {
		Default[] = { "PLA_B04_RF_D", "PLA_T15Vest_RF_D" };
		Lead[] = { "PLA_T15Vest_RD_D" };
		SQL[] = { "PLA_T15Vest_RD_D" };
		LMG[] = { "PLA_B04_MG_D" };
		MMG[] = { "PLA_B04_MG_D" };
		Sniper[] = { "V_PlateCarrier2_blk" };
		Driver[] = { "V_BandollierB_rgr" };
		HeliPilot[] = { "V_TacVest_blk" };
		JetPilot[] = { "V_TacVest_blk" };
	};

	class backpack: backpack {
		Lead[] = { "TFAR_rt1523g_black" };
		SQL[] = { "TFAR_rt1523g_black" };
		Doctor[] = { "BWA3_Kitbag_Tropen_Medic" };
		Medic[] = { "BWA3_Kitbag_Tropen_Medic" };
		LMG[] = { "rhsusf_falconii_coy" };
		LMGAsst[] = { "rhsusf_falconii_coy" };
		MMG[] = { "rhsusf_falconii_coy" };
		MMGAsst[] = { "rhsusf_falconii_coy" };
		ATSpecialist[] = { "B_FieldPack_khk" };
		ATSpecialistAsst[] = { "B_FieldPack_khk" };
		AASpecialist[] = { "B_FieldPack_khk" };
		AASpecialistAsst[] = { "B_FieldPack_khk" };
		EOD[] = { "B_Carryall_khk" };
		Engineer[] = { "B_Carryall_khk" };
		JTAC[] = { "TFAR_rt1523g_black" };
		UAVOperator[] = { "B_UAV_01_backpack_F" };
	};

	class backpackInventory: backpackInventory {
		Lead[] = {  };
		SQL[] = {  };
		RiflemanAT[] = { { 1, RAT_MAG } };
		JTAC[] = { { 4, "Laserbatteries" } };
	};

	class helmet: helmet {
		Default[] = { "VME_PLA_Helmet_D", "VME_PLA_Helmet_D_G" };
		Lead[] = { "VME_PLA_Hat_D" };
		SQL[] = { "VME_PLA_Helmet_D_R_O", "VME_PLA_Helmet_D_R" };
		Sniper[] = { "H_HelmetSpecB" };
		Driver[] = { "H_HelmetCrew_I" };
		HeliPilot[] = { "H_PilotHelmetHeli_B" };
		HeliCrew[] = { "H_CrewHelmetHeli_B" };
		JetPilot[] = { "H_PilotHelmetFighter_B" };
	};

	class primary: primary {
		Default[] = { keko_W_QBZ95 };
		FTL[] = { keko_W_QBZ95_GL };
		Grenadier[] = { keko_W_QBZ95_GL };
		LMG[] = { keko_W_QJB95 };
		MMG[] = { keko_W_A3_MMG };
		Marksman[] = { keko_W_QBU88 };
		Sniper[] = { keko_W_A3_LRR, keko_W_A3_LRR_CAMO };
		Spotter[] = { keko_W_QBU88 };
		JTAC[] = { keko_W_QBZ95_GL };
	};

	class secondary: secondary {
		Default[] = { keko_W_Rook };
	};

	class launcher: launcher {
		RiflemanAT[] = { keko_W_PF89 };
		ATSpecialist[] = { keko_W_TITAN_AT };
		AASpecialist[] = { keko_W_TITAN_AA };
	};

};
