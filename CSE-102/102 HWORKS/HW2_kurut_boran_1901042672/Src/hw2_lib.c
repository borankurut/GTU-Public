/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include <math.h>
#include "hw2_lib.h"

/*-----------------------------------------------------------------------------my functions--------------------------------------------------------------------------------*/
int is_leap(int year)
{	
	if(year%4==0) /*leap years must be divisible by 4*/
	{
		if(year%100 == 0 && year%400 != 0)/*leap years can't be divided by 100 except those that can be divided by 400.*/
		{
			return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}

int days_until_date(int day, int month, int year)
{
	int days_of_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	int total_days=0; /* days until current date. */
	
	int i = 1;
	for(;i<year;i++) /* calculating days until current year. */
	{	
		if(is_leap(i)==0)
			total_days += 365;
		else
			total_days += 366;
	}
	
	i=1;
	for(;i<month;i++) /* adding days until current month. */
	{
		total_days += days_of_months[i-1];
	}
	
	if(is_leap(year)==1 && month>2) /*if there is a 29 february until current mounth. */
	{
		total_days += 1;
	}
	
	total_days += day; /* adding days in the current month */
	
	return total_days;
	
}
/*-----------------------------------------------------------------------------my functions(end)---------------------------------------------------------------------------*/

int find_weekday_of_data(int day, int month, int year)
{
	
	int weekday;
	
	weekday = ((days_until_date(day, month, year)+6) %7) +1; /* +6 is for the fitting and +1 is for the days to start from 1. */
	
    return weekday;
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
	int total_days_start_date, total_days_end_date, result;
	
	total_days_start_date = days_until_date(start_day, start_month, start_year); /* total days until start date */
	total_days_end_date = days_until_date(end_day, end_month, end_year); /* total days until end date */
	
	result = total_days_end_date - total_days_start_date;
	
	if(total_days_start_date > total_days_end_date)
	{
		printf("start date is later than the end date!");
		return 0;
	}
    else 
    	return result;
}


double find_angle(double a, double b, double c)
{
	double angle_alpha;
	
	/* from cosinus theorem */
    double angle_A = acos((b*b+c*c-a*a)/(2*b*c));
    double angle_B = acos((a*a+c*c-b*b)/(2*a*c));
    double angle_C = acos((a*a+b*b-c*c)/(2*a*b));
    
    /* Apollonius' theorem
    
    from A to CB = Va = 3x, AG=2x
    from B to CA = Vb = 3y, BG=2y
    from C to AB = Vc = 3z, CG=2z
    
    2Va^2 = 2(3x)^2 = b^2+c^2-a^2/2
    2Vb^2 = 2(3y)^2 = a^2+c^2-b^2/2 
    2Vb^2 = 2(3z)^2 = a^2+b^2-c^2/2
    
    */
    
    double x = sqrt((2*b*b + 2*c*c - a*a)/4)/3;
    double y = sqrt((2*a*a + 2*c*c - b*b)/4)/3;
    double z = sqrt((2*a*a + 2*b*b - c*c)/4)/3;
    
    angle_alpha = acos((-a*a + (2*y)*(2*y) + (2*z)*(2*z))/(2*2*y*2*z) ); /* from cosinus theorem (CGB triangle) */

    return angle_alpha;
}


void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
    printf("\n┌-----------------------------------------------------------------------┐\n");
    printf("|        Row 101        |      Row ABCDEFG      |      Row XYZ123       |\n");
    printf("|-----------------------|-----------------------|-----------------------|\n");
    printf("|\t%5u\t\t|%g\t\t\t|%-6d\t\t\t|\n", r11, r12, r13);
	printf("|-----------------------|-----------------------|-----------------------|\n");
    printf("|\t%5u\t\t|%g\t\t\t|%-6d\t\t\t|\n", r21, r22, r23);
	printf("|-----------------------|-----------------------|-----------------------|\n");
    printf("|\t%5u\t\t|%g\t\t\t|%-6d\t\t\t|\n", r31, r32, r33);
	printf("└-----------------------------------------------------------------------┘\n");
}

