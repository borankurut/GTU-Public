#include <iostream>

using namespace std;

class Weight{

public:
    void setWeightPounds(double newWeight);
    void setWeightKilograms(double newWeight);
    void setWeightOunces(double newWeight);

    double getWeightPounds();
    double getWeightKilograms();
    double getWeightOunces();

private:
    double weightPd;    // weight(pounds)
};

void Weight::setWeightPounds(double newWeight){
    weightPd = newWeight;
}

void Weight::setWeightKilograms(double newWeight){
    double pounds = newWeight * 2.21;
    weightPd = pounds;
}

void Weight::setWeightOunces(double newWeight){
    double pounds = newWeight * 16;
    weightPd = pounds;
}

double Weight::getWeightPounds(){
    return weightPd;
}

double Weight::getWeightKilograms(){
    double kilograms = weightPd / 2.21;
    return kilograms;
}

double Weight::getWeightOunces(){
    double ounces = weightPd / 16;
    return ounces;
}

int main(){

    Weight myWeight;

    myWeight.setWeightKilograms(75);

    cout << "pd: " << myWeight.getWeightPounds() << endl 
        << "kg: " << myWeight.getWeightKilograms() << endl
        << "ounces: " << myWeight.getWeightOunces() << endl;

    myWeight.setWeightPounds(165.75);

    cout << "pd: " << myWeight.getWeightPounds() << endl 
        << "kg: " << myWeight.getWeightKilograms() << endl
        << "ounces: " << myWeight.getWeightOunces() << endl;


    return(0);
}