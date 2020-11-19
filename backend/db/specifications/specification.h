
#ifndef QUADROBANK_SPECIFICATION_H
#define QUADROBANK_SPECIFICATION_H


#include <backend/utils/non_copying.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

template<class T>
class Specification : public NonCopying {

public:

    bool filter(const T &t) const {
        return _filter(t);
    }

    const string &get_where() const {
        return _get_where();
    }

    const vector<string> &get_params() const {
        return _get_params();
    }

private:

    virtual bool _filter(const T &t) const = 0;

    virtual const string &_get_where() const = 0;

    virtual const vector<string> &_get_params() const = 0;

};


#endif //QUADROBANK_SPECIFICATION_H
