#include "script_component.hpp"

class CfgPatches {
    class bba_statemachine {
        name = CSTRING(component);
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "A3_Data_F_Tank_Loadorder",
            "BBA_Main"
        };
        author = "$STR_CBA_Author";
        authors[] = {"PiZZADOX"};
        url = "$STR_CBA_URL";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
