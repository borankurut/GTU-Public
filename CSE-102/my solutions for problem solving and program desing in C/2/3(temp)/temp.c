/* BORAN KURUT PROJECT 2.3*/
#include <stdio.h>
int main(){
	float temp;
	float time;
	int hours, minutes;
	printf("Please enter the time elapsed since the power failure => ");
	scanf("%d %d", &hours, &minutes);
	time = hours + minutes / 60.0; /* calculating time (hours) */
	printf("%.2f hours.", time);
	temp = (4 * time * time) / (time + 2) - 20;/*calculating the temperature*/
	printf("\nTemp: %.2f\n", temp);
	return (0);
}
