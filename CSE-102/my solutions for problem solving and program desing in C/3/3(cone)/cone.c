#include <stdio.h>
#include <math.h>
#define PI 3.14159

double surface_area_of_cone(double r, double h);

int main(){

	double r,h;			 /*		INPUTS: the radius of the cone the slant of the cone.	*/
	double surface_area; /*		Output: surface area of the cone						*/
	
	/*	Prompts	*/
	printf("Please enter r and h >");
	scanf("%lf %lf", &r, &h);
	
	surface_area = surface_area_of_cone(r, h);
	/*	Display	*/
	printf("\nSurface area is: %f\n",surface_area);
	
	return (0);
}
double surface_area_of_cone(double r, double h){
	/*
	*	calculates the surface area of a right circular cone.
	*	r is radius of the cone,
	*	h is the slant of the cone.
	*
	*	PRE: PI is constant and approx of pi number.
	*		 math.h is included.
	*/
	double area = PI * r * (r + sqrt(h * h + r * r));
	
	return area;
}

