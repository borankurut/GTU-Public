#include <iostream>
#include "hourlyemployee.h"
#include "salariedemployee.h"

using namespace std;
using namespace SavitchEmployees;

int main(){
    HourlyEmployee joe;
    joe.setName("Mighty Joe");
    joe.setSsn("123-45-6789");
    joe.setRate(20.50);
    joe.setHours(40);
    cout << "Check for " << joe.getName()
        <<  " for " << joe.getHours() << " hours\n";
    joe.printCheck();
    cout << endl;

    SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
    cout << "Check for " << boss.getName() << endl;
    boss.printCheck();
    cout << endl;
    return 0;
}