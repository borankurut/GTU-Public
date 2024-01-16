#include <iostream>

using namespace std;

class Money{

public:

    Money(int newDollar, int newCent);
    Money();
    void setDollar(int newDollar);
    void setCent(int newCent);

    int getDollar();
    int getCent();

    double getMoney();


private:
    int dollar,
        cent;

};

void Money::setDollar(int newDollar){
    dollar = newDollar;
}

void Money::setCent(int newCent){
    cent = newCent;
}

int Money::getDollar(){
    return dollar;
}

int Money::getCent(){
    return cent;
}

double Money::getMoney(){
    return static_cast<double>(dollar) + static_cast<double>(cent) / 100.0;
}

Money::Money(int newDollar, int newCent) : dollar(newDollar), cent(newCent){/*empty*/}
Money::Money() : dollar(0), cent(0){/*empty*/}

int main(){
    Money myMoney(15, 20);
    Money myMoney2;

    cout << myMoney.getMoney() << endl;
    cout << myMoney2.getMoney() << endl;

    return(0);
}