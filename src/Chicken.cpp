#include "../include/Chicken.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Chicken::Chicken() {

}

Chicken::Chicken(string name,string gender,float weight,int age) {
    this->name = name;
    this->gender = gender;
    this->weight = weight;
    this->age = age;
}

Chicken::~Chicken() {

}

void Chicken::setName(string name) {
    this->name = name;
}

void Chicken::setGender(string gender) {
    this->gender = gender;
}

void Chicken::setWeight(float weight) {
    this->weight = weight;
}

void Chicken::setAge(int age) {
    this->age = age;
}

string Chicken::getName() {
    return this->name;
}

string Chicken::getGender() {
    return this->gender;
}

float Chicken::getWeight() {
    return this->weight;
}

int Chicken::getAge() {
    return this->age;
}

string Chicken::getInformation() {
    stringstream ss;
    ss << "Name : " << this->name << ", Gender : " << this->gender << ", Age : " << this->age << ", Weight : " << this->weight;
    return ss.str();
}

void Chicken::display() {
    cout << "Chicken : " << endl;
    cout << "\t => Name... : " << this->name << endl;
    cout << "\t => Gender. : " << this->gender << endl;
    cout << "\t => Age.... : " << this->age << " day." << endl;
    cout << "\t => Weight. : " << this->weight << " kg." << endl;
}

bool Chicken::operator==(Chicken other) {
    return(
        this->name == other.name
        &&
        this->gender == other.gender
        &&
        this->age == other.age
        &&
        this->weight == other.weight
    );
}

Chicken Chicken::operator=(Chicken other) {
    this->name = other.name;
    this->gender = other.gender;
    this->weight = other.weight;
    this->age = other.age;

    return *this;
}