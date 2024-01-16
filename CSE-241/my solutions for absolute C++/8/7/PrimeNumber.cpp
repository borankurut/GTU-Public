#include <iostream>

using namespace std;

class PrimeNumber{

public:
    PrimeNumber();
    PrimeNumber(int prime);

    friend PrimeNumber operator ++(PrimeNumber &primeNumber); //prefix
    friend PrimeNumber operator --(PrimeNumber &primeNumber); //prefix
    friend PrimeNumber operator ++(PrimeNumber &primeNumber, int); //postfix
    friend PrimeNumber operator --(PrimeNumber &primeNumber, int); //postfix
    bool isPrime(int toCheck);
    int getValue();

private:
    int value;

};

int main(){
    PrimeNumber myPrime(53);

    return(0);
}

PrimeNumber::PrimeNumber(): value(1){/*empty*/}

PrimeNumber::PrimeNumber(int prime){
    if(isPrime(prime) == true)
        value = prime;
    else{
        cerr << "**Error: PrimeNumber constructor parameter not prime number value!\n";
        exit(1);
    }
}

bool PrimeNumber::isPrime(int toCheck){
    int divideAmount = 0,
        ix;
    for(ix = 1; ix <= toCheck; ++ix)
        if(toCheck % ix == 0)
            ++divideAmount;

    return(divideAmount == 2);
}

PrimeNumber operator ++(PrimeNumber &primeNumber){//prefix
    PrimeNumber next;

    int newValue = primeNumber.value;
    do{
        ++newValue;
    }while(!next.isPrime(newValue));

    next.value = newValue;

    primeNumber = next;
    return primeNumber;
}

PrimeNumber operator --(PrimeNumber &primeNumber){//prefix
    PrimeNumber previous;

    int newValue = primeNumber.value;
    if(primeNumber.value > 2){
        do{
            --newValue;
        }while(!previous.isPrime(newValue));

        previous.value = newValue;
    }
    else{
        previous.value = 2;
    }

    primeNumber = previous;
    return primeNumber;
}

PrimeNumber operator ++(PrimeNumber &primeNumber, int){//postfix
    PrimeNumber next,
                save;

    int newValue = primeNumber.value;
    do{
        ++newValue;
    }while(!next.isPrime(newValue));

    next.value = newValue;

    save = primeNumber;
    primeNumber = next;
    return save;
}

PrimeNumber operator --(PrimeNumber &primeNumber, int){//postfix
    PrimeNumber previous,
                save;

    int newValue = primeNumber.value;
    if(primeNumber.value > 2){
        do{
            --newValue;
        }while(!previous.isPrime(newValue));

        previous.value = newValue;
    }
    else{
        previous.value = 2;
    }

    save = primeNumber;
    primeNumber = previous;
    return save;
}

int PrimeNumber::getValue(){
    return(value);
}