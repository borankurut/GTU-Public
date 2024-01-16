#include <stdio.h>
#include "select_sort_lib.h"

int select_sort_lib_min_ix_range(int arr[], int low_ix, int high_ix){
    int minimum_ix = low_ix,
        i;

    for(i = low_ix; i <= high_ix; i++){
        if(arr[i] < arr[minimum_ix])
            minimum_ix = i;
    }

    return minimum_ix;
}

void select_sort(int arr[], int n){
    int i,
        temp,
        min_ix;

    for(i = 0; i < n; i++){
        min_ix = select_sort_lib_min_ix_range(arr, i, n);
        if(i != min_ix){
            temp = arr[i];
            arr[i] = arr[min_ix];
            arr[min_ix] = temp;
        }
    }
}