#include <iostream>
//#include "01-BSTSet.h"
#include "07-BSTMap.h"

using namespace std;

int main(){
    // BSTSet<int> treeSet;
    // for(int i=5; i > 0; i--){
    //     treeSet.add(i);
    // }

    // cout << treeSet.getSize() << endl;
    // treeSet.remove(4);

    // cout << treeSet.contains(4) << endl;
    // cout << treeSet.contains(3) << endl;

    TreeMap<int, int> map;
    map.add(3,5);
    map.add(4,6);
    map.add(4,7);
    cout << map.getSize() << endl;
    cout << map.get(4) << endl;
    int res = map.remove(4);
    cout << res << endl;
    cout << map.getSize() << endl;
    return 0;
}