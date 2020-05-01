private _genre = "Safe";
private _types = missionNamespace getVariable ["ESE_Main_var_MusicTypes", []];
if (_genre in _types) then {
	_types = _types - [_genre];
} else {
	_types = _types + [_genre];
};
missionNamespace setVariable ["ESE_Main_var_MusicTypes", _types, false];
call ESE_Main_fnc_onMusicSelChanged;