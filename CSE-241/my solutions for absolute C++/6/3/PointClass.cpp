#include <iostream>
#include "Point.h"

using namespace std;

void Point::Set(int newX, int newY){
    x = newX;
    y = newY;
}

void Point::Move(int difX, int difY){
    int newX = x + difX,
        newY = y + difY;

    Set(newX, newY);
}

void Point::Rotate(){
    Set(y, -x);
}

const int Point::GetX(){
    return x;
}

const int Point::GetY(){
    return y;
}