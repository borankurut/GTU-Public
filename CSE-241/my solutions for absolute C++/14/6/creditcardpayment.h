#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H

#include <string>
#include "payment.h"

using std::string;

namespace KurutPayment{
    class CreditCardPayment: public Payment{

    public:
        CreditCardPayment();
        CreditCardPayment(float theAmount, string theNameOnTheCard,
            string theExpirationDate, string theCardNumber);
        
        void setNameOnTheCard(string newNameOnTheCard);
        void setExpirationDate(string newExpirationDate);
        void setCardNumber(string newCardNumber);
        
        string getNameOnTheCard() const;
        string getExpirationDate() const;
        string getCardNumber() const;

        void paymentDetails() const;
        
    private:
        string nameOnTheCard;
        string expirationDate;
        string cardNumber;

        string hide() const;
    };
}

#endif