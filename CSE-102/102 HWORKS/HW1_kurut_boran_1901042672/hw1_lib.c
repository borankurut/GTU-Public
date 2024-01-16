/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/

#include <stdio.h>
#include "hw1_lib.h"

/*my functions-------------------------------------------------------*/
double calculate4 (double x,double a0,double a1,double a2, double a3, double a4){//to find the value of the function for given x.
return (a0*x*x*x*x)+(a1*x*x*x)+(a2*x*x)+(a3*x)+(a4);
}


double calculate3 (double x,double a0,double a1,double a2, double a3){//to find the value of the function for given x.
return (a0*x*x*x)+(a1*x*x)+(a2*x)+(a3);
}


int sign_of(double s){//sign of the current value of s.
	int sign;
    if(s<0)
    sign =-1;
else if(s>0)
	sign =1;
else// 0
	sign =0;
	return sign;
}

/*my functions-------------------------------------------------------*/


double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
    float i = xs;
    float result;
    
    for(;i<xe;i+=delta){
    	result+= calculate3(i,a0,a1,a2,a3)*delta;
    }
    
    return result;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
    float i = xs;
    float result;
    
    for(;i<xe;i+=delta){
    	result+= calculate4(i,a0,a1,a2,a3,a4)*delta;
    }
    return result;
}


double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{
	float sens = 0.0001;//sensitivity.
	
	float amount = 1;
	
	double force_find_root(double xs, double xe, double amount){ //squeezes to the point where sign changes.
    	double i = xs;
	   	int sign = sign_of(calculate3(xs,a0,a1,a2,a3));//sign of the result at the beginning
   	
   		for(;i<xe;i+=amount){
   	
   			if (sign_of(calculate3(i,a0,a1,a2,a3))!=sign){//passed the root
   				xe = i;
   				break;
   			}
   			else
   				xs = i;
   		}
   		if(amount>sens)//recalling itself with smaller checking amount until the error becomes smaller than sensitivity.
	   		return force_find_root(xs,xe,amount/10);
	   	else 
	   		return i;
   	}
    
    return force_find_root(xs,xe,amount);
}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{
	float sens = 0.0001;//sensitivity.
	
	float amount = 1;
	
	double force_find_root(double xs, double xe, double amount){//squeezes to the point where sign changes.
    	double i = xs;
	   	int sign = sign_of(calculate4(xs,a0,a1,a2,a3,a4));//sign of the result at the beginning
   	
   		for(;i<xe;i+=amount){
   	
   			if (sign_of(calculate4(i,a0,a1,a2,a3,a4))!=sign){//passed the root
   				xe = i;
   				break;
   			}
   			else
   				xs = i;
   		}
   		if(amount>sens)//recalling itself with smaller checking amount until the error becomes smaller than sensitivity.
	   		return force_find_root(xs,xe,amount/10);
	   	else 
	   		return i;
   	}
    
    return force_find_root(xs,xe,amount);
}
