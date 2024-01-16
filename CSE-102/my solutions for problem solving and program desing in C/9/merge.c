#include <stdio.h>

int merge(int arr0[], int arr1[], int result_arr[], int arr0_len, int arr1_len, int result_len);

void merge_recursive(int arr0[], int arr1[], int result_arr[],
                    int arr0_len, int arr1_len, int result_len,
                    int *arr0_ix, int *arr1_ix, int *result_ix);
                    
int is_in(int value, int arr[], int n);

int main(void){
    int arr0[] = {1, 2, 3, 4};
    int arr1[] = {3, 4, 5, 6};
    int result[8];
    int i;

    int result_len = merge(arr0, arr1, result, 4, 4, 8);

    for(i = 0; i < result_len; i++){
        printf("%d\n", result[i]);
    }
    
    return (0);
}

int merge(int arr0[], int arr1[], int result_arr[], int arr0_len, int arr1_len, int result_len){
    int arr0_ix = 0,
        arr1_ix = 0,
        result_ix = 0;
    merge_recursive(arr0, arr1, result_arr, arr0_len, arr1_len, result_len, &arr0_ix, &arr1_ix, &result_ix);
    return (result_ix);
}

int is_in(int value, int arr[], int n){
    int i,
        in = 0;

    for(i = 0; i < n; i++){
        if(arr[i] == value)
            in = 1;
    }

    return(in);
}

void merge_recursive(int arr0[], int arr1[], int result_arr[],
                    int arr0_len, int arr1_len, int result_len,
                    int *arr0_ix, int *arr1_ix, int *result_ix)
{
    if(*arr0_ix < arr0_len){

        if(is_in(arr0[*arr0_ix], result_arr, result_len) == 0){
            result_arr[*result_ix] = arr0[*arr0_ix];
            *result_ix += 1;
        }

        *arr0_ix += 1;
        merge_recursive(arr0, arr1, result_arr, arr0_len, arr1_len, result_len, arr0_ix, arr1_ix, result_ix);
    }
    else if(*arr1_ix < arr1_len){
        
        if( is_in(arr1[*arr1_ix], result_arr, result_len) == 0){
            result_arr[*result_ix] = arr1[*arr1_ix];
            *result_ix += 1;
        }

        *arr1_ix += 1;
        merge_recursive(arr0, arr1, result_arr, arr0_len, arr1_len, result_len, arr0_ix, arr1_ix, result_ix);
    }
}