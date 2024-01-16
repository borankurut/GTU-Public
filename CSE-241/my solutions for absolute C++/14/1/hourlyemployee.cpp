//This is the file hourlyemployee.cpp.
//This is the implementation for the class HourlyEmployee.
//The interface for the class HourlyEmployee is in
//the header file hourlyemployee.h

#include <string>
#include <iostream>
#include "hourlyemployee.h"

using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees{
    HourlyEmployee::HourlyEmployee():
    Employee(), wageRate(0), hours(0){/*empty*/}

    HourlyEmployee::HourlyEmployee(const string& theName, 
            const string& theNumber, double theWageRate,
            double theHours):
        Employee(theName, theNumber), wageRate(theWageRate),
        hours(theHours){/*empty*/}

    double HourlyEmployee::getRate() const{
        return wageRate;
    }

    double HourlyEmployee::getHours() const{
        return hours;
    }

    void HourlyEmployee::setRate(double newWageRate){
        wageRate = newWageRate;
    }

    void HourlyEmployee::setHours(double hoursWorked){
        hours = hoursWorked;
    }

    void HourlyEmployee::printCheck(){
        setNetPay(hours * wageRate);

        cout << "\n___________________________________________\n";
        cout << "Pay to the order of " << getName() << endl;
        cout << "The sum of " << getNetPay() << " Dollars\n";
        cout << "_____________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Hourly Employee. \nHours worked: " << hours
            <<  " Rate: " << wageRate << " Pay: " << getNetPay() 
            << endl;
        cout << "______________________________________________\n";
    }
}