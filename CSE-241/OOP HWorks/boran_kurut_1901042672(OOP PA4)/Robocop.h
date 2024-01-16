#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "Humanic.h"

class Robocop : public Humanic
{
public:
    Robocop();
    Robocop(int newS, int newHp);

    string typeOf() const override;
    int getDamage() const override;
};

#endif
