#include <stdio.h>
#include "bubble_sort_library.h"
#include <time.h>
#include <stdlib.h>

int main(void){
    int arr[100],
        ix;
    srand(time(NULL));

    for(ix = 0; ix < 100; ix++){
        arr[ix] = rand() % 100;
    }

    for(ix = 0; ix< 100; ix++){
        printf("%d\n", arr[ix]);
    }

    bubbleSort(arr, 100);

    for(ix = 0; ix< 100; ix++){
        printf("%d\n", arr[ix]);
    }

    return(0);
}