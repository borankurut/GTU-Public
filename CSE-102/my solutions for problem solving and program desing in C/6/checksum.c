#include <stdio.h>

char checksum();

int main(void){
    char c = checksum();
    printf("\nc: %c", c);
    return(0);
}

char checksum(){
    int sum = 0, status;    /* checksum and status of the scanf value.  */
    char c;                 /* current char                             */    
    char result;

    printf("Enter a single line ended with a period\n>");
    do{
        status = scanf("%c", &c);
        sum += (int)c;
    }while(status == 1 && c != '.' && c != '\n');

    if(c != '.'){
        printf("Please read the instruction carefully.\n\n");
        return checksum();
    }
    result = (char)((sum % 64) + ' ');
    return result;
}