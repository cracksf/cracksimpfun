#pragma once
#include "Global.h"

json readConfig(const string& filepath);
json readConfig(const string& filepath);
void writeConfig(const string& path, const string& key, const string& value);
void modifyConfigs();
