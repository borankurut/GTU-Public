/* BORAN KURUT PROJECT 2.8*/
#include <stdio.h>
int main(void){
	int low_toilet_flush = 2; /* low flush toilet model (2 liters per flush) */
	int existing_toilet_flush = 15; /* existing model (15 liters per flush) */
	int flush_per_day = 14; /* average flush amount per day for 1 toilet */
	int people; /* population */
	int toilet_amount; /* toilet amount */
	int cost; /* cost of the low flush model toilets */
	int water_saved; /* water saved per day by low flushed models */
	
	/* prompts */
	printf("Please enter the population =>");
	scanf("%d", &people);
	toilet_amount = people / 3;
	cost = toilet_amount * 150;
	water_saved = (existing_toilet_flush - low_toilet_flush) * 14 * toilet_amount;
	
	printf("Money spend: %d$\t Water saved: %d liters/day\n", cost, water_saved);
	return (0);
}
