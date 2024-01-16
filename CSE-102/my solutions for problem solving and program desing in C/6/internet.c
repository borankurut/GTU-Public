#include <stdio.h>
#include <math.h>

#define FLAT_HOURS 10           /* This number of hours is going to cost flat rate  */
#define FLAT_RATE 7.99          /* Amount of charge up to flat hours                */
#define ADDITIONAL_CHARGE 1.99  /* Additional hours charge                          */

/*  Prototypes  */
void charges(double connection_time, double *total_charge, double *avr_cost_hour);
void charges_driver(double connection_time);
void print_charge(int customer, double connection_time, FILE *fp_out);


int main(void){
    int cur_month, cur_year;    /*  current month and year  */
    int customer_num;           /*  customer number         */
    int status;                 /*  status of the scanf     */
    double connection_time;

    FILE *fp_in = fopen("usage.txt", "r");
    FILE *fp_out = fopen("charges.txt", "w");

    fscanf(fp_in, "%d %d", &cur_month, &cur_year);
    fprintf(fp_out,"Charges for %d/%d\n", cur_month, cur_year);
    fprintf(fp_out, "\t\t\t\tCharge\n");
    fprintf(fp_out, "Customer\tHours Used\tper hour\tAverage Cost\n");
    do{
        status = fscanf(fp_in, "%d %lf", &customer_num, &connection_time);
        print_charge(customer_num, connection_time, fp_out);
    }while(status == 2);

    fclose(fp_in);
    fclose(fp_out);
    return (0);
}



/*
*   Returns total charge of the customer and average cost of one hour via output parameters
*   based on the used hoursnumber of hours of connection time used in a month.
*/
void charges(double connection_time,   /*  total connected hours of the customer in a month    */
            double *total_charge,      /*  total charge of the customer                        */
            double *avr_cost_hour      /*  average cost of one hour in a month                 */
){
    if(connection_time <=  FLAT_HOURS)
        *total_charge = FLAT_RATE;
    else
        *total_charge = FLAT_RATE + (ceil(connection_time) - FLAT_HOURS) * ADDITIONAL_CHARGE;

    *avr_cost_hour = *total_charge / connection_time;
}


void charges_driver(double connection_time){
    double total_charge, avr_cost_hour;

    charges(connection_time, &total_charge, &avr_cost_hour);
    printf("results:\n");
    printf("connection time: %.2f\ntotal_charge: %.2f\navr_cost_hour: %.2f\n",
             connection_time, total_charge, avr_cost_hour);
}

void print_charge(int customer, double connection_time, FILE *fp_out){
    double total_charge, avr_cost_hour;

    charges(connection_time, &total_charge, &avr_cost_hour);
    fprintf(fp_out, "%d\t\t%.1f\t\t%.2f\t\t%.2f\n",
            customer, connection_time, total_charge, avr_cost_hour);
}