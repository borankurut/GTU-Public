#include <stdio.h>

/*  function prototypes */
void get_two_num(int *num1, int *num2);
int add(int num1, int num2);    
int sub(int num1, int num2);    
int mul(int num1, int num2);    
int div(int num1, int num2);    
int fact(int number);
int get_input();
void instruct();

int main(void){
    int choice = get_input();
    int num1, num2;

    switch (choice)
    {
    case 1:
        get_two_num(&num1, &num2);    
        printf("Sum => %d", add(num1, num2));    
        break;
    case 2:
        get_two_num(&num1, &num2);
        printf("Dif => %d", sub(num1, num2));
        break;
    case 3:
        get_two_num(&num1, &num2);
        printf("Mult => %d", mul(num1, num2));
        break;
    case 4:
        get_two_num(&num1, &num2);
        printf("Div => %d", div(num1, num2));
        break;
    case 5:
        printf("Enter the number\n>");
        scanf("%d", &num1);
        printf("Fact => %d", fact(num1));
        break;
    case 6:
        printf("Extitting\n");
        break;
    }
    return (0);
}

/*  get functions */
void get_two_num(int *num1, int *num2){
    int status, wrong_input;
    char discard;
    do{
        printf("Enter two numbers =>");
        status = scanf("%d, %d", num1, num2);
        if (status != 2){
            printf("Invalid input.\n");
            wrong_input = 1;
            while(discard != '\n'){
                scanf("%c", &discard);
            }
        }
    }while(wrong_input);
}

/* returns num1 + num2  */
int add(int num1, int num2){
    int result = num1 + num2;
    return result;
}

/* returns num1 - num2  */
int sub(int num1, int num2){
    int result = num1 - num2;
    return result;
}

/* returns num1 * num2  */
int mul(int num1, int num2){
    int result = num1 * num2;
    return result;
}

/* returns num1 / num2  */
int div(int num1, int num2){
    int result = (double)num1 / (double)num2;
    return result;
}

/* returns number!      */
int fact(int number){
    int sum = 1;
    if(number <= 1)
        return 0;
    else{
        int i;
        for(i = 1; i <= number; i++){
            sum *= i;
        }
    }
    return sum;
}

/*  gets input after displaying prompts */
int get_input(){
    int choice, wrong_input, status;
    char discard;
    do{
        wrong_input = 0;
        instruct();
        printf("Enter the choice\n>");
        status = scanf("%d", &choice);
        if(status != 1 || choice < 1 || choice > 6){
            wrong_input = 1;
            printf("Invalid input.\n");
        }
    }while(wrong_input);
    return choice;
}
void instruct(){
    printf( "1: Addition\n"
            "2: Subtraction\n"
            "3: Multiplication\n"
            "4: Division\n"
            "5: Factorial\n"
            "6: Quit\n");
}