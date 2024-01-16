#include <stdio.h>
#include <math.h>

int main(void){
    int num0, num1; /*  numbers user entered.                           */
    int gcd;        /*  greatest commond divisor of the num0 and num1   */
    int divisor, divided, remaining;

    printf("Please enter the 2 numbers >");
    scanf("%d %d", &num0, &num1);

    num0 = abs(num0);   /*  calculate the absolute values.  */
    num1 = abs(num1);

    if(num0 > num1){    /*  make the num0 smaller, num1 bigger one.   */
        int temp;
        temp = num0;
        num0 = num1;
        num1 = temp;
    }

    divisor = num0; 
    divided = num1;
    remaining = num0;
    while(remaining != 0){
        gcd = remaining;
        remaining = divided % divisor;
        divided = divisor;
        divisor = remaining;
    }

    printf("%d", gcd);

    return (0);
}