/*BORAN KURUT PROGRAMMING PROJECT 2.1*/

#define DPM 1.50 /* dollars per mile */
#include <stdio.h>
int main(void){
	double beg_odo, end_odo;/*beginning odometer reading, ending odometer reading*/
	double distance, fare;
	printf("TAXI FARE CALCULATOR\n");
	printf("Enter beginning odometer reading => ");
	scanf("%lf", &beg_odo);
	printf("\nEnter ending odometer reading => ");
	scanf("%lf", &end_odo);
	
	distance = end_odo - beg_odo;/* calculating distance */
	fare = distance * DPM;/* calculating fare */
	
	printf("You traveled a distance of %3.1f miles. At $%3.2f per mile, your fare is $%2.2f.", distance, DPM, fare);
	return (0);	
}
