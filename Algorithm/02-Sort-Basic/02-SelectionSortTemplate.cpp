#include <iostream>
#include <string>
#include "02-Student.h"
#include "03-SortTestHelper.h"

using namespace std;

template <typename T>
void selectionSort(T arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){

    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    float b[4] = {4.4, 3.3, 2.2, 1.1};
    string c[4] = {"A", "B", "C", "D"};

    Student d[4] = {{"D",90}, {"C",100},{"B",95},{"A",95}};
    
    selectionSort(a, 10);
    selectionSort(b, 4);
    selectionSort(d, 4);
    
    for(int i=0; i<10; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    delete[] arr;
    
    return 0;
}