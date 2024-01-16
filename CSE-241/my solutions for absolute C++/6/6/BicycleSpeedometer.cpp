#include <iostream>

using namespace std;

class BicycleSpeedometer{

public:

    void setDistance(double newDistance);
    void setTime(double newTime);
    void cptAvgSpeed();
    void display();

private:

    double distance,    // miles
            time,       // minutes
            avgSpeed;   // mil/hr

};

void BicycleSpeedometer::setDistance(double newDistance){
    distance = newDistance;
    cptAvgSpeed();
}

void BicycleSpeedometer::setTime(double newTime){
    time = newTime;
    cptAvgSpeed();
}

void BicycleSpeedometer::cptAvgSpeed(){
    avgSpeed = (distance/(time / 60.0)); // divided by 60 to compute hours.
}

void BicycleSpeedometer::display(){
    cout << "Distance: " << distance << " miles\n" 
        << "Time: " << time << " minutes\n" 
        << "Average Speed: " << avgSpeed << " mil/hr\n";
}


int main(){ //test
    BicycleSpeedometer myMeter;

    double time, 
            distance;

    cout << "Please enter time and distance\n>";
    cin >> time >> distance;

    myMeter.setTime(time);
    myMeter.setDistance(distance);

    myMeter.display();

    return(0);
}