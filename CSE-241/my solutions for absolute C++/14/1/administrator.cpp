#include <iostream>
#include <string>
#include "administrator.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){//Debug purposes.
    SavitchEmployees::Administrator boran;
    boran.print();
    boran.printCheck();
    boran.readSet();
    boran.print();

    return(0);
}

namespace SavitchEmployees{
    void Administrator::setSupervisor(const string& newSupervisor){
        supervisor = newSupervisor;
    }

    void Administrator::read(string& newName, string& newSsn, 
            double& newNetPay,double& newSalary,
            string& newTitle, string& newArea, 
            string& newSupervisor){

        cout << "Enter name: ";
        cin >> newName;
        cout << "Enter Ssn: ";
        cin >> newSsn;
        cout << "Enter annual salary: ";
        cin >> newSalary;

        newNetPay = newSalary / 52.0;//weekly net pay.

        cout << "Enter title: ";
        cin >> newTitle;
        cout << "Enter area of responsibility: ";
        cin >> newArea;
        cout << "Enter the immediate supervisor of admin: ";
        cin >> newSupervisor;
    }

    void Administrator::print() const{
        cout << "name: " << getName() << endl 
            <<  "Ssn: " << getSsn() << endl
            <<  "Salary: " << getSalary() << endl
            <<  "NetPay: " << getNetPay() << endl
            <<  "Title: " << title << endl
            <<  "Area: " << area << endl
            <<  "Supervisor: " << supervisor << endl;
    }

    void Administrator::printCheck() const{
        cout << "To be implemented\n";
    }

    void Administrator::readSet(){
        string newName, newSsn, 
            newTitle, newArea, 
            newSupervisor;

        double newNetPay,
                newSalary;

        read(newName, newSsn, newNetPay, 
            newSalary, newTitle, newArea,
            newSupervisor);
        setName(newName);
        setSsn(newSsn);
        setNetPay(newNetPay);
        setSalary(newSalary);
        title = newTitle;
        area = newArea;
        supervisor = newSupervisor;
    }

    Administrator::Administrator():
    SalariedEmployee(), title("Null"), area("Null"),
    supervisor("Null"){/*empty*/}
}