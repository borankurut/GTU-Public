#ifndef DOG_H
#define DOG_H

#include <string>
#include "pet.h"

using std::string;

class Dog: public Pet{

public:
    Dog();
    Dog(string theName, int theAge, int theWeight, string theBreed);

    string getLifespan() const;

    void setBreed(string newBreed);
    string getBreed() const;

private:
    string breed;
};


#endif
