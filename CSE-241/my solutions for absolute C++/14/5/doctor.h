#ifndef DOCTOR_H
#define DOCTOR_H

#include "salariedemployee.h"

using namespace SavitchEmployees;

namespace KurutClinic{

    class Doctor: public SalariedEmployee{
    public:
        Doctor();
        Doctor( const string& theName, const string& theSsn, 
                double theWeeklySalary, const string& theSpecialty,
                double theOfficeVisitFee);

        Doctor(const Doctor& doctorObj);

        Doctor& operator =(const Doctor& rtSide);

        void setSpecialty(const string& newSpecialty);
        void setOfficeVisitFee(double newOfficeVisitFee);

        string getSpecialty() const;
        double getOfficeVisitFee() const;

    private:
        string specialty;
        double officeVisitFee;
    };
}

#endif