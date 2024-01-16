#include <iostream>

using namespace std;

class Polynomial{

public:
    Polynomial();
    Polynomial(double constantNumber, int size);
    // constantNumber polynomial.
    Polynomial(const double arr[], int size);
    Polynomial(const Polynomial& polynomialObj);
    ~Polynomial();
    void print() const;
    Polynomial& operator=(const Polynomial& rightSide);
    double& operator[](int index);

    friend const Polynomial operator +(const Polynomial& op1, const Polynomial& op2);
    friend const Polynomial operator +(const Polynomial& op1, double constantNumber);
    friend const Polynomial operator +(double constantNumber, const Polynomial& op2);
    friend const Polynomial operator -(const Polynomial& op1, const Polynomial& op2);
    friend const Polynomial operator -(const Polynomial& op1, double constantNumber);
    friend const Polynomial operator -(double constantNumber, const Polynomial& op2);
    friend const Polynomial operator -(const Polynomial& op);

private:
    double *coef;
    int polSize;
};

int main(){
    double arr[] = {1.0, 2.0, 3.0, 4.5};
    Polynomial myPol(arr, 4);
    myPol.print();

    Polynomial myPol2 = myPol;
    myPol2.print();

    Polynomial myPol3 = myPol + myPol2;

    myPol3.print();
    (myPol3 - 3).print();


    return(0);
}

Polynomial::Polynomial(){
    coef = new double[3];
    polSize = 0;
}

Polynomial::Polynomial(double constantNumber, int size){
    int i;
    polSize = size;
    coef = new double[size];
    for(i = 0; i < size; ++i)
        coef[i] = 0;
    coef[0] = constantNumber;
}


Polynomial::Polynomial(const double arr[], int size){
    coef = new double[size];
    polSize = size;
    int i;
    for(i = 0; i < size; ++i){
        coef[i] = arr[i];
    }
}

Polynomial::Polynomial(const Polynomial& polynomialObj){
    int i;
    polSize = polynomialObj.polSize;
    coef = new double[polSize];
    for(i = 0; i < polSize; ++i)
        coef[i] = polynomialObj.coef[i];
}

Polynomial::~Polynomial(){
    delete [] coef;
}

void Polynomial::print() const{
    int i;
    for(i = polSize - 1; i >= 0; --i){
        cout << "(" << coef[i] << " * x^" << i << ") ";
        if(i != 0)
            cout << "+ ";
    }
    cout << endl;
}

Polynomial& Polynomial::operator=(const Polynomial& rightSide){
    int i;
    if(polSize != rightSide.polSize){
        delete [] coef;
        polSize = rightSide.polSize;
    }
    for(i = 0; i < polSize; ++i)
        coef[i] = rightSide.coef[i];

    return(*this);
}

double& Polynomial::operator[](int index){
    if(index < 0 || index >= polSize){
        cerr << "Attempt to reach invalid index in Polynomial.\n";
        exit(1);
    }
    return(coef[index]);
}

const Polynomial operator +(const Polynomial& op1, const Polynomial& op2){
    double *coef;
    int polSize,
        i;

    if(op1.polSize > op2.polSize)
        polSize = op1.polSize;
    else
        polSize = op2.polSize;
    
    coef = new double[polSize];
    for(i = 0; i < polSize; ++i)
        coef[i] = op1.coef[i] + op2.coef[i];

    Polynomial toReturn(coef, polSize);

    delete [] coef;

    return toReturn;

}

const Polynomial operator +(const Polynomial& op1, double constantNumber){
    return(op1 + Polynomial(constantNumber, op1.polSize));
}

const Polynomial operator +(double constantNumber, const Polynomial& op2){
    return(Polynomial(constantNumber, op2.polSize) + op2);
}

const Polynomial operator -(const Polynomial& op1, const Polynomial& op2){
    return(op1 + (-op2));
}

const Polynomial operator -(const Polynomial& op1, double constantNumber){
    return (op1 + (-Polynomial(constantNumber, op1.polSize)));
}

const Polynomial operator -(double constantNumber, const Polynomial& op2){
    return(Polynomial(constantNumber, op2.polSize) + (-op2));
}

const Polynomial operator -(const Polynomial& op){
    double *coef = new double[op.polSize];
    int polSize = op.polSize,
        i;
    for(i = 0; i < polSize; ++i)
        coef[i] = -op.coef[i];
    
    Polynomial toReturn(coef, polSize);

    delete [] coef;

    return toReturn;
}