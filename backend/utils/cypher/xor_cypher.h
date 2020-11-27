
#ifndef QUADROBANK_XOR_CYPHER_H
#define QUADROBANK_XOR_CYPHER_H

#include "cypher_interface.h"
#include "../singleton.h"

class XORCypher : public  CypherInterface, public Singleton<XORCypher>{

    friend Singleton;

private:
    const string _key = "J-key";

    XORCypher() = default;

    const string _encrypt(string src) const override {
        for(size_t i = 0; i < src.length(); ++i){
            src[i] ^= _key[i % _key.length()] + i;
        }
        return src;
    }

    const string _decrypt(string src) const override {
        return _encrypt(src);
    }

    bool _is_equal(const string& src, const string& encrypted) const override {
        return src == _decrypt(encrypted);
    }
};

#endif //QUADROBANK_XOR_CYPHER_H
