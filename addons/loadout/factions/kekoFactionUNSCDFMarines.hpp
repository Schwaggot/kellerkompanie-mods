class kekoFactionUNSCDFMarines: Faction_base {

	name = "[Sci-Fi] UNSCDF Marines - U.N. Space Command Defense Force Marines";
	roles[] = {
		{"Führung", {
			kekoCommand,
			kekoLead,
			kekoSergeant,
			kekoRadioOperator,
			kekoSQL,
			kekoFTL,
			kekoDoctor,
			kekoMedic}},
		{"Plebs", {
			kekoRifleman,
			kekoRiflemanAT,
			kekoGrenadier,
			kekoLMG,
			kekoLMGAsst}},
		{"Heavy Weapons", {
			kekoATSpecialist,
			kekoATSpecialistAsst,
			kekoAASpecialist,
			kekoAASpecialistAsst}},
		{"Support", {
			kekoMarksman,
			kekoEOD,
			kekoEngineer,
			kekoDriver,
			kekoUAVOperator}
		}
	};
	weaponCfg = kekoWeaponsUNSCDF;

	logisticsHelicopter = "OPTRE_Pelican_unarmed";

	// define all weapons and mags
	#include "kekoWeaponsUNSCDF.hpp"

	#include "kekoSoldier.hpp"
	#include "kekoCrate.hpp"

	crates[] = KEKO_LOGISTICS_DEFAULT_CRATE_LIST;

	class kekoSoldierUNSCDFMarine: kekoSoldier {
		uniform[] = {"OPTRE_UNSC_Marine_Uniform"};

		vest[] = {"OPTRE_UNSC_M52A_Armor_Rifleman_MAR"};

		helmet[] = {"OPTRE_UNSC_CH252_Helmet_MAR"};

		primary[] = {keko_W_OPTRE_MA37};

		secondary[] = {keko_W_OPTRE_M6G};
	};

	class kekoLead: kekoSoldierUNSCDFMarine	{
		name = "Lead";
		rank = "LIEUTENANT";
		uniform[] = {"OPTRE_UNSC_Marine_Uniform_S"};
		vest[] = {"OPTRE_UNSC_M52A_Armor_TL_MAR"};
		helmet[] = {"OPTRE_UNSC_PatrolCap_Marines"};
		optics[] = {"OPTRE_Smartfinder"};
		primary[] = {};
	};

	class kekoCommand: kekoLead	{
		name = "Command";
		rank = "COLONEL";
		medicClass = 2;
		engineerClass = 2;
		backpack[] = {"OPTRE_ANPRC_521_Black"};
	};

	class kekoSQL: kekoSoldierUNSCDFMarine	{
		name = "Squad Leader";
		rank = "SERGEANT";
		helmet[] = {"OPTRE_UNSC_CH252_Helmet2_MAR"};
		vest[] = {"OPTRE_UNSC_M52A_Armor_TL_MAR"};
		vestInventory[] = {
			{4, "OPTRE_36Rnd_95x40_Mag"},
			{4, "OPTRE_36Rnd_95x40_Mag_Tracer"},
			{2, "OPTRE_36Rnd_95x40_Mag"}
		};
		primary[] = {keko_W_OPTRE_BR55HB};
		backpack[] = {"OPTRE_UNSC_Rucksack_Lead"};
		optics[] = {"OPTRE_Smartfinder"};
		secondary[] = {
			keko_W_OPTRE_M6G};
	};

	class kekoSergeant: kekoSQL	{
		name = "Sergeant";
	};

	class kekoFTL: kekoSoldierUNSCDFMarine	{
		name = "Fire Team Leader";
		rank = "CORPORAL";
		optics[] = {"OPTRE_Binoculars"};
		helmet[] = {"OPTRE_UNSC_CH252_Helmet2_MAR"};
		vest[] = {"OPTRE_UNSC_M52A_Armor_TL_MAR"};
		backpack[] = {
			"OPTRE_UNSC_Rucksack_Lead"
		};
		primary[] = {
			keko_W_OPTRE_MA37GL
		};
	};

	class kekoDoctor: kekoSoldierUNSCDFMarine {
		name = "Doctor";
		medicClass = 2;
		rank = "SERGEANT";
		helmet[] = {"OPTRE_UNSC_CH252_Helmet2_MAR_MED"};
		vest[] = {"OPTRE_UNSC_M52A_Armor_Corpsman_MAR"};
		vestInventory[] = KEKO_LOADOUT_DOCTOR_DEFAULT_VEST_INVENTORY;

		backpack[] = {"OPTRE_UNSC_Rucksack_Medic"};
		backpackInventory[] = KEKO_LOADOUT_DOCTOR_DEFAULT_BACKPACK_INVENTORY;
	};

	class kekoMedic: kekoSoldierUNSCDFMarine {
		name = "Medic";
		medicClass = 1;
		rank = "CORPORAL";
		helmet[] = {"OPTRE_UNSC_CH252_Helmet2_MAR_MED"};
		vest[] = {"OPTRE_UNSC_M52A_Armor_Corpsman_MAR"};
		vestInventory[] = KEKO_LOADOUT_MEDIC_DEFAULT_VEST_INVENTORY;

		backpack[] = {"OPTRE_UNSC_Rucksack_Medic"};
		backpackInventory[] = KEKO_LOADOUT_MEDIC_DEFAULT_BACKPACK_INVENTORY;
	};

	class kekoRifleman: kekoSoldierUNSCDFMarine	{
		name = "Rifleman";
	};

	class kekoRadioOperator: kekoSoldierUNSCDFMarine {
		name = "Radio Operator";
		backpack[] = {"OPTRE_ANPRC_521_Black"};
	};

	class kekoRiflemanAT: kekoSoldierUNSCDFMarine	{
		name = "Rifleman Anti-Tank";
		backpack[] = {"OPTRE_UNSC_Rucksack_M41"};
		backpackInventory[] = {
			{1, "OPTRE_M41_Twin_HEAP"},
			{1, "OPTRE_M41_Twin_HEAT"}
		};
		launcher[] = {keko_W_OPTRE_M41_SSR};
	};

	class kekoGrenadier: kekoSoldierUNSCDFMarine {
		name = "Grenadier";
		primary[] = {
			keko_W_OPTRE_MA37GL};
	};

	class kekoLMG: kekoSoldierUNSCDFMarine {
		name = "Light Machine Gunner";
		vest[] = {"OPTRE_UNSC_M52A_Armor_MG_MAR"};
		primary[] = {keko_W_OPTRE_M73};
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy"};
	};

	class kekoLMGAsst: kekoSoldierUNSCDFMarine {
		name = "Light Machine Gunner Asst.";
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy"};
		optics[] = {"OPTRE_Binoculars"};
	};

	class kekoATSpecialist: kekoSoldierUNSCDFMarine {
		name = "Anti-Tank Specialist";
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy_M41G"};
		launcher[] = {keko_W_OPTRE_M41_SSR};
	};

	class kekoATSpecialistAsst: kekoSoldierUNSCDFMarine {
		name = "Anti-Tank Specialist Assistant";
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy_M41G"};
		optics[] = {"OPTRE_Smartfinder"};
	};

	class kekoAASpecialist: kekoSoldierUNSCDFMarine {
		name = "Anti-Air Specialist";
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy_M41G"};
		launcher[] = {keko_W_OPTRE_M41_SSR_G};
	};

	class kekoAASpecialistAsst: kekoSoldierUNSCDFMarine {
		name = "Anti-Air Specialist Assistant";
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy_M41G"};
		optics[] = {"OPTRE_Smartfinder"};
	};

	class kekoMarksman: kekoSoldierUNSCDFMarine {
		name = "Marksman";
		vestInventory[] = {
			{1, "ACE_RangeCard"}
		};
		primary[] = {
			keko_W_OPTRE_M392_DMR
		};
	};

	class kekoEOD: kekoSoldierUNSCDFMarine {
		name = "Explosive Specialist";
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy"};
		backpackInventory[] = KEKO_LOADOUT_EOD_DEFAULT_BACKPACK_INVENTORY;
		engineerClass = 2;
	};

	class kekoEngineer: kekoSoldierUNSCDFMarine {
		name = "Engineer";
		backpack[] = {"OPTRE_UNSC_Rucksack_Heavy"};
		backpackInventory[] = KEKO_LOADOUT_ENGINEER_DEFAULT_BACKPACK_INVENTORY;
		engineerClass = 2;
	};

	class kekoDriver: kekoSoldierUNSCDFMarine {
		name = "Crewman";
		helmet[] = {"H_HelmetCrew_B"};
		vest[] = {"OPTRE_UNSC_M52A_Armor3_MAR"};
		vestInventory[] = {
			{6, "OPTRE_60Rnd_5x23mm_Mag"}
		};
		primary[] = {
			keko_W_OPTRE_M7
		};
		engineerClass = 2;
	};

	class kekoUAVOperator: kekoSoldierUNSCDFMarine	{
		name = "UAV Operator";
		vestInventory[] = {
			{2,"ACE_UAVBattery"},
			{1,"ACE_HuntIR_monitor"},
			{8,"ACE_HuntIR_M203"}
		};
		backpack[] = {"B_UAV_01_backpack_F"};
		items[] = {"B_UavTerminal"};
	};
};
