#include "script_component.hpp"

ADDON = false;

{
    _x params ["_name", "_func"];
    uiNamespace setVariable [_name, (compileFinal preprocessFileLineNumbers _func)];
    missionNamespace setVariable [_name, (compileFinal preprocessFileLineNumbers _func)];
} forEach [
    ["CBA_statemachine_fnc_createFromConfig", "n\bba\addons\statemachine\fnc_createFromConfig.sqf"],
    ["CBA_statemachine_fnc_clockwork", "n\bba\addons\statemachine\fnc_clockwork.sqf"],
    ["CBA_statemachine_fnc_manualTransition", "n\bba\addons\statemachine\fnc_manualTransition.sqf"]
];

ADDON = true;
