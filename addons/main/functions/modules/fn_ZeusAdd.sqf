#include "\e\echos_sandbox_everywhere\addons\main\addon.hpp"
#include "\e\echos_shared_library\addons\core\script_macros.hpp"


params ["_control"];

private _curator = getAssignedCuratorLogic player;
private _objects = (allMissionObjects "all") - allCurators;
[_curator, [_objects, true]] remoteExec ["addCuratorEditableObjects", 2];