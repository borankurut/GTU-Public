#include <iostream>

using namespace std;

class Vector2D{

public:
    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);

    friend const Vector2D operator*(const Vector2D &op1, const Vector2D &op2);
    friend ostream& operator<<(ostream& outputStream, const Vector2D &op);

private:
    int x,
        y;

};

int main(){
    Vector2D myVector,
            mySecond;
    myVector.setX(1);
    myVector.setY(2);
    mySecond.setX(3);
    mySecond.setY(4);

    cout << "my: " << myVector << endl;
    cout << "second: " << mySecond << endl;
    cout << "product: " << (myVector*mySecond) << endl;
    return(0);
}

int Vector2D::getX() const{
    return x;
}

int Vector2D::getY() const{
    return y;
}

void Vector2D::setX(int newX){
    x = newX;
}

void Vector2D::setY(int newY){
    y = newY;
}

const Vector2D operator*(const Vector2D &op1, const Vector2D &op2){
    Vector2D product;

    product.setX(op1.getX() * op2.getX());
    product.setY(op1.getY() * op2.getY());

    return(product);
}

ostream& operator<<(ostream& outputStream, const Vector2D &op){
    outputStream << "X:" << op.x << " Y:" << op.y;
    return(outputStream);
}