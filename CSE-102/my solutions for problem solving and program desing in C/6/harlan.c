#include <stdio.h>
#include <math.h>

double harlan_formula(int x);

int main(void){
    double calc_e, e = exp(1);
    int x = 1;

    do{
        calc_e = harlan_formula(x);
        x += 1;

    }while (abs(e - calc_e) > 0.000001);
    printf("Calculated: %.7f\nFinal approximation: %.7f\n", calc_e, e);

    return (0);
}   
double harlan_formula(int x){
    double result, inside;
    double x_dbl = (double)x;

    inside = (2 * x_dbl + 1) / (2 * x_dbl - 1);
    result = pow(inside, x_dbl);

    return(result); 
}