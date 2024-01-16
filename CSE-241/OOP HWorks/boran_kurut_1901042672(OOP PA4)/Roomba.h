#ifndef ROOMBA_H
#define ROOMBA_H

#include "Robot.h"

class Roomba : public Robot
{
public:
    Roomba();
    Roomba(int newS, int newHp);

    string typeOf() const override;
    int getDamage() const override;
};

#endif