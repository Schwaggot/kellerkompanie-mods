//systemChat str "InitModule 3denAttributesChanged";

_module = _this select 0;
_moduleName = str (_module get3DENAttribute "name");


_initModuleExists = false;
_existingInitModule = objNull;
_gameMasterModuleExists = false;
_hc1Exists = false;
_hc2Exists = false;
_hc3Exists = false;
{ 
	_logicName = (_x get3DENAttribute "name") select 0;
	//systemChat _logicName;
	switch(_logicName) do {
		case "keko_3den_initModule": {
			_initModuleExists = true;
			_existingInitModule = _x;
			break;
		};
		case "keko_3den_gameMaster": {
			_gameMasterModuleExists = true;
			break;
		};
		case "HC1": {
			_hc1Exists = true; 
			break;
		};
		case "HC2": {
			_hc2Exists = true;
			break;
		};
		case "HC3": {
			_hc3Exists = true;
			break;
		};
	};

} forEach (all3DENEntities select 3);

if (_initModuleExists) then {
	if(_module != _existingInitModule) then {
		systemChat "ERROR: there can be only one Init Module";
		delete3DENEntities _this;
		if(true) exitWith {};
	};
}; 

if !(_initModuleExists) then {
	set3DENMissionAttributes [
	    ["Scenario", "SaveBinarized", false],
	    
	    ["Multiplayer", "Respawn", 3],
	    ["Multiplayer", "RespawnDelay", 10],
	    ["Multiplayer", "MinPlayers", 1],
	    
	    ["Multiplayer", "DisabledAI", true],
	    ["Multiplayer", "AIKills", false],
	    ["Multiplayer", "EnableTeamSwitch", false],
	    ["Multiplayer", "RespawnTemplates", ["Counter"]],

	    ["Multiplayer", "GameType", "COOP"]
	];

	_module set3DENAttribute ["Name", "keko_3den_initModule"];
};

// update number of players + 3 for headless clients
set3DENMissionAttributes [ ["Multiplayer", "MaxPlayers", (count playableUnits) + 3] ];

// update scenario variables from module settings
_missionTitle = _module getVariable "MissionTitle";
_missionAuthor = _module getVariable "MissionAuthor";
_missionPicture = _module getVariable "MissionPicture";
_missionPictureSubtitle = _module getVariable "MissionPictureSubtitle";
_sideRelations = _module getVariable "SideRelations";

"Scenario" set3DENMissionAttribute ["Author", _missionAuthor];
"Scenario" set3DENMissionAttribute ["IntelBriefingName", _missionTitle];
"Scenario" set3DENMissionAttribute ["LoadScreen", _missionPicture];
"Scenario" set3DENMissionAttribute ["OnLoadMission", _missionPictureSubtitle];

switch(_sideRelations) do {
	case 0: {		
		"Multiplayer" set3DENMissionAttribute ["IntelIndepAllegiance",[0,0]];
	};
	case 1: {
		"Multiplayer" set3DENMissionAttribute ["IntelIndepAllegiance",[1,0]];
	};
	case 2: {
		"Multiplayer" set3DENMissionAttribute ["IntelIndepAllegiance",[0,1]];
	};
	case 3: {
		"Multiplayer" set3DENMissionAttribute ["IntelIndepAllegiance",[1,1]];
	};
};


// create additional logics on first create

_modulePos = getPos _module;

if !(_gameMasterModuleExists) then {
	// create GameMaster/Zeus module for logged-in admin
	_gameMasterPos = [(_modulePos select 0) + 2, _modulePos select 1, _modulePos select 2];
	_gameMasterEntity = create3DENEntity ["Logic", "ModuleCurator_F", _gameMasterPos];
	_gameMasterEntity set3DENAttribute ["Name", "keko_3den_gameMaster"];
	set3DENAttributes [[ [_gameMasterEntity], "ModuleCurator_F_Owner", "#adminLogged" ]];
	set3DENAttributes [[ [_gameMasterEntity], "ModuleCurator_F_Addons", 3 ]];
	set3DENAttributes [[ [_gameMasterEntity], "ModuleCurator_F_Name", "Admin" ]];
};

// create modules for headless clients
if !(_hc1Exists) then {
	_hc1Pos = [(_modulePos select 0) + 3, _modulePos select 1, _modulePos select 2];
	_hc1Entity = create3DENEntity ["Logic", "HeadlessClient_F", _hc1Pos];
	_hc1Entity set3DENAttribute ["Name", "HC1"];
	_hc1Entity set3DENAttribute ["ControlSP", false];
	_hc1Entity set3DENAttribute ["ControlMP", true];
	_hc1Entity set3DENAttribute ["Description", "HC1"];
};

if !(_hc2Exists) then {
	_hc2Pos = [(_modulePos select 0) + 4, _modulePos select 1, _modulePos select 2];
	_hc2Entity = create3DENEntity ["Logic", "HeadlessClient_F", _hc2Pos];
	_hc2Entity set3DENAttribute ["Name", "HC2"];
	_hc2Entity set3DENAttribute ["ControlSP", false];
	_hc2Entity set3DENAttribute ["ControlMP", true];
	_hc2Entity set3DENAttribute ["Description", "HC2"];
};

if !(_hc3Exists) then {
	_hc3Pos = [(_modulePos select 0) + 5, _modulePos select 1, _modulePos select 2];
	_hc3Entity = create3DENEntity ["Logic", "HeadlessClient_F", _hc3Pos];
	_hc3Entity set3DENAttribute ["Name", "HC3"];
	_hc3Entity set3DENAttribute ["ControlSP", false];
	_hc3Entity set3DENAttribute ["ControlMP", true];
	_hc3Entity set3DENAttribute ["Description", "HC3"];
};