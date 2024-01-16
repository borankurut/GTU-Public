#include <stdio.h>

/*  LONGEST WAVELENGTHS */
#define GAMMA_RAY       3E-11
#define X_RAY           3E-9
#define ULTRA_VIOLET    4E-7
#define VISIBLE         7E-7
#define INFRARED        1.4E-5
#define MICROWAVE       1.0E-1
/*  radio wave is longer than 1.0E-1  */

#define SENTINEL 0

void print_category(double wavelength);

int main(void){
    double wavelength;

    printf("Enter the wavelength(enter 0 to terminate.)> ");
    scanf("%lf", &wavelength);
    while(wavelength != 0){
        printf("%e :", wavelength);
        print_category(wavelength);
        printf("Enter the wavelength(enter 0 to terminate.)> ");
        scanf("%lf", &wavelength);
    }

    return (0);
}
void print_category(double wavelength){
    if(wavelength <= GAMMA_RAY)
        printf("Gamma ray.\n");
    else if(wavelength <= X_RAY)
        printf("X-ray.\n");
    else if(wavelength <= ULTRA_VIOLET)
        printf("Ultra violet.\n");
    else if(wavelength <= VISIBLE)
        printf("Visible.\n");
    else if(wavelength <= INFRARED)
        printf("Infrared.\n");
    else if(wavelength <= MICROWAVE)
        printf("Microwave.\n");
    else
        printf("Radio wave.\n");
}