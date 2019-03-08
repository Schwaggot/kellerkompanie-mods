class GVAR(composition_Dialog)
{
    idd = 133799;
    movingEnable = true;

    class controls
    {
        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT START (by Kex, v1.063, #Qocuko)
        ////////////////////////////////////////////////////////

        class GVAR(Title): RscText
        {
            idc = 1000;
            moving = 1;

            text = "$STR_keko_zeus_ADVANCED_COMPOSITION"; //--- ToDo: Localize;
            x = 7.5 * GUI_GRID_W + 2 * GUI_GRID_W_FIX + GUI_GRID_X;
            y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 26 * GUI_GRID_W - 2 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
            size = TITLE_FONT_SIZE;
            sizeEx = TITLE_FONT_SIZE;
            colorBackground[] = {0.518,0.016,0,0.8};
        };
        class GVAR(Main_Background): IGUIBack
        {
            idc = 2000;

            x = 7.5 * GUI_GRID_W + GUI_GRID_X;
            y = 0.5 * GUI_GRID_H + 1.5 * GUI_GRID_H_FIX + GUI_GRID_Y;
            w = 26 * GUI_GRID_W;
            h = 20.5 * GUI_GRID_H;
            colorBackground[] = {0.2,0.2,0.2,0.8};
        };
        class GVAR(Dialog_Bottom_Bar): IGUIBack
        {
            idc = 2010;

            x = 8.5 * GUI_GRID_W + 6 * GUI_GRID_W_FIX + GUI_GRID_X;
            y = 20.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 24 * GUI_GRID_W - 13 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
            size = DEFAULT_FONT_SIZE;
            sizeEx = DEFAULT_FONT_SIZE;
            colorBackground[] = {0,0,0,0.6};
        };
        class GVAR(Cancle_Button): RscButtonMenuCancel
        {
            idc = 3010;

            onButtonClick = "uiNamespace setVariable ['keko_zeus_Dialog_Result', -1]; closeDialog 2;";
            x = 8 * GUI_GRID_W + GUI_GRID_X;
            y = 20.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 6 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
            size = DEFAULT_FONT_SIZE;
            sizeEx = DEFAULT_FONT_SIZE;
            colorText[] = {1,1,1,1};
            colorBackground[] = {0,0,0,0.8};
        };
        class RscButtonMenuOK: RscButtonMenuOK
        {
            idc = 3000;

            onButtonClick = "uiNamespace setVariable ['keko_zeus_Dialog_Result', 1]; closeDialog 1;";

            text = "$STR_keko_zeus_SPAWN"; //--- ToDo: Localize;

            x = 33 * GUI_GRID_W - 7 * GUI_GRID_W_FIX + GUI_GRID_X;
            y = 20.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 7 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
            size = DEFAULT_FONT_SIZE;
            sizeEx = DEFAULT_FONT_SIZE;
        };
        class GVAR(Background_Edit): IGUIBack
        {
            idc = 2020;

            x = 8 * GUI_GRID_W + GUI_GRID_X;
            y = 1 * GUI_GRID_H + 1.5 * GUI_GRID_H_FIX + GUI_GRID_Y;
            w = 25 * GUI_GRID_W;
            h = 19 * GUI_GRID_H - 1.5 * GUI_GRID_H_FIX;
            colorBackground[] = {0,0,0,0.6};
        };
        class GVAR(Paragraph_edit): RscText
        {
            idc = 1020;

            text = "Select composition to edit or delete."; //--- ToDo: Localize;
            x = 8 * GUI_GRID_W + GUI_GRID_X;
            y = 1 * GUI_GRID_H + 1.5 * GUI_GRID_H_FIX + GUI_GRID_Y;
            w = 25.5 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H_FIX;
            size = DEFAULT_FONT_SIZE;
            sizeEx = DEFAULT_FONT_SIZE;
        };
        class GVAR(composition_tree): RscTree
        {
            idc = 1400;

            expandOnDoubleclick = 1;
            colorMarked[] = {1, 1, 1, 0.350000};
            colorMarkedSelected[] = {1, 1, 1, 0.700000};

            x = 8.5 * GUI_GRID_W + GUI_GRID_X;
            y = 1 * GUI_GRID_H + 3 * GUI_GRID_H_FIX + GUI_GRID_Y;
            w = 24 * GUI_GRID_W;
            h = 18.5 * GUI_GRID_H - 3 * GUI_GRID_H_FIX;
            size = DEFAULT_FONT_SIZE;
            sizeEx = DEFAULT_FONT_SIZE;
            colorText[] = {0.5,0.5,0.5,1};
            colorBackground[] = {0,0,0,0.5};
        };
        class GVAR(Icon_Background): IGUIBack
        {
            idc = 2020;

            x = 7.5 * GUI_GRID_W + GUI_GRID_X;
            y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
            colorBackground[] = {0.518,0.016,0,0.8};
        };
        class GVAR(Icon): RscPicture
        {
            idc = 2030;

            text = QPATHTOF(ui\icons\icon_keko_zeus_dialog.paa);
            x = 7.5 * GUI_GRID_W + GUI_GRID_X;
            y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
        };
        class GVAR(Delete_Button): RscActivePicture
        {
            idc = 3020;

            onButtonClick = "([""DELETE_BUTTON""] + _this) call keko_zeus_fnc_RscDisplayAttributes_manageAdvancedComposition;";
            soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1};

            text = "a3\3den\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
            x = 33 * GUI_GRID_W - 2 * GUI_GRID_W_FIX + GUI_GRID_X;
            y = 20.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
        };
        class GVAR(Edit_Button): GVAR(Delete_Button)
        {
            idc = 3030;

            onButtonClick = "([""EDIT_BUTTON""] + _this) call keko_zeus_fnc_RscDisplayAttributes_manageAdvancedComposition;";
            text = "a3\3den\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
            x = 33 * GUI_GRID_W - 4.5 * GUI_GRID_W_FIX + GUI_GRID_X;
            y = 20.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
        };
        class GVAR(New_Button): GVAR(Delete_Button)
        {
            idc = 3040;

            onButtonClick = "([""NEW_BUTTON""] + _this) call keko_zeus_fnc_RscDisplayAttributes_manageAdvancedComposition;";
            text = "a3\3den\Data\Displays\Display3DEN\PanelRight\customcomposition_add_ca.paa";
            x = 33 * GUI_GRID_W - 7 * GUI_GRID_W_FIX + GUI_GRID_X;
            y = 20.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W_FIX;
            h = 1.5 * GUI_GRID_H_FIX;
        };

        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT END
        ////////////////////////////////////////////////////////
    };
};
