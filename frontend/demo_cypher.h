
#ifndef QUADROBANK_DEMO_CYPHER_H
#define QUADROBANK_DEMO_CYPHER_H

#include "backend/utils/cypher/xor_cypher.h"
#include <iostream>

using std::cout;
using std::endl;

void demo_cypher(){
    const CypherInterface& cypher = XORCypher::get_instance();
    {
        string src = "hello";
        string encrypted = cypher.encrypt(src);
        string decrypted = cypher.decrypt(encrypted);

        cout << "Input: " << src << endl;
        cout << "Encrypted: " << encrypted << endl;
        cout << "Decrypted: " << decrypted << endl << endl;
//        Input: hello
//        Encrypted: "K╔╝
//        Decrypted: hello
    }
    {
        string src = "hellohellohello";
        string encrypted = cypher.encrypt(src);
        string decrypted = cypher.decrypt(encrypted);

        cout << "Input: " << src << endl;
        cout << "Encrypted: " << encrypted << endl;
        cout << "Decrypted: " << decrypted << endl << endl;
//        Input: hellohellohello
//        Encrypted: "K╔╝'V╔э<]?ш
//        Decrypted: hellohellohello
    }
}

#endif //QUADROBANK_DEMO_CYPHER_H
