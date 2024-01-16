#include "Humanic.h"
#include <stdlib.h> //random

Humanic::Humanic(): Robot(){}

Humanic::Humanic(int newS, int newHp):
    Robot(newS, newHp){}

string Humanic::typeOf() const{return "humanic";}

int Humanic::getDamage() const{
    int attack = Robot::getDamage();
    bool tactical = (rand()%100 < 10);

    if(tactical){
        cout << typeOf() << " inflicted tactical nuke attack! (" << attack << " + 50)" << endl;
        attack += 50;
    }
    return attack;
}