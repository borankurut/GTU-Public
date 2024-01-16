#include "Bulldozer.h"

Bulldozer::Bulldozer(): Robot(){}
Bulldozer::Bulldozer(int newS, int newHp): Robot(newS, newHp){}

int Bulldozer::getDamage() const{
    int attack = Robot::getDamage();
    cout << typeOf() << "'s attack: " << attack << endl;
    return attack;
}

string Bulldozer::typeOf() const{return "bulldozer";}