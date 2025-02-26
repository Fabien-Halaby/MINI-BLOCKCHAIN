#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include <string>

using namespace std;

class Chicken {
private:
    string name;
    string gender;
    float weight;
    int age;
public:
    Chicken();
    Chicken(string name,string gender,float weight,int age);
    ~Chicken();
    void setName(string name);
    void setGender(string gender);
    void setWeight(float weight);
    void setAge(int age);
    string getName();
    string getGender();
    float getWeight();
    int getAge();
    string getInformation();
    void display();
    Chicken operator=(Chicken other);
    bool operator==(Chicken other);
};

#endif