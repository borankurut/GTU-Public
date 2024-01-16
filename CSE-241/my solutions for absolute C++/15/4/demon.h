#ifndef DEMON_H
#define DEMON_H

#include "creature.h"

namespace KurutRpg{

    class Demon: public Creature{       
    public:
        Demon();
        Demon(int theStrength, int theHitpoint);

        int getDamage() const override;
    };
}

#endif