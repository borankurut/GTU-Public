#include "human.h"
#include <iostream>

using std::cout;
using std::endl;

namespace KurutRpg{
    Human::Human(): Creature(10, 10){/**/}
    Human::Human(int theStrength, int theHitpoints): 
        Creature(theStrength, theHitpoints){/**/}

    int Human::getDamage() const{
        int damage = Creature::getDamage();
        cout << getSpecies() << " Attacked with " << damage << endl;

        return damage;
    }
    string Human::getSpecies() const{return "Human";}
}