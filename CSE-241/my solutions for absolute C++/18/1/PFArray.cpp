#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class PFArrayD;
class OutOfRange{   //exception class.
    friend PFArrayD;

public:
    OutOfRange(int theIx, string theMsg);
private:
    int ix;
    string msg;
};

class PFArrayD{
public:
    PFArrayD();

    PFArrayD(int theCapacity);

    PFArrayD(const PFArrayD& pfaObj);

    void addElement(double element);

    bool full() const;

    int getCapacity() const;

    int getNumberUsed() const;

    void emptyArray();

    double& operator[](int index);

    PFArrayD& operator=(const PFArrayD& rtSide);

    virtual ~PFArrayD();
private:
    void incrementCapacity(int n);
    double *a;
    int capacity;
    int used;
};

OutOfRange::OutOfRange(int theIx, string theMsg): 
    ix(theIx), msg(theMsg){/**/}

PFArrayD::PFArrayD(): capacity(5), used(0){
    a = new double[capacity];
}

PFArrayD::PFArrayD(int theCapacity): capacity(theCapacity), used(0){
    a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD& pfaObj):
    capacity(pfaObj.capacity), used(pfaObj.used)
{
    a = new double[capacity];
    int i;
    for(i = 0; i < used; ++i)
        a[i] = pfaObj.a[i];
}

void PFArrayD::addElement(double element){
    try
    {
        if(full())
            throw OutOfRange(used, "Attempt to add an element into full array.");

        a[used++] = element;
    }
    catch(OutOfRange outE)
    {   
        incrementCapacity(outE.ix - capacity + 5);
        a[used++] = element;
    }
}

bool PFArrayD::full() const{
    return(capacity <= (used + 1)); // +1 is just to be safe.
}

int PFArrayD::getCapacity() const {return capacity;}

int PFArrayD::getNumberUsed() const {return used;}

void PFArrayD::emptyArray() {used = 0;}

double& PFArrayD::operator[](int index){
    try{
        if(index < 0 || index >= used){
            throw OutOfRange(index, "PFArrayD::operator[] out of range index");
        }
        return a[index];
    }
    catch(OutOfRange outE){
        cout << "Trying to access the index " << outE.ix << endl
            <<  outE.msg << endl
            << "Program aborted." << endl;
        exit(1);
    }
}

PFArrayD& PFArrayD::operator=(const PFArrayD& rtSide){
    if(capacity != rtSide.capacity){
        delete [] a;
        capacity = rtSide.capacity;
        a = new double[capacity];
    }
    used = rtSide.used;

    int i;
    for(i = 0; i < used; ++i){
        a[i] = rtSide.a[i];
    }
    return(*this);
}

PFArrayD::~PFArrayD(){
    delete [] a;
}

void PFArrayD::incrementCapacity(int n){
    double *newA = new double[capacity + n];
    capacity += n;

    int i;
    for(i = 0; i < used; ++i)
        newA[i] = a[i];

    delete [] a;
    a = newA;
}

int main(){
    PFArrayD myArr;
    myArr.addElement(1.5);
    myArr.addElement(2.5);
    myArr.addElement(3.5);
    myArr.addElement(4.5);
    myArr.addElement(5.5);
    myArr.addElement(6.5);
    myArr.addElement(7.5);

    int i;
    for(i = 0; i < 10; ++i)
        cout << myArr[i] << endl;

    return 0;
}