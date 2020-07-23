#include <iostream>
#include "01-BSTSet.h"

using namespace std;

int main(){
    BSTSet<int> treeSet;
    for(int i=5; i > 0; i--){
        treeSet.add(i);
    }

    cout << treeSet.getSize() << endl;
    treeSet.remove(4);

    cout << treeSet.contains(4) << endl;
    cout << treeSet.contains(3) << endl;
    return 0;
}