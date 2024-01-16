#include <stdio.h>

int binary_search(int arr[], int first_ix, int last_ix, int target);

int main(void){

    int arr[] = {1, 2, 5, 8, 9, 10, 20, 50};

    printf("%d", binary_search(arr, 0, 8, 10));

    return(0);
}

int binary_search(int arr[], int first_ix, int last_ix, int target){
    printf("binary_search in: first ix:%d, last_ix:%d, target:%d\n", first_ix, last_ix, target);
    int middle_ix,
        result_ix;

    if(target == arr[first_ix])
        result_ix = first_ix;
    else if(target == arr[last_ix])
        result_ix = last_ix;
    
    else{
        middle_ix = (first_ix + last_ix) / 2;
        if(target == arr[middle_ix])
            result_ix = middle_ix;
        else if(target > arr[middle_ix])
            result_ix = binary_search (arr, middle_ix, last_ix, target);
        else /* target < arr[middle_ix] */
            result_ix = binary_search(arr, first_ix, middle_ix, target);
    }
    printf("binary_search out: result ix:%d\n", result_ix);
    return (result_ix);
}