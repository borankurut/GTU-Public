#include <iostream>
#include "cyberdemon.h"

using std::cout;
using std::endl;

namespace KurutRpg{
    Cyberdemon::Cyberdemon(): Demon(50, 300){/**/}

    Cyberdemon::Cyberdemon(int theStrength, int theHitpoint):
        Demon(theStrength, theHitpoint){/**/}

    int Cyberdemon::getDamage() const{
        int damage = Demon::getDamage();
        return damage;
    }

    string Cyberdemon::getSpecies() const{return "Cyberdemon";}
}