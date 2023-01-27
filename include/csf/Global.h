#pragma once

#include <Windows.h>
#include <TlHelp32.h>

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

#include "mc/json_tool.h"

#include "mc/tool.h"
#include "mc/Level.h"

using namespace std;

extern string serverRoot;
extern string pluginRoot;
extern string confPath;