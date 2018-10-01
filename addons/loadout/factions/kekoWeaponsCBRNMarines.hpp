#include "script_macro.hpp"

#define SMOKE_WHITE "SmokeShell"
#define SMOKE_GREEN "SmokeShellGreen"
#define SMOKE_RED "SmokeShellRed"
#define GRENADE "HandGrenade"

#define PRIMARY_MAG "30Rnd_65x39_caseless_mag"
#define PRIMARY_MAG_TRACER "30Rnd_65x39_caseless_mag_Tracer"
#define PRIMARY_MAG_LMG "100Rnd_65x39_caseless_mag_Tracer"
#define PRIMARY_MAG_MMG "130Rnd_338_Mag"
#define PRIMARY_MAG_MARKSMAN "ACE_30Rnd_65x47_Scenar_mag"
#define SECONDARY_MAG "11Rnd_45ACP_Mag"
#define SECONDARY_MAG_P99 "16Rnd_9x21_Mag"
#define PRIMARY_MAG_P90 "50Rnd_570x28_SMG_03"

#define RAT_LAUNCHER "launch_NLAW_F"
#define AT_LAUNCHER "launch_B_Titan_short_F"
#define AA_LAUNCHER "launch_B_Titan_F"

#define AT_MAG "Titan_AT"
#define AA_MAG "Titan_AA"
#define UGL_MAG "1Rnd_HE_Grenade_shell"

class kekoWeaponsCBRNMarines {
	// Primary
	class keko_W_A3_MX: kekoPrimaryWeapon
	{
		cfgName = "arifle_MX_F";
		items[] = {};
		magazines[] = {PRIMARY_MAG,PRIMARY_MAG_TRACER};
	};
	class keko_W_A3_MX_BLACK: keko_W_A3_MX
	{
		cfgName = "arifle_MX_Black_F";
	};

	// Staff
	class keko_W_A3_MXC: keko_W_A3_MX
	{
		cfgName = "arifle_MXC_F";
		items[] = {};
	};
	class keko_W_A3_MXC_BLACK: keko_W_A3_MXC
	{
		cfgName = "arifle_MXC_Black_F";
	};

	// Grenadier
	class keko_W_A3_MX_GL: keko_W_A3_MX
	{
		cfgName = "arifle_MX_GL_F";
		uglMagazines[] = {UGL_MAG};
	};
	class keko_W_A3_MX_GL_BLACK: keko_W_A3_MX_GL
	{
		cfgName = "arifle_MX_GL_Black_F";
	};

	// Marksman
	class keko_W_A3_MXM: kekoPrimaryWeapon
	{
		cfgName = "arifle_MXM_F";
		items[] = {};
		magazines[] = {PRIMARY_MAG_MARKSMAN};
	};
	class keko_W_A3_MXM_BLACK: keko_W_A3_MXM
	{
		cfgName = "arifle_MXM_Black_F";
	};

	// LMG
	class keko_W_A3_MX_SW: keko_W_A3_MX
	{
		cfgName = "arifle_MX_SW_F";
		magazines[] = {PRIMARY_MAG_LMG};
	};
	class keko_W_A3_MX_SW_BLACK: keko_W_A3_MX_SW
	{
		cfgName = "arifle_MX_SW_Black_F";
	};

	// MMG
	class keko_W_A3_MMG: kekoPrimaryWeapon
	{
		cfgName = "MMG_02_sand_F";
		items[] = {"bipod_01_F_blk"};
		magazines[] = {PRIMARY_MAG_MMG};
	};
	class keko_W_A3_MMG_BLACK: keko_W_A3_MMG
	{
		cfgName = "MMG_02_black_F";
	};

	// Sniper
	class keko_W_A3_LRR: keko_W_A3_MX
	{
		cfgName = "srifle_LRR_F";
		magazines[] = {"ACE_7Rnd_408_305gr_Mag"};
	};
	class keko_W_A3_LRR_CAMO: keko_W_A3_LRR
	{
		cfgName = "srifle_LRR_camo_F";
	};


	class keko_W_A3_P90: kekoPrimaryWeapon
	{
		cfgName = "SMG_03C_TR_black";
		items[] = {"acc_flashlight","optic_Holosight_smg_blk_F"};
		magazines[] = {PRIMARY_MAG_P90};
	};

	class keko_W_P99_KHAKI: kekoSecondaryWeapon
	{
		cfgName = "hgun_P07_khk_F";
		items[] = {};
		magazines[] = {SECONDARY_MAG_P99};
	};



	// Secondary
	class keko_W_TACTICAL: kekoSecondaryWeapon
	{
		cfgName = "hgun_Pistol_heavy_01_F";
		items[] = {};
		magazines[] = {SECONDARY_MAG};
	};
	class keko_W_TACTICAL_SPECOPS: keko_W_TACTICAL
	{
		items[] = {};
	};



	// Launcher
	class keko_W_TITAN_AT: kekoLauncherWeapon
	{
		cfgName = AT_LAUNCHER;
		magazines[] = {AT_MAG};
	};
	class keko_W_TITAN_AA: kekoLauncherWeapon
	{
		cfgName = AA_LAUNCHER;
		magazines[] = {AA_MAG};
	};
	class keko_W_NLAW: kekoLauncherWeapon
	{
		cfgName = RAT_LAUNCHER;
	};



	// Throwables
	class keko_W_GRENADE {
		cfgName = GRENADE;
	};
	class keko_W_SMOKE_WHITE {
		cfgName = SMOKE_WHITE;
	};
	class keko_W_SMOKE_GREEN {
		cfgName = SMOKE_GREEN;
	};
	class keko_W_SMOKE_RED {
		cfgName = SMOKE_RED;
	};
};
