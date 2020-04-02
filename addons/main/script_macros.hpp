//#define DEBUG_SYNCHRONOUS
#include "\n\bba\addons\main\script_macros_common.hpp"

// Default versioning level
#define DEFAULT_VERSIONING_LEVEL 2

#define DGVAR(varName)    if(isNil "BBA_DEBUG_NAMESPACE") then { BBA_DEBUG_NAMESPACE = []; }; if(!(QUOTE(GVAR(varName)) in BBA_DEBUG_NAMESPACE)) then { PUSH(BBA_DEBUG_NAMESPACE, QUOTE(GVAR(varName))); }; GVAR(varName)
#define DVAR(varName)     if(isNil "BBA_DEBUG_NAMESPACE") then { BBA_DEBUG_NAMESPACE = []; }; if(!(QUOTE(varName) in BBA_DEBUG_NAMESPACE)) then { PUSH(BBA_DEBUG_NAMESPACE, QUOTE(varName)); }; varName
#define DFUNC(var1) TRIPLES(ADDON,fnc,var1)
#define DEFUNC(var1,var2) TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)

#undef QFUNC
#undef QEFUNC
#define QFUNC(var1) QUOTE(DFUNC(var1))
#define QEFUNC(var1,var2) QUOTE(DEFUNC(var1,var2))

#define PREP_MODULE(folder) [] call compile preprocessFileLineNumbers QPATHTOF(folder\__PREP__.sqf)

#define BBA_DEPRECATED(arg1,arg2,arg3) WARNING_3("%1 is deprecated. Support will be dropped in version %2. Replaced by: %3",arg1,arg2,arg3)

#define GETMVALUE(var1,var2) getMissionConfigValue [ARR_2(QUOTE(TRIPLES(PREFIX,COMPONENT,var1)),var2)]
#define EGETMVALUE(var1,var2,var3) getMissionConfigValue [ARR_2(QUOTE(TRIPLES(PREFIX,var1,var2)),var3)]

#define SETVAR_SYS(var1,var2) setVariable [ARR_2(QUOTE(TRIPLES(PREFIX,COMPONENT,var1)),var2)]
#define ESETVAR_SYS(var1,var2,var3) setVariable [ARR_2(QUOTE(TRIPLES(PREFIX,var1,var2)),var3)]
#define SETPVAR_SYS(var1,var2) setVariable [ARR_3(QUOTE(TRIPLES(PREFIX,COMPONENT,var1)),var2,true)]
#define ESETPVAR_SYS(var1,var2,var3) setVariable [ARR_3(QUOTE(TRIPLES(PREFIX,var1,var2)),var3,true)]

#define SETVAR(var1,var2,var3) var1 SETVAR_SYS(var2,var3)
#define ESETVAR(var1,var2,var3,var4) var1 ESETVAR_SYS(var2,var3,var4)
#define SETPVAR(var1,var2,var3) var1 SETPVAR_SYS(var2,var3)
#define ESETPVAR(var1,var2,var3,var4) var1 ESETPVAR_SYS(var2,var3,var4)

#define SETMVAR(var1,var2) missionNamespace SETVAR_SYS(var1,var2)
#define ESETMVAR(var1,var2,var3) missionNamespace ESETVAR_SYS(var1,var2,var3)
#define SETMPVAR(var1,var2) missionNamespace SETPVAR_SYS(var1,var2)
#define ESETMPVAR(var1,var2,var3) missionNamespace ESETPVAR_SYS(var1,var2,var3)

#define SETPLVAR(var1,var2) player SETVAR_SYS(var1,var2)
#define ESETPLVAR(var1,var2,var3) player ESETVAR_SYS(var1,var2,var3)
#define SETPLPVAR(var1,var2) player SETPVAR_SYS(var1,var2)
#define ESETPLPVAR(var1,var2,var3) player ESETPVAR_SYS(var1,var2,var3)

#define GETVAR_SYS(var1,var2) getVariable [ARR_2(QUOTE(TRIPLES(PREFIX,COMPONENT,var1)),var2)]
#define EGETVAR_SYS(var1,var2,var3) getVariable [ARR_2(QUOTE(TRIPLES(PREFIX,var1,var2)),var3)]

#define GETVAR(var1,var2,var3) var1 GETVAR_SYS(var2,var3)
#define EGETVAR(var1,var2,var3,var4) var1 EGETVAR_SYS(var2,var3,var4)

#define GETPLVAR(var1,var2) player GETVAR_SYS(var1,var2)
#define EGETPLVAR(var1,var2,var3) player EGETVAR_SYS(var1,var2,var3)

#define GETMVAR(var1,var2) missionNamespace GETVAR_SYS(var1,var2)
#define EGETMVAR(var1,var2,var3) missionNamespace EGETVAR_SYS(var1,var2,var3)


#define QN(var1) '##var1##'

//Script control
#define EXEC_CHECK(ARG) \
private _argUpper = toUpper(#ARG);\
if (isNil QEGVAR(Core,Enabled)) then {\
    EGVAR(Core,Enabled) = EGETMVALUE(Core,Enabled,false);\
};\
if ((_argUpper isEqualto "SERVER") && {(((!isServer) && isMultiplayer) || (!(EGVAR(Core,Enabled))))}) exitWith {}; \
if ((_argUpper isEqualto "CLIENT") && {((!hasinterface) || (!(EGVAR(Core,Enabled))))}) exitWith {};\
if ((_argUpper isEqualto "HC") && {(((hasinterface || isServer) && isMultiplayer) || (!(EGVAR(Core,Enabled))))}) exitWith {};\
if ((_argUpper isEqualto "CLIENTHC") && {(((isDedicated) && isMultiplayer) || (!(EGVAR(Core,Enabled))))}) exitWith {};\
if ((_argUpper isEqualto "SERVERHC") && {(((hasinterface) && isMultiplayer) || (!(EGVAR(Core,Enabled))))}) exitWith {};\
if ((_argUpper isEqualto "ALL") && {(!(EGVAR(Core,Enabled)))}) exitWith {};\
if !(EGVAR(Core,Enabled)) exitWith {}

#define EDEN_CHECK if !(is3DEN) exitwith {}

#define VERSIONNUMBER (EGETMVAR(Version_UpdatedNumber,102))
#define VERSION_CHECK(var1) if (var1 < VERSIONNUMBER) exitwith {}
