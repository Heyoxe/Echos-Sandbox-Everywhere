params ["_control", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];

private _vehicle = missionNamespace getVariable ["ESE_Main_var_lastVehicle", objNull];
if !(_vehicle isEqualTO objNull) then {
	private _crewCount = count (fullCrew _vehicle);
	if (_crewCount isEqualTo 0) then {
		deleteVehicle _vehicle;
		_control ctrlEnable false;
		hint (localize "STR_ese_main_vehicleDeleted");
		missionNamespace setVariable ["ESE_Main_var_lastVehicle", objNull];
	} else {
		hint (localize "STR_ese_main_vehicleMustEmpty");
	};
};