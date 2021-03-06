class FactionCTRG: FactionBase {
    name = "[Minimal] CTRG - Combat Technology and Research Group";
    logisticsHelicopter = "B_CTRG_Heli_Transport_01_tropic_F";

    #include "WeaponsCTRG.hpp"

    class uniform: uniform {
        Default[] = {
                "U_B_CTRG_1",
                "U_B_CTRG_2",
                "U_B_CTRG_3"
            };
        Lead[] = { "U_B_CTRG_1" };
        Command[] = { "U_B_CTRG_1" };
        HeliPilot[] = { "U_B_HeliPilotCoveralls" };
        JetPilot[] = { "U_B_PilotCoveralls" };
    };

    class vest: vest {
        Default[] = { "V_PlateCarrierL_CTRG", "V_PlateCarrierH_CTRG" };
        Lead[] = { "V_Chestrig_khk" };
        Command[] = { "V_Chestrig_khk" };
        Doctor[] = { "V_PlateCarrierH_CTRG" };
        Medic[] = { "V_PlateCarrierH_CTRG" };
        Driver[] = { "V_BandollierB_rgr" };
        HeliPilot[] = { "V_TacVest_blk" };
        JetPilot[] = { "V_TacVest_blk" };
    };

    class backpack: backpack {
        Lead[] = { "TFAR_rt1523g_black" };
        Command[] = { "TFAR_rt1523g_black" };
        Sergeant[] = { "TFAR_rt1523g_black" };
        SQL[] = { "TFAR_rt1523g_black" };
        Doctor[] = { "B_Kitbag_rgr" };
        Medic[] = { "B_Kitbag_rgr" };
        LMG[] = { "B_FieldPack_khk" };
        LMGAsst[] = { "B_FieldPack_khk" };
        MMG[] = { "B_FieldPack_khk" };
        MMGAsst[] = { "B_FieldPack_khk" };
        ATSpecialist[] = { "B_FieldPack_cbr" };
        ATSpecialistAsst[] = { "B_FieldPack_cbr" };
        AASpecialist[] = { "B_FieldPack_cbr" };
        AASpecialistAsst[] = { "B_FieldPack_cbr" };
        EOD[] = { "B_Carryall_khk" };
        Engineer[] = { "B_Carryall_khk" };
        JTAC[] = { "TFAR_rt1523g_black" };
        UAVOperator[] = { "B_UAV_01_backpack_F" };
    };

    class backpackInventory: backpackInventory {
        JTAC[] = { { 4, "Laserbatteries" } };
    };

    class helmet: helmet {
        Default[] = {
                "H_HelmetB_light_black",
                "H_HelmetSpecB_blk",
                "H_HelmetB_black",
                "H_HelmetB_camo",
                "H_HelmetSpecB_sand",
                "H_HelmetB_sand",
                "H_HelmetB_light_sand",
                "H_HelmetSpecB_snakeskin"
            };
        Lead[] = { "H_Booniehat_khk_hs" };
        Command[] = { "H_Cap_khaki_specops_UK" };
        Driver[] = { "H_HelmetCrew_B" };
        HeliPilot[] = { "H_PilotHelmetHeli_B" };
        HeliCrew[] = { "H_CrewHelmetHeli_B" };
        JetPilot[] = { "H_PilotHelmetFighter_B" };
    };

    class primary: primary {
        Default[] = { "keko_W_A3_HK416", "keko_W_A3_HK416_SAND" };
        Lead[] = { "keko_W_A3_HK416_GL", "keko_W_A3_HK416_GL_SAND" };
        Sergeant[] = { "keko_W_A3_HK416_GL", "keko_W_A3_HK416_GL_SAND" };
        SQL[] = { "keko_W_A3_HK416_GL", "keko_W_A3_HK416_GL_SAND" };
        FTL[] = { "keko_W_A3_HK416_GL", "keko_W_A3_HK416_GL_SAND" };
        Grenadier[] = { "keko_W_A3_HK416_GL", "keko_W_A3_HK416_GL_SAND" };
        LMG[] = { "keko_W_A3_HK416_DRUM", "keko_W_A3_HK416_DRUM_SAND" };
        MMG[] = { "keko_W_A3_MINIMI" };
        Marksman[] = { "keko_W_A3_HK417", "keko_W_A3_HK417_SAND" };
        JTAC[] = { "keko_W_A3_HK416_GL", "keko_W_A3_HK416_GL_SAND" };
        UAVOperator[] = { "keko_W_A3_HK416_GL", "keko_W_A3_HK416_GL_SAND" };
    };

    class secondary: secondary {
        Default[] = { "keko_W_P99" };
    };

    class launcher: launcher {
        RiflemanAT[] = { "keko_W_NLAW" };
        ATSpecialist[] = { "keko_W_TITAN_AT" };
        AASpecialist[] = { "keko_W_TITAN_AA" };
    };

};
