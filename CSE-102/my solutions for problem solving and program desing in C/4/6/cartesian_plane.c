#include <stdio.h>
void print_where(double x, double y);
int main(){
    double x, y;
    printf("Please enter x and y\n>");
    scanf("%lf %lf", &x, &y);
    print_where(x, y);
    return (0);
}
void print_where(double x, double y){
    /*
    *   prints the location of the point.
    */
    if(x < 0.0){
        if(y < 0.0){
            printf("(%.1f, %.1f) is in quadrant III\n", x, y);
            return;
        }else if(y == 0.0){
            printf("(%.1f, %.1f) is on the x-axis\n", x, y);
            return;
        }else{
            printf("(%.1f, %.1f) is in quadrant II\n", x, y);
            return;
        }
    }

    else if(x == 0.0){
        if(y < 0.0){
            printf("(%.1f, %.1f) is on the x-axis\n", x, y);
            return;
        }else if(y == 0.0){
            printf("(%.1f, %.1f) is on the origin\n", x, y);
            return;
        }else{
            printf("(%.1f, %.1f) is on the y-axis\n", x, y);
            return;
        }

    }

    else{
        if(y < 0.0){
            printf("(%.1f, %.1f) is in quadrant IV\n", x, y);
            return;
        }else if(y == 0.0){
            printf("(%.1f, %.1f) is on the x-axis\n", x, y);
            return;
        }else{
            printf("(%.1f, %.1f) is in quadrant I\n", x, y);
            return;
        }
    }
}
