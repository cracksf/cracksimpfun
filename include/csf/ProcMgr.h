#pragma once
#include "Global.h"
#include "Config.h"

void runCmdAsync(const char* cmd);
int countRunningProcessByName(const string& processName);
DWORD WINAPI runLoop(LPVOID lpParam);
DWORD WINAPI runCmdFromConf(LPVOID lpParam);