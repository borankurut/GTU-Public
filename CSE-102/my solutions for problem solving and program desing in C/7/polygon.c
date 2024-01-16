#include <stdio.h>
#include <stdlib.h>

#define IN_DATA     "polygon_in_data.txt"
#define OUT_DATA    "polygon_out_data.txt"
#define MAX_CORNER  20

/*  Prototypes  */
int get_corners(FILE *fp_in, double x[], double y[], int size);
void output_corners(FILE *fp_out, double x[], double y[], int num_corner);
double polygon_area(double x[], double y[], int num_corner);

int main(void){
    FILE *fp_in = fopen(IN_DATA, "r");
    FILE *fp_out = fopen(OUT_DATA, "w");
    double x[MAX_CORNER], y[MAX_CORNER];

    int num_corner = get_corners(fp_in, x, y, MAX_CORNER);
    output_corners(fp_out, x, y, num_corner);
    printf("%.2f", polygon_area(x, y, num_corner));

    fclose(fp_in);
    fclose(fp_out);
    return (0);
}

int get_corners(FILE *fp_in,    /*  input data pointer      */
                double x[],     /*  x-coordinate values     */
                double y[],     /*  y-coordinate values     */
                int size)       /*  size of arrays          */
{
    int i, num_corner, status;
    for(i = 0; i < size; i++){
        status = fscanf(fp_in, "%lf%lf", &x[i], &y[i]);
        if(status != 2)
            break;
    }
    if(status == 2)
        num_corner = i + 1;
    else 
        num_corner = i;
    return (num_corner);
}

void output_corners(FILE *fp_out,           /*  output data pointer */
                    double x[],             /*  x-coordinate values */
                    double y[],             /*  y-coordinate values */
                    int num_corner)         /*  number of corners   */
{
    int i;
    fprintf(fp_out, "x\t\ty\n");
    for(i = 0; i < num_corner; i++){
        fprintf(fp_out, "%.1f\t\t%.1f\n", x[i], y[i]);
    }
}

double polygon_area(double x[],         /*  x-coordinate values */
                    double y[],         /*  y-coordinate values */
                    int num_corner)     /*  number of corners   */
{
    int i;
    double result = 0;
    for(i = 0; i < num_corner - 1; i++){
        result += (x[i+1] + x[i]) * (y[i + 1] - y[i]);
    }
    result = abs(result);
    result /= 2.0;
    return (result);
}