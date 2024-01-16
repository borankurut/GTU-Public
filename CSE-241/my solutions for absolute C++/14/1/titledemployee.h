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