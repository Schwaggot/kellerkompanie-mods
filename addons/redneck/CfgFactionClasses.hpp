class CfgFactionClasses {
  class NO_CATEGORY;
  class GVAR(faction): NO_CATEGORY
  {
      displayName = "Kellerkompanie Redneck";
  };

  class GVAR(blufor) {
		displayName = "Kellerkompanie Redneck";
		priority = 1;
		side = 1;
		icon = "\A3\data_f\cfgfactionclasses_blu_ca.paa";
		scopeCurator = 1;
	};
	class GVAR(indfor) {
		displayName = "Kellerkompanie Redneck";
		priority = 1;
		side = 2;
		icon = "\A3\data_f\cfgfactionclasses_ind_ca.paa";
		scopeCurator = 1;
	};
	class GVAR(opfor) {
		displayName = "Kellerkompanie Redneck";
		priority = 1;
		side = 0;
		icon = "\A3\data_f\cfgfactionclasses_opf_ca.paa";
		scopeCurator = 1;
	};
};
