[] spawn {
	closeDialog 2; 
	uiSleep 0.001; 
	closeDialog 2;
     private _hasMap = ("ItemMap" in assignedItems player || "ItemGps" in assignedItems player);
     if !(_hasMap) then { player addWeapon "ItemMap" };

     openMap [true, false];

     private _event = addMissionEventHandler ["MapSingleClick", {
          params ["_units", "_pos", "_alt", "_shift"];
          private _oldPos = getPos player;
          (vehicle player) setPos _pos;
          private _newPos = getPos player;
          openMap false;
          if (isMultiplayer) then {
               [player, _oldPos, _newPos] remoteExec ["ESE_Main_fnc_onTeleport"];
               // (format [localize "STR_ese_main_teleported", name player]) remoteExec ["systemChat"];
          };
     }];

     waitUntil { !visibleMap };
     removeMissionEventHandler ["MapSingleClick", _event];
     if !(_hasMap) then { player removeWeapon "ItemMap" };
}