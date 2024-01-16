#include <stdio.h>
#include <string.h>

#define SENTINEL -1

int get_input();
void display_result(int num);

int main(void){
    int input = get_input();

    while (input != SENTINEL){
        display_result(input);

        input = get_input();
    }

    return (0);
}

int get_input(){
    int input;

    do{
        printf("Enter an integer between 0 and 9 or -1 to quit => ");
        scanf("%d", &input);

        if((input < 0 || input > 9) && input != SENTINEL)
            printf("Invalid entry\n");
        
    }while((input < 0 || input > 9) && input != SENTINEL);

    return (input);
}

void display_result(int num){
    int fact_result = 1,
        i;

    char result[100];
    char temp[20];

    sprintf(result, "%d! = ", num);
    
    for(i = 1; i <= num; i++){
        fact_result *= i;
        if(i != num)
            sprintf(temp, "%d X ", num - i + 1);
        else
            sprintf(temp, "%d = ", num - i + 1);
        if(num != 1)
            strcat(result, temp);
    }

    sprintf(temp, "%d", fact_result);
    strcat(result, temp);

    printf("%s\n", result);
}