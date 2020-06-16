#ifndef QUEUE_H__
#define QUEUE_H__

#include "01-GenericDynamicArray.h"
template <typename T>
class MyArray;

template <typename T>
class Queue{
    public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void enqueue(T e) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() = 0;
};

template <typename T>
class MyArrayQueue : public Queue<T>{
    private:
    MyArray<T> myArray;
    public:
    MyArrayQueue(int c=10);
    virtual int getSize();
    virtual bool isEmpty();
    virtual void enqueue(T e);
    virtual T dequeue();
    virtual T getFront();
};

template <typename T>
MyArrayQueue<T>::MyArrayQueue(int c){
    myArray.resize(c);
}

template <typename T>
int MyArrayQueue<T>::getSize(){
    return myArray.getSize();
}

template <typename T>
bool MyArrayQueue<T>::isEmpty(){
    return myArray.isEmpty();
}

template <typename T>
void MyArrayQueue<T>::enqueue(T e){
    myArray.addLast(e);
}

template <typename T>
T MyArrayQueue<T>::dequeue(){
    return myArray.removeFirst();
}

template <typename T>
T MyArrayQueue<T>::getFront(){
    return myArray.getFirst();
}

#endif