#ifndef BALROG_H
#define BALROG_H

#include "demon.h"

namespace KurutRpg{
    class Balrog: public Demon{
    public:
        Balrog(); // 100 200
        Balrog(int theStrength, int theHitpoint);

        int getDamage() const;
        string getSpecies() const;
    };
}


#endif