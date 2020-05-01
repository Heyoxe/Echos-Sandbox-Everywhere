#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"

if !(missionNamespace getVariable [QVAR(cpreInit), false]) then {
	call (uiNamespace getVariable ["ESE_Main_fnc_preInit", {}]);
};

if !(missionNamespace getVariable [QVAR(cpostInit), false]) then {
	call (uiNamespace getVariable ["ESE_Main_fnc_postInit", {}]);
};