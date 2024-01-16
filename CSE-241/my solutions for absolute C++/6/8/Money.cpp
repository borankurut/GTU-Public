#include <iostream>

using namespace std;

class Money{

public:
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

int main(){
    Money myMoney;

    myMoney.setDollar(15);
    myMoney.setCent(20);

    cout << myMoney.getMoney();

    return(0);
}