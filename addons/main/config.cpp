#include "addon.hpp"
class CfgPatches {
    class PATCH_CNAME {
        name = PATCH_BNAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "A3_Ui_F", "ESL_Core_E" };
        author = "Heyoxe";
        url = "";
    };
};

enableDebugConsole = 2;


class CfgEFunctions {
    class MOD {
        prefix = "E";
        path = "echos_sandbox_everywhere";
        class main {
            class system {
                class postInit {
                    postInit = 1;
                };
                class preInit {
					preInit = 1;
				};

				class reInit {};
            };
			class dialogs {
				class onLoadURL {};
				class onLoad {};
				class onMouseButtonDown {};
				class onCheckBoxesSelChanged {};

				class onHelpLoad {};
				class onSLoad {};
				class onSMouseButtonDown {};
			};

			class events {
				class onCuratorObjectPlaced {};
				class onMusicSelChanged {};
				class onTeleport {};
			};

			class modules {
				class MiscTeleport {};
				class MiscInvincibility {};
				class MiscNoFatigue {};
				class MiscUnlimitedAmmo {};
				class MiscNoRecoil {};
				class MiscRapidFire {};
				class MiscSteadyAim {};

				class MusicActionAdd {};
				class MusicCalmAdd {};
				class MusicCombatAdd {};
				class MusicLeadAdd {};
				class MusicSafeAdd {};
				class MusicStealthAdd {};

				class SettingsAssign {};

				class VirtualACE {};
				class VirtualBI {};
				class VirtualGarage {};
				class VirtualDeleteLast {};

				class ZeusAdd {};
				class ZeusCollaboration {};
				class ZeusReload {};
			};
        };
    };
};

#include "layouts\MainMenu.hpp"

class RscButtonMenu;
class RscStandardDisplay;
class RscStructuredText;

class ESELoader: RscButtonMenu {
	idc = -1;
	disabled = 1;
	text = "Load ESE";
	tooltip = "Force the loading process of Echo's Sandbox Everywhere";
	x = "35 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)";
	y = "23 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
	h = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = { 0, 0, 0, 0 };

	onLoad = "call (uiNamespace getVariable ['ESE_Main_fnc_reInit', {}])";
};

class ESEHelper: RscStructuredText {
	idc = -1;
	disabled = 1;
	text = "";
	tooltip = "";
	x = "10 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)";
	y = "23 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "65 * (((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = { 0, 0, 0, 0 };
	onLoad = "_this call (uiNamespace getVariable ['ESE_Main_fnc_onHelpLoad', {}])";
};

class RscDisplayInterrupt: RscStandardDisplay {
	class Controls {
		class ButtonLoadESE: ESELoader {};
		class ButtonHelpESE: ESEHelper {};
	};
};

class RscDisplayMovieInterrupt: RscStandardDisplay {
	class Controls {
		class ButtonLoadESE: ESELoader {};
		class ButtonHelpESE: ESEHelper {};
	};
};

class RscDisplayMPInterrupt: RscStandardDisplay {
	class Controls {
		class ButtonLoadESE: ESELoader {};
		class ButtonHelpESE: ESEHelper {};
	};
};