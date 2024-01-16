#include <iostream>
#include "RainbowColor.h"

using namespace std;


namespace{
    string colorIntToStr(int colorToStr){
        if(colorToStr == 0)
            return("Red");
        if(colorToStr == 1)
            return("Orange");
        if(colorToStr == 2)
            return("Yellow");
        if(colorToStr == 3)
            return("Green");
        if(colorToStr == 4)
            return("Blue");
        if(colorToStr == 5)
            return("Indigo");
        if(colorToStr == 6)
            return("Violet");
    }

    
    bool isColor(int colorToCheck){
        if(colorToCheck >= 0 && colorToCheck < 7)
            return true;
        else
            return false;
    }
    
    int colorCharToInt(char colorToInt){
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

    bool isColor(char colorToCheck){
        return isColor(colorCharToInt(colorToCheck));
    }

}

namespace RainbowColorKurut{

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
}