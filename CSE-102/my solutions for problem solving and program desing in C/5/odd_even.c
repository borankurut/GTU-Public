#include <stdio.h>

int main(void){
    int n;                                      /*  this number of values will be scanned.            */
    int input, count_even = 0, count_odd = 0;   /*  current input, number of even and odd numbers.    */
    int sum_even = 0, sum_odd = 0;              /*  sum of the even and odd numbers.                  */

    printf("Enter the N >");
    scanf("%d", &n);
    int i;

    for(i = 0; i < n; i++){
        printf("Please enter the %d. number >", i + 1);
        scanf("%d", &input);
        if(input % 2 == 0){
            count_even += 1;
            sum_even += input;
        }else{
            count_odd += 1;
            sum_odd += input;
        }
    }

    printf("Number of even numbers: %d\nNumber of odd numbers: %d\n", count_even, count_odd);
    printf("Sum of even: %d\nSum of odd: %d\n", sum_even, sum_odd);
    printf("Square of sum of even: %d\nSquare of sum of odd: %d\n", (sum_even * sum_even), (sum_odd * sum_odd));

    return(0);
}