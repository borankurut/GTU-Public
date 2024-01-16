#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "Robot.h"

class Bulldozer: public Robot
{
public:
    Bulldozer();
    Bulldozer(int newS, int newHp);

    int getDamage() const override;
    string typeOf() const override;
};

#endif