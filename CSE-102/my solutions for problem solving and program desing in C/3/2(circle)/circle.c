#include <stdio.h>
void draw_circle();
void draw_trapezium();

int main(){
	draw_circle();
	draw_trapezium();
	printf("\n");
	draw_circle();
	draw_trapezium();
	return (0);
}
void draw_circle(){
	printf("     *     \n");
	printf(" *       * \n");
	printf("*         *\n");
	printf(" *       *  \n");
	printf("     *     \n");
}
void draw_trapezium(){
	printf("********   \n");
	printf("*       *   \n");
	printf("*        *  \n");
	printf("*         * \n");
	printf("************\n");	
}

