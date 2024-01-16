#include <iostream>
using namespace std;

int main(){
    const double SALES_PERC = 13.0,   // increase percent in sales from previous year
                PROFIT_PERC = 27.0;   // increase percent in profit from previous year

    double salesPrevYr,     // previous year's sales
            profitPrevYr,   // previous year's profit (in millions)
            salesIncrease,  // increase in sales
            profitIncrease; // increase in profit (in millions)
    
    cout << "Enter the previous year's sales\n>";
    cin >> salesPrevYr;
    cout << "Enter the previous year's profit (in millions)\n>";
    cin >> profitPrevYr;

    salesIncrease = salesPrevYr * (SALES_PERC / 100.0);
    profitIncrease = profitPrevYr * (PROFIT_PERC / 100.0);

    cout << "Increase in sales: " << salesIncrease << endl;
    cout << "Increase in profit: " << profitIncrease << " millions" << endl;

    return(0);
}