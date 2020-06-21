#include <iostream>
using namespace std;

int sum (int arr[], int l, int length){
    if(l == length){
        return 0;
    }
    return arr[l] + sum(arr, l+1, 8);
}

int main(){
    int nums[] = {1,2,3,4,5,6,7,8};
    cout << sum(nums, 0, 8) << endl;
    return 0;
}