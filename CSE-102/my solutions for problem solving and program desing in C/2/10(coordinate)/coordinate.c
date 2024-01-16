/* BORAN KURUT PROJECT 2.10 */
#include <stdio.h>
int main(void){
	double x1, y1, x2, y2, xmid, ymid; /* x's and y's */
	double slope, preslope; /* slope of the given 2 point and the slope of the prependicular bisector */
	double pre_c, yint; /* prependicular bisector's c value and y intercept of it */
	
	/* prompt and input */
	printf("Please type the first x- and y- =>");
	scanf("%lf %lf", &x1, &y1);
	printf("Please type the second x- and y- =>");
	scanf("%lf %lf", &x2, &y2);
	
	
	slope = (y2 - y1) / (x2 - x1);
	xmid = (x1 + x2) / 2;
	ymid = (y1 + y2) / 2;
	preslope = -(1/slope);
	pre_c = ymid - preslope * xmid;
	yint = pre_c;
	
	printf("x1:%.1f, y1:%.1f \nx2:%.1f, y2:%.1f\n", x1, y1, x2, y2);/* feedback */
	printf("Slope:%f\n", slope);
	printf("Mid point: (%f, %f)\n", xmid, ymid);
	printf("Slope of the prependicular bisector:%f\n", preslope);
	printf("Prependicular bisector: y = %.1fx + %.1f\n", preslope, pre_c);
	
	/* infinity slope point pairs will cause this program to fail. */
	
	
	return (0);
}
