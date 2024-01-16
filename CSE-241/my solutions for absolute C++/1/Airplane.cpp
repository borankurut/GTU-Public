#include <iostream>
using namespace std;

int main(){
    double speedMph,    // IN - the speed of the airplane (miles per hour)
            time,       // IN - travel time (hour)
            speedMps,   // OUT - speed (meters per second)
            distance;   // OUT - travelled distance (miles)

    cout << "Enter the speed of the airplane (miles per hour)\n>";
    cin >> speedMph;

    cout << "Enter the travel time (hour)\n>";
    cin >> time;

    // formula
    speedMps = (speedMph / 3600.0) * 1609.344;
    
    distance = speedMph * time;

    cout << "You travelled " << distance << " miles "
        << "with a speed of " << speedMps << "m/s\n";

    return(0);
}