#include <stdio.h>
#include <string.h>
#define STR_SIZE 20

int ends_with(const char *str, const char *suffix);
char *past(const char *word, char *past_word);

int main(void){
    char word[STR_SIZE];
    char past_word[STR_SIZE + 5];   /*  adding 5 characters just to be safe.    */
    printf("Please enter a word up to %d characters\n>", STR_SIZE);
    scanf("%s", word);

    printf("Result :%s\n", past(word, past_word));

    return (0);
}

int ends_with(const char *str, const char *suffix){
    int string_len = strlen(str);
    int suffix_len = strlen(suffix);

    if(strcmp(&str[string_len - suffix_len], suffix) == 0)
        return (1);
    else
        return (0);
}

char *past(const char *word, char *past_word){
    strcpy(past_word, word);
    if(ends_with(word, "e"))
        strcat(past_word, "d");
    else if(ends_with(word, "ss") || ends_with(word, "gh"))
        strcat(past_word, "ed");
    else
        printf("Verb may have an irregular past tense\n");
    
    return (past_word);
}