//This is the file salariedemployee.cpp
//This is the implementation for the class SalariedEmployee.
//The interface for the class SalariedEmployee is in
//the header file salariedemployee.h.

#include <iostream>
#include <string>
#include "salariedemployee.h"

using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees{
    SalariedEmployee::SalariedEmployee(): Employee(), salary(0.0){/*empty*/}

    SalariedEmployee::SalariedEmployee(const string& theName, const string& theNumber,
            double theWeeklyPay):
        Employee(theName, theNumber), salary(theWeeklyPay){/*empty*/}

    double SalariedEmployee::getSalary() const{
        return salary;
    }

    void SalariedEmployee::setSalary(double newSalary){
        salary = newSalary;
    }

    void SalariedEmployee::printCheck(){
        setNetPay(salary);

        cout << "\n___________________________________________\n";
        cout << "Pay to the order of " << getName() << endl;
        cout << "The sum of " << getNetPay() << " Dollars\n";
        cout << "_____________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Salaried Employee. Regular Pay: "
            <<  salary << endl;
        cout << "______________________________________________\n";
    }
}