#include <iostream>
#include "payment.h"

using std::cout;
using std::endl;

namespace KurutPayment{
    Payment::Payment(): amount(0.0){/**/}

    Payment::Payment(float theAmount): amount(theAmount){/**/}

    void Payment::setAmount(float newAmount) {amount = newAmount;}

    float Payment::getAmount() const {return amount;}

    void Payment::paymentDetails() const{
        cout << "Amount of the payment: $" << amount << endl;
    }
}