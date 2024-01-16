#include <iostream>
#include <random>
#include <time.h>

using namespace std;
const int minValidNum = 1;
const int maxValidNum = 987654321;
const int maxAttempt = 100;

bool differentDigits(int num);
bool isValidNum(int num);
int generateRandom(int digitAmount);
int digitAmountOf(int num);
bool validGuess(int guess, int secret){return digitAmountOf(guess) == digitAmountOf(secret);}
void game(int secret);

int exactCount(int secret, int guess);
int misplacedCount(int secret, int guess);

bool check_number(string str);

int main(int argc, char *argv[]){
    srand(time(0));
    int secret;

    string choice = argv[1];

    if(!check_number(string(argv[2]))){
        cout << "E2";
        exit(1);
    }

    int argNumber = stoi(argv[2]); 

    if(choice == "-r"){ // user argument is random.
        if(argNumber <= 0 || argNumber >= 10){ // invalid digit amount
            cout << "E0";
            exit(0);
        }
        else
            secret = generateRandom(argNumber);
    }

    else if(choice == "-u"){    // user argument is user.
        if(!isValidNum(argNumber)){
            cout << "E0";
            exit(0);
        }
        else
            secret = argNumber;
    }

    else{
        cout << "E0";
        exit(0);
    }

    game(secret);

    return(0);
}

// returns whether number is valid
// number interval checked first to speed up the function
bool isValidNum(int num){
    return(num >= minValidNum && num <= maxValidNum && differentDigits(num));
}

//returns true if num doesn't have same digit twice
bool differentDigits(int num){
    bool different = true;          // assume number has different digits

    int digitToCheck = num%10;
    num /= 10;
    int digitsSoFar[10];
    int n = 0;                      // digitsSoFar used positions
    

    digitsSoFar[n++] = digitToCheck; // take rightmost digit

    while(num != 0){                        // loop through all digits
        digitToCheck = num%10;              // take next digit to check
        num /= 10;  
        for(int i = 0; i < n; ++i){    // compare current digit with digits so far
            if(digitsSoFar[i] == digitToCheck){         
                different = false;
                break;
            }
        }
        if(different)
            digitsSoFar[n++] = digitToCheck;    // update digits so far
    }
    return different;
}

// generates random valid number 
int generateRandom(int digitAmount){
    int randomNumber;
    
    // make different random digits and multiply with digit power to generate randomNumber
    do{
        int digits[10];
        int n = 0;

        for(int i = 0; i < digitAmount; ++i){
            digits[n++] = rand() % 10;
        }

        randomNumber = 0;
        int multiplier = 1;
        for(int i = 0; i < n; ++i){
            randomNumber += digits[i] * multiplier;
            multiplier *= 10;
        }

    }while(!isValidNum(randomNumber));

    return randomNumber;
}

// returns number of digits of num
int digitAmountOf(int num){
    int digitAmount = 0;

    if(num == 0)
        digitAmount = 1;

    while(num!=0){
        num/=10;
        digitAmount += 1;
    }
    return digitAmount;   
}

int exactCount(int secret, int guess){
    int count = 0;

    int secretDigit = secret%10;
    int guessDigit = guess%10;
    secret/=10;
    guess/=10;

    if(secretDigit == guessDigit)
        count += 1;

    // iterate right to left and increase count if the digits are same
    while(secret != 0 && guess != 0){
        secretDigit = secret%10;
        guessDigit = guess%10;
        secret/=10;
        guess/=10;
        if(secretDigit == guessDigit)
            count += 1;
    }
    return count;
}

// computes the same digits number of secret and guess then subtracts exactCount 
// to find misplacedCount 
int misplacedCount(int secret, int guess){
    int secretArr[10];
    int secretN = 0;

    int guessArr[10];
    int guessN = 0;

    int exact = exactCount(secret, guess); // save exactCount

    // secret into array
    secretArr[secretN++] = secret % 10;
    secret /= 10;
    while(secret != 0){
        secretArr[secretN++] = secret % 10;
        secret /= 10;
    }

    // guess into array
    guessArr[guessN++] = guess % 10;
    guess /= 10;
    while(guess != 0){
        guessArr[guessN++] = guess % 10;
        guess /= 10;
    }

    // search every element in secret, inside guess and increase sameDigitAmount if found
    int sameDigitAmount = 0;
    for(int i = 0; i < secretN; ++i){
        for(int j = 0; j < guessN; ++j)
            if(secretArr[i] == guessArr[j])
                sameDigitAmount += 1; 
    }

    int misplaced = sameDigitAmount - exact;
    return misplaced;
}

void game(int secret){
    int attempts = 0;
    int guess = -1;

    while(guess != secret && attempts < maxAttempt){
        cin >> guess;
        if(!validGuess(guess, secret)){ // if guess doesn't have same number of digits, exit.
            cout << "E1";
            exit(0);
        }

        cout << exactCount(secret, guess) << " " 
            << misplacedCount(secret, guess) << endl;

        attempts += 1;
    }
    
    if(attempts >= maxAttempt)
        cout << "FAILED\n";
        
    else if(guess == secret){
        cout << "FOUND " << attempts << endl;
    }
}

bool check_number(string str) {
   for(int i = 0; i < str.length(); i++)
        if(isdigit(str[i]) == false)
            return false;
    return true;
}