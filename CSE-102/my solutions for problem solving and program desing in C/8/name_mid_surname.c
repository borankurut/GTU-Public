#include <stdio.h>
#include <string.h>

#define MAX_DATA        5
#define LINE_SIZE       80
#define NAME_SIZE       11
#define SURNAME_SIZE    16
#define IN_FILE "name_mid_surname_input.txt"

int get_data(char lines[][LINE_SIZE], FILE *fp_in);

void display_data(char names[][NAME_SIZE], char mid_names[][NAME_SIZE], 
                char sur_names[][SURNAME_SIZE], int data_amount);

void modify(char lines[][LINE_SIZE], int data_amount, char names[][NAME_SIZE],
            char mid_names[][NAME_SIZE], char sur_names[][SURNAME_SIZE]);

int main(void){

    FILE *fp_in = fopen(IN_FILE, "r");

    char lines[MAX_DATA][LINE_SIZE], 
        names[MAX_DATA][NAME_SIZE], 
        mid_names[MAX_DATA][NAME_SIZE],
        sur_names[MAX_DATA][SURNAME_SIZE];

    int data_amount = get_data(lines, fp_in);

    modify(lines, data_amount, names, mid_names, sur_names);

    display_data(names, mid_names, sur_names, data_amount);

    fclose(fp_in);

    return (0);
}

int get_data(char lines[][LINE_SIZE], FILE *fp_in){
    int i = 0;
    int data_amount;

    while(fgets(lines[i], LINE_SIZE, fp_in) != NULL){
        i += 1;
        if(i >= MAX_DATA)
            break;
    }
    data_amount = i;
    return (data_amount);
}

void display_data(char names[][NAME_SIZE], char mid_names[][NAME_SIZE], 
                char sur_names[][SURNAME_SIZE], int data_amount){
    int i;
    for (i = 0; i < data_amount; i++){
        printf("%-20s %-20s %-20s\n", sur_names[i], names[i], mid_names[i]);
    }
}

void modify(char lines[][LINE_SIZE], int data_amount, char names[][NAME_SIZE],
             char mid_names[][NAME_SIZE], char sur_names[][SURNAME_SIZE]){
    int i;

    for (i = 0; i < data_amount; i++)
        strtok(lines[i], "\n");

    for(i = 0; i < data_amount; i++){
        strncpy(sur_names[i], strtok(lines[i], ", "), SURNAME_SIZE);
        strncpy(names[i], strtok(NULL, " "), NAME_SIZE);
        strncpy(mid_names[i], strtok(NULL, "."), NAME_SIZE);
        sur_names[i][SURNAME_SIZE - 1] = '\0';
        names[i][NAME_SIZE - 1] = '\0';
        mid_names[i][NAME_SIZE - 1] = '\0';
    }   
}