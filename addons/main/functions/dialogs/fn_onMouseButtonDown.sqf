#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"


params ["_data", "_args"];
_data params ["_type"];
_args params ["_control", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];


private _func = format ["ESE_Main_fnc_%1", _type];
_args call (uiNamespace getVariable [_func, {}]);