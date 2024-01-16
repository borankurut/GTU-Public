#include <iostream>

using namespace std;

class TwoD
{
public:
    static int getAlive();

    TwoD();
    // makes 5x5 arrayCapacity with all elements initialized to 0. ++alive
    TwoD(int row, int column);
    // makes row x column arraCapacity with all elements initialized to 0. ++alive
    TwoD(const TwoD& twodObject);
    // Copy constructor
    ~TwoD();
    // Destructor --alive.
    double getElement(int row, int column) const;
    void setElement(int row, int column, double element);
    TwoD& operator=(const TwoD& rightSide);
    friend const TwoD operator+(const TwoD& op1, const TwoD& op2);
    void print() const;


private:
    double **a;
    int maxRows;
    int maxColumns;
    static int alive;
    bool sameSize(const TwoD& other) const;
};

void test();

int TwoD::alive = 0;

int main(){
    TwoD myArr;

    myArr.print();
    myArr.setElement(0, 1, 1);
    myArr.print();

    TwoD myArr2 = myArr;

    myArr2.setElement(0, 1, 2);
    myArr.print();
    myArr2.print();

    (myArr+myArr2).print();

    myArr.print();
    myArr2.print();



    return(0);
}

TwoD::TwoD(): maxRows(5), maxColumns(5){
    int i, j;
    
    a = new double* [maxRows];
    for(i = 0; i < maxRows; ++i){
        a[i] = new double[maxColumns];
        for(j = 0; j < maxColumns; ++j)
            a[i][j] = 0.0;
    }

    ++alive;
}

TwoD::TwoD(const TwoD& twodObject): 
maxRows(twodObject.maxRows), maxColumns(twodObject.maxColumns){
    a = new double* [maxRows];
    int i, j;
    for(i = 0; i < maxRows; ++i){
        a[i] = new double[maxColumns];
        for(j = 0; j < maxColumns; ++j)
            a[i][j] = twodObject.a[i][j];
    }

    ++alive;
}
TwoD::TwoD(int row, int column):
maxRows(row), maxColumns(column){
    int i, j;

    a = new double* [maxRows];
    for(i = 0; i < maxRows; ++i){
        a[i] = new double[maxColumns];
        for(j = 0; j < maxColumns; ++j)
            a[i][j] = 0.0;
    }

    ++alive;
}

TwoD::~TwoD()
{
    int ix;
    for(ix = 0; ix < maxRows; ++ix)
        delete [] a[ix];
    delete [] a;
    --alive;
}

int TwoD::getAlive(){
    return(alive);
}

double TwoD::getElement(int row, int column) const{
    if(row >= 0 && column >= 0 && row < maxRows && column < maxColumns)
        return(a[row][column]);
    else{
        cerr << "Attempt to get an invalid indexed element in TwoD!\n";
        exit(1);
    }
}

void TwoD::setElement(int row, int column, double element){
    if(row >= 0 && column >= 0 && row < maxRows && column < maxColumns)
        a[row][column] = element;
    else{
        cerr << "Attempt to set an invalid indexed element in TwoD!\n";
        exit(1);
    }
}

TwoD& TwoD::operator=(const TwoD& rightSide){
    int i, 
        j;
    if(!sameSize(rightSide)){
        for(i = 0; i < maxRows; ++i)
            delete [] a[i];
        delete [] a;

        maxRows = rightSide.maxRows;
        maxColumns = rightSide.maxColumns;
        a = new double*[maxRows];
        for(i = 0; i < maxRows; ++i)
            a[i] = new double[maxColumns];
    }

    for(i = 0; i < maxRows; ++i)
        for(j = 0; j < maxColumns; ++j)
            a[i][j] = rightSide.a[i][j];
    
    return(*this);
}

const TwoD operator+(const TwoD& op1, const TwoD& op2){
    int i,
        j;
    TwoD toReturn(op1);
    if(op1.sameSize(op2)){
        for(i = 0; i < toReturn.maxRows; ++i)
            for(j = 0; j < toReturn.maxColumns; ++j)
                toReturn.setElement(i, j, op1.a[i][j] + op2.a[i][j]);
    }
    else
        toReturn = TwoD();
    return(toReturn);
}

bool TwoD::sameSize(const TwoD& other) const{
    return(maxRows == other.maxRows && maxColumns == other.maxColumns);   
}

void TwoD::print() const{
    int i,
        j;

    for(i = 0; i < maxRows; ++i){
        cout << "{";
        for(j = 0; j < maxColumns; ++j)
            cout << "'" << a[i][j] << "' ";
        cout << "}\n";
    }
    cout << endl;
}

