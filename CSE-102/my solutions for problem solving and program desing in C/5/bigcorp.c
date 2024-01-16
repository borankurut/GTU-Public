#include <stdio.h>

#define SUBSIDIZE 0.08

int main(void){
    int psg,        /*  passengers          */
    weekly_com,     /*  weekly commute(km)  */
    min_efficiency; /*  minimum efficiency  */

    double  gass_cons,  /*  gassoline consumption   */
    efficiency,         /*  efficiency ns/l         */
    weekly_sub;         /*  weekly subsidy          */

    scanf("%d", &min_efficiency);
    printf("\n\nCarpools Meeting Minimum Passenger Efficiency of %d Passenger KM/L\n\n", min_efficiency);
    printf("Passengers\tWeekly\t\tGasoline\tEfficiency\tWeekly\n");
    printf("\t\tCommute(km)\tConsumption(L)\t(pass km/L)\tSubsidy($)\n\n");

    scanf("%d %d %lf", &psg, &weekly_com, &gass_cons);
    while((psg != 0) || (weekly_com != 0) || (gass_cons != 0)){
        /*  code here   */
        efficiency = ((double)psg * (double)weekly_com) / gass_cons;

        weekly_sub = 0;
        if(efficiency >= min_efficiency)
            weekly_sub = (double)psg * (double)weekly_com * SUBSIDIZE;

        printf("%-10d%6c%-11d%5c%-14.1f%2c%-11.1f%5c%.2f\n",
                psg, ' ', weekly_com, ' ', gass_cons, ' ', efficiency, ' ', weekly_sub);
                
        scanf("%d %d %lf", &psg, &weekly_com, &gass_cons);
    }

    return (0);
}