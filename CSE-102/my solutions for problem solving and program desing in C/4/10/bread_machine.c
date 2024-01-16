#include <stdio.h>

int main(){
    char typ_of_bread;  /*  type of the bread W for White and S for Sweet   */
    int baking_type;    /*  1 if the baking is manuel.                      */
    instruct();
    printf("Please enter the type of the bread\n>>");
    scanf("%c", &typ_of_bread);
    return (0);
}
void instruct(){
    printf("Operation\t\tWhite Bread\tSweet Bread\nPrimary kneading\t15 mins\t\t20 mins\nPrimary rising\t\t60 mins\t\t60 mins\n");
    printf("Secondary kneading\t18 mins\t\t33 mins\nSecondary rising\t20 mins\t\t30 mins\nLoaf shaping\t\t2 seconds\t2 seconds\n");
    printf("Final rising\t\t75 mins\t\t75 mins\nBaking\t\t\t45 mins\t\t35 mins\nCooling\t\t\t30 mins\t\t30 mins\n");
    printf("(baking time may change by loaf size or manuel baking.)\n");
}
int calc_baking_time(char type, int baking_type){
    int baking_time;
    if(type == W)
        if(baking_type == 0)
            return .....................
}