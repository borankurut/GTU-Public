
/*Boran Kurut HW3 1901042672*/      


#include <stdio.h>
#include <float.h> /*min and maximum float value.*/

void calculate_fibonacci_sequence();
void decide_perfect_harmonic_number();
void perfect_harmonic_read();
void difference_max_min ();
void bmi_calculation ();

int main(){
	printf("Fibonacci Calculator\n\n");
	char input='1'; /* assigning the first value to execute the function. */
	do{
		if (input >= 65 && input <= 122)/* input is a letter. */
		
			printf("Please enter a number, not a letter.\n");
			
		else
		{
			printf("Enter a number: (Enter '*' to exit)\n");
			calculate_fibonacci_sequence();
		}
	}
	while((input = getchar())!= '*');
	
	
	printf("\nPerfect Harmonic Finder\n");
	
	input ='1';
	
	while((input = getchar())!= '*'){
		printf("\nEnter a number: (Enter '*' to exit)\n");
		perfect_harmonic_read();
	}
	
	difference_max_min();
	bmi_calculation();
}


void calculate_fibonacci_sequence(){
	int number;
	int a = 0;
	int b = 0;
	int c = 1;
	
	scanf("%d",&number);
	if(number<0)
		printf("The number you entered is not positive!\n");
	else if(number < 50) /*50 is a limit number.*/
	{
		printf("Fibonacci Result:\n");
		int i;
		for(i = 0; i < number; i++)
		{
			printf("%d ",c);
			a=b;
			b=c;
			c=a+b;
		}
		printf("\n\n");
	}
}

void decide_perfect_harmonic_number(int number){
	
	int harmonic_numerator = number;
	double harmonic_denominator = 0;
	
	int perfect_sum = 0;
	
	printf("Divisors: ");
	int i;
	for(i=1;i<=number;i++)
	{
		if(number%i==0 && i != number){
			printf("%d, ",i);
			perfect_sum += i;
			harmonic_denominator += (1.0/(double)i);
		}
	}
	
	harmonic_denominator += 1.0/(double)number; /*adding the number itself.*/
	printf("%d\n",number);
	
	float harmonic_result = ((double)harmonic_numerator/harmonic_denominator); /*calculating harmonic ratio*/
	
	if(perfect_sum == number)
		printf("%d is a perfect number!\n",number);
	else 
		printf("%d is not a perfect number.\n",number);
	if(harmonic_result == (int)harmonic_result) /* checking if the ratio is integer.*/
		printf("%d is a harmonic number!\n",number);
	else
		printf("%d is not a harmonic number.\n",number);
}

void perfect_harmonic_read()
{	
	int number;
	scanf("%d",&number);
	decide_perfect_harmonic_number(number);
}

void difference_max_min ()
{
	int i;
	double input;
	double min=FLT_MAX;
	double max=FLT_MIN;
	
	printf("Please enter 5 numbers:\n");
	for(i=0;i<5;i++){
		scanf("%lf",&input);
		if (input>max)
			max = input;
		if (input <min)
			min = input;
	}
	printf("Max is: %.1f\n",max);
	printf("Min is: %.1f\n",min);	
	printf("Difference is: %.1f\n",max-min);		
}
void bmi_calculation ()
{
	double weight, height, bmi;
	
	printf("Please enter weight(kg): \n");
	scanf("%lf",&weight);
	printf("Please enter height(m): \n");
	scanf("%lf",&height);
	
	bmi = weight/(height*height);
	printf("your bmi is: %f\nyour category: ",bmi);
	
	if(bmi< 16.0)
		printf("Severely underweight.");
	else if(bmi< 18.5)
		printf("Underweight.");
	else if(bmi< 25.0)
		printf("Normal.");
	else if(bmi < 30.0)
		printf("Owerweight.");
	else
		printf("Obese.");
}
