#include <stdio.h>
#include <math.h>
#include "high_library.h"


/*  main function to debug. */
int main(void){
    high_precision_t num1 = {.digits = {8, 1, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    .decpt = 1, .sign = 1};

    high_precision_t num2 = {.digits = {9, 4, 3, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    .decpt = -2, .sign = 1};

    high_precision_t num3;

    num3 = add_high(num1, num2);

    print_high(num1);
    printf("\n");
    print_high(num2);
    printf("\n");
    print_high(num3);
    
    return (0);
}

high_precision_t add_high(high_precision_t high1, high_precision_t high2){
    printf("For just positive numbers\n");
    high_precision_t sum;

    int new_number_digits[20],
        high1_digits[20],
        high2_digits[20],
        digit_sum,
        ix;

    for(ix = 0; ix < 20; ix++){
        high1_digits[ix] = high1.digits[ix];
        high2_digits[ix] = high2.digits[ix];
        new_number_digits[ix] = 0;
    }

    sum.sign = 1;

    if(high1.decpt < high2.decpt){
        sum.decpt = high2.decpt;
        shift_right(high1_digits, 20,  high2.decpt - high1.decpt);
    }
    else{
        sum.decpt = high1.decpt;
        shift_right(high2_digits, 20, high1.decpt - high2.decpt);
    }

    for(ix = 19; ix >= 0; ix--){
        digit_sum = high1_digits[ix] + high2_digits[ix];
        new_number_digits[ix] += digit_sum % 10;
        if(ix != 0)
            new_number_digits[ix - 1] += digit_sum / 10;
        if(ix == 0 && digit_sum >= 10){
            shift_right(new_number_digits, 20, 1);
            new_number_digits[0] = digit_sum / 10;
            sum.decpt += 1;
        }
    }

    for(ix = 0; ix < 20; ix++){
        sum.digits[ix] = new_number_digits[ix];
    }

    return (sum);
}

high_precision_t subtract_high(high_precision_t high1, high_precision_t high2){
    printf("to be implemented\n");
}

high_precision_t multiply_high(high_precision_t high1, high_precision_t high2){
    printf("to be implemented\n");
}

int high_library_min_of(int num1, int num2){
    if(num1 < num2)
        return num1;
    else
        return num2;
}

void high_library_shift_right(int arr[], int n, int times){
    if(times <= 0)
        return;
    else{
        int ix;
        for(ix = n - 1; ix > 0; ix--){
            arr[ix] = arr[ix - 1];
        }   
        arr[0] = 0;
        shift_right(&arr[1], n-1, times-1);
    }
}

void print_high(high_precision_t number){
    int ix;

    if(number.sign != 1)
        printf("-");

    if(number.decpt <= 0){
        printf("0.");
        for(ix = number.decpt; ix < 20 + number.decpt - 1; ix++){
            if(ix < 0)
                printf("0");
            else
                printf("%d", number.digits[ix]);
        }
    }
    else{
        for(ix = 0; ix < 20; ix++){
            if(number.decpt == ix)
                printf(".");
            printf("%d", number.digits[ix]);
        }
    }
}