#include <stdio.h>
#include <math.h>
#define PI 3.14159
double calculate_factorial_of(double n);
int main(){
	int n; /*	Input: number n		*/
	
	/*	Prompts	*/
	printf("Enter the value of n >");
	scanf("%d", &n);
	
	printf("%d! equals approximately %.1f", n, calculate_factorial_of(n));
	
	return (0);
}
double calculate_factorial_of(double n){
	/*	
	*	calculates the factorial of n approximately using Gosper's formula.
	*	
	*	Pre: math.h is included.
	*		 PI is defined constant representing an approximation of number pi.
	*/	
	double result = pow(n, n) * pow(exp(1), -n) * sqrt((2*n + 1/3) * PI);
	return result;
}
