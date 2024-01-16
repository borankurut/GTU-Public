#ifndef HUMAN_H
#define HUMAN_H

#include "creature.h"

namespace KurutRpg
{
    class Human: public Creature{
    public:
        Human();
        Human(int theStrength, int theHitpoints);

        string getSpecies() const;
        int getDamage() const;
    };
    
} // namespace KurutRpg


#endif