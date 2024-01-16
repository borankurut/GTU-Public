#include <stdio.h.>

int check_num(const int barcode[12]);
int check_barcode(const int barcode[12]);

int main(void){
    int barcode[12];
    int i;

    printf("Please enter your barcode\n>");
    for(i = 0; i < 12; i++)
        scanf("%d", &barcode[i]);
    printf("Entered barcode:\n");
    for(i = 0; i < 12; i++)
        printf("%d ", barcode[i]);
    printf("\n");

    if(check_barcode(barcode))
        printf("Validated.\n");
    else   
        printf("Error in barcode.\n");

    return (0);
}


/*  Returns the given barcode's checked number */
int check_num(const int barcode[12]){
    int check_digit,
        odd_pos_sum = 0,    /*  Sum of the numbers on odd numbered positions    */
        even_pos_sum = 0,   /*  Sum of the numbers on even numbered positions   */
        sum,                /*  Sum based on check num formula                  */
        i;                  

    for(i = 0; i < 11; i++){
        if(i % 2 == 0)      /*   first, third..     */
            odd_pos_sum += barcode[i];
        else                /*  second, fourth..    */
            even_pos_sum += barcode[i];
    }

    printf("Step 1 check digit calculation: %d\n", (3 * odd_pos_sum));

    sum = 3 * odd_pos_sum + even_pos_sum;
    
    printf("Step 2 check digit calculation: %d\n", sum);

    if(sum % 10 == 0)
        check_digit = 0;
    else
        check_digit = 10 - (sum % 10);

    return (check_digit);
}

/*  Returns whether the last digit matches the 12th digit  */
int check_barcode(const int barcode[12]){
    if(barcode[11] == check_num(barcode))
        return  (1);
    else 
        return (0);
}