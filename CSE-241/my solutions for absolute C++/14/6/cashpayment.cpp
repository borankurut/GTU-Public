#include <iostream>
#include "cashpayment.h"

using std::cout;
using std::endl;

namespace KurutPayment{
    CashPayment::CashPayment(): Payment(){/**/}
    CashPayment::CashPayment(float theAmount): Payment(theAmount){/**/}

    void CashPayment::paymentDetails() const{
        cout << "Amount of the payment(cash): $" << getAmount() << endl;
    }

}