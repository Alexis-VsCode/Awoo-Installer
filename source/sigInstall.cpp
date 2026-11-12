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
        inst::ui::mainApp->CreateShowDialog("community.title"_lang,
            "community.patches_disabled"_lang,
            {"common.ok"_lang}, true);
    }
}
