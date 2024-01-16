#include <iostream>
#include <time.h>

using namespace std;

class GasPump{

public:

    void reset();                   // sets amtDispensed and amtCharged to 0
    void start();                   // starts to fill fuel.
    void dispense(double fuelAmt);  // dispense fuelAmt gallons fuel.
    void show();                    // prints the informations.
    
    void setCostPerGal(double cost);

private:
    double amtDispensed,
        amtCharged,
        costPerGal;
};

void GasPump::reset(){
    amtDispensed = 0;
    amtCharged = 0;
}

void GasPump::setCostPerGal(double cost){
    costPerGal = cost;
}

void GasPump::show(){
    cout << "Gas pump screen:\n"
        <<  "Dispensed: " << amtDispensed << endl 
        <<  "Charged: $" << amtCharged << endl
        <<  "Cost per Gallon: " << costPerGal << endl;
}

void GasPump::dispense(double fuelAmt){
    amtDispensed += fuelAmt;
    amtCharged += fuelAmt * costPerGal;
}

void GasPump::start(){
    //clock_t thisTime = clock();
    //clock_t lastTime = thisTime;

    // I couldn't find a way to continuously dispense fuel based on time (!)until user enters input(!).
}


int main(){ //testing.

    return(0);
}