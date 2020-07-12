#include "09-TraverseBinarySearchTreeNR.h"
#include <iostream>

using namespace std;

int main(){
    BinarySearchTree<int> bst;

    int nums[6] = {5, 3, 6, 8, 4, 2};
    for(int i=0; i<6; i++){
        bst.add(nums[i]);
    }
    //bst.inOrder();
    //bst.print();

    bst.preOrderNR();

    return 0;
}