#include <stdio.h>
double population(double year);
int main(){
	double year;	/*	Input	*/
	double pop;		/*	Output	*/
	printf("Enter a year after 1990 >");
	scanf("%lf", &year);
	pop = population(year);
	printf("Predicted Gotham City population for %.0f (in thousands):\n%6.3f\n", year, pop);
	
	return (0);
}
double population(double year){
	/*
	*	Predicts the population of the Gotham City by given year that is after 1990.
	*/
	double predicted_pop;
	year -= 1990;
	predicted_pop = 52.966 + 2.184 * year;
	return predicted_pop;
}
