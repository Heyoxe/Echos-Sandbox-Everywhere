params ["_data", "_args"];
_data params ["_type"];
_args params ["_control"];

lbClear _control;

private _current = parseNumber ((profileNamespace getVariable ["ESE_main_var_userAction", "User13"]) select [4,2]);

private _index = -1;
private _data = "";
for "_i" from 1 to 20 do {
	_data = format ["User%1", _i];
	_index = _control lbAdd (localize format ["str_usract_user_%1", _i]);
	_control lbSetData [_index, _data];
};

_control lbSetCurSel (_current - 1);
