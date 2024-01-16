#include <iostream>

using namespace std;

class Rectangle{

private:
    double width,
            height;
    bool check() const;

public:
    Rectangle(double newWidth, double newHeight);
    Rectangle(); // 5, 5
    void setWidth(double newWidth);
    void setHeight(double newHeight);
    double area();
    void output();
};

bool Rectangle::check() const{
    if(height < 0 || width < 0)
        return false;
    else
        return true;
}

Rectangle::Rectangle(double newWidth, double newHeight): width(newWidth), height(newHeight){
    if(!check()){
        cerr << "Invalid rectangle value!\n";
        exit(1);
    }
}

Rectangle::Rectangle(): width(5.0), height(5.0){/*empty*/}

void Rectangle::setWidth(double newWidth){
    width = newWidth;

    if(!check()){
        cerr << "Invalid rectangle value!\n";
        exit(1);
    }
}

void Rectangle::setHeight(double newHeight){
    height = newHeight;

    if(!check()){
        cerr << "Invalid rectangle value!\n";
        exit(1);
    }
}

double Rectangle::area(){
    return height * width;
}

void Rectangle::output(){
    cout << "Height: " << height << " Width: " << width << " Area: " << area() << endl;
}

int main(){
    Rectangle myRectangle(2.0, 3.0);
    myRectangle.output();
    myRectangle.setHeight(4.0);
    myRectangle.output();
    myRectangle.setWidth(4.0);
    myRectangle.output();

    myRectangle = Rectangle();

    myRectangle.output();

    Rectangle illegal(-1, -1);
    
    return(0);
}