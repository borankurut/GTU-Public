#include "creditcardpayment.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

namespace KurutPayment{

    CreditCardPayment::CreditCardPayment(): 
        Payment(), nameOnTheCard(""), expirationDate("00/00"), 
        cardNumber("0000-0000-0000-0000"){/**/}

    CreditCardPayment::CreditCardPayment(float theAmount, string theNameOnTheCard,
            string theExpirationDate, string theCardNumber):
        Payment(theAmount), nameOnTheCard(theNameOnTheCard), 
        expirationDate(theExpirationDate), cardNumber(theCardNumber){/**/}

    void CreditCardPayment::setNameOnTheCard(string newNameOnTheCard)
    {nameOnTheCard = newNameOnTheCard;}

    void CreditCardPayment::setExpirationDate(string newExpirationDate)
    {expirationDate = newExpirationDate;}

    void CreditCardPayment::setCardNumber(string newCardNumber)
    {cardNumber = newCardNumber;}

    string CreditCardPayment::getNameOnTheCard() const
    {return nameOnTheCard;}

    string CreditCardPayment::getExpirationDate() const
    {return expirationDate;}

    string CreditCardPayment::getCardNumber() const
    {return cardNumber;}

    void CreditCardPayment::paymentDetails() const{
        cout << "Credit card payment $" << getAmount() << endl 
            << "'" << hide() << "' numbered" << endl
            << getExpirationDate() << " expiration dated credit card of "
            << getNameOnTheCard() << endl;
        
    }

    string CreditCardPayment::hide() const{
        string hidden = getCardNumber();
        int i;
        for(i = 0; i < hidden.length(); ++i)
            if(hidden[i] != '-' && (i > 3))
                hidden[i] = '*';

        return hidden;
    }
}