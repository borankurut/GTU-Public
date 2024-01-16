/*BORAN KURUT PROJECT 2.6*/
#include <stdio.h>
int main(void){
	float needed_final_score, required_average, current_average; /* scores */
	float final_percentage;
	char grade;
	
	/* prompts, readings */
	printf("Enter desired grade> ");
	scanf("%c", &grade);
	printf("Enter minimum average required> ");
	scanf("%f", &required_average);
	printf("Enter current average in course> ");
	scanf("%f", &current_average);
	printf("Enter how much the final counts as a percentage of the course grade> ");
	scanf("%f", &final_percentage);
	
	needed_final_score = (100 * required_average - (100 - final_percentage) * current_average) / final_percentage; /* equation for the required final score */
	
	printf("\nYou need a score of %.2f on the final to get a %c.", needed_final_score, grade);
	
	return (0);
}
