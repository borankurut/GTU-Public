#ifndef RAINBOW_COLOR_H
#define RAINBOW_COLOR_H

#include <iostream>

using namespace std;

namespace RainbowColorKurut{
    class RainbowColor{
    public:
        RainbowColor(char newColor);
        RainbowColor(int newColor);
        RainbowColor();
        int returnColor() const;
        void input();
        void output() const;
        RainbowColor returnNext() const;

    private:
        // ROYGBIV 0123456
        int color;
    };
}

#endif