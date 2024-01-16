#include <stdio.h>

/*  Prototypes  */
int get_problem();

void get_rate_drop_factor(double *rate, double *drop_factor);

void get_kg_rate_conc(double *rate, double *weight, double *concentration);

void get_units_conc(double *rate, double *concentration);

int fig_drops_min(double rate, double drop_factor);

int fig_ml_hr(double hr);

int by_weight(double rate, double weight, double concentration);

int by_units(double rate, double concentration);

void instruct();

int main(void){
    double rate, drop_factor, weight, concentration, hr;
    int choice = get_problem();
    switch (choice)
    {
    case 1:
        get_rate_drop_factor(&rate, &drop_factor);
        printf("The drop rate per minute is %d.\n", fig_drops_min(rate, drop_factor));
        break;
    case 2:
        printf("Enter number of hours=> ");
        scanf("%lf", &hr);
        printf("The rate in milliliters per hour is %d.", fig_ml_hr(hr));
        break;
    case 3:
        get_kg_rate_conc(&rate, &weight, &concentration);
        printf("The rate in milliliters per hour is %d.", by_weight(rate, weight, concentration));
        break;
    case 4:
        get_units_conc(&rate, &concentration);
        printf("The rate in milliliters per hour is %d.", by_units(rate, concentration));
        break;
    case 5:
        printf("Exitting.\n");
        break;
    }
    return (0);
}

/*
*   Displays the user menu, then inputs and returns as the function
*   value the problem number selected.
*/
int get_problem(){
    int input;
    int wrong_input = 0;
    do{
        wrong_input = 0;
        instruct();
        scanf("%d", &input);
        if(input <0 || input > 5){
            wrong_input = 1;
            printf("\n---Please read the instructions carefully!---\n\n");
        }
    }while(wrong_input);
    return (input);
}

/*   
*   Prompts the user to enter the data required for
*   problem 1, and sends this data back to the calling module via output
*   parameters.
*/
void get_rate_drop_factor(double *rate, double *drop_factor) {
    printf("Enter rate in ml/hr=> \n");
    scanf("%lf", rate);
    printf("Enter tubing's drop factor(drops/ml)=> \n");
    scanf("%lf", drop_factor);
}                           

/*
*   Prompts the user to enter the data required for problem 3
*   and sends this data back to the calling module via output parameters.
*/
void get_kg_rate_conc(double *rate, double *weight, double *concentration){
    printf("Enter rate in mg/kg/hr=> ");
    scanf("%lf", rate);
    printf("Enter patient weight in kg=> ");
    scanf("%lf", weight);
    printf("Enter concentration in mg/ml=> ");
    scanf("%lf", concentration);

}

/*  
*   Prompts the user to enter the data required for problem 4,
*   and sends this data back to the calling module via output parameters.
*/
void get_units_conc(double *rate, double *concentration){
    printf("Enter rate in units/hr=> ");
    scanf("%lf", rate);
    printf("Enter concentration in units/ml=> ");
    scanf("%lf", concentration);

}

/*  
*   Takes rate and drop factor as input parameters and returns
*   drops/min (rounded to nearest whole drop) as function value.
*/
int fig_drops_min(double rate, double drop_factor){
    int drops_min;

    double per_min_rate = rate / 60;
    drops_min = (int)(per_min_rate * drop_factor + 0.5);
    return (drops_min);
}

/*
*   Takes as an input parameter the number of hours over which
*   one liter is to be delivered and returns ml/hr (rounded) as function value.
*/
int fig_ml_hr(double hr){
    int ml_hr = (int)(1000 / hr + 0.5);
    return (ml_hr);
}

/*
*   Takes as input parameters rate in mg/kg/hr, patient weight in kg,
*   and concentration of drug in mg/ml and returns ml/hr (rounded) as function
*   value.
*/
int by_weight(double rate, double weight, double concentration){
    int ml_pr_hr;
    double mg_pr_hr = rate * weight;
    ml_pr_hr = (int)(mg_pr_hr / concentration + 0.5);
    return (ml_pr_hr);
}

/*
*   Takes as input parameters rate in units/hr and concentration in
*   units/ml, and returns ml/hr (rounded) as function value.
*/
int by_units(double rate, double concentration){
    int result = (int)(rate / concentration + 0.5);
    return result;
}

/*
*   Prompts the user for choice.    
*/
void instruct(){
    printf("Enter the number of the problem you wish to solve.\n"
        "GIVEN A MEDICAL ORDER IN CALCULATE RATE IN\n"
        "(1) ml/hr & tubing drop factor drops / min\n"
        "(2) 1 L for n hr ml / hr\n"
        "(3) mg/kg/hr & concentration in mg/ml ml / hr\n"
        "(4) units/hr & concentration in units/ml ml / h\n"
        "(5) QUIT\nChoice:\n>");
}