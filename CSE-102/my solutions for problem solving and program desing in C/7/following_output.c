#include <stdio.h>

int main(void){

    int arr[5];
    int i, j;

    for(i = 0; i < 5; i++){
        arr[i] = i + 6;
        printf("\t%d", i + 6);
    }
    printf("\n\n\n");
    for(i = 0; i < 5; i++){
        printf("%d\t", arr[i]);
        for(j = 0; j < 5; j++)
            printf("%d\t", arr[i] * arr[j]);
        printf("\n\n\n");
    }

    return (0);
}