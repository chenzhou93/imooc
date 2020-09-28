#include <iostream>
using namespace std;

template <typename T>
void mergeSortBU(T arr[], int n){
    for(int sz=1; i<=n; sz += sz){
        for(int i=0; i<n; i+= sz+sz){
            __merge(arr, i, i + sz - 1, min(i + sz+sz-1,n-1));
        }
    }
}