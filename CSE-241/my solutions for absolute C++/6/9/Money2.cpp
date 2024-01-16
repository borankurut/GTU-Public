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
    double amt;

};

void Money::setDollar(int newDollar){
    amt -= static_cast<int>(amt);
    amt += newDollar;
}

void Money::setCent(int newCent){
    amt -= amt - static_cast<int>(amt);
    amt += static_cast<double>(newCent) / 100.0;
}

int Money::getDollar(){
    return static_cast<int>(amt);
}

int Money::getCent(){
    return 100 * (amt - static_cast<int>(amt) + 0.0000001);
}

double Money::getMoney(){
    return amt;
}

int main(){
    Money myMoney;

    myMoney.setDollar(15);
    myMoney.setCent(20);

    cout << "$" << myMoney.getMoney() << endl
    << myMoney.getDollar() << endl
    << myMoney.getCent() << endl;

    myMoney.setDollar(20);
    myMoney.setCent(60);

    cout << "$" << myMoney.getMoney() << endl
    << myMoney.getDollar() << endl
    << myMoney.getCent() << endl;

    myMoney.setDollar(10);

    cout << "$" << myMoney.getMoney() << endl
    << myMoney.getDollar() << endl
    << myMoney.getCent() << endl;


    return(0);
}