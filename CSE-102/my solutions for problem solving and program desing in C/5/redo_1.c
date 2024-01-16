#include <stdio.h>

int main(void){
    int sum = 0;
    char digit;
    printf("Please enter a num> ");
    scanf("%c", &digit);

    while(digit != '\n'){
        sum += (int)digit - (int)'0';
        scanf("%c", &digit);
    }
    
    if(sum % 9 == 0){
        printf("num is divisible by 9.(Digit sum is: %d)", sum);
    }
    else{
        printf("num is not divisible by 9.(Digit sum is: %d)", sum);
    }
    return (0);
}