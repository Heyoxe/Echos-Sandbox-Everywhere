#include "\e\echos_shared_library\addons\core\gui_macros.hpp"

#define SET_X(X) x = (X * 311 * safeZoneW) / 1920
#define SET_Y(Y) y = (Y * 56 * safeZoneH) / 1080

#define TAB(NAME,POSITION,TEXT) \
	class NAME: ESL_ControlsGroup { \
		x = (POSITION * 311 * safeZoneW) / 1920; \
		y = (0 * safeZoneH) / 1080; \
		w = (279 * safeZoneW) / 1920; \
		h = (318 * safeZoneH) / 1080; \
		class Controls { \
			class Background: ESL_Background { \
				ESL_POSITION_CT(0,0,279,279); \
				colorBackground[] = ESL_TOCOLOR(60,103,152,1); \
			}; \
			class Icon: ESL_Picture { \
				ESL_POSITION_CT(26,26,228,228); \
				colorBackground[] = ESL_COLOR_WHITE; \
				text = \e\echos_sandbox_everywhere\addons\main\data\images\NAME.png; \
			}; \
			class Text: ESL_Text_Background_Center { \
				ESL_POSITION_CT(0,279,279,39); \
				colorBackground[] = ESL_TOCOLOR(46,74,104,1); \
				colorText[] = ESL_TOCOLOR(215,218,224,1); \
				text = TEXT; \
			}; \
			class Button: ESL_Button { \
				ESL_POSITION_CT(0,0,279,318); \
				colorBackground[] = ESL_COLOR_TRANSPARENT; \
				colorFocused[] = ESL_COLOR_TRANSPARENT; \
				colorBackgroundActive[] = ESL_COLOR_TRANSPARENT; \
				onButtonClick = createDialog #ESE_Main_dialog_##NAME##Menu; \
			}; \
		}; \
	}

class ESE_Main_dialog_MainMenu {
	idd = 283927;
	class Controls {
		class Title: ESL_Title_Center {
			ESL_POSITION(146,302,1627,35);
			colorBackground[] = ESL_TOCOLOR(87,160,242,1);
			text = "Echo's Sandbox Everywhere";
		};
		class Background: ESL_Background {
			ESL_POSITION(146,337,1627,441);
			colorBackground[] = ESL_TOCOLOR(33,37,43,1);
		};

		class Close: ESL_ButtonPicture {
			ESL_POSITION(1738,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,87,87,1);
			colorFocused[] = ESL_TOCOLOR(242,87,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,87,87,1);
			onButtonClick = "closeDialog 2";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Close.png";
		};

		class Tabs: ESL_ControlsGroup {
			ESL_POSITION(199,378,1523,318);
			class Controls {
				TAB(Zeus,0,$STR_ese_main_zeus);
				TAB(Music,1,$STR_ese_main_jukebox);
				TAB(Virtual,2,$STR_ese_main_virtual);
				TAB(Misc,3,$STR_ese_main_misc);
				TAB(Settings,4,$STR_ese_main_settings);
			};
		};
	};
};

#define ACTION(X,Y,NAME,TEXT) class NAME: ESL_Button { \
	x = (X * 311 * safeZoneW) / 1920; \
	y = (Y * 56 * safeZoneH) / 1080; \
	w = (279 * safeZoneW) / 1920; \
	h = (39 * safeZoneH) / 1080; \
	colorBackground[] = ESL_TOCOLOR(46,74,104,1); \
	colorFocused[] = ESL_TOCOLOR(46,74,104,1); \
	colorBackgroundActive[] = ESL_TOCOLOR(46,74,104,1); \
	colorText[] = ESL_TOCOLOR(215,218,224,1); \
	text = TEXT; \
	onMouseButtonDown = [[#NAME, 'Action'], _this] call (uiNamespace getVariable ['ESE_Main_fnc_onMouseButtonDown', {}]); \
}

#define SWITCH(X,Y,NAME,TEXT) class NAME: ESL_Switch { \
	x = (X * 311 * safeZoneW) / 1920; \
	y = (Y * 56 * safeZoneH) / 1080; \
	w = (279 * safeZoneW) / 1920; \
	h = (39 * safeZoneH) / 1080; \
	STRings[] = { TEXT }; \
	checked_STRings[] = { TEXT }; \
	onLoad = [[#NAME], _this] call (uiNamespace getVariable ['ESE_Main_fnc_onLoad', {}]); \
	onMouseButtonDown = [[#NAME, 'Switch'], _this] call (uiNamespace getVariable ['ESE_Main_fnc_onMouseButtonDown', {}]); \
}

#define SSWITCH(X,Y,NAME,TEXT) class NAME: ESL_Switch { \
	x = (X * 311 * safeZoneW) / 1920; \
	y = (Y * 56 * safeZoneH) / 1080; \
	w = (279 * safeZoneW) / 1920; \
	h = (39 * safeZoneH) / 1080; \
	STRings[] = { TEXT }; \
	checked_STRings[] = { TEXT }; \
	onLoad = [[#NAME], _this] call (uiNamespace getVariable ['ESE_Main_fnc_onSLoad', {}]); \
	onMouseButtonDown = [[#NAME, 'Switch'], _this] call (uiNamespace getVariable ['ESE_Main_fnc_onSMouseButtonDown', {}]); \
}

#define LINK(X,Y,NAME) class NAME: ESL_STRucturedText { \
	x = (X * 311 * safeZoneW) / 1920; \
	y = (Y * 56 * safeZoneH) / 1080; \
	w = (279 * safeZoneW) / 1920; \
	h = (39 * safeZoneH) / 1080; \
	colorBackground[] = ESL_TOCOLOR(46,74,104,0); \
	colorText[] = ESL_TOCOLOR(215,218,224,1); \
	size = 0.04; \
	onLoad = [#NAME,_this] call (uiNamespace getVariable ['ESE_Main_fnc_onLoadURL', {}]); \
}

#define TEXT(X,Y,NAME,TEXT) class NAME: ESL_Text { \
	x = (X * 311 * safeZoneW) / 1920; \
	y = (Y * 56 * safeZoneH) / 1080; \
	w = (279 * safeZoneW) / 1920; \
	h = (39 * safeZoneH) / 1080; \
	colorText[] = ESL_TOCOLOR(215,218,224,1); \
	text = TEXT; \
}

#define FORMAT_DETAILS(TEXT, DETAILS) TEXT## ##DETAILS
#define DETAILS(X,Y,NAME,TEXT, DETAILS) class NAME: ESL_Text { \
	x = (X * 311 * safeZoneW) / 1920; \
	y = (Y * 56 * safeZoneH) / 1080; \
	w = (279 * safeZoneW) / 1920; \
	h = (39 * safeZoneH) / 1080; \
	colorText[] = ESL_TOCOLOR(215,218,224,1); \
	text = #FORMAT_DETAILS(TEXT, DETAILS); \
}

class ESE_Main_dialog_ZeusMenu {
	idd = 283928;
	class Controls {
		class Title: ESL_Title_Center {
			ESL_POSITION(146,302,1627,35);
			colorBackground[] = ESL_TOCOLOR(87,160,242,1);
			text = "Echo's Sandbox Everywhere";
		};
		class Background: ESL_Background {
			ESL_POSITION(146,337,1627,441);
			colorBackground[] = ESL_TOCOLOR(33,37,43,1);
		};

		class Close: ESL_ButtonPicture {
			ESL_POSITION(1738,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,87,87,1);
			colorFocused[] = ESL_TOCOLOR(242,87,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,87,87,1);
			onButtonClick = "[] spawn { closeDialog 2; uiSleep 0.001; closeDialog 2 }";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Close.png";
		};

		class Back: ESL_ButtonPicture {
			ESL_POSITION(1703,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,190,87,1);
			colorFocused[] = ESL_TOCOLOR(242,190,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,190,87,1);
			onButtonClick = "closeDialog 2";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Back.png";
		};

		class Actions: ESL_ControlsGroup {
			ESL_POSITION(199,378,1523,318);
			class Controls {
				ACTION(0,0,ZeusAdd,$STR_ese_main_add);
				ACTION(0,1,ZeusReload,$STR_ese_main_reloadZeus);
				SWITCH(0,2,ZeusCollaboration,$STR_ese_main_zeusRTC);
			};
		};
	};
};

class ESE_Main_dialog_MusicMenu {
	idd = 283929;
	class Controls {
		class Title: ESL_Title_Center {
			ESL_POSITION(146,302,1627,35);
			colorBackground[] = ESL_TOCOLOR(87,160,242,1);
			text = "Echo's Sandbox Everywhere";
		};
		class Background: ESL_Background {
			ESL_POSITION(146,337,1627,441);
			colorBackground[] = ESL_TOCOLOR(33,37,43,1);
		};

		class Close: ESL_ButtonPicture {
			ESL_POSITION(1738,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,87,87,1);
			colorFocused[] = ESL_TOCOLOR(242,87,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,87,87,1);
			onButtonClick = "[] spawn { closeDialog 2; uiSleep 0.001; closeDialog 2 }";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Close.png";
		};

		class Back: ESL_ButtonPicture {
			ESL_POSITION(1703,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,190,87,1);
			colorFocused[] = ESL_TOCOLOR(242,190,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,190,87,1);
			onButtonClick = "closeDialog 2";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Back.png";
		};

		class Actions: ESL_ControlsGroup {
			ESL_POSITION(199,378,1523,318);
			class Controls {
				TEXT(0,0,MusicGenres,$STR_ese_main_musicSelect);
				SWITCH(0,1,MusicActionAdd,$STR_ese_main_action);
				SWITCH(0,2,MusicCalmAdd,$STR_ese_main_calm);
				SWITCH(0,3,MusicCombatAdd,$STR_ese_main_combat);
				SWITCH(0,4,MusicLeadAdd,$STR_ese_main_lead);
				SWITCH(0,5,MusicSafeAdd,$STR_ese_main_safe);
				SWITCH(0,6,MusicStealthAdd,$STR_ese_main_stealth);
			};
		};
	};
};

class ESE_Main_dialog_VirtualMenu {
	idd = 283930;
	class Controls {
		class Title: ESL_Title_Center {
			ESL_POSITION(146,302,1627,35);
			colorBackground[] = ESL_TOCOLOR(87,160,242,1);
			text = "Echo's Sandbox Everywhere";
		};
		class Background: ESL_Background {
			ESL_POSITION(146,337,1627,441);
			colorBackground[] = ESL_TOCOLOR(33,37,43,1);
		};

		class Close: ESL_ButtonPicture {
			ESL_POSITION(1738,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,87,87,1);
			colorFocused[] = ESL_TOCOLOR(242,87,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,87,87,1);
			onButtonClick = "[] spawn { closeDialog 2; uiSleep 0.001; closeDialog 2 }";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Close.png";
		};

		class Back: ESL_ButtonPicture {
			ESL_POSITION(1703,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,190,87,1);
			colorFocused[] = ESL_TOCOLOR(242,190,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,190,87,1);
			onButtonClick = "closeDialog 2";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Back.png";
		};

		class Actions: ESL_ControlsGroup {
			ESL_POSITION(199,378,1523,318);
			class Controls {
				ACTION(0,0,VirtualGarage,$STR_ese_main_virtualGarage);
				class VirtualDeleteLast: ESL_Button {
					x = (0 * 311 * safeZoneW) / 1920;
					y = (1 * 56 * safeZoneH) / 1080;
					w = (279 * safeZoneW) / 1920;
					h = (39 * safeZoneH) / 1080;
					colorBackground[] = ESL_TOCOLOR(46,74,104,1);
					colorFocused[] = ESL_TOCOLOR(46,74,104,1);
					colorBackgroundActive[] = ESL_TOCOLOR(46,74,104,1);
					colorText[] = ESL_TOCOLOR(215,218,224,1);
					text = $STR_ese_main_deleteLast;
					onLoad = "if ((missionNamespace getVariable ['ESE_Main_var_lastVehicle', objNull]) isEqualTo objNull) then { (_this#0) ctrlEnable false; }";
					onMouseButtonDown = "[['VirtualDeleteLast'], _this] call (uiNamespace getVariable ['ESE_Main_fnc_onMouseButtonDown', {}])";
				};
				ACTION(0,2,VirtualBI,$STR_ese_main_biArsenal);
				class VirtualACE: ESL_Button {
					x = (0 * 311 * safeZoneW) / 1920;
					y = (3 * 56 * safeZoneH) / 1080;
					w = (279 * safeZoneW) / 1920;
					h = (39 * safeZoneH) / 1080;
					colorBackground[] = ESL_TOCOLOR(46,74,104,1);
					colorFocused[] = ESL_TOCOLOR(46,74,104,1);
					colorBackgroundActive[] = ESL_TOCOLOR(46,74,104,1);
					colorText[] = ESL_TOCOLOR(215,218,224,1);
					text = $STR_ese_main_aceArsenal;
					onLoad = "if !('ace_arsenal' in activatedAddons) then { (_this#0) ctrlEnable false; (_this#0) ctrlShow false; }";
					onMouseButtonDown = "[['VirtualACE'], _this] call (uiNamespace getVariable ['ESE_Main_fnc_onMouseButtonDown', {}])";
				};
			};
		};
	};
};

class ESE_Main_dialog_MiscMenu {
	idd = 283931;
	class Controls {
		class Title: ESL_Title_Center {
			ESL_POSITION(146,302,1627,35);
			colorBackground[] = ESL_TOCOLOR(87,160,242,1);
			text = "Echo's Sandbox Everywhere";
		};
		class Background: ESL_Background {
			ESL_POSITION(146,337,1627,441);
			colorBackground[] = ESL_TOCOLOR(33,37,43,1);
		};

		class Close: ESL_ButtonPicture {
			ESL_POSITION(1738,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,87,87,1);
			colorFocused[] = ESL_TOCOLOR(242,87,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,87,87,1);
			onButtonClick = "[] spawn { closeDialog 2; uiSleep 0.001; closeDialog 2 }";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Close.png";
		};

		class Back: ESL_ButtonPicture {
			ESL_POSITION(1703,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,190,87,1);
			colorFocused[] = ESL_TOCOLOR(242,190,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,190,87,1);
			onButtonClick = "closeDialog 2";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Back.png";
		};

		class Actions: ESL_ControlsGroup {
			ESL_POSITION(199,378,1523,318);
			class Controls {
				ACTION(0,0,MiscTeleport,$STR_ese_main_teleport);
				SWITCH(0,1,MiscInvincibility,$STR_ese_main_invincibility);
				SWITCH(0,2,MiscNoFatigue,$STR_ese_main_noFatigue);
				TEXT(1,0,MiscWeapons,$STR_ese_main_weapons);
				SWITCH(1,1,MiscUnlimitedAmmo,$STR_ese_main_unlimitedAmmo);
				SWITCH(1,2,MiscNoRecoil,$STR_ese_main_noRecoil);
				SWITCH(1,3,MiscRapidFire,$STR_ese_main_rapidFire);
				SWITCH(1,4,MiscSteadyAim,$STR_ese_main_steadyAim);
			};
		};
	};
};


class ESE_Main_dialog_SettingsMenu {
	idd = 283932;
	class Controls {
		class Title: ESL_Title_Center {
			ESL_POSITION(146,302,1627,35);
			colorBackground[] = ESL_TOCOLOR(87,160,242,1);
			text = "Echo's Sandbox Everywhere";
		};
		class Background: ESL_Background {
			ESL_POSITION(146,337,1627,441);
			colorBackground[] = ESL_TOCOLOR(33,37,43,1);
		};

		class Close: ESL_ButtonPicture {
			ESL_POSITION(1738,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,87,87,1);
			colorFocused[] = ESL_TOCOLOR(242,87,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,87,87,1);
			onButtonClick = "[] spawn { closeDialog 2; uiSleep 0.001; closeDialog 2 }";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Close.png";
		};

		class Back: ESL_ButtonPicture {
			ESL_POSITION(1703,302,35,35);
			colorBackground[] = ESL_TOCOLOR(242,190,87,1);
			colorFocused[] = ESL_TOCOLOR(242,190,87,1);
			colorBackgroundActive[] = ESL_TOCOLOR(242,190,87,1);
			onButtonClick = "closeDialog 2";
			text = "\e\echos_sandbox_everywhere\addons\main\data\images\Back.png";
		};

		class Actions: ESL_ControlsGroup {
			ESL_POSITION(199,378,1523,318);
			class Controls {
				TEXT(0,0,SettingsContact,$STR_ese_main_links);
				LINK(0,1,SettingsDiscord);
				LINK(0,2,SettingsGitHub);
				LINK(0,3,SettingsBIForum);
				LINK(0,4,SettingsSteam);

				TEXT(1,0,SettingsSettings,$STR_ese_main_settingsSettings);
				SSWITCH(1,1,EscapeMenuText,$STR_ese_main_escapeMenuText);

				TEXT(2,0,SettingsInformations,$STR_ese_main_author);
				TEXT(2,1,SettingsAuthor,$STR_ese_main_authorName);
				DETAILS(2,2,SettingsAuthorDiscord,"Discord: ","Heyoxe#0557");
				// LINK(2,3,SettingsAuthorWebsite);
				LINK(2,3,SettingsAuthorGithub);
				LINK(2,4,SettingsAuthorSteam);

				TEXT(3,0,SettingsHelp,$STR_ese_main_help);
				ACTION(3,1,SettingsAssign,$STR_ese_main_keys);

				TEXT(4,0,SettingsDebug,$STR_ese_main_debug);
				DETAILS(4,1,SettingsVersion,"Version: ", MAJOR.MINOR.PATCH);
				// DETAILS(2,2,SettingsHash,"Hash", "ab43ccd6");
			};
		};
	};
};