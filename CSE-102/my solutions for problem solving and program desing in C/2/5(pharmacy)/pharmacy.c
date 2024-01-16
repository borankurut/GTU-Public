/* BORAN KURUT PROJECT 2.5 */
#include <stdio.h>
int main(void){
	float quantity; /* quantitiy of the fluid (ml)*/
	float time; /* number of minutes over which the fluid should be infused (minute)*/
	float vtbi; /* volume to be infused (ml/h)*/ 
	
	printf("enter the quantity of fluid in the bag => ");/* prompt */
	scanf("%f", &quantity);
	printf("enter the number of minutes => ");/* prompt */
	scanf("%f", &time);
	vtbi = quantity / (time / 60.0); /* calculating vtbi */
	printf("\nVTBI = %.2f",vtbi);
	return (0);
}
