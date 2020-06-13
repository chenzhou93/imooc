#include <iostream>
#include "01-Stack.h"
#include "06-LoopQueue.h"
using namespace std;


int main(){
    // MyArrayStack<int> stack(10);

    // for(int i=0; i<10; i++){
    //     stack.push(i);
    // }

    // for(int i=0; i<10; i++){
    //     cout << stack.pop() << endl;
    // }

    LoopQueue<int> loopQueue(10);

    for(int i=0; i<12; i++){
        loopQueue.enqueue(i);
    }
    cout << "size: " << loopQueue.getSize() << endl;
    cout << "capacity: " << loopQueue.getCapacity() << endl;

    for(int i=0; i<11; i++){
        cout << loopQueue.dequeue() << endl;
    }

    return 0;
}