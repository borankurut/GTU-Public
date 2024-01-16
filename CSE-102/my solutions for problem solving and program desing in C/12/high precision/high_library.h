/*  high_library header */

/*  
*   high precision type
*
*   attributes:
*       digits, decpt, sign.
*   functions:
*       add_high, subtract_high, multiply_high.
*/

#if !defined HIGH_LIBRARY_HEADER
#define HIGH_LIBRARY_HEADER

typedef struct{
    int digits[20],     /*  20 decimal digits of the number */
        decpt,          /*  position of the decimal point   */
        sign;           /*  sign of the number              */
}high_precision_t;

/*  returns high_num1 + high_num2 in hight_precision_t      */
extern high_precision_t add_high(high_precision_t high_num1, high_precision_t high_num2);

/*  returns high_num1 - high_num2 in hight_precision_t      */
extern high_precision_t subtract_high(high_precision_t high_num1, high_precision_t high_num2);

/*  returns high_num1 * high_num2 in hight_precision_t      */
extern high_precision_t multiply_high(high_precision_t high_num1, high_precision_t high_num2);

/*  returns minimum of 2 integer numbers                    */
extern int high_library_min_of(int num1, int num2);
        
/*  shifts 1 element right given array.                     */
extern void high_library_shift_right(int arr[], int n, int times);

/*  prints the high precision type number                   */
extern void print_high(high_precision_t number);

#endif