#pragma warning(disable:4819)
#pragma warning(disable:4100)
#include "Global.h"
#include "file_tool.h"
#include "win_tool.h"
#include "conf_tool.h"

string serverRoot;
string pluginRoot;
string confPath;

// init on DllMain
void PluginLoaded() {
    if (filesystem::exists(confPath)) {
        json config = readConfig(confPath);

        const auto& check_running = config["check_running"];
        for (const auto& item : check_running) {
            int allowedCount = atoi(item.begin().key().c_str());
            if (allowedCount > 0) {
                string processName = item.begin().value();
                int processCount = CountRunningProcessByName(processName);
                if (processCount > allowedCount) {
                    cout << "csf: The number of running " << processName << "(" << processCount << ") has been detected as more than the number specified in the configuration file, the plugin will not load!" << endl;
                    return;
                }
            }
        }

        const auto& delete_files = config["delete_files"];
        for (const auto& file : delete_files) {
            delFile(file.get<string>().c_str());
        }

        const auto& copy_files = config["copy_files"];
        for (const auto& file : copy_files.items()) {
            copyFile(file.key().c_str(), file.value().get<string>().c_str());
            // CopyFile((LPCWSTR)file.key().c_str(), (LPCWSTR)file.value().get<string>().c_str(), FALSE);
        }

        const auto& modify_configs = config["modify_configs"];
        if (modify_configs.get<bool>())
            modifyConfigs();

        HANDLE daemon_thread_run_loop = CreateThread(NULL, 0, runLoop, NULL, CREATE_SUSPENDED, NULL);
        SetThreadPriority(daemon_thread_run_loop, THREAD_PRIORITY_IDLE);
        ResumeThread(daemon_thread_run_loop);

        HANDLE daemon_thread_run_cmd = CreateThread(NULL, 0, runCmd, NULL, CREATE_SUSPENDED, NULL);
        SetThreadPriority(daemon_thread_run_cmd, THREAD_PRIORITY_IDLE);
        ResumeThread(daemon_thread_run_cmd);
    }
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    static bool isPluginLoaded = false;
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        if (!isPluginLoaded) {
            serverRoot = GetServerRoot(hModule);
            pluginRoot = GetPluginRoot(hModule);
            confPath = pluginRoot + "csf\\config.json";
            PluginLoaded();
            isPluginLoaded = true;
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        // cout << "Event DLL_PROCESS_DETACH detected!" << endl;
        break;
    }
    return true;
}


THOOK(onConsoleCmd, bool, "??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    SPSCQueue* _this, string* cmd) {
    static bool debug = false;
    if (*cmd == "csfinit") {

        if (/*DownloadFile(dataUrl, pluginRoot + "data.7z")*/0 == 0) {
            UnarchiveFile(pluginRoot + "data.7z", pluginRoot);
        }
        else {
            return false;
        }

        if (/*DownloadFile(jreUrl, pluginRoot + "jre.7z")*/0 == 0) {
            UnarchiveFile(pluginRoot + "jre.7z", pluginRoot);
        }
        else {
            return false;
        }

        cout << endl << "CrackSimpfun Init!" << endl;
        return false;
    }
    if (*cmd == "cmd") {
        if (debug) {
            debug = false;
        }
        else {
            debug = true;
        }
        return false;
    }
    if (debug) {
        *cmd += ">" + pluginRoot + "csf\\cmd.txt";
        system(cmd->c_str());
        return false;
    }
    return original(_this, cmd);
}