#include <stdio.h>

double round();
void part1();
void part2();
int power(int a,int b);
void part3();

int main(){
	part1();
	part2();
	part3();
}
void part1(){

	int degree;/*degree of the polynomial.*/
	double coef;/*coefficient of the current value.*/
	double abs_coef;
	printf("Please type the degree of the polynomial and coefficients.\n");
	scanf("%d",&degree);
	
	int pow;/*power of the x.*/
	for(pow=degree; pow>=0; pow--){
		scanf("%lf",&coef);
		
    	if(coef==0)
    		continue;
    		
    	else if(coef<0){
    		abs_coef=coef*-1;
    		printf("-");
    	}
    	else if(coef>0){
    		abs_coef=coef;
    		if(pow!=degree)/*+ won't be included for the first coefficient.*/
    			printf("+");
    	}
    	if((abs_coef!=1 || pow==0)&&coef==(int)coef){   /*when power equals 0 we need to print the coefficient.*/
    		printf("%.0f",abs_coef);
    		}
    	else if((abs_coef!=1 || pow==0))/*there is remaining part.*/
    		printf("%.2f",abs_coef); 
    	/*end of printing coefficients.*/
    	
    	
    	if(pow >=2)
    		printf("x^%d ",pow);
    	else if(pow==1)
    		printf("x ");/*power won't be included.*/
    	/*end of printing powers.(for pow=0, power and x won't be included.)*/
	}
	printf("\n");
}

void part2(){
	int num;
	printf("Please enter a number.\n");
	scanf("%d",&num);
	
	int num_save = num;
	
	int is_armstrong = 0; /*1 if the number is armstrong.*/
	int is_palindrome = 0; /*1 if the number is palindrome.*/
	
	int sum=0;
	int digit;
	int i;
	
	for(i=1000000000; i>=1; i=i/10){
		if(i>num)/*divisor bigger than the number.*/
			continue;
		digit = num/i;/*determining digits.*/
		num -= digit*i;
		sum += digit*digit*digit;/*armstrong formula*/
		
	}
	num = num_save;/*recalling the original value of the number.*/
	
	if(sum==num)/*checking armstrong.*/
		is_armstrong =1;
		
	sum =0;	
	int inverse_digit =0;
	for(i=1000000000; i>=1; i=i/10){
		if(i>num)/*divisor bigger than the number.*/
			continue;
		digit = num/i;/*determining digits.*/
		num -= digit*i;
		sum += digit*power(10,inverse_digit);/*10s exponent but inverse.*/
		inverse_digit++;
	}
	num_save = num;/*recalling the original value of the number.*/
	if(sum==num)/*checking palindrome.*/
		is_palindrome =1;
	
	if(is_palindrome==1&&is_armstrong==1)
		printf("This number is both Palindrome and Armstrong number.\n");
	else if(is_palindrome==1&&is_armstrong ==0)
		printf("This number is only Palindrome number.\n");
	else if(is_palindrome==0&& is_armstrong==1)
		printf("This number is only Armstrong number.\n");
	else if(is_palindrome==0&&is_armstrong==0)
		printf("This number does not satisfy any special cases.\n");
	
}
void part3(){


	int first, second;
	
	printf("Please enter first integer number:");
	scanf("%d",&first);
	printf("\nPlease enter second integer number:");
	scanf("%d",&second);
	
	int num;
	int sum=0;
	for(num = first+1; num< second; num++){/*numbers between first and second.*/
		int counter=0;
		int i =1;
		for(i;i<num;i++){ /*numbers between 0 and num to determine divisor amount.*/
			if(num%i==0)/*i is a divisor of the number.*/
				counter ++;
		}
		if(counter ==1)/*number is prime.*/
			sum+=num;
	}
	printf("\n Sum of prime numbers between %d and %d:%d",first,second,sum);
	
}
int power(int a,int b){ /*returns a^b*/
	int result=1;
	int i;
	for(i=0; i<b; i++)
		result *= a;
	return result;
}
