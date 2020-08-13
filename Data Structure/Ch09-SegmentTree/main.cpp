#include <iostream>
#include "01-SegmentTree.h"
using namespace std;

int main(){
    int arr[] = {1,3,5,7,9,11,13,15};
    SegmentTree<int> segTree(arr, 8);
    cout << segTree.getSize() << endl;
    segTree.print();
    
    return 0;
}