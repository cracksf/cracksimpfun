#pragma once
#include "Global.h"
#include "conf_tool.h"

void Exec(const char* cmd);
int CountRunningProcessByName(const string& processName);
DWORD WINAPI runLoop(LPVOID lpParam);
DWORD WINAPI runCmd(LPVOID lpParam);