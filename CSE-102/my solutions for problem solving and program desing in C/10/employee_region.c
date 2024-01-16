#include <stdio.h>
#include <string.h>

#define NAME_LEN 20
#define NUM_LEN  16     /*+1-202-555-0123(random)*/

typedef struct{
    char name[NAME_LEN],
        city[NAME_LEN],
        contact_number[NUM_LEN],
        department[NAME_LEN];


    int ID,
        gross_salary;
}employee_t;

int main(void){

    return(0);
}

void sort_employee_by_city(employee_t employee_arr[], int n){
    int ix;
    int prior_ix = 0;
    employee_t temp;

    if(n > 0){
        for(ix = 1; ix < n; ix++){
            if(strcmp(employee_arr[ix].city, employee_arr[prior_ix].city) > 0)
                prior_ix = ix;
        }
    temp = employee_arr[0];
    employee_arr[0] =  employee_arr[prior_ix];
    employee_arr[prior_ix] = temp;
    }

    sort_employee_by_city(&employee_arr[1], n - 1);
}