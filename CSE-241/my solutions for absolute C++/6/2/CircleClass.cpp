#include <iostream>
#include "Circle.h"

using namespace std;

void Circle::Set(int newRadius){
    if(newRadius >= 0)
        radius = newRadius;
    else{
        cerr << "Illegal radius value! Program aborted.\n";
        exit(1);
    }
}

void Circle::Calculate(int &area, int &diameter, int &circumference){
    area = PI * radius * radius;
    diameter = 2 * radius;
    circumference = 2 * PI * radius;
}

int Circle::GetRadius(){
    return radius;
}