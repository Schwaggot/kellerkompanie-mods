////////////////////////////////////////////////////////////////////
//DeRap: babe_core\config.bin
//Produced from mikero's Dos Tools Dll version 6.44
//'now' is Tue Jun 12 14:55:46 2018 : 'file' last modified on Thu May 10 19:35:41 2018
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BaBe_core
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_UI_F"};
	};
};
class RscStandardDisplay;
class RscDisplayModLauncher: RscStandardDisplay
{
	onMouseMoving = "if (isNull ((findDisplay 157) displayCtrl 212513)) then {call (uiNamespace getVariable 'babe_core_fnc_modmenu_init'); uiNamespace setVariable ['babe_core_modmenu_init', true]};";
};
