#include "Robocop.h"

Robocop::Robocop(): Humanic(){}

Robocop::Robocop(int newS, int newHp): 
    Humanic(newS, newHp){}

string Robocop::typeOf() const{return "robocop";}

int Robocop::getDamage() const{return Humanic::getDamage();}