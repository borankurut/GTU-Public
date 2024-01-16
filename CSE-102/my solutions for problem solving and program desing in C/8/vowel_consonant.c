#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STR_SIZE 100

void count_vow_cons(char string[STR_SIZE], int *vowp, int *consp);
int isvowel(char character);

int main(void){
    char string_input[STR_SIZE];

    int vowel, consonant;

    printf("Please enter a string up to %d characters\n>", STR_SIZE);
    fgets(string_input, STR_SIZE, stdin);

    count_vow_cons(string_input, &vowel, &consonant);
    printf("Consonants: %d\nVowels: %d\n", consonant, vowel);
    return (0);
}

void count_vow_cons(char string[STR_SIZE], int *vowp, int *consp){
    int string_length = strlen(string),
        i;

    *vowp = 0;
    *consp = 0;

    for(i = 0; i < string_length - 1; i++){
        if(isvowel(string[i]) == 1)
            *vowp += 1;
        else if(isblank(string[i]) == 0)
            *consp += 1;
    }
}

int isvowel(char character){
    switch (character)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return (1);
        break;

    default:
        return (0);
        break;
    }
}

