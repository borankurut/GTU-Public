#include <stdio.h>
#include <string.h>

#define STR_SIZE 20

void get_input(char *string_1, char *string_2);
int appear_time(const char *string_base, const char *string_part);

int main(void){
    char string_1[STR_SIZE],
         string_2[STR_SIZE];
        

    get_input(string_1, string_2);
    printf("%d", appear_time(string_1, string_2));
}

void get_input(char *string_1, char *string_2){
    printf("Please enter string 1 (up to %d characters)\n>", STR_SIZE);
    scanf("%s", string_1);
    printf("Please enter string 2 (up to %d characters)\n>", STR_SIZE);
    scanf("%s", string_2);
}

int appear_time(const char *string_base, const char *string_part){
    int i,
        total_appear = 0;

    for(i = 0; i < (strlen(string_base) - strlen(string_part) + 1); i++)
        if(strncmp(&string_base[i], string_part, strlen(string_part)) == 0)
            total_appear += 1;

    return (total_appear);
}