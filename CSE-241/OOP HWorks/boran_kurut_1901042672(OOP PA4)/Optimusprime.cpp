#include "Optimusprime.h"
#include <stdlib.h> //random

Optimusprime::Optimusprime(): Humanic(){}

Optimusprime::Optimusprime(int newS, int newHp):
    Humanic(newS, newHp){}

string Optimusprime::typeOf() const{return "optimusprime";}

int Optimusprime::getDamage() const{
    int attack = Humanic::getDamage();

    bool strongAttack = (rand() % 100 < 15);

    if(strongAttack){
        cout << typeOf() << " inflicted strong attack! (" << attack << " * 2)" << endl;
        attack *= 2;
    }
    return attack;
}