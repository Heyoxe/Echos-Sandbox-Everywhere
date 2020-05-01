#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"

params ["_curator", "_entity"];
if (GET_MVAR(collaboration,false)) then {
	private _curator = getAssignedCuratorLogic player;
	[_curator, [[_entity], true]] remoteExec ["addCuratorEditableObjects", 2];
};