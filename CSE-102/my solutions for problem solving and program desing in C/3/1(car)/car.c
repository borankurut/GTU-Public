#include <stdio.h>
#include <math.h>
double calculate_payment(double i, double p, double n);
int main(){
	double price, down_payment, annual_interest_rate, total_number_of_payments; /* INPUTS */
	double payment; /* OUTPUT */
	
	double principle;
	double monthly_interest_rate;	
	
	/*prompts*/
	printf("Please enter the purchase price, the down payment,\nthe annual interest rate and the total number of payments>");
	scanf("%lf %lf %lf %lf", &price, &down_payment, &annual_interest_rate, &total_number_of_payments);
	
	/*calculations*/
	principle = price - down_payment;
	monthly_interest_rate = annual_interest_rate / 12;
	
	payment = calculate_payment(monthly_interest_rate, principle, total_number_of_payments);
	printf("\n payment: $%.2f, amount borrowed: $%.2f", payment, principle);
	
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

