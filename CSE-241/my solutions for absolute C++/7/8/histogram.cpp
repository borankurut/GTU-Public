#include <iostream>
#include <vector>

using namespace std;

class Histogram{
public:
    Histogram(vector<int> newGrades);
    Histogram();
    void addGrade(int toAddGrade);
    void output();
    int computeMaxValue();
    int getMax();
    void computeHistogram();
    void printAmounts();
    int amountOf(int grade);
private:
    vector<int> grades;
    vector<int> amounts;
    int maxValue;

};

int main(){
    Histogram myHisto;

    int grade = 0;
    while(grade != -1){
        cin >> grade;
        myHisto.addGrade(grade);
        myHisto.output();
    }
    return(0);
}

void Histogram::addGrade(int toAddGrade){
    bool found = false;
    int ToPlaceGrade,
        ix;
    for(ix = 0; ix < grades.size(); ++ix){
        if(toAddGrade < grades[ix]){
            found = true;
            ToPlaceGrade = grades[ix];
            grades[ix] = toAddGrade;
            addGrade(ToPlaceGrade);
            break;
        }
    }
    if(!found)
        grades.push_back(toAddGrade);

    maxValue = computeMaxValue();
}

void Histogram::output(){
    int ix;
    for(ix = 0; ix < grades.size(); ++ix){
        cout << grades[ix] << " ";
    }
    cout << "  Max:" << getMax() <<  endl;
    cout << "Amounts: ";
    printAmounts();
}

Histogram::Histogram(vector<int> newGrades){
    int ix;
    for(ix = 0; ix < newGrades.size(); ++ix){
        addGrade(newGrades[ix]);
    }
}

Histogram::Histogram(){/*empty*/}

int Histogram::computeMaxValue(){
    int maxValue = -1;
    int ix;
    for(ix = 0; ix < grades.size(); ++ix){
        if(grades[ix] > maxValue)
            maxValue = grades[ix];
    }   
    return(maxValue);
}

int Histogram::getMax(){
    return(maxValue);
}

void Histogram::computeHistogram(){
    while(amounts.size() <= getMax()){
        amounts.push_back(0);
    }
    int ix;
    for(ix = 0; ix < amounts.size(); ++ix){
        amounts[ix] = amountOf(ix);
    }

}

void Histogram::printAmounts(){
    computeHistogram();
    int ix;
    for(ix = 0; ix < amounts.size(); ix++){
        cout << ix << ": " << amounts[ix] << "  ";
    }
    cout << endl;
}

int Histogram::amountOf(int grade){
    int amount = 0,
        ix;
    for(ix = 0; ix < grades.size(); ++ix){
        if(grade == grades[ix])
            amount++;
    }
    return(amount);
}