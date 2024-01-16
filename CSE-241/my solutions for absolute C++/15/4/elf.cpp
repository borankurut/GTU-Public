#include <iostream>
#include <stdlib.h> //rand
#include "elf.h"

using std::cout;
using std::endl;

namespace KurutRpg{
    Elf::Elf(): Creature(300, 20){/**/}
    Elf::Elf(int theStrength, int theHitpoints):
        Creature(theStrength, theHitpoints){/**/}
    
    int Elf::getDamage() const{
        int damage = Creature::getDamage();
        if(rand()%100 < 10){
            damage *= 2;
            cout << "Magical Attack!\n";
        }
        return damage;
    }

    string Elf::getSpecies() const{return "Elf";}
}