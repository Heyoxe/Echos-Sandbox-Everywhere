/************************/
/*		LEGACY CODE		*/
/************************/

private _hadMap = true;
if ("ItemMap" in assignedItems player || "ItemGps" in assignedItems player) then {_hadMap = true} else {
	_hadMap = false;
	player addWeapon "ItemMap";
};
openMap [true, false];
onMapSingleClick {
     (vehicle player) setPos _pos;
     onMapSingleClick {};
	 openMap false;
     if (isMultiplayer) then {
          (format ['Player %1 has Teleported!', name player]) remoteExec ["systemChat"];
     };
};
waitUntil {!visibleMap}
onMapSingleClick {};
if (_hadMap) then {} else {
	player removeWeapon "ItemMap";
};