#include <stdio.h>
#include <math.h>
#include <string.h>

#define STR_SIZE 30

typedef struct{
    double  mantissa;
    int     exponent;
}sci_not_t;

/*  Prototypes      */
int scan_sci(sci_not_t *sci_num);
int is_valid_mant(double mantissa);
double to_double(sci_not_t sci_num);
sci_not_t to_sci_not(double number);
void print_sci(sci_not_t sci_num);
sci_not_t sum_sci(sci_not_t sci_num0, sci_not_t sci_num1);
sci_not_t dif_sci(sci_not_t sci_num0, sci_not_t sci_num1);
sci_not_t pro_sci(sci_not_t sci_num0, sci_not_t sci_num1);
sci_not_t quo_sci(sci_not_t sci_num0, sci_not_t sci_num1);

int main(void){
    sci_not_t num0, num1;
    scan_sci(&num0);
    scan_sci(&num1);

    printf("Values entered: ");
    print_sci(num0);
    printf("\n");
    print_sci(num1);

    printf("\nsum: ");
    print_sci(sum_sci(num0, num1));
    printf("\ndif: ");
    print_sci(dif_sci(num0, num1));
    printf("\npro: ");
    print_sci(pro_sci(num0, num1));
    printf("\nquo: ");
    print_sci(quo_sci(num0, num1));

    return (0);
}

/*  so shity.  */
int scan_sci(sci_not_t *sci_num){
    char line[STR_SIZE];
    char mantis_str[STR_SIZE];
    char exp_str[STR_SIZE];

    double mantissa;
    int exponent;
    int status;

    status = scanf("%s", line);

    if(status == 1){
        strcpy(mantis_str, strtok(line, "e"));
        strcpy(exp_str, strtok(NULL, "e"));
        
        sscanf(mantis_str, "%lf", &mantissa);
        sscanf(exp_str, "%d", &exponent);

        if(is_valid_mant(mantissa)){
            sci_num->mantissa = mantissa;
            sci_num->exponent = exponent;
        }
    }

    else if(status != EOF)
        status = 0;

    return (status);
}

int is_valid_mant(double mantissa){
    return (mantissa >= 0.1 && mantissa < 1.0);
}

double to_double(sci_not_t sci_num){
    return(sci_num.mantissa * pow(10, sci_num.exponent));
}

sci_not_t to_sci_not(double number){
    sci_not_t sci_num;
    int exponent = 0;
    double mantissa = number;

    if(number < 0.00001){
        printf("negative error.\n");
        mantissa = 0;
        exponent = 0;
    }
    else{
        while(mantissa > 1.0){
            mantissa /= 10;
            exponent += 1;
        }
        while (mantissa < 0.1)
        {   
            mantissa *= 10;
            exponent -= 1;
        }
    }
    sci_num.mantissa = mantissa;
    sci_num.exponent = exponent;
    return sci_num;
}

void print_sci(sci_not_t sci_num){
    printf("%.5lfe%d", sci_num.mantissa, sci_num.exponent);
}

/*  returns sci_num0 + sci_num1     */
sci_not_t sum_sci(sci_not_t sci_num0, sci_not_t sci_num1){

    double result = to_double(sci_num0) + to_double(sci_num1);
    return(to_sci_not(result));
}

/*  returns sci_num0 - sci_num1     */
sci_not_t dif_sci(sci_not_t sci_num0, sci_not_t sci_num1){

    double result = to_double(sci_num0) - to_double(sci_num1);
    return(to_sci_not(result));
}

/*  returns sci_num0 * sci_num1     */
sci_not_t pro_sci(sci_not_t sci_num0, sci_not_t sci_num1){

    double result = to_double(sci_num0) * to_double(sci_num1);
    return(to_sci_not(result));
}

/*  returns sci_num0 / sci_num1     */
sci_not_t quo_sci(sci_not_t sci_num0, sci_not_t sci_num1){

    double result = to_double(sci_num0) / to_double(sci_num1);
    return(to_sci_not(result));
}