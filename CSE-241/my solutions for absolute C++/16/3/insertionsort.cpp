#include <iostream>

using namespace std;

template<class T>
void insertionSort(T arr[], int n);

template<class T>
void printArr(T arr[], int n);

int main(){

    int arr[] = {2, 1, 5, 6, 3, 9, 3};
    double dblarr[] = {1.2, 1.1, 1.5, 1.6, 1.3, 1.9, 1.3};
    printArr(arr, 7);
    printArr(dblarr, 7);

    insertionSort(arr, 7);
    insertionSort(dblarr, 7);

    printArr(arr, 7);
    printArr(dblarr, 7);



    return(0);
}
 
template<class T> 
void insertionSort(T arr[], int n)
{
    int i, 
        j;

    T toBePlaced;

    for (i = 1; i < n; i++)
    {
        toBePlaced = arr[i];
        
        for(j = i - 1; j >= 0 && arr[j] > toBePlaced; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = toBePlaced;
    }
}

template<class T>
void printArr(T arr[], int n){
    int i;
    for(i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}