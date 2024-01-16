#include <stdio.h>
double celsius_at_depth(double depth);
double fahrenheit(double celsius);
int main(){
	double depth;				/*	INPUTS	depth(km) inside the earth	*/
	double temp_cel, temp_fah;	/*	OUTPUTS	temp(celsius, fahrenheit)	*/
	/*	prompts	*/
	printf("Please enter the depth(km) >");
	scanf("%lf", &depth);
	/*	calculations	*/
	temp_cel = celsius_at_depth(depth);
	temp_fah = fahrenheit(temp_cel);
	/*	display	*/
	printf("Temperature at the depth %.1fkm = %.1f celsius (%.1f fahrenheit).\n", depth, temp_cel, temp_fah);

	return(0);
}
double fahrenheit(double celsius){
	/*
	*	Converts celsius to fahrenheit and returns the value.
	*/
	double result = celsius * 1.8 + 32;
	return result;
}
double celsius_at_depth(double depth)
{
	/*	
	*	Returns the temperature(celsius) at the depth(km)
	*/
	double temp = 10 * depth + 20;
	return temp;
}
