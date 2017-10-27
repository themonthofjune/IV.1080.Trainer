// std includes
#include <windows.h>
#include <stdio.h>
#include <string>

// scripthook includes
#include "ScriptHook/ScriptHookManager.h"
#include "ScriptHook/Log.h"
#include "ScriptHook/ScriptThread.h"
#include "ScriptHook/ScriptingEnums.h"
#include "ScriptHook/Scripting.h"

// our includes
#include "Menus.h"
#include "Globals.h"
#include "Utils.h"

// our libs
#pragma comment(lib, "Release/ScriptHook.lib")
#pragma comment(lib, "User32.lib")

// lazy
using namespace Scripting;