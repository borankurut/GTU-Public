#include <stdio.h>
#include <string.h>

int is_palindrome(char *str);

int main(void){

    char str[] = "level";

    int result = is_palindrome(str);

    printf("%d", result);

    return (0);
}

int is_palindrome(char *str){
    int result;

    printf("input:%s.\n", str);

    if(strlen(str) == 1)
        result = 1;
    else{
        if(str[0] == str[strlen(str) - 1]){
            str[strlen(str) - 1] = '\0';
            result = is_palindrome(&str[1]);
        }
        else
            result = 0;
    }
    printf("result: %d\n", result);
    return(result);
}