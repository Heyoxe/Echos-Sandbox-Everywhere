#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"


params ["_control", "_index", "_state"];

private _enabled = [false,true]#_state;
SET_MVAR(collaboration,_enabled,false);