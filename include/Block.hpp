#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "../include/Chicken.hpp"
#include <vector>
#include <string>

using namespace std;

class Block {
private:
    vector<Chicken> block;
    int size;
    string timestamp;
    string hash;
    string previous_hash;

    string getHash();
public:
    Block();
    Block(vector<Chicken> block);
    int getSize();
    Block getBlock();
    void addChicken(Chicken new_chicken);
    void removeChicken(Chicken a_chicken);
    void searchChickenByName(string chicken_name);
    void searchChickenByWeight(float chicken_weight);
    void searchChickenByAge(int chicken_age);
    void searchChickenByGender(string chicken_gender);
    void dropDuplicatesByName(string name);
    void display();
    bool operator==(Block other);
    ~Block();
};

#endif