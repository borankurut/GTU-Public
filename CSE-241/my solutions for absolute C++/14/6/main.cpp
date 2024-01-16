#include <iostream>
#include "payment.h"
#include "cashpayment.h"
#include "creditcardpayment.h"

using namespace std;
using namespace KurutPayment;

int main(){
    CashPayment newcash(12.0);
    CashPayment newcash2(24.0);

    CreditCardPayment newcredit(250.0, "Walter Savitch", "12/23", "1122-3344-5566-7788");
    CreditCardPayment newcredit2(10.0, "Boran Kurut", "05/24", "4321-1234-5678-8765");

    newcash.paymentDetails();
    cout << endl;
    newcash2.paymentDetails();
    cout << endl;

    newcredit.paymentDetails();
    cout << endl;
    newcredit2.paymentDetails();
    cout << endl;

    return(0);
}