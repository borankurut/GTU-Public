#include <stdio.h>
#include <math.h>
double sound_speed(double temp);
void instruct();
int main(){
	instruct();
	return(0);
}
double sound_speed(double temp){
	/*
	*	Calculates and returns 
	*	the speed of sound by the temperature(celcius).
	*	math.h is included (sqrt)
	*/
	double speed = 1086.0 * sqrt( (5.0 * temp + 297.0) / 247.0); /*	sound speed(ft/sec)	formula	*/
	return speed;
}
void instruct(){
	/*
	*	Displays instructions to the program user
	*/
	double temp;	/*	Input	temperature(celsius)	*/
	double speed;	/*	Output	sound speed(ft/sec)		*/
	/*	prompt	*/
	printf("Please enter the temperature(celsius) >");
	scanf("%lf", &temp);
	/*	call	*/
	speed = sound_speed(temp);
	
	printf("Speed of sound is %.2fft/sec when the temperature is %.2f celsius degree.\n", speed, temp);	
}
