#include <stdio.h>
#include <math.h>
double calculate_payment(double i, double p, double n);
int main(){
	double price, down_payment, annual_interest_rate, total_number_of_payments, income_per_hour; /* INPUTS */
	double payment, hours_to_work; /* OUTPUT */
	
	double principle;
	double monthly_interest_rate;
	
	/*prompts*/
	printf("Please enter the purchase price, the down payment,\nthe annual interest rate, the total number of payments >");
	scanf("%lf %lf %lf %lf", &price, &down_payment, &annual_interest_rate, &total_number_of_payments);
	printf("Please enter the income per hour.");
	scanf("%lf", &income_per_hour);
	
	/*calculations*/
	principle = price - down_payment;
	monthly_interest_rate = annual_interest_rate / 12;
	
	payment = calculate_payment(monthly_interest_rate, principle, total_number_of_payments);
	
	hours_to_work = (payment / 20.0) / income_per_hour;
	
	printf("\n payment: $%.2f, amount borrowed: $%.2f, you need to work %.2f hours a day. ", payment, principle, hours_to_work);

	return (0);
}
double calculate_payment(double i, double p, double n){
	/*	calculate the payment using:
	*	i = monthly interest rate
	*	p = principal,
	*	n = total number of payments.
	*	PRE: math.h is used, denominator isn't zero and all numbers are defined. 
	*/
	
	/* calculation of payment */
	double payment = (i * p) / (1 - pow((1 + i), -n));
	
	return payment;
}

