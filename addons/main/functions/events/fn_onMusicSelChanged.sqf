private _configs = "true" configClasses (configFile >> "CfgMusic");
private _musics = [];
{
	private _class = toLower getText (_x >> "musicClass");
	private _theme = toLower getText (_x >> "theme");
	private _name = configName _x;
	_musics pushBack [_name, _class, _theme];
} forEach _configs;

private _types = (missionNamespace getVariable ["ESE_Main_var_MusicTypes", []]) apply { toLower _x };
private _selected = [];
{
	private _genre = _x;
	private _corresponding = _musics select { _genre in _x };
	_selected append _corresponding;
} forEach _types;

private _names = _selected apply { _x#0 };
missionNamespace setVariable ["ESE_Main_var_MusicSelection", _names, false];