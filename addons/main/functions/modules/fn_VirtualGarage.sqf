/************************/
/*		LEGACY CODE		*/
/************************/

[] spawn {
	closeDialog 2; 
	uiSleep 0.001; 
	closeDialog 2;

    private _pos = ASLToATL (player getPos [10, getDir player]);
    BIS_fnc_garage_center = createVehicle [ "Land_HelipadEmpty_F", _pos, [], 0, "NONE"]; 
    ["Open", true ] call BIS_fnc_garage; 
    uiSleep 1;
    waitUntil {(uiNamespace getVariable ["BIS_fnc_arsenal_cam", false]) isEqualTo false};
    private _veh = BIS_fnc_garage_center nearEntities [["LandVehicle", "Air", "Ship"], 20] select 0;
    private _vehClass = typeOf _veh;
    private _vehPos = getPosATL _veh;
    private _addedVariant = [];
    private _addedAnimations = [];
    _addedVariant = getObjectTextures _veh;
    private _allAnimations = animationNames _veh;
    {
        _state = _veh animationPhase _x;
        _addedAnimations pushBack _x;
        _addedAnimations pushBack _state;
    } forEach _allAnimations;
    deleteVehicle _veh;
    _veh = createVehicle [_vehClass, _vehPos,[], 0, "NONE"];
    [
        _veh,
        false, 
        _addedAnimations
    ] call BIS_fnc_initVehicle;

    {
        _veh setObjectTextureGlobal [_forEachIndex, _x];
    } forEach _addedVariant;
};