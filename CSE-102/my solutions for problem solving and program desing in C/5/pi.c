#include <stdio.h>

int main(void){
    int iterations, denominator;
    double cal_pi = 0;
    printf("Please enter the number of iterations> ");
    scanf("%d", &iterations);
    int i;
    for(i = 1; i < iterations; i+=4){
        cal_pi += 1.0/i - 1.0/(i+2);
    }
    cal_pi *= 4;
    printf("%.8f", cal_pi);

    return (0);
}