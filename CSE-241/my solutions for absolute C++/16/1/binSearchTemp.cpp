#include <iostream>

using namespace std;

template<class T>
int binarySearch(T arr[], int left, int right, T target);

int main(){
    int someArr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    double someDbArr[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5};

    cout << binarySearch(someArr, 0, 7, 10) << endl;
    cout << binarySearch(someDbArr, 0, 7, 3.5) << endl;
    cout << binarySearch(someDbArr, 0, 7, 3.4) << endl;


    return(0);
}

template<class T>
int binarySearch(T arr[], int left, int right, T target){
    int mid = (right - left) / 2 + 1 + left;

    cout << "inside(left: " << left << " right: " << right << " target: " << target << endl;

    if(right != left){
        if(target == arr[mid])
            return mid;

        else if(target > arr[mid]){
            return binarySearch(arr, mid + 1, right, target);
        }
        else{
            return binarySearch(arr, left, mid - 1, target);
        }
    }
    else{
        return(-1);
    }
}