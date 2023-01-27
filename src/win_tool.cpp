#include <csf/win_tool.h>

extern string confPath;

void Exec(const char* cmd) {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcessA(NULL, (LPSTR)cmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        // printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }
}

int CountRunningProcessByName(const string& processName) {
    int count = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return count;
    }

    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(snapshot, &process)) {
        do {
            if (lstrcmpiA(LPCSTR(process.szExeFile), processName.c_str()) == 0) {
                ++count;
            }
        } while (Process32Next(snapshot, &process));
    }

    CloseHandle(snapshot);
    return count;
}


DWORD WINAPI runLoop(LPVOID lpParam) {
    json config = readConfig(confPath);
    int interval = config["run_loop_interval"].get<int>() * 1000;

    while (true) {
        Sleep(interval);
        const auto& run_loop = config["run_loop"];
        for (const auto& cmd : run_loop) {
            string target = cmd.begin().key();
            string command = cmd.begin().value();
            if (target == "system") {
                system(command.c_str());
            }
            else if (target == "console") {
                global<Level>->runcmd(command.c_str());
            }
        }
    }
    return 0;
}

DWORD WINAPI runCmd(LPVOID lpParam) {
    json config = readConfig(confPath);

    const auto& exec_background_cmd = config["exec_background_cmd"];
    for (const auto& cmd : exec_background_cmd) {
        int delay = atoi(cmd.begin().key().c_str());
        Sleep(delay);
        string command = cmd.begin().value();
        Exec(command.c_str());
    }

    const auto& exec_cmd = config["exec_cmd"];
    for (const auto& cmd : exec_cmd) {
        int delay = atoi(cmd.begin().key().c_str());
        Sleep(delay);
        string command = cmd.begin().value();
        system(command.c_str());
    }
    return 0;
}