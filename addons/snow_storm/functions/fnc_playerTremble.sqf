#include "script_component.hpp"

if ((!hasInterface) or (GVAR(pos_p) != "open")) exitWith {};

params ["_pozitie_x", "_pozitie_y"];

drop [
	["\A3\data_f\cl_basic",1,0,1],
	"",
	"Billboard",
	0.5,
	(GVAR(snow_gust)#1) / 2,
	[_pozitie_x, _pozitie_y, 0],
	[GVAR(vit_x), GVAR(vit_y),0],
	13,
	1.3,
	1,
	0.1,
	[1,10,15],
	[
		[1,1,1,0],
		[1,1,1,.1],
		[1,1,1,0]
	],
	[1],
	1,
	0,
	QFUNC(createSnowGustsEffect),
	"",
	GVAR(hunt_alias),
	0,
	true,
	0.1
];

sleep 0.6; playSound QGVAR(rafala_1);

_fulgi  = "#particlesource" createVehiclelocal getposaTL player;
_fulgi setParticleCircle [0,[0,0,0]];
_fulgi setParticleRandom [0,[10,10,5],[0,0,0],0,0.1,[0,0,0,0.1],0,0];
_fulgi setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,12,8,1],"","Billboard",1,5,[0,0,7],[GVAR(vit_x),GVAR(vit_y),0],0,1.7,1,0,[0.1],[[1,1,1,1]],[1],0,0,"","",player];
_fulgi setDropInterval 0.01;

_snow_flakes  = "#particlesource" createVehiclelocal getposaTL player;
_snow_flakes setParticleCircle [0,[0,0,0]];
_snow_flakes setParticleRandom [0,[5,5,9],[0,0,0],0,0.1,[0,0,0,0.1],0,0];
_snow_flakes setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,12,8,1],"","Billboard",1,3,[0,0,10],[GVAR(vit_x)*2,GVAR(vit_y)*2,0],3,1.7,1,0,[0.2],[[1,1,1,1]],[1],0.3,1,"","",player];
_snow_flakes setDropInterval 0.01;

if (GVAR(player_act_cold)) then {
	enableCamShake true;

	["FilmGrain", 2000] spawn {
		params ["_name","_priority","_effect","_handle"];

		while {_handle = ppEffectCreate [_name, _priority];	_handle < 0} do {
			_priority = _priority + 1
		};
		_handle ppEffectEnable true;
		for "_i" from 0 to 0.1 step 0.01 do {
			_handle ppEffectAdjust [_i,1,5,0.5,0.3,0];
			sleep 0.3;
			_handle ppEffectCommit 0;
		};
		sleep 5;
		_i = 0.1;
		while {_i > 0} do {
			_i = _i - 0.01;
			_handle ppEffectAdjust [_i, 1, 5, 0.5, 0.3, 0];
			sleep 0.5;		
			_handle ppEffectCommit 0;
		};
		_handle ppEffectEnable false;
		ppEffectDestroy _handle;
	};

	if (goggles player == "") then {
		["RadialBlur", 100, [0.11, 1, 0.33, 0.16]] spawn {
			params ["_name", "_priority", "_effect", "_handle"];

			while {	_handle = ppEffectCreate [_name, _priority]; _handle < 0} do {
				_priority = _priority + 1
			};
			sleep 2;
			call BIS_fnc_fatigueEffect;
			_handle ppEffectEnable true;
			_handle ppEffectAdjust _effect;
			_handle ppEffectCommit 4;
			waitUntil {ppEffectCommitted _handle};
			call BIS_fnc_fatigueEffect;
			_i = 0.11;
			sleep 2;
			while {_i>0} do {
				_i = _i - 0.01;
				_handle ppEffectAdjust [_i,1,0.33,0.16];
				sleep 0.5;		
				_handle ppEffectCommit 0;
			};	
			_handle ppEffectEnable false;
			ppEffectDestroy _handle;
		};
	};

	sleep 1;
	_tremurici = selectRandom [QGVAR(tremurat_1), QGVAR(tremurat_2), QGVAR(NoSound), QGVAR(tremurat_3), QGVAR(tremurat_4), QGVAR(rafala_8)]; 
	playSound _tremurici;
	addCamShake [0.5, (GVAR(snow_gust)#1) * 2, 25];
};
sleep (GVAR(snow_gust)#1) / 2;
deleteVehicle _snow_flakes;	
deleteVehicle _fulgi;