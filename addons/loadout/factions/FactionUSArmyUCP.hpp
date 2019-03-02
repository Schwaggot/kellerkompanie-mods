class FactionUSArmyUCP: FactionBase {
	name = "[Main] U.S. Army (UCP)";
	logisticsHelicopter = "RHS_UH60M";

	#include "WeaponsUSArmy.hpp"

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
		ATSpecialist = "Anti-Tank Specialist";
		ATSpecialistAsst = "Anti-Tank Specialist Assistant";
		AASpecialist = "Anti-Air Specialist";
		AASpecialistAsst = "Anti-Air Specialist Assistant";
		Marksman = "Marksman";
		Sniper = "Sniper";
		Spotter = "Spotter";
		EOD = "Explosive Specialist";
		Engineer = "Engineer";
		Driver = "Driver/Crewman";
		HeliPilot = "Helicopter Pilot";
		HeliCrew = "Helicopter Crew";
		JetPilot = "Jet Pilot";
		JTAC = "JTAC";
		UAVOperator = "UAV Operator";
	};

	class uniform: uniform {
		Default[] = {
				"rhs_uniform_cu_ucp",
				"rhs_uniform_cu_ucp_101st",
				"rhs_uniform_cu_ucp_10th",
				"rhs_uniform_cu_ucp_1stcav",
				"rhs_uniform_cu_ucp_82nd"
			};
		Sniper[] = { "U_B_FullGhillie_sard" };
		HeliPilot[] = { "rhs_uniform_cu_ucp_1stcav" };
		JetPilot[] = { "U_B_PilotCoveralls" };
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
		Default[] = { "rhsusf_iotv_ucp_Rifleman" };
		Lead[] = { "rhsusf_iotv_ucp_Teamleader" };
		SQL[] = { "rhsusf_iotv_ucp_Squadleader" };
		Doctor[] = { "rhsusf_iotv_ucp_Medic" };
		Medic[] = { "rhsusf_iotv_ucp_Medic" };
		Grenadier[] = { "rhsusf_iotv_ucp_Grenadier" };
		LMG[] = { "rhsusf_iotv_ucp_SAW" };
		MMG[] = { "rhsusf_iotv_ucp_SAW" };
		Sniper[] = { "V_PlateCarrier2_blk" };
		EOD[] = { "rhsusf_iotv_ucp_Repair" };
		Engineer[] = { "rhsusf_iotv_ucp_Repair" };
		Driver[] = { "V_BandollierB_rgr" };
		HeliPilot[] = { "V_TacVest_blk" };
		JetPilot[] = { "V_TacVest_blk" };
	};

	class backpack: backpack {
		Lead[] = { "TFAR_rt1523g_rhs" };
		SQL[] = { "TFAR_rt1523g_rhs" };
		Doctor[] = { "rhsusf_assault_eagleaiii_ucp" };
		Medic[] = { "rhsusf_assault_eagleaiii_ucp" };
		LMG[] = { "rhsusf_assault_eagleaiii_ucp" };
		LMGAsst[] = { "rhsusf_assault_eagleaiii_ucp" };
		MMG[] = { "rhsusf_assault_eagleaiii_ucp" };
		MMGAsst[] = { "rhsusf_assault_eagleaiii_ucp" };
		ATSpecialist[] = { "B_Carryall_cbr" };
		ATSpecialistAsst[] = { "B_Carryall_cbr" };
		AASpecialist[] = { "rhsusf_assault_eagleaiii_ucp" };
		AASpecialistAsst[] = { "rhsusf_assault_eagleaiii_ucp" };
		EOD[] = { "rhsusf_assault_eagleaiii_ucp" };
		Engineer[] = { "rhsusf_assault_eagleaiii_ucp" };
		JTAC[] = { "TFAR_rt1523g_rhs" };
		UAVOperator[] = { "B_UAV_01_backpack_F" };
	};

	class backpackInventory: backpackInventory {
		Lead[] = { { 1, "ACE_HuntIR_monitor" }, { 4, "ACE_HuntIR_M203" } };
		SQL[] = { { 1, "ACE_HuntIR_monitor" }, { 4, "ACE_HuntIR_M203" } };
		Doctor = KEKO_LOADOUT_DOCTOR_DEFAULT_BACKPACK_INVENTORY;
		Medic = KEKO_LOADOUT_MEDIC_DEFAULT_BACKPACK_INVENTORY;
		EOD = KEKO_LOADOUT_EOD_DEFAULT_BACKPACK_INVENTORY;
		Engineer = KEKO_LOADOUT_ENGINEER_DEFAULT_BACKPACK_INVENTORY;
		JTAC[] = { { 4, "Laserbatteries" } };
	};

	class helmet: helmet {
		Default[] = {
				"rhsusf_ach_helmet_ucp_norotos",
				"rhsusf_ach_helmet_headset_ess_ucp",
				"rhsusf_ach_helmet_headset_ucp",
				"rhsusf_ach_helmet_ESS_ucp",
				"rhsusf_ach_helmet_ucp"
			};
		Lead[] = { "rhsusf_patrolcap_ucp" };
		Command[] = { "H_Cap_tan_specops_US" };
		Sniper[] = { "H_HelmetSpecB" };
		Driver[] = { "H_HelmetCrew_I" };
		HeliPilot[] = { "H_PilotHelmetHeli_B" };
		HeliCrew[] = { "H_CrewHelmetHeli_B" };
		JetPilot[] = { "H_PilotHelmetFighter_B" };
	};

	class primary: primary {
		Default[] = { keko_W_M4 };
		Lead[] = { keko_W_M4_GL_HUNTIR };
		SQL[] = { keko_W_M4_GL_HUNTIR };
		FTL[] = { keko_W_M4_GL };
		Grenadier[] = { keko_W_M4_GL };
		LMG[] = { keko_W_M249 };
		MMG[] = { keko_W_M240B };
		Marksman[] = { keko_W_M14 };
		Sniper[] = { keko_W_A3_LRR };
		Spotter[] = { keko_W_M4_GL };
		JTAC[] = { keko_W_M4_GL_HUNTIR };
		UAVOperator[] = { keko_W_M4_GL_HUNTIR };
	};

	class secondary: secondary {
		Default[] = { keko_W_M9 };
		Sniper[] = { keko_W_M9 };
	};

	class launcher: launcher {
		RiflemanAT[] = { keko_W_M136 };
		ATSpecialist[] = { keko_W_Javelin };
		AASpecialist[] = { keko_W_Stinger };
	};

};
