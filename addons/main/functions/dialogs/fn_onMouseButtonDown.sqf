#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"


params ["_data", "_args"];
_data params ["_type", "_mode"];
_args params ["_control", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];

private _func = format ["ESE_Main_fnc_%1", _type];
_args call (uiNamespace getVariable [_func, {}]);

private _var = format ["ESE_Main_var_%1", _type];
private _value = missionNamespace getVariable [_var, false];
missionNamespace setVariable [_var, !_value, false];
