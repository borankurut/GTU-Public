/* BORAN KURUT PROJECT 2.11 */
#include <stdio.h>
int main(void){
	int m, n;
	int side1, side2, hypotenuse;
	
	/* prompt input */
	printf("Please enter m and n =>");
	scanf("%d %d", &m, &n);
	
	side1 = (m * m) - (n * n);
	side2 = 2 * m * n;
	hypotenuse = (m * m) + (n * n);
	
	printf("side1: %d, side2: %d, hypotenuse: %d\n", side1, side2, hypotenuse);
	return(0);
}
