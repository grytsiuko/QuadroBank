#ifndef QUADROBANK_STRING_CONVERT_H
#define QUADROBANK_STRING_CONVERT_H

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

inline string double_string(const double a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

#endif //QUADROBANK_STRING_CONVERT_H
