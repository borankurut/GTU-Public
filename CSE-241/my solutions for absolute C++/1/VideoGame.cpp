#include <iostream>
using namespace std;

int main(){
    const int CANDY_BAR_CP = 10;    // amount of coupons cost for a candy bar
    const int GUMBALL_CP = 3;       // amount of coupons cost for a gumball

    int coupons,
        candyBars,
        gumballs;

    cout << "Enter the number of coupons\n>";
    cin >> coupons;

    candyBars = coupons / CANDY_BAR_CP;
    coupons %= CANDY_BAR_CP;

    gumballs = coupons / GUMBALL_CP;
    coupons %=  GUMBALL_CP;

    cout << "You get " << candyBars << " candy bars and "
        << gumballs << " gumballs.\n";
    
    cout << "Remaining coupons: " << coupons << endl;

    return(0);
}