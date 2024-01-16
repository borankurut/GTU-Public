#include <stdio.h>
#include <string.h>

#define IN_FILE     "hurricane_data.txt"
#define MAX_DATA    30
#define STR_SIZE    30

/*  prototypes shit */
void get_data(int years[], char names[][STR_SIZE], char states[][STR_SIZE], 
                int *data_amount, FILE *fp_in);

void display_data(int years[], char *names[], char *states[], int data_amount);

char *precedence_str(char *str_arr[], int min_ix, int max_ix, int *wherep);

void sort_by_name(  int years[], char names[][STR_SIZE], char states[][STR_SIZE], 
                    int  data_amount, char *names_by_name[], char *states_by_name[], 
                    int years_by_name[]);

int main(void){
    FILE *fp_in = fopen(IN_FILE, "r");

    int years[MAX_DATA],            /*  years data parallel array            */
        years_by_name[MAX_DATA],    /*  years data array but sorted          */
        data_amount,                                
        i;

    char names[MAX_DATA][STR_SIZE], /*  names data parallel array           */
        states[MAX_DATA][STR_SIZE], /*  states data parallel array          */
        *names_by_name[MAX_DATA],   /*  names data array but sorted         */
        *states_by_name[MAX_DATA];  /*  states data array but sorted        */
    
    get_data(years, names, states, &data_amount, fp_in);
    sort_by_name(years, names, states, data_amount, names_by_name, states_by_name, years_by_name);
    display_data(years_by_name, names_by_name, states_by_name, data_amount);
    

    return (0);
}

/*  gets the data from input file pointer and assigns it to parallel arrays described.  */
void get_data(int years[],              /*  Parallel integer array years                */
            char names[][STR_SIZE],     /*  parallel string array hurricane names       */
            char states[][STR_SIZE],    /*  Parallel string array states information    */
            int *data_amount,           /*  Amount of data line entered                 */
            FILE *fp_in)                /*  Input file pointer                          */
{
    int i = 0, status;

    for(status = fscanf(fp_in, "%d", &years[i]); 
        status == 1;
        status = fscanf(fp_in, "%d", &years[i]))
    {
        if(i == MAX_DATA - 1){
            printf("Data exceeds maximum.\n");
            break;
        }
        fscanf(fp_in, "%s ", names[i]); /*  blank is necessary.                 */
        fgets(states[i], 20, fp_in);    /*  fgets used for multiple states.     */
        strtok(states[i], "\n");        /*  strtok is used for excluding the new line char assigned by fgets.*/
        i += 1;
    }

    *data_amount = i;
}


/*  to be implemented   */
void display_data(int years[], char *names[], char *states[], int data_amount){
    int i;
    for(i = 0; i < data_amount; i++)
        printf(".%d.%s.%s.\n", years[i], names[i], states[i]);
}

/*  returns the string that takes precedence and the index of it in the range inside the given array*/
char *precedence_str(char *str_arr[], int min_ix, int max_ix, int *wherep){
    int i;
    char *result = str_arr[min_ix];

    for(i = min_ix + 1; i < max_ix; i++)
        if(strcmp(result, str_arr[i]) > 0){
            result = str_arr[i];
            *wherep = i;
        }
    return(result);
}

void sort_by_name(int years[],          /*  Parallel integer array years                    in  */
            char names[][STR_SIZE],     /*  parallel string array hurricane names           in  */
            char states[][STR_SIZE],    /*  Parallel string array states information        in  */
            int  data_amount,           /*                                                  in  */
            char *names_by_name[],      /*  Parallel pointer array names sorted by name     out */
            char *states_by_name[],     /*  Parallel pointer array states sorted by name    out */
            int years_by_name[]         /*  Parallel integer array years sorted by name     out */
            )
{
    int i, where, integer_temp;
    char *temp;

    for(i = 0; i < data_amount; i++){
        names_by_name[i] = names[i];
        states_by_name[i] = states[i];
        years_by_name[i] = years[i];
    }
    for(i = 0; i < data_amount; i++){
        if(names_by_name[i] != precedence_str(names_by_name, i, data_amount, &where)){
            temp = names_by_name[i];
            names_by_name[i] = names_by_name[where];
            names_by_name[where] = temp;

            temp = states_by_name[i];
            states_by_name[i] = states_by_name[where];
            states_by_name[where] = temp;

            integer_temp = years_by_name[i];
            years_by_name[i] = years_by_name[where];
            years_by_name[where] = integer_temp;
        }
    }
}


/*  returns the number that is minimum and the index of it in the range inside the given array*/
int minimum_arr(int arr[], int min_ix, int max_ix, int *wherep){
    int i;
    int result = arr[0];

    for(i = min_ix + 1; i < max_ix; i++)
        if(arr[i] > result){
            result = arr[i];
            *wherep = i;
        }
    return (result);
}
