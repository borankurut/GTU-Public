/* BORAN KURUT PROJECT 2*/

#define G 9.80 /* gravity constant(m/s^2) */
#define EC 90/100 /* efficiency constant */
#include <stdio.h>
int main(void){
	int height; /* height of the dam(m) */
	double flow; /* water projected to flow each second (m^3/s) */
	double work_per_second;/* work done by water per second */
	double power_produced; /* W */
	printf("Please enter the height of the dam(m) => ");/*prompt*/
	scanf("%d", &height);
	printf("\nPlease enter the flow of the water(m^3/s) => ");/*prompt*/
	scanf("%lf", &flow);
	
	work_per_second = (flow*1000) * G * height; /* flow * 1000 equals to mass per second */
	power_produced = work_per_second * EC;
	
	printf("\nThe produced power is %.1fMW", power_produced/1000000);
	return (0);
}

