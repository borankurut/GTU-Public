#include <stdio.h>

#define A 3.592     /*  L^2 * (atm/mol^2)   */
#define B 0.0427    /*  L/mol               */
#define R 0.08206   /*  L * atm/mol         */

double calculate_p( /*  calculates the pressure of the carbondioxide    */
    double volume,  /*  L   */
    double temp,    /*  K   */  
    double n       /*  n mols of gas.  */
);

int main(void){
    double n,       /*  n mols of gas   */
    temp;           /*  K               */

    int initial_vol,    /*  initial volume  */
    final_vol,          /*  final volume    */
    volume_increment;   /*  volume increment*/
    
    printf("Quantity of carbon dioxide (moles)> ");
    scanf("%lf", &n);
    printf("Temperature (kelvin)> ");
    scanf("%lf", &temp);
    printf("Initial volume (milliliters)> ");
    scanf("%d", &initial_vol);
    printf("Final volume (milliliters)> ");
    scanf("%d", &final_vol);
    printf("Volume increment (milliliters)> ");
    scanf("%d", &volume_increment);

    printf("Volume (ml)%5cPressure (atm)\n", ' ');
    int i;
    for(i = initial_vol; i <= final_vol; i += volume_increment){
        printf("%6d%10c%9.4f\n", i, ' ', calculate_p(i/1000.0, temp, n));
    }

    return (0);
}

double calculate_p( /*  calculates the pressure of the carbondioxide    */
    double volume,  /*  L   */
    double temp,    /*  K   */  
    double n       /*  n mols of gas.  */
){
    double pressure;
    double first = (n * R * temp) / (volume - (B * n));
    double second = (A * n * n) / (volume * volume);
    pressure = first - second;
    return pressure;
}