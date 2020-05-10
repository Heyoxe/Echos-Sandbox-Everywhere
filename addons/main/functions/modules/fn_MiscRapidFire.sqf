private _state = player getVariable ["ESE_Main_var_RapidFire", -1];
if (_state isEqualTo -1) then {
	private _id = player addEventHandler ["Fired",{
		params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
		(vehicle player) setWeaponReloadingTime [player, _muzzle, 0];
	}];
	player setVariable ["ESE_Main_var_RapidFire", _id];
} else {
	private _id = player getVariable ["ESE_Main_var_RapidFire", _id];
	player removeEventHandler ["Fired", _id];
	player setVariable ["ESE_Main_var_RapidFire", -1];
};