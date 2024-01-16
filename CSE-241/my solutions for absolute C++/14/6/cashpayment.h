#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "payment.h"

namespace KurutPayment{
    class CashPayment: public Payment{

    public:
        CashPayment();
        CashPayment(float theAmount);

        void paymentDetails() const;

    private:
        //empty
    
    };
}

#endif