#include "script_component.hpp"

class CfgPatches {
    class ADDON {
      name = COMPONENT_NAME;
      units[] = {};
      weapons[] = {};
      requiredVersion = REQUIRED_VERSION;
      requiredAddons[] = {
          "keko_common",
          "ace_grenades"
      };
      author = "Schwaggot";
      authors[] = {"Schwaggot"};
      url = ECSTRING(main,URL);
      VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"