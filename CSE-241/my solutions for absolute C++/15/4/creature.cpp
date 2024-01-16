#include <iostream>
#include <stdlib.h> //random
#include "creature.h"

using std::cout;
using std::endl;


namespace KurutRpg{
    Creature::Creature(): strength(0), hitpoints(0){/**/}

    Creature::Creature(int theStrength, int theHitpoints):
        strength(theStrength), hitpoints(theHitpoints){/**/}

    int Creature::getDamage() const{
        int damage;
        damage = (rand() % strength) + 1;
        return damage;
    }

    int Creature::getStrength() const{return strength;}
    int Creature::getHitpoints() const{return hitpoints;}

    void Creature::setStrength(int newStrength){strength = newStrength;}
    void Creature::setHitpoints(int newHitpoints){hitpoints = newHitpoints;}


    void Creature::attack(Creature& enemy) const{
        int damage;
        cout << getSpecies() << " Attacked with " << (damage = getDamage()) << " to " << enemy.getSpecies() << endl;
        enemy.hitpoints -= damage;
    }

    ostream& operator <<(ostream& output, const Creature& cr){
        output << cr.getSpecies() << " STR: " << cr.getStrength() << "  HP: " << cr.getHitpoints();
        return output;
    }
}