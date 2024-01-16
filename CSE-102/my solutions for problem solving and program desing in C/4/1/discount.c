/*
*   This program calculates and displays the
*   total cost of a purchase considering 
*   the student discount and taxes.
*/
#include <stdio.h>

#define STD_DSC 20  /*  student discount percent    */
#define TAX_PRC 5   /*  tax percent                 */

void prompt();                  /*  prompt the user             */

void display(char purchaser,    /*  display the results         */    
double purchase_total, 
double discount, 
double tax, 
double total_cost);

int main(){
    char purchaser = 'n';   /*  n indicates "non student", s indicates "student"    */
    double purchase_total;  /*  purchase total                                      */
    double discount = 0;    /*  calculated discount if the purchaser is a student   */
    double tax;             /*  calculated taxes                                    */
    double total_cost;      /*  calculated total cost                               */

    prompt();
    scanf("%lf %c", &purchase_total, &purchaser);


    if(purchase_total < -0.01 ){    /*  if user enters invalid purchase_total value */
        printf("Invalid purchase total.\n\n");
        prompt();
        scanf("%lf %c", &purchase_total, &purchaser);
    }

    if(purchaser!='s' && purchaser!='n'){   /*  if user enters invalid purchaser    */
        printf("Invalid purchaser.\n\n");
        prompt();
        scanf("%lf %c", &purchase_total, &purchaser);
    }

    /*  calculation of the total cost   */
    if(purchaser == 's')
        discount = purchase_total * (STD_DSC/100.0);
    
    total_cost = purchase_total;
    total_cost -= discount;
    tax = total_cost * (TAX_PRC/100.0); /*  calculate the tax.  */
    total_cost += tax;
    display(purchaser, purchase_total, discount, tax, total_cost);
    
}



void prompt(){
    printf("Please enter the purchase total($) and ");  /*  prompt the user */
    printf("type 's' if the purchaser is a student\n");
    printf("or type 'n' if the purchaser is not a student ");
    printf("after a blank line (like: ""$100 s"" or ""$100 n"").\n>");
}

void display(char purchaser,double purchase_total, double discount, 
double tax, double total_cost){
    printf("Total purchases\t\t\t\t%.2f\n", purchase_total);
    if(purchaser == 's'){
        printf("Student's discount (%d%%)\t\t%.2f\n", STD_DSC, discount);
        printf("Discounted total\t\t\t%.2f\n", purchase_total-discount);
    }
    printf("Sales tax (%d%%)\t\t\t\t%.2f\n", TAX_PRC, tax);
    printf("Total\t\t\t\t\t%.2f\n", total_cost);
}