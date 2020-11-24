#include <iostream>
using namespace std;

template <typename T>
int __partition2(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int i = l+1, j = r;
    while(1){
        while(i<=r && arr[i] < v) i++;
        while(j>=l+1 && arr[j] > v) j--;
        if(i > j){
            break;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
        swap(arr[l], arr[j]);
        return j;
    }

}

template <typename T>
void quickSort2(T arr[], int n){
    int p = __partition2(arr, l, r);
}

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    int j = l;
    for(int i=l+1; i<=r; i++){
        if(arr[i] < v){
            swap(arr[j+1], arr[i]);
            j++;
        }
    }

    swap(arr[l], arr[j]);
    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r){
    if(l>=r){
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

int main(){
    return 0;
}