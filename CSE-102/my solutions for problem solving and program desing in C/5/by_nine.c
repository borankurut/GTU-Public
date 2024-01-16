/*
*   This program tests whether the given numbers
*   are divisible by 9 by calculating the sum of their digits.
*/
#include <stdio.h>

int main(void){
    int digit, sum = 0, n = 154368; /*  current digit, sum of the digits(out), n(in)    */
    int n_temp = n; /*  temporary varible to hold the original n value. */

    while(n != 0){  /*  calculate the sum of the digits */
        digit = n % 10;
        sum += digit;
        n = n / 10;
    }

    n = n_temp; /*  restore the n   */

    if(sum % 9 == 0){
        printf("%d is divisible by 9.(Digit sum is: %d)", n, sum);
    }
    else{
        printf("%d is not divisible by 9.(Digit sum is: %d)", n, sum);
    }

    return (0);
}