#include "06-PriorityQueue.h"
#include <iostream>
using namespace std;

int main(){
    // MaxHeap<int> heap;
    // for(int i=0; i<10; i++){
    //     heap.add(i);
    // }

    // cout << heap.findMax() << endl;
    // cout << heap.extractMax() << endl;
    // cout << heap.findMax() << endl;

    PriorityQueue<int> pq;
    for(int i=0; i<10; i++){
        pq.enqueue(i);
    }

    cout << pq.getFront() << endl;

    for(int i=0; i<4; i++){
        cout << pq.dequeue() << endl;
    }
    
    return 0;
}