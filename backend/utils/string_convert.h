#ifndef QUADROBANK_STRING_CONVERT_H
#define QUADROBANK_STRING_CONVERT_H

#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::to_string;

inline string to_param(const double p) {
    stringstream ss;
    ss << p;
    return ss.str();
}

inline string to_param(const int p){
    return to_string(p);
}

inline string to_param(const string& p){
    return "'" + p + "'";
}

inline string to_param(const time_t p){
    return to_string(p);
}

inline string to_param(const bool p){
    return p ? "1" : "0";
}

#endif //QUADROBANK_STRING_CONVERT_H
