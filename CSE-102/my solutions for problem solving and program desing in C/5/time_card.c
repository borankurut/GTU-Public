#include <stdio.h>

#define OVERWORK 40         /*  after this hours of working the hourly rate will be multiplied by overwork_rate.*/
#define OVERWORK_RATE 1.5
#define TAX_PERCENT 3.625   /*  tax amount of TAX_PERCENT% of gross salary will be deducted.  */

int main(void){
    int id_num,         /*  identification num (input - output)                 */
    week_hr;            /*  number of hours worked during a given week (input)  */

    double hr_wage_rt,  /*  hourly wage rate (input)                            */
    net_pay;            /*  net pay of the employee(output)                     */

    printf("Please enter the id num (enter -1 for the id num to terminate.)> ");
    scanf("%d", &id_num);
    while(id_num != -1){
        printf("Hourly wage rate> ");
        scanf("%lf", &hr_wage_rt);
        printf("Number of hours worked during week> ");
        scanf("%d", &week_hr);

        /*  calculate gross */
        if(week_hr > OVERWORK){
            net_pay = OVERWORK * hr_wage_rt;
            net_pay += (week_hr - OVERWORK) * hr_wage_rt * OVERWORK_RATE;
        }
        else{
            net_pay = hr_wage_rt * week_hr;
        }

        /*  deduct the tax  */
        net_pay -= net_pay * (TAX_PERCENT / 100.0);

        printf("id:%d\tnet pay:%.2f\n", id_num, net_pay);

        printf("Please enter the id num (enter -1 for the id num to terminate.)> ");
        scanf("%d", &id_num);
    }

    return (0);
}