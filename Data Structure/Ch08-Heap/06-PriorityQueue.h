#ifndef PRIORITY_QUEUE_H__
#define PRIORITY_QUEUE_H__

#include "06-Queue.h"
#include "05-ReplaceHeapify.h"

template <typename T>
class PriorityQueue : public Queue<T>{
    private:
    MaxHeap<T> heap;

    public:
    int getSize();
    bool isEmpty();
    void enqueue(T e);
    T dequeue();
    T getFront();
};

template <typename T>
int PriorityQueue<T>::getSize(){
    return heap.size();
}

template <typename T>
bool PriorityQueue<T>::isEmpty(){
    return heap.isEmpty();
}

template <typename T>
void PriorityQueue<T>::enqueue(T e){
    return heap.add(e);
}

template <typename T>
T PriorityQueue<T>::dequeue(){
    return heap.extractMax();
}

template <typename T>
T PriorityQueue<T>::getFront(){
    return heap.findMax();
}

#endif