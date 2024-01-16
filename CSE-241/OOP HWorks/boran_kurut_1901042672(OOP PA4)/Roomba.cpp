#include "Roomba.h"

Roomba::Roomba(): Robot(){}
Roomba::Roomba(int newS, int newHp):
    Robot(newS, newHp){}

string Roomba::typeOf() const {return "roomba";}
int Roomba::getDamage() const {
    int firstAttack = Robot::getDamage();
    int secondAttack = Robot::getDamage();
    cout << typeOf() << "'s first attack: " << firstAttack << endl;
    cout << typeOf() << "'s second attack: " << secondAttack << endl;
    return firstAttack + secondAttack;
}