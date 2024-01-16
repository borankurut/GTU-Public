/*
*   This program calculates the bmi and categorizes it
*/

#include <stdio.h>

void prompt(double* wt_lb, double* ht_in);      /*  prompts weight and height, returns them.    */
int calculate_bmi(double wt_lb, double ht_in);  /*  calculates bmi based on weight and height.  */
void display_result(double bmi);                /*  displays the category of the given bmi.     */

int main(){
    double wt_lb, ht_in;    /*  Inputs: weight(pound), height(inch).    */
    double bmi;             /*  Outputs: body mass index.               */
    prompt(&wt_lb, &ht_in);

    /*  Calculation */
    bmi = calculate_bmi(wt_lb, ht_in);

    display_result(bmi);
    printf("(%.1f)", bmi);
    return(0);
}

void prompt(double* wt_lb, double* ht_in){   /*  prompts weight and height, returns them.    */
    printf("Please enter your weight(pound)\n>");
    scanf("%lf",wt_lb);
    printf("\nPlease enter your height(inch)\n>");
    scanf("%lf",ht_in);
}

int calculate_bmi(double wt_lb, double ht_in){   /*  calculates bmi based on weight(pound) and height(inch).  */
    double bmi = (703.0 * wt_lb) / (ht_in * ht_in);
    return bmi;
}

void display_result(double bmi){   /*  displays the category of the given bmi.     */
    if(bmi < 1){
        printf("Unexpected result.");
    }else if(bmi < 18.5){
        printf("Underweight.");
    }else if(bmi <= 24.9){
        printf("Normal.");
    }else if(bmi <= 29.9){
        printf("Overweight.");
    }else{
        printf("Obese.");
    }
}