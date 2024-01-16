#ifndef PAYMENT_H
#define PAYMENT_H

namespace KurutPayment{
    class Payment{

    public:
        Payment(); // sets amount 0.0
        Payment(float theAmount);

        void setAmount(float newAmount);
        float getAmount() const;

        void paymentDetails() const;

    private:
        float amount;

    };
}

#endif