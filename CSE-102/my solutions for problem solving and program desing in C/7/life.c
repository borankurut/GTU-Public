#include <stdio.h>

#define DECADE_AMT  6

void get_data(FILE * fp_in, double arr[][2], int decade_amount);
void matrix_dif(double arr1[][2], double arr2[][2], double arr3[][2], int n);
void display(double male[][2], double female[][2], double dif[][2]);


int main(void){
    FILE *f_in = fopen("female.txt", "r");      /*  female data file    */
    FILE *m_in = fopen("male.txt", "r");        /*  male data file      */

    double female[DECADE_AMT][2];   /*  first represents which decade, second represents race(0 = black, 1 = white) */
    double male[DECADE_AMT][2];
    double dif[DECADE_AMT][2];

    get_data(f_in, female, DECADE_AMT);
    get_data(m_in, male, DECADE_AMT);

    matrix_dif(female, male, dif, DECADE_AMT);

    display(male, female, dif);

    fclose(f_in);
    fclose(m_in);

    return (0);
}

void get_data(FILE * fp_in, double arr[][2], int decade_amount){
    int status, year,
        i = -1;
    do{
        i += 1;
        status = fscanf(fp_in, "%d %lf %lf", &year, &arr[i][0], &arr[i][1]);
    }while(status == 3 && i < decade_amount - 1);
}

/*  returns arr3 which is arr1 - arr2*/
void matrix_dif(double arr1[][2], double arr2[][2], double arr3[][2], int n){
    int i;
    for(i = 0; i < n; i++){
        arr3[i][0] = arr1[i][0] - arr2[i][0];
        arr3[i][1] = arr1[i][1] - arr2[i][1];
    }
}

void display(double male[][2], double female[][2], double dif[][2]){
    int year = 1950;
    int i;
    printf("Female\t\t\t\tMale\t\t\t\t\tDifference\n");
    printf("Year\tBlack\tWhite\t\tYear\tBlack\tWhite\t\t\tYear\tBlack\tWhite\n");

    for(i = 0; i < DECADE_AMT; i++){
        year += i * 10;
        printf("%d\t%.2f\t%.2f\t\t", year, female[i][0], female[i][1]);
        printf("%d\t%.2f\t%.2f\t\t\t", year, male[i][0], male[i][1]);
        printf("%d\t%.2f\t%.2f", year, dif[i][0], dif[i][1]);
        printf("\n");
    }
}