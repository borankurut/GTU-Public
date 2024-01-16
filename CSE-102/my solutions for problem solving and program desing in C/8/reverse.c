#include <stdio.h>
#include <string.h>

#define STR_SIZE    50

char *reverse(const char string_input[STR_SIZE], char reversed[STR_SIZE]);

int main(void){
    char string_input[STR_SIZE];
    char reversed[STR_SIZE];

    printf("Please enter a string up to %d characters \n>", STR_SIZE);
    scanf("%s", string_input);

    printf("Reversed string:\n%s", reverse(string_input, reversed));

    return (0);
}

char *reverse(const char string_input[STR_SIZE], char reversed[STR_SIZE]){
    int length = strlen(string_input),
        i;
    
    for(i = 0; i < length; i++){
        reversed[i] = string_input[length - 1 - i];
    }
    reversed[length] = '\0';

    return (reversed);
}