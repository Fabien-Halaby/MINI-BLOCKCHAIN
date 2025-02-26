#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "../include/Block.hpp"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Blockchain {
private:
    map<string,Block> chain;
public:
    Blockchain();
    Blockchain(map<string,Block> chain);
    void addChain(string name,Block block);
    ~Blockchain();
};

#endif