#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"


params ["_control"];

if (isServer) then {
	if (isServer) then {
		private _group = createGroup sideLogic;
		private _curators = [];
		private _slots = (playableSlotsNumber blufor) + (playableSlotsNumber opfor) + (playableSlotsNumber independent) + (playableSlotsNumber civilian);
		for "_i" from 0 to _slots do {
			private _curator = _group createUnit ["ModuleCurator_F", [0,0,0], [], 0, "CAN_COLLIDE"];
			_curator setVariable ["addons", 3, true];
			_curator setVariable ["owner", "objNull", true];
			_curators pushback _curator;
		};
		missionNamespace setVariable [QVAR(curators), _curators, true];
	};

	if (!isMultiplayer) then {
		private _curators = GET_MVAR(curators, [objNull]);
		_curators params [
			["_curator", objNull, [objNull]]
		];
		_curator setVariable ["owner", "0", true];
		player assignCurator _curator;
	} else {
		if (isServer) then {
			_this spawn {
				while { true } do {
					private _freeCurators = GET_MVAR(curators, []) select { (getAssignedCuratorUnit _x) isEqualTo objNull };
					private _freePlayers = allPlayers select { (getAssignedCuratorLogic _x) isEqualTo objNull };
					{
						if !((count _freeCurators) isEqualTo 0) then {
							_x assignCurator (_freeCurators#0);
							_freeCurators = _freeCurators - [(_freeCurators#0)];
						};
					} forEach _freePlayers;
					uiSleep 5;
				};
			};
		};
	};
} else {
	_this remoteExec ["ESE_Main_fnc_ZeusReload", 2];
};
