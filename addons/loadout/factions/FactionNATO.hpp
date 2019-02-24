class FactionNato: FactionBase {

	name = "[Minimal] NATO - North Atlantic Treaty Organization";
	logisticsHelicopter = "B_Heli_Transport_03_F";

	// define all weapons and mags
	#include "WeaponsNATO.hpp"

	class Uniform: Uniform {
		Default[] = {
			U_B_CombatUniform_mcam,
			U_B_CombatUniform_mcam_tshirt,
			U_B_CombatUniform_mcam_vest,
			U_B_CombatUniform_mcam_worn
		};
		Lead[] = {
			U_B_CombatUniform_mcam
		};
		HeliPilot[] = {
			U_B_HeliPilotCoveralls
		};
		HeliCrew[] = {
			U_B_HeliPilotCoveralls
		};
		JetPilot[] = {
			U_B_PilotCoveralls
		};
		Sniper[] = {
			U_B_FullGhillie_sard
		};
		Spotter[] = {
			U_B_FullGhillie_sard
		};
	};

	class UniformInventory: UniformInventory {
		Sniper[] = {
			{1,"ACE_ATragMX"},
			{10,"ACE_quikclot"},
			{1,"ACE_Flashlight_MX991"},
			{1,"ACE_IR_Strobe_Item"},
			{1,"ACE_Kestrel4500"},
			{1,"ACE_MapTools"},
			{1,"ACE_microDAGR"},
			{2,"ACE_morphine"},
			{3,"ACE_tourniquet"},
			{1,"ACE_surgicalKit"},
			{1,"ACE_RangeCard"},
			{2,"ACE_epinephrine"},
			{1,"ACE_salineIV"},
			{8,"ACE_fieldDressing"}
		};
	};

	class Vest: Vest {
		Default[] = {
			V_PlateCarrier1_rgr,
			V_PlateCarrier2_rgr
		};
		Lead[] = {
			V_Chestrig_rgr
		};
		Doctor[] = {
			V_PlateCarrierSpec_rgr
		};
		Medic[] = {
			V_PlateCarrierSpec_rgr
		};
		Driver[] = {
			V_BandollierB_rgr
		};
		HeliPilot[] = {
			V_TacVest_blk
		};
		JetPilot[] = {
			V_TacVest_blk
		};
		Sniper[] = {
			V_PlateCarrier2_blk
		};
		Spotter[] = {
			V_PlateCarrier2_blk
		};
	};

	class VestInventory: VestInventory {
		Marksman[] = {
			{1, "ACE_RangeCard"}
		};
		Driver[] = {
			{1, "ACE_microDAGR"},
			{10, "ACE_quikclot"}
		};
		JTAC[] = {
			{4,"UGL_FlareGreen_F"},
			{4,"1Rnd_SmokeRed_Grenade_shell"},
			{4,"1Rnd_SmokeBlue_Grenade_shell"},
			{2,"SmokeShellBlue"},
			{2,"SmokeShellGreen"},
			{2,"SmokeShellOrange"},
			{2,"SmokeShellPurple"},
			{2,"SmokeShellYellow"}
		};
		UAVOperator[] = {
			{2,"ACE_UAVBattery"},
			{1,"ACE_HuntIR_monitor"},
			{8,"ACE_HuntIR_M203"}
		};
		HeliPilot[] = {
			{1, "ACE_microDAGR"},
			{10, "ACE_quikclot"}
		};
		Sniper[] = {
			{8,"ACE_7Rnd_408_305gr_Mag"}
		};
		Spotter[] = {
			{1,"SmokeShell"},
			{1,"SmokeShellGreen"},
			{2,"11Rnd_45ACP_Mag"},
			{10,"ACE_30Rnd_65x47_Scenar_mag"}
		};
	};

	class Backpack: Backpack {
		Default[] = { };
		Doctor[] = { B_Kitbag_mcamo	};
		Medic[] = { B_Kitbag_mcamo };
		LMG[] = { B_FieldPack_khk };
		LMGAsst[] = { B_FieldPack_khk };
		Lead[] = { TFAR_rt1523g_rhs };
		SQL[] = { TFAR_rt1523g_rhs };
		MMG[] = { B_FieldPack_khk };
		MMGAsst[] = { B_FieldPack_khk };
		ATSpecialist[] = { B_FieldPack_cbr };
		ATSpecialistAsst[] = { B_FieldPack_cbr };
		AASpecialist[] = { B_FieldPack_cbr };
		AASpecialistAsst[] = { B_FieldPack_cbr };
		EOD[] = { B_Carryall_cbr };
		Engineer[] = { B_Carryall_cbr };
		JTAC[] = { TFAR_rt1523g_rhs	};
		UAVOperator[] = { B_UAV_01_backpack_F };
	};

	class BackpackInventory: BackpackInventory {
		Lead[] = {
			{1, ACE_HuntIR_monitor},
			{4, ACE_HuntIR_M203}
		};
		SQL[] = {
			{1, ACE_HuntIR_monitor},
			{4, ACE_HuntIR_M203}
		};
		JTAC[] = {
			{4, Laserbatteries}
		};
	};

	class Helmet: Helmet {
		default[] = {
			H_HelmetSpecB_blk,
			H_HelmetSpecB_paint2,
			H_HelmetSpecB_paint1,
			H_HelmetSpecB_sand,
			H_HelmetSpecB_snakeskin,
			H_HelmetB,
			H_HelmetB_black,
			H_HelmetB_camo,
			H_HelmetB_desert,
			H_HelmetB_grass,
			H_HelmetB_sand,
			H_HelmetB_snakeskin
		};
		command[] = {
			H_Cap_tan_specops_US
		};
		lead[] = {
			H_MilCap_mcamo
		};
		Driver[] = {
			H_HelmetCrew_I
		};
		HeliPilot[] = {
			H_PilotHelmetHeli_B
		};
		HeliCrew[] = {
			H_CrewHelmetHeli_B
		};
		JetPilot[] = {
			H_PilotHelmetFighter_B
		};
		Sniper[] = {
			H_HelmetSpecB
		};
		Spotter[] = {
			H_HelmetSpecB
		};
	};

	class Primary: Primary {
		Default[] = {
			keko_W_A3_MX,
			keko_W_A3_MX_BLACK
		};
		Lead[] = {
			keko_W_A3_MX_GL_HUNTIR,
			keko_W_A3_MX_GL_BLACK_HUNTIR
		};
		SQL[] = {
			keko_W_A3_MX_GL_HUNTIR,
			keko_W_A3_MX_GL_BLACK_HUNTIR
		};
		FTL[] = {
			keko_W_A3_MX_GL,
			keko_W_A3_MX_GL_BLACK
		};
		Grenadier[] = {
			keko_W_A3_MX_GL,
			keko_W_A3_MX_GL_BLACK
		};
		LMG[] = {
			keko_W_A3_MX_SW,
			keko_W_A3_MX_SW_BLACK
		};
		MMG[] = {
			keko_W_A3_MMG,
			keko_W_A3_MMG_BLACK
		};
		Marksman[] = {
			keko_W_A3_MXM,
			keko_W_A3_MXM_BLACK
		};
		JTAC[] = {
			keko_W_A3_MX_GL_HUNTIR,
			keko_W_A3_MX_GL_BLACK_HUNTIR
		};
		UAVOperator[] = {
			keko_W_A3_MX_GL_HUNTIR,
			keko_W_A3_MX_GL_BLACK_HUNTIR
		};
		Sniper[] = {
			keko_W_A3_LRR,
			keko_W_A3_LRR_CAMO
		};
		Spotter[] = {
			keko_W_A3_MXM,
			keko_W_A3_MXM_BLACK
		};
	};

	class Secondary: Secondary {
		Default[] = { keko_W_TACTICAL };
		Sniper[] = { keko_W_TACTICAL_SPECOPS };
		Spotter[] = { keko_W_TACTICAL_SPECOPS };
	};

	class Launcher: Launcher {
		RiflemanAT[] = { keko_W_NLAW };
		ATSpecialist[] = { keko_W_TITAN_AT };
		AASpecialist[] = { keko_W_TITAN_AA };
	};
};
