/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/


#include <stdio.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{
	double a0,a1,a2,a3,b0,b1,b2,b3;
	
	char op;
	
	printf("Please type the first polynomial - (3,a),(2,b),(1,c),(0,d)\n");
	scanf("(3,%lf),(2,%lf),(1,%lf),(0,%lf)",&a0,&a1,&a2,&a3);
	printf("a0:%f, a1:%f, a2:%f, a3:%f\n",a0,a1,a2,a3);
	getchar();
	
	printf("Please type the second polynomial - (3,a),(2,b),(1,c),(0,d)\n");
	scanf("(3,%lf),(2,%lf),(1,%lf),(0,%lf)",&b0,&b1,&b2,&b3);
	printf("a0:%f, a1:%f, a2:%f, a3:%f\n",b0,b1,b2,b3);
	getchar();
	
	printf("Please enter 'a' for addition, 's' for subtraction, 'm' for multiplication\n ");
	scanf("%c",&op);
	
	operate_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, &b0, op);
	printf("result: (%f)*x^6 + (%f)*x^5 + (%f)*x^4 + (%f)*x^3 + (%f)*x^2 + (%f)*x^1 + (%f)*x^0\n",a3,a2,a1,a0,b3,b2,b1);
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=0, partyB=0, partyC=0, partyD=0, partyE=0, numberOfSeats=10;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0, x3=0.0, y3=0.0;
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	unsigned char number=0;
	number_encrypt (&number);
	printf("Encrypted number: %d\n\n\n", number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt ();
	return (0);
} /* end main */
