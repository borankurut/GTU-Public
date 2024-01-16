#include <iostream>
#include <cmath>

using namespace std;

class Rational{
public:
    Rational();
    Rational(int wholeNumber);
    Rational(int newNumerator, int newDenominator);
    friend istream& operator >>(istream& inputStream, Rational& rational);
    friend ostream& operator <<(ostream& outputStream, const Rational& rational);
    friend bool operator ==(const Rational& op1, const Rational& op2);
    friend bool operator !=(const Rational& op1, const Rational& op2);
    friend bool operator <(const Rational& op1, const Rational& op2);
    friend bool operator <=(const Rational& op1, const Rational& op2);
    friend bool operator >(const Rational& op1, const Rational& op2);
    friend bool operator >=(const Rational& op1, const Rational& op2);
    friend const Rational operator+(const Rational& op1, const Rational& op2);
    friend const Rational operator-(const Rational& op1, const Rational& op2);
    friend const Rational operator*(const Rational& op1, const Rational& op2);
    friend const Rational operator/(const Rational& op1, const Rational& op2);

private:
    int numerator,
        denominator;
    void normalize();
    bool valid() const;
};

int main(){

    while(true){
        Rational rational,
                rational2;

        cin >> rational;
        cout << rational << endl;
        cin >> rational2;
        cout << rational2 << endl;

        cout << rational << " == " << rational2 << ": " << (rational == rational2) << endl;
        cout << rational << " != " << rational2 << ": " << (rational != rational2) << endl;
        cout << rational << " < " << rational2 << ": " << (rational < rational2) << endl;
        cout << rational << " > " << rational2 << ": " << (rational > rational2) << endl;

        cout << rational << " + " << rational2 << ": " << (rational + rational2) << endl;
        cout << rational << " - " << rational2 << ": " << (rational - rational2) << endl;
        cout << rational << " * " << rational2 << ": " << (rational * rational2) << endl;
        cout << rational << " / " << rational2 << ": " << (rational / rational2) << endl;
        
    }

    return(0);  
}

Rational::Rational(): numerator(0), denominator(1){/**/}

Rational::Rational(int wholeNumber): numerator(wholeNumber), denominator(1){/**/}

Rational::Rational(int newNumerator, int newDenominator): 
numerator(newNumerator), denominator(newDenominator){
    normalize();
}

void Rational::normalize(){
    int i;

    if(abs(numerator) < abs(denominator))
        i = abs(numerator);
    else
        i = abs(denominator);

    for(; i > 1; i--)
        if(numerator % i == 0 && denominator % i == 0){
            numerator /= i;
            denominator /= i;
        }

    if(denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }
}

istream& operator >>(istream& inputStream, Rational& rational){
    char divideCharacter;
    do{
        inputStream >> rational.numerator >> divideCharacter >> rational.denominator;
        if(rational.valid() == false)
            cout << "Denominator cannot be zero.\n";
    }while(!rational.valid());

    rational.normalize();

    return inputStream;
}

ostream& operator <<(ostream& outputStream, const Rational& rational){
    cout << rational.numerator << "/" << rational.denominator;
    return outputStream;
}

bool Rational::valid() const{
    return(denominator != 0);
}   

bool operator ==(const Rational& op1, const Rational& op2){
    return(op1.numerator == op2.numerator && op2.denominator == op2.denominator);
}

bool operator !=(const Rational& op1, const Rational& op2){
    return!(op1 == op2);
}

bool operator <(const Rational& op1, const Rational& op2){
    return(op1.numerator*op2.denominator < op2.numerator*op1.denominator); // ad < cb
}

bool operator <=(const Rational& op1, const Rational& op2){
    return!(op1 > op2);
}

bool operator >(const Rational& op1, const Rational& op2){
    return(op1.numerator*op2.denominator > op2.numerator*op1.denominator);
}

bool operator >=(const Rational& op1, const Rational& op2){
    return!(op1 < op2);
}

const Rational operator+(const Rational& op1, const Rational& op2){
    return Rational((op1.numerator * op2.denominator + op2.numerator * op1.denominator), //numerator
                    (op1.denominator * op2.denominator));                                //denominator
}

const Rational operator-(const Rational& op1, const Rational& op2){
    return Rational((op1.numerator * op2.denominator - op2.numerator * op1.denominator), //numerator
                    (op1.denominator * op2.denominator));                                //denominator
}

const Rational operator*(const Rational& op1, const Rational& op2){
    return Rational((op1.numerator * op2.numerator),        //numerator
                    (op1.denominator * op2.denominator));   //denominator
}

const Rational operator/(const Rational& op1, const Rational& op2){
    return Rational((op1.numerator * op2.denominator),      //numerator
                    (op1.denominator * op2.numerator));     //denominator
}