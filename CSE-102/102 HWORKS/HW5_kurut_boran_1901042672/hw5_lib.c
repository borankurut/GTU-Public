/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/

#include <stdio.h>
#include "hw5_lib.h"
#include <math.h>


void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
	/*addition, subtraction, and multiplication.*/
	
	double a=0,b=0,c=0,d=0,e=0,f=0,g=0;/*a= coef of x^6 ... g= coef of x^0*/
	
	switch(op){
	
	case 'a':/*addition*/
		d = *a3 + *b3;/*3*/
		e = *a2 + *b2;/*2*/
		f = *a1 + *b1;/*1*/
		g = *a0 + *b0;/*0*/
		break;
		
	case 's':/*subtraction*/
		d = *a3 - *b3;/*3*/
		e = *a2 - *b2;/*2*/
		f = *a1 - *b1;/*1*/
		g = *a0 - *b0;/*0*/
		break;
		
	case 'm':/*multiplication*/
		a = (*a3) * (*a3); /*6*/
		b = (*a3) * (*b2) + (*b3) * (*a2); /*5*/
		c = (*a3) * (*b1) + (*a2) * (*b2) + (*a1) * (*b3); /*4*/
		d = (*a3) * (*b0) + (*a2) * (*b1) + (*a1) * (*b2) + (*a0) * (*b3); /*3*/
		e = (*a2) * (*b0) + (*a1) * (*b1) + (*a0) * (*b2); /*2*/
		f = (*a1) * (*b0) + (*b0) * (*a1); /*1*/
		g = (*a0) * (*b0); /*0*/
		break;
		
	default:
		printf("operate_polynomials 'op' error.\n");
		break;
		}
	*a3 = a;/*6*/
	*a2 = b;/*5*/
	*a1 = c;/*4*/
	*a0 = d;/*3*/
	*b3 = e;/*2*/
	*b2 = f;/*1*/
	*b1 = g;/*0*/
}


void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
	double d0, d1, d2, d3, euclidian_distance;
	double b0,b1,b2,b3;
	double sum0 = 0;
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;
	double counter = 0;
	
	int i;
	for(i=0; i<N; i++){
		if(i!=0){
			b0=*mean_a0;
			b1=*mean_a1;
			b2=*mean_a2;
			b3=*mean_a3;
		}
		printf("Please enter the %dth vector.\n",i+1);
		scanf("%lf %lf %lf %lf",mean_a0 ,mean_a1 ,mean_a2 ,mean_a3);
		sum0+=*mean_a0;
		sum1+=*mean_a1;
		sum2+=*mean_a2;
		sum3+=*mean_a3;
		counter+=1;
	
		d0 = *mean_a0 - b0;
		d1 = *mean_a1 - b1;
		d2 = *mean_a2 - b2;
		d3 = *mean_a3 - b3;
		distance_between_4d_points (d0, d1, d2, d3, &euclidian_distance);
		
		if(euclidian_distance > *longest_distance)
			*longest_distance = euclidian_distance;
			
		if((*mean_a0 == -1) && (*mean_a1 == -1) && (*mean_a2 == -1) && (*mean_a3 == -1)){
			i=N;
			break;
		}
	}
	*mean_a0 = sum0/counter;
	*mean_a1 = sum1/counter;
	*mean_a2 = sum2/counter;
	*mean_a3 = sum3/counter;
	/*calculating averages.*/
}


void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance)
{
    *euclidian_distance = sqrt(d0*d0 + d1*d1 + d2*d2 + d3*d3);
}


void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
	
	int winner_counter;
	int A_divisor=1;
	int B_divisor=1;
	int C_divisor=1;
	int D_divisor=1;
	int E_divisor=1;
	
	
	
	for(winner_counter = 0; winner_counter < numberOfSeats; winner_counter++){
		if(*partyA==biggest_of(*partyA, *partyB, *partyC, *partyD, *partyE)){
		
			*partyA /= A_divisor;
			A_divisor++;
			continue;
			/*winner is A*/
		}
			
		if(*partyB==biggest_of(*partyA, *partyB, *partyC, *partyD, *partyE)){
		
			*partyB /= B_divisor;
			B_divisor++;
			continue;
			/*winner is B*/
		}
			
		if(*partyC==biggest_of(*partyA, *partyB, *partyC, *partyD, *partyE)){
			
			*partyC /= C_divisor;
			C_divisor++;
			continue;
			/*winner is C*/
		}
			
		if(*partyD==biggest_of(*partyA, *partyB, *partyC, *partyD, *partyE)){
		
			*partyD /= D_divisor;
			D_divisor++;
			continue;
			/*winner is D*/
		}
			
		if(*partyE==biggest_of(*partyA, *partyB, *partyC, *partyD, *partyE)){
			
			*partyE /= E_divisor;
			E_divisor++;
			continue;
			/*winner is E*/
		}
	}
	*partyA= A_divisor - 1;
	*partyB= B_divisor - 1;
	*partyC= C_divisor - 1;
	*partyD= D_divisor - 1;
	*partyE= E_divisor - 1;/*winned seats.*/
}
int biggest_of(int x0, int x1, int x2, int x3, int x4){
	
	int biggest = x0;
	if(x1>biggest)
		biggest = x1;
	if(x2>biggest)
		biggest = x2;
	if(x3>biggest)
		biggest = x3;
	if(x4>biggest)
		biggest = x4;
	
	return biggest;
}


void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)
{
	printf("TO BE IMPLEMENTED\n");
}


void number_encrypt (unsigned char* number)
{
	char b7='-', b6='-', b5='-', b4='-', b3='-', b2='-', b1='-', b0='-';
	get_number_components (*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components (number, b7, b6, b5, b4, b3, b2, b1, b0);
	printf("TO BE IMPLEMENTED\n");
}

void fill_char(int x, char* c){

	if(x%2==0)
		*c = '0';	
	else
		*c = '1';
}

void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0)
{
	int number_int = (int) number;
	
	fill_char(number_int, b0);
	number_int/=2;
	fill_char(number_int, b1);
	number_int/=2;
	fill_char(number_int, b2);
	number_int/=2;
	fill_char(number_int, b3);
	number_int/=2;
	fill_char(number_int, b4);
	number_int/=2;
	fill_char(number_int, b5);
	number_int/=2;
	fill_char(number_int, b6);
	number_int/=2;
	fill_char(number_int, b7);
}

int digit_value(char b, int exp)
{
	int result = 1;
	if(b== '1'){
		int i;
		for(i=0;i<exp; i++)
			result*=2;
		return result;
	}
	else
		return 0;

}

void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0)
{
	char bit0=b0, bit1=b1, bit2=b2, bit3=b3, bit4=b4, bit5=b5, bit6=b6, bit7=b7;/*saving.*/
	int int_number;

		
	b2 = bit7;
	b7 = bit1;
	b6 = bit3;
	b3 = bit6;
	b5 = bit0;
	b0 = bit5;
	b4 = bit1;
	b1 = bit4;/*Change bit-7 with bit-2, bit-6 with bit-3, bit-5 with bit-0, bit 4 with bit-1.*/
	
	bit0=b0, bit1=b1, bit2=b2, bit3=b3, bit4=b4, bit5=b5, bit6=b6, bit7=b7;/*saving*/
	
	b0 = bit2;
	b1 = bit3;
	b2 = bit4;
	b3 = bit5;
	b4 = bit6;
	b5 = bit7;
	b6 = bit0;
	b7 = bit1;/*shitfing.*/
	
	int_number = digit_value(b0, 0) + digit_value(b1, 1) + digit_value(b2, 2) + digit_value(b3, 3) + digit_value(b4, 4) + digit_value(b5, 5) + digit_value(b6, 6) + digit_value(b7, 7);
	
	*number = int_number;
		
}
