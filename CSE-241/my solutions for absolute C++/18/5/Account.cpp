#include <iostream>

using namespace std;

class DepositException{};
class WithdrawException{};
class OverWithdrawException{};

class Account{
public:
    Account(){balance = 0;}

    Account(double initialDeposit){balance = initialDeposit;}

    double getBalance(){return balance;}

    double deposit(double amount) throw(DepositException){
        if (amount < 0)
            throw DepositException();

        balance += amount;

        return balance;
    }

    // returns new balance or -1 if invalid amount
    double withdraw(double amount) throw(WithdrawException, OverWithdrawException){
        if ((amount > balance))
            throw OverWithdrawException();
        else if(amount < 0)
            throw WithdrawException();
        
        balance -= amount;

        return balance;
    }

    void print(){
        cout << "You have $" << balance << " in your account.\n";
    }

private:
    double balance;
};


int main(){
    Account myAccount(5.0);
    myAccount.print();

    try{
        int input;
        cout << "Deposit\n> $";
        cin >> input;
        myAccount.deposit(input);

        cout << "Withdraw\n> $";
        cin >> input;
        myAccount.withdraw(input);
    }
    catch(DepositException e){
        cout << "You cannot deposit less than $0 to your account." << endl;
    }
    catch(WithdrawException e){
        cout << "You cannot withdraw less than $0 from your account." << endl;
    }
    catch(OverWithdrawException e){
        cout << "You don't have enough money in your account." << endl;
    }

    myAccount.print();
    return 0;
}