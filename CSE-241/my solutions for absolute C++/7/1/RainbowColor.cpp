#include <iostream>

using namespace std;

class RainbowColor{

private:
    // ROYGBIV 0123456
    int color;
    int colorCharToInt(char colorToInt) const;
    string colorIntToStr(int colorToStr) const;
    bool isColor(int colorToCheck);
    bool isColor(char colorToCheck);

public:
    RainbowColor(char newColor);
    RainbowColor(int newColor);
    RainbowColor();
    int returnColor() const;
    void input();
    void output() const;
    RainbowColor returnNext() const;
};

int RainbowColor::colorCharToInt(char colorToInt) const{
    // ROYGBIV 0123456
    if(colorToInt == 'R')
        return(0);
    else if(colorToInt == 'O')
        return(1);
    else if(colorToInt == 'Y')
        return(2);
    else if(colorToInt == 'G')
        return(3);
    else if(colorToInt == 'B')
        return(4);
    else if(colorToInt == 'I')
        return(5);
    else if(colorToInt == 'V')
        return(6);
    else{
        cerr << "Illegal color value!\n";
        exit(1);
    }
}

string RainbowColor::colorIntToStr(int colorToStr) const{
    if(color == 0)
        return("Red");
    if(color == 1)
        return("Orange");
    if(color == 2)
        return("Yellow");
    if(color == 3)
        return("Green");
    if(color == 4)
        return("Blue");
    if(color == 5)
        return("Indigo");
    if(color == 6)
        return("Violet");
}

bool RainbowColor::isColor(int colorToCheck){
    if(colorToCheck >= 0 && colorToCheck < 7)
        return true;
    else
        return false;
}

bool RainbowColor::isColor(char colorToCheck){
    return isColor(colorCharToInt(colorToCheck));
}

RainbowColor::RainbowColor(){
    color = 0;
}

RainbowColor::RainbowColor(int newColor): color(newColor){
    if(!isColor(color)){
        cerr << "Illegal color value!\n";
        exit(1);
    }
}

RainbowColor::RainbowColor(char newColor): color(colorCharToInt(newColor)){
    if(!isColor(color)){
        cerr << "Illegal color value!\n";
        exit(1);
    }
}

int RainbowColor::returnColor() const{
    return color;
}

void RainbowColor::input(){
    int newColor;
    cout << "Enter the color as an integer (ROYGBIV 0123456).\n";
    cin >> newColor;
    color = newColor;
}

void RainbowColor::output() const{
    cout << "Color: " << colorIntToStr(color) << endl;
}

RainbowColor RainbowColor::returnNext() const{
    RainbowColor next((color + 1) % 7);
    return next;
}


int main(){
    RainbowColor myRainbowColor(5);
    myRainbowColor.output();
    myRainbowColor.input();
    myRainbowColor.output();
    myRainbowColor.returnNext().output();
    myRainbowColor.returnNext().returnNext().output();

    return(0);
}
