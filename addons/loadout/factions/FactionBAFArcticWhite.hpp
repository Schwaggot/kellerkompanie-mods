class FactionBAFArcticWhite: FactionBase {
	name = "[Event] BAF MTP Arctic White - British Armed Forces (MTP Arctic White)";
	logisticsHelicopter = "UK3CB_BAF_Chinook_HC2_MTP";

	#include "WeaponsBAF.hpp"

	class uniform: uniform {
		Default[] = { "UK3CB_BAF_U_Smock_Arctic" };
		Lead[] = { "UK3CB_BAF_U_RolledUniform_MTP" };
		Command[] = { "UK3CB_BAF_U_RolledUniform_MTP" };
		HeliPilot[] = { "UK3CB_BAF_U_HeliPilotCoveralls_RAF" };
		JetPilot[] = { "UK3CB_BAF_U_HeliPilotCoveralls_RAF" };
	};

	class vest: vest {
		Default[] = { "UK3CB_BAF_V_PLCE_Webbing_Plate_Winter" };
		Driver[] = {
				"UK3CB_BAF_V_Osprey_Lite",
				"UK3CB_BAF_V_Osprey",
				"UK3CB_BAF_V_Osprey_Belt_A"
			};
		HeliPilot[] = { "UK3CB_BAF_V_Pilot_A" };
		JetPilot[] = { "UK3CB_BAF_V_Pilot_A" };
	};

	class backpack: backpack {
		Lead[] = { "UK3CB_BAF_B_Bergen_Arctic_SL_A" };
		Command[] = { "UK3CB_BAF_B_Bergen_Arctic_SL_A" };
		Sergeant[] = { "UK3CB_BAF_B_Bergen_Arctic_SL_A" };
		SQL[] = { "UK3CB_BAF_B_Bergen_Arctic_SL_A" };
		Doctor[] = { "UK3CB_BAF_B_Kitbag_Arctic" };
		LMG[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		LMGAsst[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		MMG[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		MMGAsst[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		ATSpecialist[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		ATSpecialistAsst[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		AASpecialist[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		AASpecialistAsst[] = { "UK3CB_BAF_B_Bergen_Arctic_Rifleman_A", "UK3CB_BAF_B_Bergen_Arctic_Rifleman_B" };
		EOD[] = { "UK3CB_BAF_B_Carryall_Arctic" };
		Engineer[] = { "UK3CB_BAF_B_Carryall_Arctic" };
		JTAC[] = { "UK3CB_BAF_B_Bergen_Arctic_JTAC_H_A", "UK3CB_BAF_B_Bergen_Arctic_JTAC_A" };
		UAVOperator[] = { "B_UAV_01_backpack_F" };
	};

	class backpackInventory: backpackInventory {
		Lead[] = { { 1, "ACE_HuntIR_monitor" }, { 4, "ACE_HuntIR_M203" } };
		Sergeant[] = { { 1, "ACE_HuntIR_monitor" }, { 4, "ACE_HuntIR_M203" } };
		SQL[] = { { 1, "ACE_HuntIR_monitor" }, { 4, "ACE_HuntIR_M203" } };
		ATSpecialist[] = { { 1, "UK3CB_BAF_Javelin_CLU" } };
		JTAC[] = { { 4, "Laserbatteries" } };
	};

	class helmet: helmet {
		Default[] = { "UK3CB_BAF_H_Mk7_Win_A", "UK3CB_BAF_H_Mk7_Win_ESS_A" };
		Lead[] = { "UK3CB_BAF_H_Beret_TYR_PRR" };
		Command[] = { "UK3CB_BAF_H_Beret_TYR_PRR" };
		Driver[] = { "UK3CB_BAF_H_CrewHelmet_B" };
		HeliPilot[] = { "UK3CB_BAF_H_PilotHelmetHeli_A" };
		HeliCrew[] = { "UK3CB_BAF_H_PilotHelmetHeli_A" };
		JetPilot[] = { "UK3CB_BAF_H_PilotHelmetHeli_A" };
	};

	class primary: primary {
		Default[] = { keko_W_BAF_L85A2 };
		Lead[] = { keko_W_BAF_L85A2_UGL_HUNTIR };
		Sergeant[] = { keko_W_BAF_L85A2_UGL_HUNTIR };
		SQL[] = { keko_W_BAF_L85A2_UGL_HUNTIR };
		FTL[] = { keko_W_BAF_L85A2_UGL };
		Grenadier[] = { keko_W_BAF_L85A2_UGL };
		LMG[] = { keko_W_BAF_L110 };
		MMG[] = { keko_W_BAF_L7A2 };
		Marksman[] = { keko_W_BAF_L129A1 };
		JTAC[] = { keko_W_BAF_L85A2_UGL_SMOKE };
		UAVOperator[] = { keko_W_BAF_L85A2_UGL_HUNTIR };
	};

	class secondary: secondary {
		Default[] = { keko_W_BAF_L131A1 };
	};

	class launcher: launcher {
		RiflemanAT[] = { keko_W_AT4 };
		ATSpecialist[] = { keko_W_BAF_JAVELIN };
		AASpecialist[] = { keko_W_STRINGER };
	};

};
