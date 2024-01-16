#include <stdio.h>
int fun1();
int fun2();

int main(){
    printf("Testing &&\n");
    if(fun1() && fun2() == 1){
        printf("test of && complete.\n");
    }
    printf("Testing ||\n");
    if(fun1() || fun2() == 1){
        printf("test of || complete.\n");
    }

}

int fun1(){
    char choice;
    printf("Enter 'T' for true or 'F' for false.\n>");
    scanf("%c", &choice);
    if(choice == 'T')
        return 1;
    else if(choice == 'F')
        return 0;
    else{
        printf("Invalid choice.\n");
        return 0;
    }
}
int fun2(){
    printf("fun2 executed.\n");
    return 1;
}