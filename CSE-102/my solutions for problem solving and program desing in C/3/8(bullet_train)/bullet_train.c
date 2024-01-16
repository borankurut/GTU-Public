#include <stdio.h>
#define TRANSFORMATION_CONSTANT 0.44704 /* mi/hr to m/s multiplication constant. */
void instruct();
double calculate_stop_time(double v_final, double v_initial, double time);
int main(){
	instruct();
	return (0);
}
void instruct(){
	/*
	*	prompts and gets the data of a train
	*	v_inital(m/s) is the first speed of the train
	*	v_final(m/s) is the final speed of the train
	*	time(s) is the elapsed time between these two speeds.
	*/
	double v_initial, v_final, time; /*	INPUTS */
	double stop_time; /* OUTPUTS */
	printf("Please enter the first speed(mi/hr) >");
	scanf("%lf", &v_initial);
	printf("Please enter the last speed(mi/hr) >");
	scanf("%lf", &v_final);
	printf("Please enter the time(s) mesured >");
	scanf("%lf", &time);
	
	/* transformations */
	v_initial = v_initial * TRANSFORMATION_CONSTANT;
	v_final = v_final * TRANSFORMATION_CONSTANT;
	
	stop_time = calculate_stop_time(v_final, v_initial, time);
	
	printf("\nTrain stopped after %.1f seconds from its initial speed.\n", stop_time);
	
}

double calculate_stop_time(double v_final, double v_initial, double time){
	/* 	calculates the acceleration and 
	*	returns how much time will it take to thing to stop
	*	Pre: velocity(m/s), time(s), acceleration is constant, final speed is less than the initial speed.
	*/
	
	double acceleration = (v_final - v_initial) / time;
	
	double stop_time = -(v_initial / acceleration);
	
	return stop_time;
}
