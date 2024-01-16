#include <stdio.h>

#define PI 3.14159  /*  Pi number   */

/*  Prototypes  */

int get_problem();

void instruct();

void get_parallelogram(double *height, double *base);

double cal_area_parallelogram(double height, double base);

void get_triangle(double *height, double *base);

double cal_area_triangle(double height, double base);

void get_trapezoid(double *height, double *base, double *base2);

double cal_area_trapezoid(double height, double base, double base2);

void get_circle(double *radius);

double cal_area_circle(double radius);


int main(){
    double base, base2, height, radius;
    int choice = get_problem();
    switch (choice)
    {
    case 1:
        get_parallelogram(&height, &base);
        printf("Area of the parallelogram: %.2f\n", cal_area_parallelogram(height, base));
        break;
    case 2:
        get_triangle(&height, &base);
        printf("Area of the triangle: %.2f\n", cal_area_triangle(height, base));
        break;
    case 3:
        get_trapezoid(&height, &base, &base2);
        printf("Area of the trapezoid: %.2f\n", cal_area_trapezoid(height, base, base2));
        break;
    case 4:
        get_circle(&radius);
        printf("Area of the circle: %.2f\n", cal_area_circle(radius));
        break;
    case 5:
        printf("Exitting.\n");
        break;
    }

    return (0);
}

/*
*   Instructs the user takes the input until user enters a valid input
*   and returns the input.  
*/
int get_problem(){  
    int input,
    wrong_input;
    do{
        wrong_input = 0;

        instruct();
        scanf("%d", &input);

        if(input < 1 || input > 5){
            printf("\nPlease read the instructions carefully!\n");
            wrong_input = 1;
        }
    }while(wrong_input);

    return (input);
}

/*
*   Prints the instructions.
*/
void instruct(){
    printf("Enter the number of the problem you wish to solve.\n");
    printf("(1) Area of a parallelogram\n(2) Area of a triangle\n(3) Area of a trapezoid\n");
    printf("(4) Area of a circle\n(5) QUIT\n>");
}

/*
*   gets the base and height of the parallelogram.
*/
void get_parallelogram(double *height, double *base){
    printf("Enter the base of the parallelogram\n>");
    scanf("%lf", base);
    printf("Enter the height of the parallelogram\n>");
    scanf("%lf", height);
}

/*
*   calculates the area of the parallelogram.
*   Pre: height, base of the parallelogram are given.
*   Post: area is the returned value.
*/
double cal_area_parallelogram(double height, double base){
    double area = height * base;
    return area;
}

/*
*   gets the height and base of the triangle
*/
void get_triangle(double *height, double *base){
    printf("Enter the base of the triangle\n>");
    scanf("%lf", base);
    printf("Enter the height of the triangle\n>");
    scanf("%lf", height);
}

/*
*   calculates the are of a triangle.
*   Pre: height and base of the triangle is given.
*   Post: area of the triangle is the returned value.
*/
double cal_area_triangle(double height, double base){
    double area = base * height / 2;
    return area;
}

/*
*   gets the base, second base and the height of the trapezoid.
*/
void get_trapezoid(double *height, double *base, double *base2){
    printf("Enter the first base of the trapezoid\n>");
    scanf("%lf", base);
    printf("Enter the second base of the trapezoid\n>");
    scanf("%lf", base2);
    printf("Enter the height of the trapezoid\n>");
    scanf("%lf", height);
}

/*
*   calculates the area of a trapezoid.
*   Pre: height, base and upper base of the trapezoid are given.
*   Post: area is the returned value.    
*/
double cal_area_trapezoid(double height, double base, double base2){
    double area = height * (base + base2) / 2;
    return area;
}

/*
*   gets the radius of the circle.
*/
void get_circle(double *radius){
    printf("Enter the radius of the circle\n>");
    scanf("%lf", radius);
}

/*
*   calculates the area of a circle.
*   Pre: radius of the circle is given, pi number is defined constant.
*   Post: area of the circle is returned value. 
*/
double cal_area_circle(double radius){
    double area = PI * radius * radius ;
    return area;
}