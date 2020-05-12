private _keys = actionKeysNames "User13";
private _second = if !(_keys isEqualTo "") then {
	format [localize "STR_ese_main_helpLoadFirst", _keys];
} else {
	""
};

hint parseText format [localize "STR_ese_main_helpLoadSecond", profileName, _second];