#include <stdio.h>

/*  Prototypes  */
void guess_root_of(double number, double *guess);
double abs(double x);
void driver_guess_root();

int main(void){
    driver_guess_root();
    return (0);
}

/*  
*   Function to guess the root of the number via formula: NG = 0.5(LG + N/LG).
*   Pre:    number is defined, positive number.
*   Post:   *guess is the value of the root of the number.
*/
void guess_root_of(double number, double *guess){
    double ng, lg = *guess;
    ng = 0.5 * (lg + number / lg);

    while(abs(ng - lg) > 0.005){
        lg = ng;
        ng = 0.5 * (lg + number / lg);
    }
    *guess = ng;
}

/*  returns the absolute value of x.    */
double abs(double x){
    if(x < 0)
        return -x;
    else
        return x;
}

/*
*   driver function of the guess_root_of function.
*   it scans for the number and prints the guessed root of the number
*   while the number is not zero and the scanf is successful.
*/
void driver_guess_root(){
    double value, guess = 1;
    int status;

    printf("Enter a value(0 to exit)\n>");
    status = scanf("%lf", &value);

    while(status == 1 && value != 0){
        guess_root_of(value, &guess);
        printf("The guessed value is: %.2f\n\n", guess);
        printf("Enter a value(0 to exit)\n>");
        status = scanf("%lf", &value);
    }
}