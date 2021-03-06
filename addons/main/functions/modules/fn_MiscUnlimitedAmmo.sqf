private _state = player getVariable ["ESE_Main_var_UnlimitedAmmo", -1];
if (_state isEqualTo -1) then {
	private _id = player addEventHandler ["Fired",{
		params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
		private _secondaryWeapon = secondaryWeapon player;
		if ((_weapon in ["Throw", "Put"]) || (_secondaryWeapon isEqualTo _weapon)) then {
			player addItem _magazine;
		} else {
			player setVehicleAmmo 1;
		};
	}];
	player setVariable ["ESE_Main_var_UnlimitedAmmo", _id];
} else {
	private _id = player getVariable ["ESE_Main_var_UnlimitedAmmo", -1];
	player removeEventHandler ["Fired", _id];
	player setVariable ["ESE_Main_var_UnlimitedAmmo", -1];
};