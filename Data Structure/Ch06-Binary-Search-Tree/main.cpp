#include "04-TraverseBinarySearchTree.h"
#include <iostream>

using namespace std;

int main(){
    BinarySearchTree<int> bst;

    int nums[6] = {5, 3, 6, 8, 4, 2};
    for(int i=0; i<6; i++){
        bst.add(nums[i]);
    }

    bst.preOrder();
    bst.inOrder();
    bst.print();

    return 0;
}