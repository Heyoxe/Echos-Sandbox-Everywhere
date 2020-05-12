params ["_control"];
private _keys = actionKeysNames "User13";
private _second = if !(_keys isEqualTo "") then {
	format [localize "STR_ese_main_helpLoadFirst", _keys];
} else {
	""
};

private _text  = format [localize "STR_ese_main_helpLoadSecond", _second];
if (profileNamespace getVariable ["ESE_Main_var_EscapeMenuText", true]) then {
	_control ctrlSetStructuredText (parseText _text);
};