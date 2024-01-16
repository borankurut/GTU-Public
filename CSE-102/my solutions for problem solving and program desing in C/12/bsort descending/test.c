#include <stdio.h>
#include "bsort_descending.h"
#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL));

    int arr[100],
        i;
    for(i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }

    for(i = 0; i < 100; i++){
        printf("%d\n", arr[i]);
    }

    bubbleSortD(arr, 100);

    for(i = 0; i < 100; i++){
        printf("%d\n", arr[i]);
    }

    return (0);
}