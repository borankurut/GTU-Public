#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "Humanic.h"

class Optimusprime : public Humanic
{
public:
    Optimusprime();
    Optimusprime(int newS, int newHp);

    string typeOf() const override;
    int getDamage() const override;
};

#endif