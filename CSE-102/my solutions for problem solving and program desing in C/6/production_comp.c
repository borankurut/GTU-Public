#include <stdio.h>
#include <math.h>

#define START_YEAR 1990

double annual_revenue(double time);
double predict_year(double revenue);

int main(void){
    double end_year = predict_year(1000000);

    FILE *fp_out = fopen("production_comp_out.txt", "w");
    fprintf(fp_out, "Year\t\t\tRevenue\n\n");
    double f;
    for(f = START_YEAR; f <= end_year; f += 1.0){
        fprintf(fp_out, "%.0f\t\t\t%.3f\n", f, annual_revenue(f));
    }
    fclose(fp_out);
    return (0);
}

double annual_revenue(double year){
    /*      Formula:    R(t) = 471.621 * (1.063)^t     t: current year - start year     */   
    double revenue;
    year -= START_YEAR;
    revenue = 471.621 * pow(1.063, year);
    return revenue;
}

double predict_year(double revenue){
    double year = START_YEAR, calculated_revenue = 0;

    while(calculated_revenue < revenue){
        calculated_revenue = annual_revenue(year);
        year += 1;
    }
    return year;
}