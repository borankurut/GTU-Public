#include <stdio.h>
#include <math.h>
double predict_total_case(double day);
void inst();
void disp();
int main(){
	double day; /*	INPUTS	*/
	double total_case; /*	OUTPUTS	*/

	/*	prompt, get data	*/
	inst();
	scanf("%lf", &day);
	/*	calculation	*/
	total_case = predict_total_case(day);
	/*	display	*/
	disp(day, total_case);
	
	inst();
	scanf("%lf", &day);
	total_case = predict_total_case(day);
	disp(day, total_case);
	
	inst();
	scanf("%lf", &day);
	total_case = predict_total_case(day);
	disp(day, total_case);
		
}
double predict_total_case(double day){
	/*
	*	Returns the predicted total case amount using the day to case formula.
	*	Pre: math.h is included.
	*/
	double total_case = (40000.0 / (1 + 39999 * exp(-0.24681))); /*??*/
	
	return total_case;

}
void inst(){
	/*	prompts user.	*/
	printf("Enter day number >>");
}
void disp(double day, double total_case){
	/*	displays the result	*/
	printf("By day %.0f, model predicts %.0f cases total.\n", day, total_case);
}
