#include <stdio.h>
#include <math.h>
void speeds_ratio(double speed_max, double speed_min);
int main(){
	double speed_max, speed_min; /*	Inputs	*/
	/*	prompts	*/
	printf("Please enter the max speed >");
	scanf("%lf", &speed_max);
	printf("Please enter the min speed >");
	scanf("%lf", &speed_min);
	
	speeds_ratio(speed_max, speed_min);
	
	return(0);
}
void speeds_ratio(double speed_max, double speed_min){
	/*	
	*	Calculates and displays the ratio
	*	for the 6 speed gearbox.
	*	PRE: math.h is included.
	*/
	double ratio = pow((speed_max/speed_min), 1.0/5);
	
	printf("The ratio between successive speeds of a six-speed gearbox \nwith maximum speed %.0frpm ",speed_max);
	printf("and  \nminimum speed %.0f rpm is %.3f.\n", speed_min, ratio);
}
