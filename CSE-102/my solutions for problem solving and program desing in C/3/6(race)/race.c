#include <stdio.h>
void display();
int main(){
	double minute, second; /*	INPUTS	*/
	
	display();
	
	scanf("%lf %lf", &minute, &second);
	
	printf("minutes: %.2f, seconds: %.2f.\n", minute, second);
	
	return (0);
}
void display(void){
	/*
	*	displays instruction to the program user.
	*/
	printf("Please enter the minutes and seconds >");
}
