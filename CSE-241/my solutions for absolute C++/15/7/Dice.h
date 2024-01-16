#ifndef DICE_H
#define DICE_H

class Dice{
public:
    Dice();
    Dice(int theNumOfSides);
    virtual int rollDice() const;
protected:
    int numSides;
};

int rollTwoDice(const Dice& d1, const Dice& d2);

#endif