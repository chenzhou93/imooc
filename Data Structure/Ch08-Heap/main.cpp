#include "02-MaxHeap.h"
#include <iostream>
using namespace std;

int main(){
    MaxHeap<int> heap;
    for(int i=0; i<10; i++){
        heap.add(i);
    }

    cout << heap.findMax() << endl;
    cout << heap.extractMax() << endl;
    cout << heap.findMax() << endl;
    
    return 0;
}