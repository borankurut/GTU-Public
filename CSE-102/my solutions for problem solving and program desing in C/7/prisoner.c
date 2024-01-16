#include <stdio.h>
#include <stdlib.h>

#define WITHIN_MNTHS    36  /*  if criminals commit crime within this amount of mounths they counted as recidivist.   */
#define MAX_RECORDS     20  /*  maximum record amount allowed               */
#define MAX_FILE_NAME_C 50  /*  maximum file name character allowed         */

void fill_data( FILE *fp_in, int id[], int release_y[], int release_m[], 
                int rearrest_y[], int rearrest_m[], int *record_num);

double recidivism(int id[], int release_y[], int release_m[], int rearrest_y[], int rearrest_m[], int record_num);

void display_data(int id[], int release_y[], int release_m[], int rearrest_y[], int rearrest_m[], int record_num);

void get_f_name(char file_name[]);

int main(void){

    int id[MAX_RECORDS],                    /*  criminal id */
        release_y[MAX_RECORDS],             /*  criminal release year   */
        release_m[MAX_RECORDS],             /*  criminal release month  */
        rearrest_y[MAX_RECORDS],            /*  criminal rearrest year  */
        rearrest_m[MAX_RECORDS],            /*  criminal rearrest month */
        record_num;                         /*  number of records       */
    
    char    file_name[MAX_FILE_NAME_C],
            c;

    double recidivism_percent;

    get_f_name(file_name);

    FILE* fp_in = fopen(file_name, "r");

    if(fp_in == NULL){
        printf("Couldn't found the file.\n");
        exit(1);
    }

    fill_data(fp_in, id, release_y, release_m, rearrest_y, rearrest_m, &record_num);
    display_data(id, release_y, release_m, rearrest_y, rearrest_m, record_num);
    recidivism_percent = recidivism(id, release_y, release_m, rearrest_y, rearrest_m, record_num);

    printf("\nRecidivism Percent: %%%.2f", recidivism_percent);

    return (0);
}

/*
*   takes five parallel arrays containing criminals informations
*   returns recidivism percent
*/
double recidivism(int id[],                 /*  criminal id */
                int release_y[],            /*  criminal release year   */
                int release_m[],            /*  criminal release month  */
                int rearrest_y[],           /*  criminal rearrest year  */
                int rearrest_m[],           /*  criminal rearrest month */
                int record_num)             /*  number of records       */
{
    int i;
    int month_elapsed;          /*  months elapsed from realese until rearrest   */
    int recidivist = 0;         /*  recidivist amount */
    double recidivism_percent;  

    for(i = 0; i < record_num; i++){
        if(rearrest_m[i] == 0 && rearrest_y[i] == 0)    /*  not rearrested  */
            continue;
        else{
            month_elapsed = (rearrest_y[i] - release_y[i]) * 12;
            month_elapsed += (rearrest_m[i] - release_m[i]);
        }
        if(month_elapsed <= WITHIN_MNTHS)
            recidivist += 1;
    }

    recidivism_percent = ((double)recidivist / (double)record_num) * 100.0;

    return (recidivism_percent);
}

/*  fills criminal datas    */
void fill_data(FILE *fp_in,             /*  input - file pointer    */
                int id[],               /*  out - criminal id */
                int release_y[],        /*  out - criminal release year   */
                int release_m[],        /*  out - criminal release month  */
                int rearrest_y[],       /*  out - criminal rearrest year  */
                int rearrest_m[],       /*  out - criminal rearrest month */
                int *record_num)        /*  out - number of records       */
{
    int status,
        i = -1;
    do{
        i += 1;
        status = fscanf(fp_in, "%d%d%d%d%d", &id[i], &release_m[i], &release_y[i], &rearrest_m[i], &rearrest_y[i]);
    }while(status == 5);

    *record_num = i;
}

void display_data(int id[], int release_y[], int release_m[], int rearrest_y[], int rearrest_m[], int record_num){
    int i;
    printf("Given data:\n");
    printf("OFFENDER ID\tMONTH OF RELEASE\tYEAR OF RELEASE\t\tMONTH OF REARREST\tYEAR OF REARREST\n");
    for(i = 0; i < record_num; i++){
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", id[i], release_m[i], release_y[i], rearrest_m[i], rearrest_y[i]);
    }
}

void get_f_name(char file_name[]){
    int i = -1,
        status;

    printf("Please enter the name of the file\n>");

    do{
        i += 1;
        status = scanf("%c", &file_name[i]);
    }while(status == 1 && file_name[i] != '\n');
    file_name[i] = '\0';
}