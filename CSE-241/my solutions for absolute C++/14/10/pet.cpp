#include "pet.h"

Pet::Pet(): name("unknown"), age(0), weight(0){/**/}

Pet::Pet(string theName, int theAge, int theWeight): 
    name(theName), age(theAge), weight(theWeight){/**/}

string Pet::getLifespan() const{return "unknown lifespan";}

void Pet::setName(string newName){name = newName;}
void Pet::setAge(int newAge){age = newAge;}
void Pet::setWeight(int newWeight){weight = newWeight;}

string Pet::getName() const{return name;}
int Pet::getAge() const{return age;}
int Pet::getWeight() const{return weight;}