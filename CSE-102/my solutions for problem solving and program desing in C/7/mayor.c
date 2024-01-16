#include <stdio.h>

#define FILE_NAME       "mayor.txt"     /*      name of the input file  */
#define MAX_R           10              /*      maximum report number   */

typedef enum
        {A, B, C, D, N}
winner_t;

/*      prototypes    */
void get_data(  FILE *fp_in,
                int precinct[], int candidate_a[], int candidate_b[],
                int candidate_c[], int candidate_d[], int *number_of_reports);

void display_data(  int precinct[], int candidate_a[], int candidate_b[],
                int candidate_c[], int candidate_d[], int number_of_reports);

void decide_winner(winner_t winner_s[], int candidate_a[], int candidate_b[],
        int candidate_c[], int candidate_d[], int number_of_reports);

int rtn_min(int arr[], int left, int right, int *where);

void sort_arr(int arr[], int n);

void drive_sort();

int main(void){

        int precinct[MAX_R], candidate_a[MAX_R], candidate_b[MAX_R], candidate_c[MAX_R], candidate_d[MAX_R];
        FILE *fp_in = fopen(FILE_NAME, "r");

        int i;
        int n_of_reports;        /*      number of reports       */

        get_data(fp_in, precinct, candidate_a, candidate_b, candidate_c, candidate_d, &n_of_reports);
        display_data(precinct, candidate_a, candidate_b, candidate_c, candidate_d, n_of_reports);

        drive_sort();


        fclose(fp_in);
}

/*  gets the results from the mayor’s race    */

void get_data(FILE *fp_in,
        int precinct[],
        int candidate_a[],
        int candidate_b[],
        int candidate_c[],
        int candidate_d[],
        int *number_of_reports)
{
        int status,     /*      status for scanf function       */
                i = -1;

        do{
                i += 1;
                status = fscanf(fp_in, "%d%d%d%d%d",   &precinct[i],
                                &candidate_a[i], &candidate_b[i],
                                &candidate_c[i], &candidate_d[i]);
        }while(status == 5 && i < MAX_R - 1);

        if(i == MAX_R){
                printf("Error: Input file contents exceed the maximum data to be processed\n");
        }            
        *number_of_reports = i;
}

void display_data(int precinct[],
        int candidate_a[],
        int candidate_b[],
        int candidate_c[],
        int candidate_d[],
        int number_of_reports)
{
        winner_t winner_s[3];
        int i;
        printf("%18cCandidate%8cCandidate%8cCandidate%8cCandidate\n", ' ', ' ', ' ', ' ');
        printf("%2cPrecinct%12cA%16cB%16cC%16cD\n\n", ' ', ' ', ' ', ' ', ' ');
        for(i = 0; i < number_of_reports; i++){
                printf("%5c%-16d %-16d %-16d %-16d %-16d\n", ' ', precinct[i], candidate_a[i],
                                                        candidate_b[i], candidate_c[i], candidate_d[i]);
        }

}

void decide_winner(winner_t winner_s[],
        int candidate_a[],
        int candidate_b[],
        int candidate_c[],
        int candidate_d[],
        int number_of_reports)

{
        int score_sum = 0;
        int scores[4] = {0, 0, 0, 0};
        int i;

        for(i = 0; i < number_of_reports; i++){
                scores[0] += candidate_a[i];
                scores[1] += candidate_b[i];
                scores[2] += candidate_c[i];
                scores[3] += candidate_d[i];

                score_sum += candidate_a[i] + candidate_b[i] +candidate_c[i] + candidate_d[i];
        }

        sort_arr(scores, 4);

        if(scores[0] >= score_sum / 2.0){
                
        }
        
}

int rtn_min(int arr[], int left, int right, int *where){
        int min = arr[left];
        int i;

        *where = left;

        for(i = left; i < right; i++)
                if(arr[i] < min){
                        min = arr[i];
                        *where = i;
                }
        return min;
}

void sort_arr(int arr[], int n){
        int min, temp, where;
        int i;
        for (i = 0; i < n; i++){
                temp = arr[i];
                arr[i] = rtn_min(arr, i, n, &where);
                arr[where] = temp;
        }
}