#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>

using namespace std;

class Robot{
private:
    int s;          // strength
    int hp;         // hitpoint

public:
    Robot();
    Robot(int newStrength, int newHit);

    // getters, setters
    int getHp() const;
    void setHp(int newHp);

    int getStrength() const;
    void setStrength(int newS);

    virtual string typeOf() const; // returns the type of robot

    // Returns the damage the robot can inflict
    virtual int getDamage() const;
};

#endif