#include "dog.h"

Dog::Dog(): Pet(), breed("unknown breed"){/**/}

Dog::Dog(string theName, int theAge, int theWeight, string theBreed):
    Pet(theName, theAge, theWeight), breed(theBreed){/**/}

string Dog::getLifespan() const{
    if(getWeight() < 100)
        return "Approximately 13 years";
    else
        return "Approximately 7 years";
}

void Dog::setBreed(string newBreed) {breed = newBreed;}

string Dog::getBreed() const{return breed;}