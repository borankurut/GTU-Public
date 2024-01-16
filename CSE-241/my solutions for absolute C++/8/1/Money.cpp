#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Money{

public:
    Money();
    Money(double amount);
    Money(int newDollars, int newCents);
    Money(int newDollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;
    const Money percent(int percentFigure) const;
    friend const Money operator +(const Money &op1, const Money &op2);
    friend const Money operator -(const Money &op1, const Money &op2);
    friend bool operator ==(const Money &op1, const Money &op2);
    friend const Money operator -(const Money &op);
    friend istream& operator >>(istream &inputStream, Money &op);
    friend ostream& operator <<(ostream &outputStream, const Money &op);
    friend bool operator <(const Money &op1, const Money &op2);
    friend bool operator <=(const Money &op1, const Money &op2);
    friend bool operator >(const Money &op1, const Money &op2);
    friend bool operator >=(const Money &op1, const Money &op2);

private:
    int dollars, 
        cents;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
};

int main(){
    Money money1,
        money2;

    int fig1,
        fig2;

    cin >> money1 >> money2;
    if(money1 > money2){
        cout << money1 << "is greater than " << money2 << endl;
    }
    if(money1 >= money2){
        cout << money1 << "is greater or equal to " << money2<< endl;
    }
    if(money1 <= money2){
        cout << money1 << "is less than or equal to " << money2<< endl;
    }
    if(money1 < money2){
        cout << money1 << "is less than " << money2<< endl;
    }

    cout << "Enter fig 1 and fig 2: ";
    cin >> fig1 >> fig2;

    cout << "%" << fig1 << " of " << money1 << " is: " << money1.percent(fig1) << endl;
    cout << "%" << fig2 << " of " << money2 << " is: " << money2.percent(fig2) << endl;


    return(0);
}

int Money::dollarsPart(double amount) const{
    return(static_cast<int>(amount));
}

int Money::centsPart(double amount) const{
    int cents = ((amount+amount*0.00000001) - static_cast<int>(amount)) * 100;
    return cents;
}

int Money::round(double number) const{
    return static_cast<int>(floor(number + 0.5));
}


Money::Money(): dollars(0), cents(0){/*empty*/};

Money::Money(double amount){
    dollars = dollarsPart(amount);
    cents = centsPart(amount);
}

Money::Money(int newDollars, int newCents): dollars(newDollars), cents(newCents){/*empty*/}

Money::Money(int newDollars): dollars(newDollars){/*empty*/}

double Money::getAmount() const{
    return(dollars + cents / 100.0);
}

int Money::getDollars() const{
    return(dollars);
}

int Money::getCents() const{
    return(cents);
}


const Money operator +(const Money &op1, const Money &op2){
    int allCents = (op1.cents + op1.dollars*100) + (op2.cents + op2.dollars*100);
    int absAllCents = abs(allCents);
    int sumCents = absAllCents % 100;
    int sumDollars = absAllCents / 100;

    if(allCents < 0){
        sumCents = -sumCents;
        sumDollars = -sumDollars;
    }

    return(Money(sumDollars, sumCents));
}

const Money operator -(const Money &op1, const Money &op2){
    int allCents = (op1.cents + op1.dollars*100) - (op2.cents + op2.dollars*100);
    int absAllCents = abs(allCents);
    int difCents = absAllCents % 100;
    int difDollars = absAllCents / 100;

    if(allCents < 0){
        difCents = -difCents;
        difDollars = -difDollars;
    }

    return(Money(difDollars, difCents));
}

bool operator ==(const Money &op1, const Money &op2){
    return(op1.dollars == op2.dollars && op1.cents == op2.cents);
}

const Money operator -(const Money &op){
    return(Money(-op.dollars, -op.cents));
}

istream& operator >>(istream &inputStream, Money &op){
    char dollarSign;
    double moneyValue;
    cout << "Enter value:";
    inputStream >> dollarSign >> moneyValue;
    op.dollars = op.dollarsPart(moneyValue);
    op.cents = op.centsPart(moneyValue);

    return(inputStream);
}

ostream& operator <<(ostream &outputStream, const Money &op){
    int dispDollars = abs(op.dollars);
    int dispCents = abs(op.cents);
    
    if(op.dollars < 0 || op.cents < 0)
        outputStream << "-";
    outputStream << "$" << dispDollars << ".";
    if(dispCents< 10)
        outputStream << "0";
    outputStream << dispCents;
    return(outputStream);
}

bool operator <(const Money &op1, const Money &op2){
    return( (op1.dollars < op2.dollars) || 
            (op1.dollars == op2.dollars && op1.cents < op2.cents));
}

bool operator <=(const Money &op1, const Money &op2){
    return !(op1 > op2);
}

bool operator >(const Money &op1, const Money &op2){
    return( (op1.dollars > op2.dollars) || 
            (op1.dollars == op2.dollars && op1.cents > op2.cents));
}

bool operator >=(const Money &op1, const Money &op2){
    return !(op1 < op2);
}

const Money Money::percent(int percentFigure) const{
    int allCents = dollars*100 + cents;
    double newValue = (percentFigure/100.0) * allCents;
    newValue = round(newValue) / 100.0;//cent to dollars;
    cout << newValue;
    return(Money(newValue));
}