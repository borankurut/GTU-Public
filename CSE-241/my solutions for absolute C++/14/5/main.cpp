#include <iostream>
#include "billing.h"
#include "doctor.h"
#include "employee.h"
#include "patient.h"
#include "person.h"
#include "salariedemployee.h"

using namespace std;
using namespace KurutClinic;

int main(){

    Doctor newBillDoctor("billDoctorName", "billSsn", 10000.0, "brain", 50.0);

    Doctor newDoctor("newDoctorName", "newSsn", 5000.0, "cardiology", 75.0);

    Patient newPatient("patientName", newDoctor);
    
    Billing newBill(newPatient, newBillDoctor, 150.0);


    cout << "doctor in bill:\n";

    cout << newBill.getDoctor().getName() << endl;
    cout << newBill.getDoctor().getNetPay() << endl;
    cout << newBill.getDoctor().getOfficeVisitFee() << endl;
    cout << newBill.getDoctor().getSalary() << endl;
    cout << newBill.getDoctor().getSpecialty() << endl;
    cout << newBill.getDoctor().getSsn() << endl;


    cout << "\n\npatientName:\n";
    cout << newBill.getPatient().getName() << endl;
    cout << "Patient's doctor:\n";

    cout << newBill.getPatient().getPrimaryPhysician().getName() << endl;
    cout << newBill.getPatient().getPrimaryPhysician().getNetPay() << endl;
    cout << newBill.getPatient().getPrimaryPhysician().getOfficeVisitFee() << endl;
    cout << newBill.getPatient().getPrimaryPhysician().getSalary() << endl;
    cout << newBill.getPatient().getPrimaryPhysician().getSpecialty() << endl;
    cout << newBill.getPatient().getPrimaryPhysician().getSsn() << endl;


    return(0);
}