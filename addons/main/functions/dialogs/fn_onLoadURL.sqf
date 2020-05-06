params ["_name", "_args"];
_args params ["_control"];

private _data = switch (_name) do {
	case "SettingsDiscord": {
		["Discord", "https://discord.gg/QDGatN2"];
	};

	case "SettingsGitHub": {
		["GitHub Repo", "https://github.com/Heyoxe/Echos-Sandbox-Everywhere"];
	};

	case "SettingsBIForum": {
		["BI Forum Thread", "https://forums.bohemia.net/forums/topic/229039-echos-sandbox-everywhere/"];
	};

	case "SettingsSteam": {
		["Steam", "https://steamcommunity.com/sharedfiles/filedetails/?id=2081120309"];
	};

	case "SettingsAuthorSteam": {
		["Personal Steam", "https://steamcommunity.com/id/a3_echo"];
	};

	// case "SettingsAuthorWebsite": {
	// 	["Personal Website", "https://wwww.heyoxe.ch/"];
	// };

	case "SettingsAuthorGithub": {
		["Personal GitHub", "https://github.com/Heyoxe"];
	};
};

_data params ["_title", "_url"];

private _text = parseText format ["<t color='#3ea6ff'><a href='%2'>%1</a></t>", localize (format ["STR_ese_main_%1", _name]), _url];
_control ctrlSetSTRucturedText _text;