#include <stdio.h>
/*  BOILING POINTS  */
#define BPWATER 100
#define BPMERCURY 357
#define BPCOOPER 1187
#define BPSILVER 2193
#define BPGOLD 2660

int within_x_percent(double ref, double data, double x);

int main(){
    double bp;
    printf("Please enter the observed boiling point of a substance in C\n>>");
    scanf("%lf", &bp);
    if(within_x_percent(BPWATER, bp, 5) == 1)
        printf("Water\n");
    else if(within_x_percent(BPMERCURY, bp, 5) == 1)
        printf("Mercury\n");
    else if(within_x_percent(BPCOOPER, bp, 5) == 1)
        printf("Cooper\n");
    else if(within_x_percent(BPSILVER, bp, 5) == 1)
        printf("Silver\n");
    else if(within_x_percent(BPGOLD, bp, 5) == 1)
        printf("Gold\n");
    else 
        printf("Substance unknown\n");

    return (0);
}
int within_x_percent(double ref, double data, double x){
    /*  
    *   returns 1 if the data is in the 
    *   %x error range of the reference
    *   otherwise returns 0.
    */
    double min = ref - (ref* x/100);
    double max = ref + (ref* x/100);

    if(min < data && data < max)
        return 1;
    else 
        return 0;
}