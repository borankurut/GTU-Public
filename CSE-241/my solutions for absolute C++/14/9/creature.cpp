#include <iostream>
#include <stdlib.h> //random
#include "creature.h"

using std::cout;
using std::endl;


namespace KurutRpg{
    int Creature::getDamage() const{
        int damage;
        damage = (rand() % strength) + 1;
        return damage;
    }

    Creature::Creature(): strength(0), hitpoints(0){/**/}

    Creature::Creature(int theStrength, int theHitpoints):
        strength(theStrength), hitpoints(theHitpoints){/**/}

    string Creature::getSpecies() const{return "Unknown Creature";}
}