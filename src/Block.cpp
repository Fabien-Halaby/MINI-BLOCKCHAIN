#include "../include/Block.hpp"
#include <sstream>
#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <algorithm>

Block::Block() {
    this->block = {};
    this->size = this->block.size();
    this->timestamp = __TIMESTAMP__;
    this->previous_hash = "";
    this->hash = this->getHash();
}

Block::Block(vector<Chicken> block) {
    this->block = block;
    this->size = this->block.size();
    this->timestamp = __TIMESTAMP__;
    this->previous_hash = "";
    this->hash = this->getHash();
}

Block::~Block() {

}

string Block::getHash() {
    string block_info = this->timestamp;
    for(auto bloc : this->block) {
        block_info += bloc.getInformation();
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len = 0;

    // Création d'un contexte pour le hachage
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    if (mdctx == nullptr) {
        throw std::runtime_error("Erreur lors de la création du contexte EVP_MD_CTX");
    }

    if (1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr)) {
        EVP_MD_CTX_free(mdctx);
        throw std::runtime_error("Erreur lors de l'initialisation d'EVP_DigestInit_ex");
    }

    if (1 != EVP_DigestUpdate(mdctx, block_info.c_str(), block_info.size())) {
        EVP_MD_CTX_free(mdctx);
        throw std::runtime_error("Erreur lors de la mise à jour d'EVP_DigestUpdate");
    }

    if (1 != EVP_DigestFinal_ex(mdctx, hash, &hash_len)) {
        EVP_MD_CTX_free(mdctx);
        throw std::runtime_error("Erreur lors de la finalisation d'EVP_DigestFinal_ex");
    }

    EVP_MD_CTX_free(mdctx);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (unsigned int i = 0; i < hash_len; i++) {
        ss << std::setw(2) << static_cast<int>(hash[i]);
    }
    return ss.str();
}

void Block::display() {
    cout << "-----------BLOCK---------" << endl;
    cout << "\t => MEMBER" << endl;
    for(auto bloc : this->block) {
        bloc.display();
        cout << endl;
    }
    cout << "Timestamp. : " << this->timestamp << endl;
    cout << "Hash ..... : " << this->hash << endl;
}

void Block::addChicken(Chicken new_chicken) {
    if(find(this->block.begin(),this->block.end(),new_chicken) != this->block.end()) {
        cout << " => '" << new_chicken.getName() << "' is already a member." << endl;
    }else {
        this->block.push_back(new_chicken);
        this->size += 1;
        cout << " => '" << new_chicken.getName() << "' added successfully." << endl;
    }
}

void Block::removeChicken(Chicken a_chicken) {
    if(find(this->block.begin(),this->block.end(),a_chicken) != this->block.end()) {
        this->block.erase(remove(this->block.begin(),this->block.end(),a_chicken));
        this->size -= 1;
        cout << " => '" << a_chicken.getName() << "' deleted successfully." << endl;
    }else {
        cout << " => '" << a_chicken.getName() << "' is not a member." << endl;
    }
}

void Block::searchChickenByName(string name) {
    cout << endl << "Result found by name : " << name << endl;
    auto it = find_if(
        this->block.begin(),
        this->block.end(),[&](Chicken found){
        return found.getName() == name;
    });

    if(it != this->block.end()) {
        for_each(
            this->block.begin(),
            this->block.end(),
            [&](Chicken found){
                if(found.getName() == name) {
                    found.display();
                }
            }
        );
    }else {
        cout << "No result." << endl;
    }
}

void Block::searchChickenByWeight(float weight) {
    cout << endl << "Result found by weight : " << weight << endl;
    auto it = find_if(
        this->block.begin(),
        this->block.end(),
        [&](Chicken found){
            return found.getWeight() == weight;
        }
    );

    if(it != this->block.end()) {
        for_each(
            this->block.begin(),
            this->block.end(),
            [&](Chicken found) {
                if(found.getWeight() == weight) {
                    found.display();
                }
            }
        );
    }else {
        cout << "No result." << endl;
    }
}

void Block::searchChickenByAge(int age) {
    auto it = find_if(
        this->block.begin(),
        this->block.end(),
        [&](Chicken found) {
            return found.getAge() == age;
        }
    );

    cout << endl << "Result found by age : " << age << endl;
    if(it != this->block.end()) {
        for_each(
            this->block.begin(),
            this->block.end(),
            [&](Chicken found) {
                if(found.getAge() == age) {
                    found.display();
                }
            }
        );
    }else {
        cout << "No result." << endl;
    }
}

int Block::getSize() {
    return this->size;
}

Block Block::getBlock() {
    return this->block;
}

void Block::searchChickenByGender(string gender) {
    auto it = find_if(
        this->block.begin(),
        this->block.end(),
        [&](Chicken found) {
            return found.getGender() == gender;
        }
    );

    cout << endl << "Result found by gender : " << gender << endl;
    if(it != this->block.end()) {
        for_each(
            this->block.begin(),
            this->block.end(),
            [&](Chicken found) {
                if(found.getGender() == gender) {
                    found.display();
                }
            }
        );
    }else {
        cout << "No result." << endl;
    }
}

void Block::dropDuplicatesByName(string name) {
    this->block.erase(
        remove_if(
            this->block.begin(),
            this->block.end(),
            [&name](Chicken other) {
                return other.getName() == name;
            }
        ),this->block.end()
    );

    this->hash = this->getHash();
    this->size = this->block.size();
}

bool Block::operator==(Block other) {
    if(this->block.size() != other.block.size()) {
        return false;
    }

    return equal(this->block.begin(),this->block.end(),other.block.begin());
}