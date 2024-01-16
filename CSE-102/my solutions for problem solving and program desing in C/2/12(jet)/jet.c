/* BORAN KURUT PROJECT 2.12 */
#include <stdio.h>
int main(void){
	double v, a, t, s; /* velocity(m/s), acceleration(m/s^2), time(s), distance(m)*/
	double input_v; /* input velocity (km/hr)*/
	/* prompt, input */
	printf("Please enter the takeoff speed(km/hr) and the distance(m) =>");
	scanf("%lf %lf", &input_v, &s);
	v = input_v * (10.0/36.0);
	a = (v * v) / (2 * s);
	t = v / a;
	printf("acceleration: %.1fm/s^2, time: %.1fs\n", a, t);
	
	return(0);
}
