#include <stdio.h>

void ct_even_odd(int number, int *even_ct, int *odd_ct);

int main(void){
    int number, even_ct, odd_ct;
    printf("Please enter an integer\n>");
    scanf("%d", &number);
    ct_even_odd(number, &even_ct, &odd_ct);
    printf("even:%d\nodd:%d", even_ct, odd_ct);
    return (0);
}

void ct_even_odd(int number, int *even_ct, int *odd_ct){
    *even_ct = 0;
    *odd_ct = 0;
    while(number != 0){
        if((number % 10) % 2 == 0)
            *even_ct += 1;
        else 
            *odd_ct += 1;
        number /= 10;
    }
}