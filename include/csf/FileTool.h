#pragma once
#include "Global.h"
#include "ProcMgr.h"

void delFile(const char* fileName);
void copyFile(const char* source, const char* dest);
string GetPluginRoot(HMODULE hModule);
string GetServerRoot(HMODULE hModule);
int DownloadFile(string url, string output);
int UnarchiveFile(string filePath, string outputDir);
