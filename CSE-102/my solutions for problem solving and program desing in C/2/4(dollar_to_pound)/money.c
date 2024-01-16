/* BORAN KURUT PROJECT 2.4 */
#define DPC 0.65 /* dollar to pound constant (1 USD = 0.65 GBP) */
#include <stdio.h>
int main(void){
	float dollar; /* currency in US dollars */
	float pound; /* currency in British pounds */
	
	printf("Usd dollars =>");
	scanf("%f", &dollar);
	pound = dollar * DPC; /* calculating currency in pound */
	printf("Equals to %.2f pounds.\n", pound);
	return (0);
}
