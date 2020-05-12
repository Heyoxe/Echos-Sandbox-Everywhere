#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"

params ["_data", "_args"];
_data params ["_type"];
_args params ["_control"];

private _var = format ["ESE_Main_var_%1", _type];
private _state = profileNamespace getVariable [_var, true];
_control ctrlSetChecked [0, _state];