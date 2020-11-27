
#ifndef QUADROBANK_XOR_CYPHER_H
#define QUADROBANK_XOR_CYPHER_H

#include "cypher_interface.h"
#include "../singleton.h"

class XORCypher : public  CypherInterface, public Singleton<XORCypher>{

    friend Singleton;

private:
    const string _key = "J-key";

    const string _encrypt(string src) const override {
        for(size_t i = 0; i < src.length(); ++i){
            src[i] ^= _key[i % _key.length()] + i;
        }
        return src;
    }

    const string _decrypt(string src) const override {
        return _encrypt(src);
    }

    bool _is_equal(const string& str1, const string& str2) const override {
        return str1 == str2;
    }
};

#endif //QUADROBANK_XOR_CYPHER_H
