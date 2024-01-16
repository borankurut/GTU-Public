#include <stdio.h>

int main(){
    int service;    /*  free service number */
    int miles;      /*  number of miles     */
    printf("Enter the Free Service number>> ");
    scanf("%d", &service);
    printf("Enter number of Miles>> ");
    scanf("%d", &miles);

    if(service == 1){
        /*  first free service  */
        if(miles > 1500 && miles <= 3000)
            printf("Vehicle must be serviced.\n");

    }
    else if(service == 2){
        /*  second free service */
        if(miles>3001 && miles <= 4500)
            printf("Vehicle must be serviced.\n");
    }
    else{
        printf("invalid service number.\n");
    }

    return (0);
}