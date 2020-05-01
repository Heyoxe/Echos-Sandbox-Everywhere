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
			};

			class events {
				class onCuratorObjectPlaced {};
				class onMusicSelChanged {};
			};

			class modules {
				class MiscTeleport {};

				class MusicActionAdd {};
				class MusicCalmAdd {};
				class MusicCombatAdd {};
				class MusicLeadAdd {};
				class MusicSafeAdd {};
				class MusicStealthAdd {};

				class VirtualACE {};
				class VirtualBI {};
				class VirtualGarage {};

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

class RscButtonMenuESE: RscButtonMenu {
	idc = -1;
	disabled = 1;
	text = "Load ESE";
	tooltip = "Force the loading process of Echo's Sandbox Everywhere";
	x = "35 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)";
	y = "23.0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
	h = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = { 0, 0, 0, 0 };

	onLoad = "call (uiNamespace getVariable ['ESE_Main_fnc_reInit', {}])";
};

class RscDisplayInterrupt: RscStandardDisplay {
	class Controls {
		class ButtonLoadESE: RscButtonMenuESE {};
	};
};

class RscDisplayMovieInterrupt: RscStandardDisplay {
	class Controls {
		class ButtonLoadESE: RscButtonMenuESE {};
	};
};

class RscDisplayMPInterrupt: RscStandardDisplay {
	class Controls {
		class ButtonLoadESE: RscButtonMenuESE {};
	};
};