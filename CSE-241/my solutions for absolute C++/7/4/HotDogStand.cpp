#include <iostream>

using namespace std;

class HotDogStand{

private:

    int idNum,
        hotDogsSold;

    static int totalSold;

public:

    HotDogStand(int newId, int newSold);
    HotDogStand();
    void justSold();
    int soldAmount();
    static int totalSoldAmount();

};

int HotDogStand::totalSold = 0;

HotDogStand::HotDogStand(int newId, int newSold){
    idNum = newId;
    hotDogsSold = newSold;
    totalSold += newSold;
}

HotDogStand::HotDogStand(){
    idNum = 0;
    hotDogsSold = 0;
}

void HotDogStand::justSold(){
    hotDogsSold += 1;
    totalSold += 1;
}

int HotDogStand::soldAmount(){
    return(hotDogsSold);
}

int HotDogStand::totalSoldAmount(){
    return(totalSold);
}

int main(){

    HotDogStand stand0(0, 5), 
                stand1(1, 3), 
                stand2(2, 10);

    cout << stand0.soldAmount() << endl;
    cout << stand1.soldAmount() << endl;
    cout << stand2.soldAmount() << endl;

    cout << HotDogStand::totalSoldAmount() << endl;

    stand0.justSold();
    stand1.justSold();

    cout << stand0.soldAmount() << endl;
    cout << stand1.soldAmount() << endl;
    cout << stand2.soldAmount() << endl;

    cout << HotDogStand::totalSoldAmount() << endl;

    return(0);
}