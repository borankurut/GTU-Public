#include <iostream>
#include "Circle.h"

using namespace std;

int main(){
    Circle myCircle;
    int diameter, area, circumference;

    myCircle.Set(10);
    myCircle.Calculate(area, diameter, circumference);

    cout << "radius:" << myCircle.GetRadius() << "\narea: " << area;
    cout << "\ndiameter: " << diameter << "\ncircumference: " << circumference;

    return (0);
}