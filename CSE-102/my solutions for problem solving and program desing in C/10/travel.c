#include <stdio.h>
#include <string.h>
#define NAME_LEN 50

typedef struct{
    char destination[NAME_LEN];

    double  distance,   /*  m                       */
            time;       /*  s                       */

    char direction;     /*  'N', 'S', 'E', or 'W'   */
}travel_data;

int scan_travel_data(travel_data *new_travel);
void print_travel_data(travel_data to_print);
int travel_data_compare(travel_data data0, travel_data data1);

int main(void){
    travel_data my_data,
                my_data2;

    scan_travel_data(&my_data);
    scan_travel_data(&my_data2);
    print_travel_data(my_data);
    print_travel_data(my_data2);



    printf("\n\n%d\n", travel_data_compare(my_data, my_data2));

    return (0);
}

int scan_travel_data(travel_data *new_travel){
    int status;
    printf("Enter destination > ");
    status = scanf("%s", new_travel->destination);

    if(status == 1){
        printf("Enter distance(m) > ");
        status = scanf("%lf", &new_travel->distance);
    }
    if(status == 1){
        printf("Enter time(s) > ");
        status = scanf("%lf", &new_travel->time);
    }
    if(status == 1){
        getchar();
        printf("Enter direction ('N', 'S', 'E', or 'W') > ");
        status = scanf("%c", &new_travel->direction);
    }

    return(status);
}

void print_travel_data(travel_data to_print){
    printf("%s is %.2f m to the %c with %.2f seconds travelling data.\n",
    to_print.destination, to_print.distance, to_print.direction, to_print.time);
}

int travel_data_compare(travel_data data0, travel_data data1){
    return (strcmp(data0.destination, data1.destination) == 0   &&
            data0.direction == data1.direction                  &&
            data0.distance == data1. distance                   &&
            data0.time == data1.time);
}