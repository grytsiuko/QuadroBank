#include "log_service.h"

void LogService::log(const string &prefix, const string &text) const {
    cout << "### LOGGER: " << prefix << " ###: " << text << "\n";
}