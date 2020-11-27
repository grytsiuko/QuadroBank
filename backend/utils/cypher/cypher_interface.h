
#ifndef QUADROBANK_CYPHER_INTERFACE_H
#define QUADROBANK_CYPHER_INTERFACE_H

#include <string>
#include <utility>

using std::string;

class CypherInterface{

public:
    const string encrypt(string src) const {
        return _encrypt(std::move(src));
    }

    const string decrypt(string src) const {
        return _decrypt(std::move(src));
    }

private:
    virtual const string _encrypt(string src) const = 0;

    virtual const string _decrypt(string src) const = 0;

};

#endif //QUADROBANK_CYPHER_INTERFACE_H
