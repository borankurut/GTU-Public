#include <iostream>

using namespace std;

class Point{

private:
    int x,
        y;

public:
    void Set(int newX, int newY);
    // sets the point.
    void Move(int difX, int difY);
    // moves the point by adding the arguments.
    void Rotate();
    // rotates the point by 90 degrees clockwise around the origin.
    const int GetX();
    // returns the x value of the Point.
    const int GetY();
    // returns the y value of the Point.
};