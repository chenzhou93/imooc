#include <iostream>
#include <algorithm>
#include "03-SortTestHelper.h"

using namespace std;

/*
    近乎有序的情况下，插入排序处理较快
*/

template<typename T>
void insertionSort(T arr[], int n){
    for(int i=1; i<n; i++){//从1开始因为0已经有序
        //寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; //保存元素e应该插入的位置
        for(j=i; j>0 && arr[j-1] > e; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

int main(){
    int n = 10000;
    int* arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int* arr2 = SortTestHelper::copyIntArray(arr, n);

    delete[] arr;
    delete[] arr2;
    return 0;
}