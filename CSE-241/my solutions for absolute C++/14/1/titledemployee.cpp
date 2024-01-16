/*

#ifndef TITLEDEMPLOYEE_H
#define TITLEDEMPLOYEE_H

#include <string>
#include "salariedemployee.h"
using std::string;

namespace SavitchEmployees{
    class TitledEmployee: public SalariedEmployee{
    public:
        TitledEmployee();
        TitledEmployee(string theName, string theTitle,
            string theSsn, double theSalary);
            
        string getTitle() const;

        void setTitle(string newTitle);

        void setName(const string& newName);

    private:
        string title;
    };
}

#endif

*/


#include <iostream>
#include <string.h>
#include "titledemployee.h"

using namespace std;

namespace SavitchEmployees{
    TitledEmployee::TitledEmployee(): SalariedEmployee(), title(""){/*empty*/}

    TitledEmployee::TitledEmployee(string theName, string theTitle,
            string theSsn, double theSalary):
        SalariedEmployee(theName, theSsn, theSalary), title(theTitle){/*empty*/}

    string TitledEmployee::getTitle() const{
        return title;
    }

    void TitledEmployee::setTitle(string newTitle){
        title = newTitle;
    }

    void TitledEmployee::setName(const string& newName){
        Employee::setName(title + newName);
    }
}