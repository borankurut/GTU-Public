#include "billing.h"

namespace KurutClinic{
    Billing::Billing(): patient(Patient()), doctor(Doctor()), due(0.0){/**/}

    Billing::Billing(Patient thePatient, Doctor theDoctor, double theDue):
        patient(thePatient), doctor(theDoctor), due(theDue){/**/}

    Billing::Billing(const Billing& billingObj):
        patient(billingObj.patient), doctor(billingObj.doctor), due(billingObj.due){/**/}

    Billing& Billing::operator=(const Billing& rtSide){
        patient = rtSide.patient;
        doctor = rtSide.doctor;
        due = rtSide.due;
        return(*this);
    }

    void Billing::setPatient(const Patient& newPatient) {patient = newPatient;}

    void Billing::setDoctor(const Doctor& newDoctor) {doctor = newDoctor;}

    void Billing::setDue(double newDue) {due = newDue;}

    const Patient& Billing::getPatient() const {return patient;}

    const Doctor& Billing::getDoctor() const {return doctor;}

    double Billing::getDue() const {return due;}
}