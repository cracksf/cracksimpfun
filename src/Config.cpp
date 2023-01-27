#include <csf/Config.h>

extern string serverRoot;
extern string pluginRoot;
extern string confPath;

json readConfig(const string& filepath) {
    ifstream file(filepath);
    json config;
    file >> config;
    return config;
}


string readConfig(const string& path, const string& key) {
    ifstream file(path);
    string line;
    string value;
    while (getline(file, line)) {
        if (line.find(key) == 0) {
            value = line.substr(line.find("=") + 1);
            break;
        }
    }
    file.close();
    return value;
}

void writeConfig(const string& path, const string& key, const string& value) {
    ifstream file(path);
    string line;
    string content;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(key) == 0) {
            line = key + "=" + value;
            found = true;
        }
        content += line + "\n";
    }
    if (!found) {
        content += key + "=" + value + "\n";
    }
    file.close();

    ofstream output(path);
    output << content;
    output.close();
}



void modifyConfigs() {
    json config = readConfig(confPath);

    string serverPropertiesPath = serverRoot + "server.properties";
    string csfcConfigPath = pluginRoot + "csf\\csfc.ini";
    string fakeplayerScriptPath = pluginRoot + "fp\\bin\\FakePlayer.bat";

    string serverPort = readConfig(serverPropertiesPath, "server-port");
    writeConfig(csfcConfigPath, "remote_port", serverPort);

    string javaExePath = pluginRoot + "fp\\jre\\bin\\java.exe";
    writeConfig(fakeplayerScriptPath, "set JAVA_EXE", javaExePath);

    const auto& server_properties = config["server_properties"];
    for (const auto& item : server_properties) {
        writeConfig(serverPropertiesPath, item.begin().key(), item.begin().value());
    }
}