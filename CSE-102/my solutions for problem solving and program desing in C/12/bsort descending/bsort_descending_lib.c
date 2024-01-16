#include <stdio.h>
#include "bsort_descending.h"

void bubble_sort_swap(int arr[], int ix1, int ix2){
    int temp;

    temp = arr[ix1];
    arr[ix1] = arr[ix2];
    arr[ix2] = temp;
}

void bubbleSortD(int arr[], int n){
    int pass_ix;
    for(pass_ix = 0; pass_ix < n; pass_ix += 1){
        bubble_sort_pass_over_descending(arr, n);
    }
}

void bubble_sort_pass_over_descending(int arr[], int n){
    int ix;
    for(ix = 0; ix < n-1; ix++){
        if(arr[ix] < arr[ix+1])
            bubble_sort_swap(arr, ix, ix+1);
    }
}