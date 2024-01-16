#include "patient.h"
#include "person.h"
#include "doctor.h"

namespace KurutClinic{
    Patient::Patient(): Person(), primaryPhysician(Doctor()){/**/}

    Patient::Patient(string theName, const Doctor& thePrimaryPhysician):
        Person(theName), primaryPhysician(thePrimaryPhysician){/**/}
    
    Patient::Patient(const Patient& patientObj):
        Person(patientObj), primaryPhysician(patientObj.primaryPhysician){/**/}

    Patient& Patient::operator=(const Patient& rtSide){
        Person::operator=(rtSide);
        primaryPhysician = rtSide.primaryPhysician;

        return(*this);
    }

    const Doctor& Patient::getPrimaryPhysician() const {return primaryPhysician;}

    void Patient::setPrimaryPhysician(const Doctor& newPrimaryPhysician){
        primaryPhysician = newPrimaryPhysician;
    }

}
