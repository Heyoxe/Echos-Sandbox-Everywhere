#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"

if !(missionNamespace getVariable ["ESE_main_var_cpreInit", false]) then {
	call (uiNamespace getVariable ["ESE_Main_fnc_preInit", {}]);
};

if !(missionNamespace getVariable ["ESE_main_var_cpostInit", false]) then {
	call (uiNamespace getVariable ["ESE_Main_fnc_postInit", {}]);
};