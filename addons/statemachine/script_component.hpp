#define COMPONENT statemachine
#include "\n\bba\addons\main\script_mod.hpp"
#include "\n\bba\addons\main\script_macros.hpp"

// #define DISABLE_COMPILE_CACHE
// #define DEBUG_MODE_FULL
// #define STATEMACHINE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_STATEMACHINE
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_STATEMACHINE
    #define DEBUG_SETTINGS DEBUG_SETTINGS_STATEMACHINE
#endif

#define TRANSITIONS(var) (var + "_transitions")
#define EVENTTRANSITIONS(var) (var + "_eventTransitions")
#define ONSTATE(var) (var + "_onState")
#define ONSTATEENTERED(var) (var + "_onStateEntered")
#define ONSTATELEAVING(var) (var + "_onStateLeaving")
#define GET_FUNCTION(var,cfg) private var = getText (cfg); \
    if (isNil var) then { \
        var = compile var; \
    } else { \
        var = missionNamespace getVariable var;\
    }
