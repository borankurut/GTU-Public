#include <iostream>
#include <stdlib.h>//random
#include "demon.h"

using std::cout;

namespace KurutRpg
{
    Demon::Demon(): Creature(5, 5){/**/}

    Demon::Demon(int theStrength, int theHitpoint): 
        Creature(theStrength, theHitpoint){/**/}

    int Demon::getDamage() const{
        int damage = Creature::getDamage();
        if(rand() % 100 < 5){
            damage += 50;
            cout << "Demonic attack!\n";
        }
        return damage;
    }

    string Demon::getSpecies() const{return "Unknown Demon";}
} // namespace KurutRpg
