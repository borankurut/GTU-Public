#include <stdio.h>
#include <math.h>

#define SENTINEL    -0.001  /*  sentinel value of get polynomial    */
#define MAX_DG      8       /*  maximum degree of a polynomial      */

/*  prototypes  */
void get_poly(double coeff[], int* degreep);
double eval_poly(const double coeff[], int degree, double x);

int main(void){
    int degree;
    double coeff[MAX_DG];

    double x;

    get_poly(coeff, &degree);

    printf("Enter x\n>");
    scanf("%lf", &x);

    printf("Result for %.2f: %.2f\ndegree:%d", x, eval_poly(coeff, degree, x), degree);

    return (0);
}

void get_poly(double coeff[], int* degreep){
    int i;
    double cf;

    printf("Please enter ""%.3lf"" to stop\nMaximum degree: %d\n", SENTINEL, MAX_DG);
    for(i = 0; i < MAX_DG; i++){
        printf("Please enter the coefficient of x^%d\n>", i);
        scanf("%lf", &cf);

        if(cf == SENTINEL){
            i -= 1;
            break;
        }

        coeff[i] = cf;
    }
    *degreep = i;
}

double eval_poly(const double coeff[], int degree, double x){
    int i;
    double result = 0;
    for(i = 0; i <= degree; i++){
        result += coeff[i] * pow(x, i);
    }
    return (result);
}