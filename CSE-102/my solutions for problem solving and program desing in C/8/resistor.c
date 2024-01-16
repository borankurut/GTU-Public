#include <stdio.h>
#include <string.h>
#include <math.h>

void get_bands(char bands[][7]);
int is_valid(int band);
int index_of(char band[], char COLOR_CODES[][7], int n);
void cal_dis_result(char bands[][7], char COLOR_CODES[][7]);

int main(void){

    char COLOR_CODES[10][7] = {"black", "brown", "red",
    "orange", "yellow", "green", "blue", "violet", "gray",
    "white"};

    char bands[3][7];

    get_bands(bands);
    cal_dis_result(bands, COLOR_CODES);


    return (0);
}

void get_bands(char bands[][7]){
    printf("Enter the colors of the resistor's three bands, beginning with\n"
            "the band nearest the end. Type the colors in lowercase letters\n"
            "only, NO CAPS.\n");
    
    int i;
    for(i = 0; i < 3; i++){
        printf("Band %d =>", i+1);
        scanf("%s", bands[i]);
    }
}

void cal_dis_result(char bands[][7], char COLOR_CODES[][7]){
    int i,
        ix[3],
        error = 0,
        result;

    for(i = 0; i < 3; i++){
        ix[i] = index_of(bands[i], COLOR_CODES, 10);
        printf(".%d.\n", ix[i]);
        if(is_valid (ix[i]) == 0){
            printf("Invalid color: %s", bands[i]);    
            error = 1;
        }
    }

    if(error == 0){
        result = (ix[0] * 10 + ix[1]) * pow(10, ix[2]);
        printf("Result: %d kilo-ohms", (result+500) / 1000);/* added the half of the denominator */
                                                            /* in terms of rounding.            */
    }
    
}

int index_of(char band[], char COLOR_CODES[][7], int n){
    int i;

    for(i = 0; i < n; i++){
        if(strcmp(COLOR_CODES[i], band) == 0)
            return (i);
    }
    return (-1);
}

int is_valid(int band){
    if(band >= 0 && band <= 9)
        return (1);
    else   
        return (0);
}