#include <stdio.h>
#define PERIOD_YEAR 5
void instruct();
double calc_total_cost(double initial_cost, double fuel_cost, double tax_rate);
int main(){
	instruct();
	instruct();
	instruct();
	return (0);
}
void instruct(){

	/*
	*	displays instcutions to the program user
	*	prompts and gets the data
	*	calls calc_total_cost to calculate the total cost
	*	and displays the result
	*/
	double initial_house_cost, annual_fuel_cost, tax_rate;	/*	INPUTS	*/
	double total_house_cost;								/*	OUTPUTS	*/
	
	printf("\nPlease enter the initial house cost >");
	scanf("%lf", &initial_house_cost);
	printf("Please enter the annual fuel cost >");
	scanf("%lf", &annual_fuel_cost);
	printf("Please enter the tax rate >");
	scanf("%lf", &tax_rate);
	
	total_house_cost = calc_total_cost(initial_house_cost, annual_fuel_cost, tax_rate);
	
	printf("\nThe total house cost is: $%.1f for the 5 year(s) period.\n", total_house_cost, PERIOD_YEAR);
	
	
}
double calc_total_cost(double initial_cost, double fuel_cost, double tax_rate){

	/*
	*	calculates the total cost of a house by its cost, fuel_cost, period year and the tax_rate.
	*	Pre:	PERIOD_YEAR is defined constant.
	*/
	double total_cost;
	total_cost = initial_cost;
	total_cost += fuel_cost * PERIOD_YEAR + (tax_rate * initial_cost * PERIOD_YEAR);
	return total_cost;
}
