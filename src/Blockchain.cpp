#include "../include/Blockchain.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

Blockchain::Blockchain() {
    this->chain = {};
}

Blockchain::Blockchain(map<string,Block> chain) {
    this->chain = chain;
}

void Blockchain::addChain(string name,Block block) {
    auto it = find_if(
        this->chain.begin(),
        this->chain.end(),
        [name,block](pair<string,Block> found){
            return (found.first == name && found.second == block);
        }
    );

    if(it != this->chain.end()) {
        cout << "The entry with the key '" << name << "' and the specified block already exists." << endl;
    }else {
        auto keyIt = this->chain.find(name);
        if(keyIt != this->chain.end()) {
            keyIt->second = block;
            cout << "Updating the block for the key '" << name << "'." << endl;
        }else {
            this->chain.insert({name,block});
            cout << "Inserting a new entry with the key '" << name << "'." << endl;
        }
    }
}

Blockchain::~Blockchain() {

}