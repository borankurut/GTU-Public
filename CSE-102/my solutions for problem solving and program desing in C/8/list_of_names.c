#include <stdio.h>
#include <string.h>

#define IN_FILE "list_of_names_input.txt"
#define MAX_DATA 10
#define STR_SIZE 25

int get_data(FILE *fp_in, char names[][STR_SIZE], char surnames[][STR_SIZE], int ages[]);

void fill( char names[][STR_SIZE],
        char surnames[][STR_SIZE],
        char *names_alp[],
        char *surnames_alp[],
        int ages[],
        int ages_alp[],
        int data_amount);

void alphabetize(char *names_alp[], char *surnames_alp[], int ages_alp[], int data_amount);

char *rtn_prior(char *names[], int min, int max, int *wherep);

void display_data(char *names[], char *surnames[], int ages[], int data_amount);

int main(void){

    FILE *fp_in = fopen(IN_FILE, "r");

    char names[MAX_DATA][STR_SIZE],
        surnames[MAX_DATA][STR_SIZE],
        *names_alp[MAX_DATA],
        *surnames_alp[MAX_DATA];

    int ages[MAX_DATA],
        ages_alp[MAX_DATA],
        data_amount = get_data(fp_in, names, surnames, ages);

    fill(names, surnames, names_alp, surnames_alp, ages, ages_alp, data_amount);
    
    alphabetize(names_alp, surnames_alp, ages_alp, data_amount);

    display_data(names_alp, surnames_alp, ages_alp, data_amount);

    fclose(fp_in);

    return (0);
}

int get_data(FILE *fp_in, char names[][STR_SIZE], char surnames[][STR_SIZE], int ages[]){
    int status,
        i;
    
    status = fscanf(fp_in, "%s %s %d", surnames[0], names[0], &ages[0]);
    strtok(surnames[0], ",");

    for(i = 1; i < MAX_DATA; i++){

        status = fscanf(fp_in, "%s %s %d", surnames[i], names[i], &ages[i]);
        strtok(surnames[i], ",");
        if(status != 3)
            break;
    }

    return (i);
}

void fill( char names[][STR_SIZE],
        char surnames[][STR_SIZE],
        char *names_alp[],
        char *surnames_alp[],
        int ages[],
        int ages_alp[],
        int data_amount)
{
    int i;
    for(i = 0; i < data_amount; i++){
        names_alp[i] = names[i];
        surnames_alp[i] = surnames[i];
        ages_alp[i] = ages[i];
    }
}

void alphabetize(char *names_alp[], char *surnames_alp[], int ages_alp[], int data_amount){
    char *temp, 
        *prior;

    int temp_int,
        i,
        where;

    for(i = 0; i < data_amount; i++){

        prior = rtn_prior(names_alp, i, data_amount, &where);

        if(prior != names_alp[i]){
            temp = names_alp[i];
            names_alp[i] = prior;
            names_alp[where] = temp;

            temp = surnames_alp[i];
            surnames_alp[i] = surnames_alp[where];
            surnames_alp[where] = temp;

            temp_int = ages_alp[i];
            ages_alp[i] = ages_alp[where];
            ages_alp[where] = temp_int;
        }
    }
}

char *rtn_prior(char *names[], int min, int max, int *wherep){
    int i, ix = min;
    char *result = names[min];

    for(i = min + 1; i < max; i++){
        if(strcmp(result, names[i]) > 0){
            result = names[i];
            ix = i;
        }
    }

    *wherep = ix;
    return (result);
}

void display_data(char *names[], char *surnames[], int ages[], int data_amount){
    int i;
    for (i = 0; i < data_amount; i++){
        printf("%s %s %d\n", names[i], surnames[i], ages[i]);
    }
}