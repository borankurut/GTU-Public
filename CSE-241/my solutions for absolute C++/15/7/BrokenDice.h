#ifndef BROKEN_DICE_H
#define BROKEN_DICE_H

#include "Dice.h"
class BrokenDice: public Dice{
public:
    BrokenDice();

    BrokenDice(int theNumOfSides);

    int rollDice() const override;

};

#endif