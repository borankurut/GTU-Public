#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"
#include "doctor.h"

namespace KurutClinic{
    class Patient: public Person{

    public:
        Patient();
        Patient(string theName, const Doctor& thePrimaryPhysician);
        Patient(const Patient& patientObj);

        Patient& operator=(const Patient& rtSide);

        const Doctor& getPrimaryPhysician() const;

        void setPrimaryPhysician(const Doctor& newPrimaryPhysician);

    private:
        Doctor primaryPhysician;

    };
}

#endif