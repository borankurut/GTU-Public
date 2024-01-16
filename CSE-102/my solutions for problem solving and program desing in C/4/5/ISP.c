#include <stdio.h>

int calc_chrg(double dt_usg);

int main(){
    double dt_usg;
    int chrg;
    printf("Please enter the data usage\n>");
    scanf("%lf", &dt_usg);
    chrg = calc_chrg(dt_usg);
    printf("Charge: $%d",chrg);
    return(0);
}
int calc_chrg(double dt_usg){
    /*
    *   returns the charge based on data usage.
    */
    if(dt_usg <= 0.0){
        printf("invalid data usage.\n");
        return 0;
    }
    else if(dt_usg<1.0)
        return 250;
    else if(dt_usg<2.0)
        return 500;
    else if(dt_usg<5.0)
        return 1000;
    else if(dt_usg<10.0)
        return 1500;
    else 
        return 2000;
}