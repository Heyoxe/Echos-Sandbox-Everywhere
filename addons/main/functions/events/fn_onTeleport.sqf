params ["_player", "_oldPos", "_newPos"];
if (profileNamespace getVariable ["ESE_Main_var_MPTeleportMessage", true]) then {
	systemChat (format [localize "STR_ese_main_teleported", name _player]);
};