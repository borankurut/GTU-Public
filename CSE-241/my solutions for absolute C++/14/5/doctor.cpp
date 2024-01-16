#include "doctor.h"

namespace KurutClinic{
    Doctor::Doctor(): SalariedEmployee(), specialty(""), officeVisitFee(0.0){/**/}

    Doctor::Doctor(const string& theName, const string& theSsn, 
                double theWeeklySalary, const string& theSpecialty,
                double theOfficeVisitFee):
        SalariedEmployee(theName, theSsn, theWeeklySalary), 
        specialty(theSpecialty), officeVisitFee(theOfficeVisitFee){/**/}

    Doctor::Doctor(const Doctor& doctorObj):
        SalariedEmployee(doctorObj), specialty(doctorObj.specialty),
        officeVisitFee(doctorObj.officeVisitFee){/**/}
    
    Doctor& Doctor::operator =(const Doctor& rtSide){
        SalariedEmployee::operator =(rtSide);
        specialty = rtSide.specialty;
        officeVisitFee = rtSide.officeVisitFee;
        return(*this);
    }

    void Doctor::setSpecialty(const string& newSpecialty){
        specialty = newSpecialty;
    }

    void Doctor::setOfficeVisitFee(double newOfficeVisitFee){
        officeVisitFee = newOfficeVisitFee;
    }

    string Doctor::getSpecialty() const{
        return specialty;
    }

    double Doctor::getOfficeVisitFee() const{
        return officeVisitFee;
    }
}