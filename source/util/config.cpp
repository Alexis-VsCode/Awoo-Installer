#include <fstream>
#include <iomanip>
#include "util/config.hpp"
#include "util/json.hpp"

namespace inst::config {
    std::string gAuthKey;
    std::string sigPatchesUrl;
    std::string lastNetUrl;
    std::vector<std::string> updateInfo;
    int languageSetting;
    bool autoUpdate;
    bool deletePrompt;
    bool gayMode;
    bool ignoreReqVers;
    bool overClock;
    bool usbAck;
    bool validateNCAs;

    void setConfig() {
        nlohmann::json j = {
            {"autoUpdate", autoUpdate},
            {"deletePrompt", deletePrompt},
            {"gAuthKey", gAuthKey},
            {"gayMode", gayMode},
            {"ignoreReqVers", ignoreReqVers},
            {"languageSetting", languageSetting},
            {"overClock", overClock},
            {"sigPatchesUrl", sigPatchesUrl},
            {"usbAck", usbAck},
            {"validateNCAs", validateNCAs},
            {"lastNetUrl", lastNetUrl}
        };
        std::ofstream file(inst::config::configPath);
        file << std::setw(4) << j << std::endl;
    }

    void parseConfig() {
        // Valores seguros al iniciar, incluso si existe un archivo antiguo o incompleto.
        gAuthKey.clear();
        sigPatchesUrl.clear();
        lastNetUrl = "https://";
        languageSetting = 99; // Idioma de la consola.
        autoUpdate = false;
        deletePrompt = true;
        gayMode = false;
        ignoreReqVers = false;
        overClock = false;
        usbAck = false;
        validateNCAs = true;

        std::ifstream file(inst::config::configPath);
        if (!file.is_open()) {
            setConfig();
            return;
        }

        // No sobrescribir un archivo dañado; conservarlo para diagnosticar el fallo.
        try {
            nlohmann::json j;
            file >> j;
            if (!j.is_object()) return;
            const auto getBool = [&j](const char* name, bool& value) {
                auto it = j.find(name);
                if (it != j.end() && it->is_boolean()) value = it->get<bool>();
            };
            const auto getString = [&j](const char* name, std::string& value) {
                auto it = j.find(name);
                if (it != j.end() && it->is_string()) value = it->get<std::string>();
            };
            getBool("deletePrompt", deletePrompt);
            getString("gAuthKey", gAuthKey);
            getBool("gayMode", gayMode);
            getBool("ignoreReqVers", ignoreReqVers);
            getBool("overClock", overClock);
            getBool("usbAck", usbAck);
            getBool("validateNCAs", validateNCAs);
            getString("lastNetUrl", lastNetUrl);

            auto lang = j.find("languageSetting");
            if (lang != j.end() && lang->is_number_integer()) {
                languageSetting = lang->get<int>();
            }
            // Las opciones automáticas de actualización permanecen deshabilitadas.
            autoUpdate = false;
        }
        catch (...) {
            // Conservar la configuración original en disco; usar solo los valores seguros.
        }
    }
}
