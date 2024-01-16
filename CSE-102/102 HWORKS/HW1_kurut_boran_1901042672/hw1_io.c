/*
** hw1_io.c:
**
** The source file implementing output functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>
#include "hw1_io.h"


void write_polynomial3(double a0, double a1, double a2, double a3)
{
    double a[4]={a0,a1,a2,a3};
    
    int i;
    int pow;//power of the current term.
    float coef, abs_coef; //coefficient and absolute value of the coefficent.
    for (i=0;i<=3;i++)
    {
    	pow = 3-i;
    	coef = a[i];
    	if(coef==0)
    		continue;
    		
    	else if(coef<0){
    		abs_coef=coef*-1;
    		printf("-");
    	}
    	else if(coef>0){
    		abs_coef=coef;
    		if(i!=0)//+ won't be included for the first coefficient.
    			printf("+");
    	}
    	if(abs_coef!=1 || pow==0){   //when power equals 0 we need to print the coefficient.
    		printf("%.1f",abs_coef);
    	}//end of printing coefficients.
    	
    	
    	if(pow >=2)
    		printf("x^%d",pow);
    	else if(pow==1)
    		printf("x");//power won't be included.
    	//end of printing powers.(for pow=0, power and x won't be included.)
    	
    }
    if(a0==0 && a1==0 && a2==0 && a3==0)// for P(x)=0;
    	printf("0");
    
    printf("\n");
}


void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
    double a[5]={a0,a1,a2,a3,a4};
    
    int i;
    int pow;//power of the current term.
    float coef, abs_coef; //coefficient and absolute value of the coefficent.
    for (i=0;i<=4;i++)
    {
    	pow = 4-i;
    	coef = a[i];
    	
    	if (coef==0)
    		continue;
    	
    	else if(coef<0){
    		abs_coef=coef*-1;
    		printf("-");
    	}
    	else if(coef>0){
    		abs_coef=coef;
    		if(i!=0)//+ won't be included for the first coefficient.
    			printf("+");
    	}
    	if(abs_coef!=1 || pow==0){   //when power equals 0 we need to print the coefficient.
    		printf("%.1f",abs_coef);
    	}//end of printing coefficients.
    	
    	
    	if(pow >=2)
    		printf("x^%d",pow);
    	else if(pow==1)
    		printf("x");//power won't be included.
    	//end of printing powers.(for pow=0, power and x won't be included.)
    }
 	if(a0==0 && a1==0 && a2==0 && a3==0 && a4==0) // for P(x)=0;
    	printf("0");
    
    printf("\n");
}
