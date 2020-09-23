#include <iostream>
#include <algorithm>
#include "03-SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
    for(int i=1; i<n; i++){//从1开始因为0已经有序
        //寻找元素arr[i]合适的插入位置
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }else{
                break;
            }
        }
        //另一种写法
        // for(int j=i; j>0 && arr[j] < arr[j-1]; j--){
        //     swap(arr[j], arr[j-1]);
        // }

    }
}

int main(){
    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr, n);

    delete[] arr;
    delete[] arr2;
    return 0;
}