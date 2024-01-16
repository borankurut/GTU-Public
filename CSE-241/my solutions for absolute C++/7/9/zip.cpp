#include <iostream>

using namespace std;

class ZipCode{

public:
    ZipCode(int newDigitGroup[5][5]);
    ZipCode(int code);
    void printCode();

private:
    void printGroup(const int group[]) const;
    void printGroup(int groupIx) const;
    bool makeGroup(int number, int group[]);
    int digitOfGroup(int groupIx) const;
    bool isGroupValid(int groupIx) const;
    bool isGroupValid (const int group[]) const;
    void setGroup(int groupIx, const int group[]);
    void copyGroup(int group0[], const int group1[]) const;

    int digitGroup[5][5];
};

int main(){
    int arr[5][5] = {{1,0,1,0,0}, {1,0,1,0,0}, {0,1,0,1,0}, {1,1,0,0,0}, {0,1,0,0,1}};

    ZipCode zipCode(arr);
    ZipCode zipCode2(99504);

    zipCode.printCode();
    cout << endl;
    zipCode2.printCode();
    cout << endl;

    int group[5];

    
    return(0);
}

ZipCode::ZipCode(int newDigitGroup[5][5]){
    int i, j;
    for(i = 0; i < 5; ++i)
        setGroup(i, newDigitGroup[i]);
}

ZipCode::ZipCode(int code){
    int codeDigits[5] = {(code/10000), ((code/1000)%10), ((code/ 100)%10), ((code/10)%10), (code%10)},
        newGroup[5],
        ix;
    for(ix = 0; ix < 5; ++ix){
        if(makeGroup(codeDigits[ix], newGroup) == true)
            setGroup(ix, newGroup);
        else{
            cout << "Wrong code in ZipCode Constructor\n";
            exit(1);
        }
    }
}

int ZipCode::digitOfGroup (int groupIx) const{
    int digit = -1,
        ix;
    if(isGroupValid(groupIx)){
        digit++;
        for(ix = 0; ix < 5; ++ix)
            if(digitGroup[groupIx][ix] == 1){
                if(ix == 0)
                    digit += 7;
                else if(ix == 1)
                    digit += 4;
                else if(ix == 2)
                    digit += 2;
                else if(ix == 3)
                    digit += 1;
                else if(ix == 4)
                    digit += 0;
            }
    }
    if(digit == 11)
        digit = 0;
    return(digit);
}

void ZipCode::printGroup (int groupIx) const{
    printGroup(digitGroup[groupIx]);
}

void ZipCode::printGroup(const int group[]) const{
    int ix;
    for(ix = 0; ix < 5; ++ix)
        cout << group[ix];

}

bool ZipCode::isGroupValid (int groupIx) const{
    return isGroupValid(digitGroup[groupIx]);
}

bool ZipCode::isGroupValid (const int group[]) const{
    int oneCounted = 0,
        ix;
    for(ix = 0; ix < 5; ++ix)
        if(group[ix] != 0)
            oneCounted += 1;
    return(oneCounted == 2);
}

void ZipCode::setGroup(int groupIx, const int group[]){
    int ix;
    if(isGroupValid(group)){
        for(ix = 0; ix < 5; ++ix)
            digitGroup[groupIx][ix] = group[ix];
    }
}

void ZipCode::printCode(){
    int ix;
    cout << 1;
    for(ix = 0; ix < 5; ++ix){
        printGroup(ix);
    }   
    cout << 1;
}

bool ZipCode::makeGroup(int number, int group[]){
    int zero[] = {0,0,0,0,0};
    copyGroup(group, zero);
    if(number == 0 || number == 11){
        int temp[] = {1,1,0,0,0};
        copyGroup(group, temp);
    }
    else if(number == 7){
        int temp[] = {1,0,0,0,1};
        copyGroup(group, temp);
    }
    else if(number == 4){
        int temp[] = {0,1,0,0,1};
        copyGroup(group, temp);
    }
    else if(number == 2){
        int temp[] = {0,0,1,0,1};
        copyGroup(group, temp);
    }
    else if(number == 1){
        int temp[] = {0,0,0,1,1};
        copyGroup(group, temp);
    }
    else{
        if(number >= 7){
            group[0] = 1;
            number -= 7;
        }
        if(number >= 4){
            group[1] = 1;
            number -= 4;
        }
        if(number >= 2){
            group[2] = 1;
            number -= 2;
        }
        if(number >= 1){
            group[3] = 1;
            number -= 1;
        }
    }
    return(isGroupValid(group));
}

void ZipCode::copyGroup(int group0[], const int group1[]) const{
    int ix;
    for(ix = 0; ix < 5; ++ix)
        group0[ix] = group1[ix];
}