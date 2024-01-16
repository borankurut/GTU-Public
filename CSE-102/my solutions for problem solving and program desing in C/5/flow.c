#include <stdio.h>
#include <math.h>

#define WIDTH       15
#define DEPTH       10
#define SLOPE       0.0015
#define ROUGHNESS   0.014
#define FLOW        1000.0
#define WITHINSENTINEL  0.1 /*  program continue asking the guess until the computed flow becomes this percent of flow. */

double cal_hydrolic_radius(double depth, double width);
double cal_flow(double roughness, double area, double slope, double radius);
int is_within(double value, double actual, double x);

int main(){
    double guess;
    double half_depth = DEPTH / 2;
    double flow = cal_flow(ROUGHNESS, WIDTH * half_depth, SLOPE, cal_hydrolic_radius(half_depth, WIDTH));
    printf("At a depth of 5.0000 feet, the flow is %.4f cubic feet per second.", flow);
            
    printf("Enter your initial guess for the channel depth\n");
    printf("when the flow is %.4f cubic feet per second\n", FLOW);
    printf("Enter guess>");
    scanf("%lf", &guess);
    flow = cal_flow(ROUGHNESS, WIDTH * guess, SLOPE, cal_hydrolic_radius(guess, WIDTH));
    while(is_within(flow, FLOW, WITHINSENTINEL) == 0){
        printf("depth:%.1f  flow:%.1f  error:%.1f\n", guess, flow, FLOW-flow);
        printf("Enter guess>");
        scanf("%lf", &guess);
        flow = cal_flow(ROUGHNESS, WIDTH * guess, SLOPE, cal_hydrolic_radius(guess, WIDTH));
    }

    
    return (0);
}

double cal_hydrolic_radius(double depth, double width){
    return depth * width/(2.0 * depth + width);
}

double cal_flow(double roughness, double area, double slope, double radius){
    double flow = (1.486 / roughness) * area * pow(radius, 2.0/3.0) * pow(slope, 1.0/2.0);
    return flow;
}
int is_within(double value, double actual, double x){   /*  is value within %x of actual    */
    double error = actual * (x/100);
    return (value <= actual + error && value >= actual - error);
}