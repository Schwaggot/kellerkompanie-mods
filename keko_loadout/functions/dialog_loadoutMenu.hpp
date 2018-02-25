class keko_loadout_menuDialog {

	idd = 11;
	movingEnable = true;
	enableSimulation = true;
	
	onload = "(_this) spawn keko_loadout_fnc_dialogLoadoutMenuInit;";

	controls[] = { 
		KEKO_LOADOUT_UI_BACK,	
		KEKO_LOADOUT_UI_FRAME,
		KEKO_LOADOUT_UI_LIST,
		KEKO_LOADOUT_UI_TEXT,
		KEKO_LOADOUT_UI_BUTTON_OK,
		KEKO_LOADOUT_UI_BUTTON_CANCEL
	};

	class KEKO_LOADOUT_UI_BACK: IGUIBack
	{
		idc = 2200;
		x = 0.06 * GUI_GRID_W + GUI_GRID_X;
		y = 0.99 * GUI_GRID_H + GUI_GRID_Y;
		w = 40 * GUI_GRID_W;
		h = 24 * GUI_GRID_H;
		moving = 1;
	};

	class KEKO_LOADOUT_UI_FRAME: RscFrame
	{
		idc = 1800;
		text = "Loadout-Auswahlmenü";
		x = 0 * GUI_GRID_W + GUI_GRID_X;
		y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
		w = 40 * GUI_GRID_W;
		h = 24.5 * GUI_GRID_H;
		sizeEx = 1 * GUI_GRID_H;
	};

	class KEKO_LOADOUT_UI_LIST: RscListbox
	{
		idc = 1500;
		text = "Loadouts";
		x = 1 * GUI_GRID_W + GUI_GRID_X;
		y = 3 * GUI_GRID_H + GUI_GRID_Y;
		w = 16 * GUI_GRID_W;
		h = 21 * GUI_GRID_H;
		
		colorSelectBackground[] = 
		{
			0.03,
			0.42,
			0.53,
			1
		};
	};

	class KEKO_LOADOUT_UI_TEXT: RscText
	{
		idc = 1000;
		text = "Loadouts";
		x = 1 * GUI_GRID_W + GUI_GRID_X;
		y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
		w = 15.5 * GUI_GRID_W;
		h = 2 * GUI_GRID_H;
	};
	
	class KEKO_LOADOUT_UI_BUTTON_OK: RscButton
	{
		idc = 1600;
		text = "OK";
		x = 18 * GUI_GRID_W + GUI_GRID_X;
		y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
		w = 9 * GUI_GRID_W;
		h = 1.5 * GUI_GRID_H;
		action = "lbData [1500, lbCurSel 1500] spawn keko_loadout_fnc_dialogLoadoutMenuCallback;";
	};

	class KEKO_LOADOUT_UI_BUTTON_CANCEL: RscButton
	{
		idc = 1601;
		text = "Abbrechen";
		x = 28.5 * GUI_GRID_W + GUI_GRID_X;
		y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
		w = 9 * GUI_GRID_W;
		h = 1.5 * GUI_GRID_H;
		action = "closeDialog 2";
	};
};