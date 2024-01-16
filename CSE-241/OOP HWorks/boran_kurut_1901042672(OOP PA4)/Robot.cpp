#include <iostream>
#include <stdlib.h> //random
#include "Robot.h"

string Robot::typeOf() const{return "robot";}

Robot::Robot():s(10), hp(10){}

Robot::Robot(int newStrength, int newHit):
    s(newStrength), hp(newHit){}

int Robot::getHp() const {return hp;}

void Robot::setHp(int newHp) {hp = newHp;} 

int Robot::getStrength() const{return s;}

void Robot::setStrength(int newS){s = newS;}

int Robot::getDamage() const{
    int damage = (rand() % s) + 1; // (0, strength]
    return damage;
}