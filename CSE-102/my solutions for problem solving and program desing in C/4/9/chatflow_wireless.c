#include <stdio.h>
#define FLT_RT 39.99        /*  flat rate                               */
#define FR_WK_MN 600        /*  offered weekday minutes                 */
#define WK_MIN_COST 0.40    /*  weekday minute cost after free minutes  */
#define TAX_RT 5.25         /*  tax rate percent                        */

int main(){
    double wday_min, n_min, wend_min;           /*  used weekday minute, night minute, weekend minute   */
    double monthly_bill, tax, pretax_bill;      /*  monthly bill, taxes, pretax bill                    */
    double av_bef_tax;                          /*  average cost of a minute before taxes               */

    printf("Please enter the number of weekday minutes, night minutes, and weekend minutes used >>");
    scanf("%lf %lf %lf", &wday_min, &n_min, &wend_min);

    /*  calculations    */
    if(wday_min < FR_WK_MN)
        pretax_bill = FLT_RT * 100;
    else
        pretax_bill = ((wday_min - FR_WK_MN) * WK_MIN_COST * 100) + FLT_RT * 100;

    av_bef_tax = pretax_bill / (wday_min + n_min + wend_min);

    tax = pretax_bill * TAX_RT/100;

    monthly_bill = pretax_bill + tax;

    printf("Monthly bill:%.2f\n", monthly_bill/100);
    printf("Average cost of a minute before taxes: %.2f\n", av_bef_tax/100);
    printf("Taxes: %.2f\n", tax/100);
    printf("Pretax bill: %.2f\n", pretax_bill/100);

    return (0);
}