#include "BrokenDice.h"
#include <cstdlib>
#include <time.h>

BrokenDice::BrokenDice() {Dice();}

BrokenDice::BrokenDice(int theNumOfSides): Dice(theNumOfSides){/**/}

int BrokenDice::rollDice() const{
    if(rand() % 2 == 0)
        return numSides;
    else 
        return Dice::rollDice();
}