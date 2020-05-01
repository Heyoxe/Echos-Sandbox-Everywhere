#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"

if (hasInterface) then {
	_this spawn {
		while { true } do {
			waitUntil { (inputAction "User13" > 0) && { alive player } && { !dialog } };
			createDialog "ESE_Main_dialog_MainMenu";
			systemChat "Menu Opened";
			uiSleep 1;
		};
	};
	_this spawn {
		addMusicEventHandler ["MusicStop", { missionNamespace setVariable ["ESE_Main_var_MusicStopped", true, false] }];
		while { true } do {
			waitUntil {
				private _musicSelection = missionNamespace getVariable ["ESE_Main_var_MusicSelection", []];
				(count _musicSelection) > 0	
			};
			private _musicSelection = missionNamespace getVariable ["ESE_Main_var_MusicSelection", []];
			private _selectionSize = count _musicSelection;
			private _randomClass = _musicSelection#(floor (random _selectionSize));
			playMusic _randomClass;
			3 fadeMusic 1;
			missionNamespace setVariable ["ESE_Main_var_MusicStopped", false];
			waitUntil {
				private _musicStopped = missionNamespace getVariable ["ESE_Main_var_MusicStopped", false];
				private _musicSelection = missionNamespace getVariable ["ESE_Main_var_MusicSelection", []];
				(_musicStopped) || ((count _musicSelection) isEqualTo 0)
			};
			3 fadeMusic 0;
			uiSleep 3;
			missionNamespace setVariable ["ESE_Main_var_MusicStopped", true, false];
			playMusic "";
		};
	};

	{
		_x addEventHandler ["CuratorObjectPlaced", {
			_this remoteExec ["ESE_Main_fnc_onCuratorObjectPlaced", -2];
		}];
	} forEach allCurators;
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

missionNamespace setVariable [QVAR(cpostInit), true];