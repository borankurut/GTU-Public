/* BORAN KURUT PROJECT 2.13*/

#include <stdio.h>
#define sec 30 /* student number in each section */
int main(void){
	int stu, sections, stu_left; /* students, required number of sections, students leftover */
	
	/* prompt input */
	printf("Please enter the number of students =>");
	scanf("%d", &stu);
	
	sections = stu / sec;
	stu_left = stu % sec;
	
	printf("students:%d, sections:%d, students leftover:%d\n", stu, sections, stu_left);
	return(0);
}
