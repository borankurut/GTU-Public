/*
*   displays what day of the year the given date is
*/
#include <stdio.h>
int is_leap(int year);
int days_in_month(int month);
int day_num_of_date(int year, int month, int day);
int main(){
    int year, month, day;
    printf("Please enter a date\n>");
    scanf("%d %d %d", &day, &month, &year);
    printf("The %d. day of the %d\n",day_num_of_date(year, month, day), year);
    return (0);
}
int is_leap(int year){
    /*
    *   returns 1 if the year is a leap year
    *   otherwise returns 0
    */
    if((year %4 == 0) && (year % 100 != 0))
        return 1;
    else if(year % 400 == 0)
        return 1;
    else 
        return 0;
}

int day_num_of_date(int year, int month, int day){
    /*
    *   returns what day of the year the given date is
    */
    int day_num = day;
    int i;
    for(i = month-1; i>0; i--){
        day_num += days_in_month(i);
    }

    if(month > 2 && is_leap(year) == 1){
        day_num += 1;
    }
    return day_num;
}

int days_in_month(int month){
    /*
    *   returns how many days the given month has
    */
    switch (month)
    {
    case 1:
        return  31;
        break;
    case 2:
        return  28;
        break;
    case 3:
        return  31;
        break;
    case 4:
        return  30;
        break;
    case 5:
        return  31;
        break;
    case 6:
        return  30;
        break;
    case 7:
        return  31;
        break;
    case 8:
        return  31;
        break;
    case 9:
        return  30;
        break;
    case 10:
        return  31;
        break;
    case 11:
        return  30;
        break;
    case 12:
        return  31;
        break;
    default:
        printf("Invalid month.\n");
        return 0;
        break;
    }
}