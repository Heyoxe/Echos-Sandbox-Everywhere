private _keys = actionKeysNames (profileNamespace getVariable ["ESE_main_var_userAction", "User13"]);
private _second = if !(_keys isEqualTo "") then {
	format [localize "STR_ese_main_helpLoadFirst", _keys];
} else {
	""
};

private _current = parseNumber ((profileNamespace getVariable ["ESE_main_var_userAction", "User13"]) select [4,2]);
private _custom = (localize format ["str_usract_user_%1", _current]);
hint parseText format [localize "STR_ese_main_helpLoadSecond", _second, _custom];