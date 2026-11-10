#include <switch.h>
#include "util/error.hpp"
#include "ui/MainApplication.hpp"
#include "util/curl.hpp"
#include "util/util.hpp"
#include "util/unzip.hpp"
#include "util/config.hpp"
#include "util/lang.hpp"

namespace inst::ui {
    extern MainApplication *mainApp;
}

namespace sig {
    void installSigPatches () {
        inst::ui::mainApp->CreateShowDialog("Community preview",
            "External patch downloads are disabled in this preview. Manage system components separately.",
            {"common.ok"_lang}, true);
    }
}
