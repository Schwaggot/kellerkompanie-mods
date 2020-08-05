class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
        clientInit = QUOTE(call COMPILE_FILE(XEH_preInitClient));
        disableModuload = 1;
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        clientInit = QUOTE(call COMPILE_FILE(XEH_postInitClient));
        disableModuload = 1;
    };
};
