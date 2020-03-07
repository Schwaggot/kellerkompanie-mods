// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX x
#define PREFIX keko

#define MAJOR 2
#define MINOR 20
#define PATCHLVL 3
#define BUILD 112

#define VERSION MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR MAJOR,MINOR,PATCHLVL,BUILD

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 1.94
#define REQUIRED_CBA_VERSION {3,12,0}

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(KEKO - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(KEKO - COMPONENT)
#endif
