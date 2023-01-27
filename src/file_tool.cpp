#include "file_tool.h"

extern string pluginRoot;

void delFile(const char* fileName) {
    stringstream cmd;
    cmd << "cmd /c del /F /Q " << fileName;
    Exec(cmd.str().c_str());
}

void copyFile(const char* source, const char* dest) {
    stringstream cmd;
    cmd << "cmd /c copy /Y " << source << " " << dest;
    Exec(cmd.str().c_str());
}

string GetPluginRoot(HMODULE hModule) {
    TCHAR dllPath[MAX_PATH];
    GetModuleFileName(hModule, dllPath, MAX_PATH);
    wstring wpath(dllPath);
    wstring_convert<codecvt_utf8<wchar_t>> convert;
    string path = convert.to_bytes(wpath);
    return path.substr(0, path.find_last_of("\\") + 1);
}

string GetServerRoot(HMODULE hModule) {
    string path = GetPluginRoot(hModule);
    return path.substr(0, path.find_last_of("\\", path.find_last_of("\\") - 1) + 1);
}

int DownloadFile(string url, string output) {
    return 0;
    if (!filesystem::exists(output)) {
        cout << "The file " << output << " was not found and is being downloaded manually" << endl;
        string DlCmd = "curl -fsSL \"" + url + "\" -o " + output;
        int retCode = system(DlCmd.c_str());
        if (retCode != 0) {
            cout << "Automatic download failed, please upload the file manually, error code: " << retCode << endl;
        }
        return retCode;
    }
    else {
        return 0;
    }
}

int UnarchiveFile(string filePath, string outputDir) {
    if (!filesystem::exists(filePath)) {
        cout << "The file " << filePath << " was not found." << endl;
        return 1;
    }
    else {
        string unarchiveDataCmd = pluginRoot + "LiteLoader\\7z\\7za.exe -y -o" + outputDir + " x " + filePath;
        return system(unarchiveDataCmd.c_str());
    }
}