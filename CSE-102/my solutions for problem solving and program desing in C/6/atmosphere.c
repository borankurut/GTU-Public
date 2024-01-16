#include <stdio.h>

#define START_TABLE 0       /* First velocity (table)           */
#define INCREMENT_TABLE 5   /* Velocity incrementation (table)  */
#define END_TABLE 40        /* Last velocity (table)            */
#define P 1.23              /* p: the density of the gas or fluid through which the body is traveling 1.23 kg/m^3 on sea level. */

void get_a_cd(double *a, double *cd);
double calculate_f(double cd, double a, double p, double v);
void display_table(double cd, double a, double p, double start_v, double inc_v, double end_v);

int main(void){
    double a, cd;    
    get_a_cd(&a, &cd);
    display_table(cd, a, P, START_TABLE, INCREMENT_TABLE, END_TABLE);
    
    return (0);
}

/*  Gets projected area and drag coefficient from the console.  */
void get_a_cd(double *a, double *cd){
    int wrong_input, status;
    char discard;
    do{
        wrong_input = 0;
        printf("Please enter the projected area of the vehicle perpendicular to the velocity vector (in m2)\n");
        printf("and then the drag coefficient\n>");

        status = scanf("%lf%lf", a, cd);

        if(status != 2){
            wrong_input = 1;
            printf("Please read the instructions carefully.\n\n");
            while(discard != '\n')
                scanf("%c", &discard);
        }
    }while(wrong_input);
}

/*  Calculates the drag force from the formula. */
/*
*       Drag force formula:  F = 1/2 CD * A * p * V^2
*/
double calculate_f(double cd, double a, double p, double v){
    double f = 1.0/2.0 * cd * a * p * v * v;
    return f;
}

/*  displays the table */
void display_table(double cd, double a, double p, double start_v, double inc_v, double end_v){
    double v;

    printf("Velocity\tDrag force\n");
    for(v = start_v; v <= end_v; v += inc_v){
        printf("%-18.2f%.2f\n", v, calculate_f(cd, a, p, v));
    }
}