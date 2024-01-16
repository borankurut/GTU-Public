#ifndef PET_H
#define PET_H

#include <string>

using std::string;

class Pet{

public:
    Pet();
    Pet(string theName, int theAge, int theWeight);

    string getLifespan() const; // unknown lifespan

    void setName(string newName);
    void setAge(int newAge);
    void setWeight(int newWeight);

    string getName() const;
    int getAge() const;
    int getWeight() const;

private:
    string name;
    int age;
    int weight;

};

#endif