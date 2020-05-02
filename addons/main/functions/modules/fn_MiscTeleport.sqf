[] spawn {
	closeDialog 2; 
	uiSleep 0.001; 
	closeDialog 2;
     private _hasMap = ("ItemMap" in assignedItems player || "ItemGps" in assignedItems player);
     if !(_hasMap) then { player addWeapon "ItemMap" };

     openMap [true, false];

     private _event = addMissionEventHandler ["MapSingleClick", {
          params ["_units", "_pos", "_alt", "_shift"];
          (vehicle player) setPos _pos;
          openMap false;
          if (isMultiplayer) then {
               (format ['Player %1 has Teleported!', name player]) remoteExec ["systemChat"];
          };
     }];

     waitUntil { !visibleMap };
     removeMissionEventHandler ["MapSingleClick", _event];
     if !(_hasMap) then { player removeWeapon "ItemMap" };
}