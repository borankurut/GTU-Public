#include <iostream>
#include "RainbowColor.h"


using namespace std;
using namespace RainbowColorKurut;

int main(){
    RainbowColor myRainbowColor(5);
    myRainbowColor.output();
    myRainbowColor.input();
    myRainbowColor.output();
    myRainbowColor.returnNext().output();
    myRainbowColor.returnNext().returnNext().output();

    return(0);
}