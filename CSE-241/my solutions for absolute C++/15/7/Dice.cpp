#include "Dice.h"
#include <cstdlib>
#include <time.h>

Dice::Dice(){
    numSides = 6;
    srand(time(NULL));
}

Dice::Dice(int theNumOfSides){
    numSides = theNumOfSides;
    srand(time(NULL));
}

int Dice::rollDice() const {return (rand() % numSides) + 1;}

int rollTwoDice(const Dice& d1, const Dice& d2){
    return d1.rollDice() + d2.rollDice();
}