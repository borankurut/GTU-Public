/* BORAN KURUT PROJECT 2.9 */
#include <stdio.h>
int main(void){
	int yard_length, yard_width, yard_area, /* feet, feet^2 */
		house_length, house_width, house_area, /* feet, feet^2 */
		grass_area; /* feet^2 */
	double time; /* second */
	
	/* prompt, read */
	printf("Please enter the length of the yard =>");
	scanf("%d", &yard_length);
	printf("Please enter the width of the yard =>");
	scanf("%d", &yard_width);
	printf("Please enter the length of the house =>");
	scanf("%d", &house_length);
	printf("Please enter the width of the house =>");
	scanf("%d", &house_width);
	
	yard_area = yard_width * yard_length; /* calculating yard area */
	house_area = house_width * house_length; /* calculating house area */
	
	grass_area = yard_area - house_area; /* calculating grass area */
	
	time = grass_area / 2.0; /* calculating time */
	
	printf("Yard area: %d feet\nHouse area: %d feet\nGrass area: %d feet\nTime required: %.0f seconds\n",
		   yard_area, house_area, grass_area, time);
	return (0);
}
