#include <stdio.h>

/*  Prototypes  */
int get_problem();

void get2_pt();

void get_pt_slope();

void slope_intcpt_from2_pt();

double intcpt_from_pt_slope();

void display2_pt();

void display_pt_slope();

void display_slope_intcpt();

void display_menu();

int digit_number_of();

int biggest();

char ask_another();

int main(void){
    double x1, x2, y1, y2, slope, b;    /*  points, slope and y-intercept of the equation.  */
    char dec;                           /*  decision to continue of the user.               */
    do{

        int choice = get_problem();

        switch (choice)
        {
        case 1:
            get2_pt(&x1, &y1, &x2, &y2);
            slope_intcpt_from2_pt(x1, y1, x2, y2, &slope, &b);
            display2_pt(x1, x2, y1, y2);
            display_slope_intcpt(slope, b);
            dec = ask_another();
            break;
        case 2:
            get_pt_slope(&slope, &x1, &y1);
            display_pt_slope(x1, y1, slope);
            b = y1 - slope * x1;
            display_slope_intcpt(slope, b);
            dec = ask_another();
            break;
        }
    }while(dec == 'y' || dec =='Y');
    
    return (0);
}

/*
*   Displays the user menu, then inputs and returns as the function
*   value the problem number selected.
*/
int get_problem(){
    
    int input, wrong_input;

    do{
        wrong_input = 0;

        display_menu();
        scanf("%d", &input);

        if(input < 1 || input > 2){
            wrong_input = 1;
            printf("\nPlease read the instructions carefully!\n\n");
        }

    }while(wrong_input);

    return (input);
}

/*
*   Prompts the user for the x-y coordinates of both points, inputs the
*   four coordinates, and returns them to the calling function through output
*   parameters.
*/
void get2_pt(double *x1, double *y1, double *x2, double *y2){
    printf("Enter the x-y coordinates of the first point separated by a space\n=> ");
    scanf("%lf %lf", x1, y1);
    printf("Enter the x-y coordinates of the second point separated by a space\n=> ");
    scanf("%lf %lf", x2, y2);
}

/*
*   Prompts the user for the slope and x-y coordinates of the
*   point, inputs the three values, and returns them to the calling function
*   through output parameters.
*/
void get_pt_slope(double *slope, double *x, double *y){
    printf("Enter the slope\n=> ");
    scanf("%lf", slope);
    printf("Enter the x-y coordinates of the point separated by a space\n=> ");
    scanf("%lf %lf", x, y);
}

/*
*   Takes four input parameters, the x-y coordinates
*   of two points, and returns through output parameters the slope (m) and
*   y-intercept (b).
*/
void slope_intcpt_from2_pt(double x1, double y1, double x2,
                           double y2, double *slope, double *b)
{
    *slope = (y2 - y1) / (x2 - x1);
    *b = y1 - *slope * x1;
}

/*
*   Takes three input parameters, the x-y coordinates of
*   one point and the slope, and returns as the function value the y-intercept.
*/
double intcpt_from_pt_slope(double x1, double y1, double slope){
    double b = y1 - slope * x1;
    return (b);
}

/*
*   Takes four input parameters, the x-y coordinates of two
*   points, and displays the two-point line equation with a heading.
*/
void display2_pt(double x1, double x2, double y1, double y2){
    int max_digit, hyphen_number;

    max_digit = biggest(digit_number_of(x1), digit_number_of(x2));
    max_digit = biggest(max_digit, digit_number_of(y1));
    max_digit = biggest(max_digit, digit_number_of(y2));
    hyphen_number = 2 * max_digit + 5;

    printf("Two-point form:\n");
    printf("%.2f - %.2f\n", y2, y1);
    int i;
    for(i = 0; i < hyphen_number; i++){
        printf("-");
    }
    printf("\n%.2f - %.2f\n\n", x2, x1);
}

/*
*   Takes three input parameters, the x-y coordinates of one
*   point and the slope, and displays the point-slope line equation with a heading.
*/
void display_pt_slope(double x1, double y1, double slope){
    printf("Point-slope form:\n");
    printf("y - (%.2f) = %.2f(x - (%.2f))\n", y1, slope, x1);
}

/*
*   Takes two input parameters, the slope and y intercept,
*   and displays the slope-intercept line equation with a heading.
*/
void display_slope_intcpt(double slope, double b){

    printf("Slope-intercept form:\n");
    if (b > 0)
        printf("y = %.2fx +%.2f\n", slope, b);
    else
        printf("y = %.2fx %.2f\n", slope, b);
}

/*  Displays the menu.  */
void display_menu(){
    printf("Select the form that you would like to convert to slope-intercept\nform:\n"
            "1) Two-point form (you know two points on the line)\n"
            "2) Point-slope form (you know the line's slope and one point)\n=>");
}

/*
*   Returns the biggest among 2 numbers.
*/
int biggest(int num1, int num2){
    if(num1 > num2)
        return num1;
    else
        return num2;
}

/*  Returns the digit number of x.  */
int digit_number_of(double x){
    int digit = 0;
    do{
        x /= 10;
        digit += 1;
    }while(x > 0.01 || x < -0.01);   /*  x != 0 for a double number.  */

    return (digit);
}

/*
*   Returns the decision to continue of the user.
*/
char ask_another(){
    char dec = 'y';
    char discard;

    do{
        scanf("%c", &discard);
    }while (discard != '\n');
    
    do{
        printf("\nDo another conversion (Y or N)\n=>");
        scanf("%c", &dec);
    }while(dec != 'y' && dec != 'n' && dec != 'Y' && dec != 'N');

    return (dec);
}