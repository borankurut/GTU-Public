#include <iostream>

using namespace std;

const double PI = 3.14159;

class Circle
{
private:
    int radius;

public:
    void Set(int newRadius);
    // sets the radius of the circle object.

    void Calculate(int &area, int &diameter, int &circumference);
    // calculates the area, diameter, circumference of the circle object.

    int GetRadius();
    // returns the radius of the circlel object.
};