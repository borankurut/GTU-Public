#include <iostream>
#include "Point.h"

using namespace std;

const int SENTINEL = -999;

int main(){
    int x, y;

    while (true){
        cout << "Enter x and y (" << SENTINEL << " to quit).\n";
        cin >> x;
        if(x == SENTINEL)
            break;
        cin >> y;
        
        Point newPoint;
        newPoint.Set(x, y);

        cout << "Point: " << newPoint.GetX() << ", " << newPoint.GetY() << endl;

        cout << "Move args: ";
        cin >> x >> y;
        newPoint.Move(x, y);
        cout << "Point: " << newPoint.GetX() << ", " << newPoint.GetY() << endl;

        newPoint.Rotate();
        cout << "Rotated point: " << newPoint.GetX() << ", " << newPoint.GetY() << endl;
    }

    cout << "Ended";

    return (0);
}