#ifndef ELF_H
#define ELF_H

#include "creature.h"

namespace KurutRpg{
    class Elf: public Creature{
    public:
        Elf();
        Elf(int theStrength, int theHitpoints);

        int getDamage() const;
        string getSpecies() const;
    };
}

#endif