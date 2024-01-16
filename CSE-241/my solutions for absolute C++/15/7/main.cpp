#include <iostream>
#include "Dice.h"
#include "BrokenDice.h"

using std::cout;
using std::endl;

int main(){

    Dice dice(10);
    BrokenDice brokenDice(10);

    cout << "Normal:\n";
    for(int i = 0; i < 10; ++i)
        cout << rollTwoDice(dice, dice) << endl;

    cout << "\nBroken:\n";
    for(int i = 0; i < 10; ++i)
        cout << rollTwoDice(brokenDice, brokenDice) << endl;


    return 0;
}