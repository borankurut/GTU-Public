#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "salariedemployee.h"

using std::string;

namespace SavitchEmployees{
    class Administrator: public SalariedEmployee{
    public:
        Administrator();

        void setSupervisor(const string& newSupervisor);
        void read(string& newName, string& newSsn, double& newNetPay,
            double& newSalary, string& newTitle, 
            string& newArea, string& newSupervisor);
        void readSet();
        void print() const;
        void printCheck() const;

    private:
        string title;       //title of admin
        string area;        //company area of responsibility
        string supervisor;  //immediate supervisor of admin
    };
}

#endif