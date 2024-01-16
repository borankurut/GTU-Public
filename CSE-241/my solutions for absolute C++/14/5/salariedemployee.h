//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <iostream>
#include <string>
#include "employee.h"


using std::string;
using std::ostream;
using std::istream;

namespace SavitchEmployees{
    class SalariedEmployee: public Employee{
    public:
        SalariedEmployee();
        SalariedEmployee(const string& theName, const string& theSsn,
                        double theWeeklySalary);
        
        double getSalary() const;

        void setSalary(double newSalary);

        void printCheck();

    private:    
        double salary;//weekly
    };
}
#endif