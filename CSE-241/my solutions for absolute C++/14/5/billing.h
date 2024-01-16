#ifndef BILLING_H
#define BILLING_H

#include "patient.h"
#include "doctor.h"

namespace KurutClinic{
    class Billing{

    public:
        Billing();
        Billing(Patient thePatient, Doctor theDoctor, double theDue);
        Billing(const Billing& billingObj);

        Billing& operator=(const Billing& rtSide);

        void setPatient(const Patient& newPatient);
        void setDoctor(const Doctor& newDoctor);
        void setDue(double newDue);

        const Patient& getPatient() const;
        const Doctor& getDoctor() const;
        double getDue() const;

    private:
        Patient patient;
        Doctor doctor;
        double due;
    };  
}


#endif