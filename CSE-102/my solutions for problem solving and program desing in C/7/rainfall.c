#include <stdio.h>
#include <stdlib.h>

#define MNTH            12
#define IN_FILE_NAME    "rainfall_input.txt"

void get_data(FILE *fp_in, double this_year[], double last_year[]);
void display_result(double this_year[], double last_year[]);

int main(void){
    int i;
    double  this_year[MNTH], 
            last_year[MNTH];

    FILE *fp_in = fopen(IN_FILE_NAME, "r");

    get_data(fp_in, this_year, last_year);
    display_result(this_year, last_year);

    return (0);
}

void get_data(FILE *fp_in, double this_year[], double last_year[]){
    int i, status;

    for (i = 0; i < MNTH; i++){
        status = fscanf(fp_in, "%lf%lf", &this_year[i], &last_year[i]);

        if(status != 2){
            printf("Error: invalid input data format.\n");
        }
    }
}

void display_result(double this_year[], double last_year[]){
    int i;
    double this_total = 0, last_total = 0, this_av, last_av;
    printf("\t\tJan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
    printf("This Year:\t");
    for(i = 0; i < MNTH; i++){
        printf("%.1f\t", this_year[i]);
        this_total += this_year[i];
    }
    printf("\nLast Year:\t");
    for(i = 0; i< MNTH; i++){
        printf("%1.f\t", last_year[i]);
        last_total += last_year[i];
    }
    printf("\n");

    this_av = this_total / (double)MNTH;
    last_av = last_total / (double)MNTH;
    printf("This year total: %.1lf\tAverage: %.1lf\n", this_total, this_av);
    printf("Last year total: %.1lf\tAverage: %.1lf\n", last_total, last_av);
}