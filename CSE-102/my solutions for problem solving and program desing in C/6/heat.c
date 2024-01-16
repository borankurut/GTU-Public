#include <stdio.h>
#define Q_MARK -0.00001

/*  Prototypes  */
void calc_h(double *h, double k, double a, double t1, double t2, double x);
void calc_x(double h, double k, double a, double t1, double t2, double *x);
void calc_k(double h, double *k, double a, double t1, double t2, double x);
void calc_a(double h, double k, double *a, double t1, double t2, double x);
void calc_t1(double h, double k, double a, double *t1, double t2, double x);
void calc_t2(double h, double k, double a, double t1, double *t2, double x);
void driver_function();
void is_unknown(int status, double *unknown_number);
void display_formula();
void display_result(double h, double k, double a, double t1, double t2, double x);

int main(void){

    driver_function();
    return (0);
}

/*  Calculates the h from the formula via output    */
void calc_h(double *h, double k, double a, double t1, double t2, double x){
    *h = (k * a * (t2 - t1)) / x;
}

/*  Calculates the x from the formula via output    */
void calc_x(double h, double k, double a, double t1, double t2, double *x){
    *x = (k * a * (t2 - t1)) / h;
}

/*  Calculates the k from the formula via output    */
void calc_k(double h, double *k, double a, double t1, double t2, double x){
    *k = (h * x) / a * (t2 - t1);
}

/*  Calculates the a from the formula via output    */
void calc_a(double h, double k, double *a, double t1, double t2, double x){
    *a = (h * x) / (k*(t2 - t1));
}

/*  Calculates the t1 from the formula via output   */
void calc_t1(double h, double k, double a, double *t1, double t2, double x){
    *t1 = t2 - (h * x) / (k * a);
}

/*  Calculates the t2 from the formula via output   */
void calc_t2(double h, double k, double a, double t1, double *t2, double x){
    *t2 = t1 + (h * x) / (k * a);
}

void driver_function(){
    int status;                 /*  return value of the scanf function*/
    double h, k, a, t1, t2, x;  /*  elements of the formula.    */

    printf( "Respond to the prompts with the data known.\n" 
            "For the unknown quantity, enter a question mark (?).\n");

    printf("Rate of heat transfer (watts) >> ");
    status = scanf("%lf", &h);
    is_unknown(status, &h);

    printf("Coefficient of thermal conductivity (W/m-K) >> ");
    status = scanf("%lf", &k);
    is_unknown(status, &k);

    printf("Cross-sectional area of conductor (m^2) >> ");
    status = scanf("%lf", &a);
    is_unknown(status, &a);

    printf("Temperature on one side (K) >> ");
    status = scanf("%lf", &t2);
    is_unknown(status, &t2);

    printf("Temperature on other side (K) >> ");
    status = scanf("%lf", &t1);
    is_unknown(status, &t1);

    printf("Thickness of conductor (m) >> ");
    status = scanf("%lf", &x);
    is_unknown(status, &x);

    display_formula();

    if (h == Q_MARK)
        calc_h(&h, k, a, t1, t2, x);
    else if(k == Q_MARK)
        calc_k(h, &k, a, t1, t2, x);
    else if(a == Q_MARK)
        calc_a(h, k, &a, t1, t2, x);
    else if(t1 == Q_MARK)
        calc_t1(h, k, a, &t1, t2, x);
    else if (t2 == Q_MARK)
        calc_t2(h, k, a, t1, &t2, x);
    else if(x == Q_MARK)
        calc_x(h, k, a, t1, t2, &x);

    display_result(h, k, a, t1, t2, x);

}

/*  
*   check whether the scanned value is different than expected,
*   if so check if it is question mark, if it is then assign it the
*   defined Q_MARK value if it is not then exit.
*/
void is_unknown(int status, double *unknown_number){
    char discard, q_mark;

    if(status == 0){
        scanf("%c", &q_mark);

        if(q_mark == '?')
            *unknown_number = Q_MARK;

        else{
            printf("\nUnknown input.\n");
            exit(0);
        }

        while (discard != '\n'){
            scanf("%c", &discard);
        }
    }   
}

/*  Display the formula */
void display_formula(){
    printf( "      kA (T2 - T1)\n"
            "H = ----------------\n"
            "           X\n");
}

/*  Display the result  */
void display_result(double h, double k, double a, double t1, double t2, double x){
    printf( "H = %.1f W\tT2 = %.0f K\n"
            "k = %.3f W/m-K\tT1 = %.0f K\n"
            "A = %.3f m^2\tX = %.4f m\n", h, t2, k, t1, a, x);
}