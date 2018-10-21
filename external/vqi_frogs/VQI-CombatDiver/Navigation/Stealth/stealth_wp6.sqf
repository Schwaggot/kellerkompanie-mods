//
//



// Stealth-Click 6 ////////////////////////////////////////////////
subnav = true;

while {subnav} do {
	hint "L-Click to MOVE - TIME: 1hr \n \n HMS Proteus: . . . . . 1kph / -30m \n - STEALTH MODE -";
	
	MapClickTravel = false;
	onMapSingleClick "posSUBstealth6 = _pos; MapClickTravel = true; onMapSingleClick ''; true";
	waitUntil {MapClickTravel}; publicVariable "posSUBstealth6"; sleep 1;

	
	// Max Speed
	_wp = posSUBstealth6 distance2D posSUBstealth5;
	
	if (_wp < 1000) then { 
		
		// Min Depth
		_depth = getTerrainHeightASL posSUBstealth6;
		if (_depth < -30) then { 
			subnav = false; 
		} else { 
			hint "Too Shallow - Stay DEEPER than -30m \n TRY AGAIN";
			sleep 3;
		};
		
	} else {
		hint "Too Fast - Must be LESS than 1km \n TRY AGAIN";
		sleep 3;
	};
};


skipTime 1;


hint "Stand By...";
// Passive SONAR -- center, classname, sonar range
_ping1 = nearestObjects [posSUBstealth6, ["VQI_SUB_Class1"], 2000]; sleep 1;		// ENEMY SONAR RANGE - 2nd PING - TORP IN WATER!
_ping2 = nearestObjects [posSUBstealth6, ["VQI_SUB_Class2"], 3000]; sleep 1;		// ENEMY SONAR RANGE - 2nd PING - TORP IN WATER!
_ping3 = nearestObjects [posSUBstealth6, ["VQI_SUB_Class3"], 4000]; sleep 1;		// ENEMY SONAR RANGE - 2nd PING - TORP IN WATER!
_ping4 = nearestObjects [posSUBstealth6, ["VQI_SUB_Class4"], 3000]; sleep 1;		// ENEMY SONAR RANGE - 2nd PING - TORP IN WATER!
_ping5 = nearestObjects [posSUBstealth6, ["VQI_SUB_Class5"], 3000]; sleep 1;		// ENEMY SONAR RANGE - 2nd PING - TORP IN WATER!
_ping6 = nearestObjects [posSUBstealth6, ["VQI_SUB_Class6"], 7000]; sleep 1;		// ENEMY SONAR RANGE - 2nd PING - TORP IN WATER!

// count all activity
_ENEMY = count (_ping1 + _ping2 + _ping3 + _ping4 + _ping5 + _ping6);
//hint format ["%1",_ENEMY];



deleteMarker "mkrD";
if (!isNil "HMSProteus") then { deleteVehicle HMSProteus; sleep 1; };
HMSProteus = "Submarine_01_F" createVehicle posSUBstealth6;



if (_ENEMY == 0) then {
	_mkrS6 = createMarker["mkrS6", posSUBstealth6];
	"mkrS6" setMarkerShape "ICON";
	"mkrS6" setMarkerType "mil_dot";
	"mkrS6" setMarkerColor "ColorBLACK";
	"mkrS6" setMarkerText "S6";
	"mkrS6" setMarkerAlpha 0.5;
	
	_mkrD = createMarker["mkrD", posSUBstealth6];
	"mkrD" setMarkerShape "ELLIPSE";			//
	"mkrD" setMarkerBrush "FDiagonal";
	"mkrD" setMarkerColor "ColorBLACK";
	"mkrD" setMarkerSize [1000,1000];
	"mkrD" setMarkerAlpha 0.3;
	
	[] execVM "vqi_frogs\VQI-CombatDiver\Navigation\Stealth\stealth_wp7.sqf";
};

if (_ENEMY > 0) then {
	_mkrT6 = createMarker["mkrT6", posSUBstealth6];
	"mkrT6" setMarkerShape "ICON";
	"mkrT6" setMarkerType "hd_warning";
	"mkrT6" setMarkerColor "ColorOPFOR";
	"mkrT6" setMarkerText "TORP !";
	"mkrT6" setMarkerAlpha 1;
	
	[posSUBstealth6] execVM "vqi_frogs\VQI-CombatDiver\Navigation\Pinged\EnemyTorp\enemy_torp.sqf";
	[] execVM "vqi_frogs\VQI-CombatDiver\Navigation\Stealth\stealth_wp7.sqf";
};




//////////////////////////////////
/* NOTES:


*/