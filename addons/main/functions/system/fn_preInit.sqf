#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"

// if (hasInterface) then {
// 	if ((uiNamespace getVariable [VAR(EHLoaded), -1]) isEqualTo -1) then {
// 		LDEBUG("Adding 'Loaded' Mission Event Handler...");
// 		private _event = addMissionEventHandler ["Loaded", {
// 			removeMissionEventHandler ["Loaded", (uiNamespace getVariable [VAR(EHLoaded), -1])];
// 			uiNamespace setVariable [VAR(EHLoaded), -1];
// 			params ["_saveType"];
// 			LDEBUG("Calling 'PostInit' from 'Loaded'");
// 			["postInit"] call ESL_INTERNAL_fnc_EInits;
// 		}];
// 		uiNamespace setVariable [VAR(EHLoaded), _event];
// 	};
// };

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
	missionNamespace setVariable ["ESE_main_var_curators", _curators, true];
};
missionNamespace setVariable ["ESE_main_var_cpreInit", true];