#ifndef HUMANIC_H
#define HUMANIC_H

#include "Robot.h"

class Humanic : public Robot
{
public:
    Humanic();
    Humanic(int newS, int newHp);

    string typeOf() const override;
    int getDamage() const override;
};

#endif