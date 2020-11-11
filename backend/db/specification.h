#ifndef QUADROBANK_SPECIFICATION_H
#define QUADROBANK_SPECIFICATION_H

#include <functional>
#include <utility>
#include "../utils/non_copying.h"
#include "../account/model/account.h"

using std::string;
using std::vector;
using std::function;

template<class T>
class Specification : public NonCopying {

private:

    const function<bool(const T &)> _filter;
    const string _where;
    const vector<string> _params;

public:

    explicit Specification(
            const function<bool(const T &)> filter,
            string where = "",
            vector<string> params = {}
    ) :
            _filter(std::move(filter)),
            _where(std::move(where)),
            _params(std::move(params)) {};

    bool filter(const T &t) const {
        return _filter(t);
    }

    const string &get_where() const {
        return _where;
    }

    const vector<string> &get_params() const {
        return _params;
    }

};

#endif //QUADROBANK_SPECIFICATION_H
