#pragma once
#include "Global.h"
#include "ProcMgr.h"

void delFile(const char* fileName);
void copyFile(const char* source, const char* dest);
string getPluginRoot(HMODULE hModule);
string getServerRoot(HMODULE hModule);
int downloadFile(string url, string output);
int unarchiveFile(string filePath, string outputDir);
