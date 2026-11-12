#include <curl/curl.h>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include "util/curl.hpp"
#include "util/config.hpp"
#include "util/error.hpp"
#include "ui/instPage.hpp"

static size_t writeDataFile(void *ptr, size_t size, size_t nmemb, void *stream) {
  return fwrite(ptr, 1, size * nmemb, (FILE *)stream);
}

size_t writeDataBuffer(char *ptr, size_t size, size_t nmemb, void *userdata) {
    std::ostringstream *stream = (std::ostringstream*)userdata;
    size_t count = size * nmemb;
    stream->write(ptr, count);
    return count;
}

int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    if (ultotal) {
        int uploadProgress = (int)(((double)ulnow / (double)ultotal) * 100.0);
        inst::ui::instPage::setInstBarPerc(uploadProgress);
    } else if (dltotal) {
        int downloadProgress = (int)(((double)dlnow / (double)dltotal) * 100.0);
        inst::ui::instPage::setInstBarPerc(downloadProgress);
    }
    return 0;
}

namespace inst::curl {
    bool downloadFile (const std::string ourUrl, const char *pagefilename, long timeout, bool writeProgress) {
        CURL *curl_handle;
        CURLcode result;
        FILE *pagefile;
        
        if (!pagefilename) return false;
        pagefile = fopen(pagefilename, "wb");
        if (!pagefile) return false;
        if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) {
            fclose(pagefile);
            return false;
        }
        curl_handle = curl_easy_init();
        if (!curl_handle) {
            fclose(pagefile);
            curl_global_cleanup();
            return false;
        }
        
        curl_easy_setopt(curl_handle, CURLOPT_URL, ourUrl.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "Awoo-Installer");
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYHOST, 2L);
        curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT_MS, timeout);
        curl_easy_setopt(curl_handle, CURLOPT_CONNECTTIMEOUT_MS, timeout);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, writeDataFile);
        if (writeProgress) curl_easy_setopt(curl_handle, CURLOPT_XFERINFOFUNCTION, progress_callback);
        
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);
        result = curl_easy_perform(curl_handle);
        
        curl_easy_cleanup(curl_handle);
        curl_global_cleanup();
        if (fclose(pagefile) != 0) return false;
        if (result != CURLE_OK) std::remove(pagefilename);

        if (result == CURLE_OK) return true;
        else {
            LOG_DEBUG(curl_easy_strerror(result));
            return false;
        }
    }

    std::string downloadToBuffer (const std::string ourUrl, int firstRange, int secondRange, long timeout) {
        CURL *curl_handle;
        CURLcode result;
        std::ostringstream stream;
        
        if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) return "";
        curl_handle = curl_easy_init();
        if (!curl_handle) {
            curl_global_cleanup();
            return "";
        }
        
        curl_easy_setopt(curl_handle, CURLOPT_URL, ourUrl.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "Awoo-Installer");
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYHOST, 2L);
        curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT_MS, timeout);
        curl_easy_setopt(curl_handle, CURLOPT_CONNECTTIMEOUT_MS, timeout);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, writeDataBuffer);
        const std::string ourRange = std::to_string(firstRange) + "-" + std::to_string(secondRange);
        if (firstRange && secondRange) {
            curl_easy_setopt(curl_handle, CURLOPT_RANGE, ourRange.c_str());
        }
        
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &stream);
        result = curl_easy_perform(curl_handle);
        
        curl_easy_cleanup(curl_handle);
        curl_global_cleanup();

        if (result == CURLE_OK) return stream.str();
        else {
            LOG_DEBUG(curl_easy_strerror(result));
            return "";
        }
    }
}