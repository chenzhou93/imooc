#ifndef MAXHEAP_H__
#define MAXHEAP_H__
#include "02-Array.h"
#include <iostream>

template <typename T>
class MaxHeap{
    private:
    MyArray<T>* data;
    int parent(int index);
    int leftChild(int index);
    int rightChild(int index);
    void siftUp(int k);
    void siftDown(int k);

    public:
    MaxHeap();
    MaxHeap(T arr[], int n);
    MaxHeap(int capacity);
    ~MaxHeap();
    int size();
    bool isEmpty();
    void add(T e);
    T findMax();
    T extractMax();
    T replace(T e);
};

template <typename T>
MaxHeap<T>::MaxHeap(){
    data = new MyArray<T>();
}

template <typename T>
MaxHeap<T>::MaxHeap(int capacity){
    data = new MyArray<T>(capacity);
}

template <typename T>
MaxHeap<T>::~MaxHeap(){
    delete data;
}

template <typename T>
int MaxHeap<T>::size(){
    return data->getSize();
}

template <typename T>
bool MaxHeap<T>::isEmpty(){
    return data->isEmpty();
}

template <typename T>
int MaxHeap<T>::parent(int index){
    if(index == 0){
        return 0;
    }
    return (index-1)/2;
}

template <typename T>
int MaxHeap<T>::leftChild(int index){
    return index * 2 + 1;
}

template <typename T>
int MaxHeap<T>::rightChild(int index){
    return index * 2 + 2;
}

template <typename T>
void MaxHeap<T>::siftUp(int k){
    while(k>0 && data->get(k) > data->get(parent(k))){
        data->swap(k, parent(k));
        k = parent(k);
    }
}

template <typename T>
void MaxHeap<T>::add(T e){
    data->addLast(e);
    siftUp(data->getSize() - 1);
}

template <typename T>
T MaxHeap<T>::findMax(){
    if(data->getSize() == 0){
        return -1;
    }
    return data->get(0);
}

template <typename T>
T MaxHeap<T>::extractMax(){
    T res = findMax();
    data->swap(0, data->getSize()-1);
    data->removeLast();
    siftDown(0);
    return res;
}

template <typename T>
void MaxHeap<T>::siftDown(int k){
    while(leftChild(k) < data->getSize()){
        int j = leftChild(k);
        if(j+1<data->getSize() && data->get(j+1) > data->get(j)){
            j = rightChild(k);
        }

        if(data->get(k) >= data->get(j)){
            break;
        }

        data->swap(k, j);
        k = j;
    }
}

template <typename T>
T MaxHeap<T>::replace(T e){
    T ret = findMax();
    data->set(0, e);
    siftDown(0);
    return ret;
}

template <typename T>
MaxHeap<T>::MaxHeap(T arr[], int n){
    data = new MyArray<T>(arr, n);
    for(int i=parent(data->size-1); i>=0; i--){
        siftDown(i);
    }
}
#endif