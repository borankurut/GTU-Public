int rtn_min(int arr[], int left, int right, int *where){
        int min = arr[left];
        int i;

        *where = left;

        for(i = left; i < right; i++)
                if(arr[i] < min){
                        min = arr[i];
                        *where = i;
                }
        return min;
}

void sort_arr(int arr[], int n){
        int min, temp, where;
        int i;
        for (i = 0; i < n; i++){
                temp = arr[i];
                arr[i] = rtn_min(arr, i, n, &where);
                arr[where] = temp;
        }
}