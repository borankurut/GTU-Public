#include <stdio.h>

int bin_search(int arr[], int n, int target);

int main(void){
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    printf("%d", bin_search(arr, 7, 4));

    return (0);
}

/*  
*   takes array, array length, target and binary searches for target in the array.  
*   returns where if finds. 
*/

int bin_search(int arr[], int n, int target){ 
    int bottom = 0, top = n - 1, is_found = 0;
    int middle, ix = -1;

    if(arr[top] == target)
        return top;

    while(is_found == 0 && top > bottom){
        middle = (top + bottom) / 2;

        if(arr[middle] == target){
            is_found = 1;
            ix = middle;
        }
        else if(arr[middle] > target){
            top = middle;
        }
        else
            bottom = middle;
    }
    return ix;
}