#include <stdio.h>

void select_sort(int arr[], int n);

int main(void){
    int i;
    int arr[] = {5, 2, 3, 1, 0, 4, 1};
    select_sort(arr, 7);

    for(i = 0; i < 7; i++){
        printf("%d\n", arr[i]);
    }

    return (0);
}

void select_sort(int arr[], int n){
    int cur_ix = 0,
        max_ix = 0,
        temp,
        i;

    for(i = 1; i < n; i++){
        if(arr[i] > arr[max_ix])
            max_ix = i;
    }
    if(max_ix != cur_ix){
        temp = arr[cur_ix];
        arr[cur_ix] = arr[max_ix];
        arr[max_ix] = temp;
    }

    if(n > 1)
        select_sort(&arr[1], n - 1);
}