#ifndef ROCK_H
#define ROCK_H

#include "pet.h"
#include "string"

using std::string;

class Rock: Pet{

public:
    Rock();
    
    string getLifespan() const;
};

#endif