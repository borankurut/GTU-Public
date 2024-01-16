/* BORAN KURUT PROJECT 2.7 */
#include <stdio.h>
#define EOB 5.8 /* energy of 1 barrel (million BTU)*/
#define G_IN_B 42 /* the gallon amount in 1 barrel */
int main(void){
	double gallon;/* gallon amount */
	double barrel, efficiency, energy, heat; /* barrel amount, efficiency while converting energy to heat, exposed energy by barrels, heat delivered to house */
	
	
	printf(" Please enter the gallon amount => "); /* prompt */
	scanf("%lf", &gallon);
	printf(" Please enter the %% efficiency => ");
	scanf("%lf", &efficiency);
	
	barrel = gallon / G_IN_B;
	energy = (EOB * 1000000) * barrel;
	heat = energy * (efficiency / 100);
	
	printf("\ngallon amount: %.0f\tbarrel amount: %.2f\nefficiency: %%%.0f \tenergy exposed by barrels: %.0fBTU\nheat delivered to house: %.0fBTU\n",
		   gallon, barrel, efficiency, energy, heat);
	return (0);
}
