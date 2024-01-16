#include <stdio.h>
int main(void){
    int input;
    int status;     /*  status of scanf */
    int high_s = 0, /*  number of vehicles moving at high,  */
    med_s = 0,      /*  medium,                             */
    low_s = 0;      /*  low speed.                          */

    printf("Speed of vehicles (in miles) >");
    status = scanf("%d", &input);
    while(status == 1){
        if(input >= 90){
            high_s += 1;
            printf("The vehicle is moving at high speed(%d).\n", input);
        }else if(input >= 50){
            med_s += 1;
            printf("The vehicle is moving at medium speed(%d).\n", input);
        }else if(input > 0){
            low_s += 1;
            printf("The vehicle is moving at low speed(%d).\n", input);
        }
        status = scanf("%d", &input);
    }
    printf("Car amount in categories:\n");
    printf("High: %d\nMedium: %d\nLow: %d\n", high_s, med_s, low_s);

    return (0);
}