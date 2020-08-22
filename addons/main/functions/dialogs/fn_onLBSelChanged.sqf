params ["_data", "_args"];
_data params ["_type"];
_args params ["_control", "_selectedIndex"];

private _current = parseNumber ((profileNamespace getVariable ["ESE_main_var_userAction", "User13"]) select [4,2]);
private _new = _selectedIndex + 1;
if (_current isEqualTo _new) exitWith {};

private _key = _control lbData _selectedIndex;
profileNamespace setVariable ["ESE_main_var_userAction", _key];


private _newName = localize format ["str_usract_user_%1", _new];
private _newKeys = actionKeysNames (format ["User%1", _new]);
private _currentName = localize format ["str_usract_user_%1", _current];
private _currentKeys = actionKeysNames (format ["User%1", _current]);

if (_newKeys isEqualTo "") then { _newKeys = format [localize "STR_ese_main_notAssigned", "&"] };
if (_currentKeys isEqualTo "") then { _currentKeys = format [localize "STR_ese_main_notAssigned", "&"] };

hint parseText format [localize "STR_ese_main_keyChanged", _newName, _newKeys, _currentName, _currentKeys];
saveProfileNamespace;