#include <stdio.h>

/*  Prototypes  */
void reverse_prime_palindrome(int number, int *reversed, int *is_prime, int *is_palindrome);

int reverse(int number);

int is_prime(int number);

int is_palindrome(int number);

int main(void){
    int input,                  /* number input                 */
        reversed,               /* reversed number              */
        is_prime_value,         /* whether number prime         */
        is_palindrome_value,    /* whether number palindrome    */
        status;                 /* scanf status                 */

    FILE *fp_in = fopen("3_integers.txt", "r"); 

    status = fscanf(fp_in, "%d", &input);
    while (status == 1){
        reverse_prime_palindrome(input, &reversed, &is_prime_value, &is_palindrome_value);

        /* Print results */
        printf("%d, Reversed: %d, ", input, reversed);
        printf("Is prime: ");
        if(is_prime_value == 1)
            printf("YES, ");
        else
            printf("NO, ");
        printf("Is palindrome: ");
        if(is_palindrome_value == 1)
            printf("YES.\n");
        else
            printf("NO.\n");
        printf("\n");

        status = fscanf(fp_in, "%d", &input);
    }

    fclose(fp_in);

    return (0);
}
/*
*   takes an integer, 
*   returns:
*   its reversed value, whether it is prime, 
*   whether it is palindrome via output parameters.
*/
void reverse_prime_palindrome(int number, int *reversed, int *is_prime_value, int *is_palindrome_value){
    /*  reverse */
    *reversed = reverse(number);

    /*  prime */
    *is_prime_value = is_prime(number);

    /*  palindrome  */
    *is_palindrome_value = is_palindrome(number);
}

/*  returns the reversed number */
int reverse(int number){
    int reversed = 0;

    while (number != 0){
        reversed *= 10;
        reversed += number % 10;
        number /= 10;
    }
    return reversed;
}

/*  returns whether the number is prime */
int is_prime(int number){
    int result = 1;

    int i;
    for(i = 2; i < number; i++){
        if(number % i == 0)
            result = 0;
    }
    if (number == 2)
        result = 1;
    else if(number < 2)
        result = 0;
    
    return result;
}

/*  returns whether the number is palindrome.   */
int is_palindrome(int number){
    int result = 0;

    if(number == reverse(number))
        result = 1;

    return result;
}