#include <iostream>
using namespace std;

struct Employee
{
    int coreCmp,        // graded on 10 points, %30 of final
        prfrmncEva,     // graded on 30, %50 of final
        ideation,       // graded on 10, %20 of final
        final;          // final rating
};

int computeFinal(int core, int prf, int id);
int rateFinal(int final);
void getEmployee(Employee &employee);


int main(){

    Employee employee;
    char quit = 'c';

    while(quit != 'q'){
        getEmployee(employee);
        cout << "Final point: " << employee.final << endl;
        cout << "Rate: " << rateFinal(employee.final) << ".\n";

        cout << "Enter 'q' to quit or 'c' to continue: ";
        cin >> quit;
    }

    return(0);
}

int computeFinal(int core, int prf, int id){
    int final = 0;
    final += (core * 10.0) * (30.0 / 100.0) + 0.5;          // 0.5 added to roll.
    final += (prf * (10.0/3.0)) * (50.0 / 100.0) + 0.5;
    final += (id * 10.0) * (20.0 / 100.0) + 0.5;
    return (final);
}

int rateFinal(int final){
    int rate;
    if(final >= 80)
        rate = 1;
    else if(final >= 60)
        rate = 2;
    else if(final >= 50)
        rate = 3;
    else 
        rate = 4;

    return(rate);
}

void getEmployee(Employee &employee){
    cout << "Enter Core competency: ";
    cin >> employee.coreCmp;

    cout << "Enter Performance evaluation: ";
    cin >> employee.prfrmncEva;

    cout << "Enter Ideation: ";
    cin >> employee.ideation;

    employee.final = computeFinal(employee.coreCmp, employee.prfrmncEva, employee.ideation);
}