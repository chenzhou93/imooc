#ifndef LINKEDLISTSTACK_H__
#define LINKEDLISTSTACK_H__

#include "04-LinkedListQueryUpdate.h"
#include <iostream>
using namespace std;

template <typename T>
class MyStack{
    public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};

template <typename T>
class LinkedListStack : public MyStack<T>{
    private:
    LinkedList<T> linkedList;
    
    public:
    LinkedListStack();
    int getSize();
    bool isEmpty();
    void push(T e);
    T pop();
    T peek();
};

template <typename T>
LinkedListStack<T>::LinkedListStack(){

}

template <typename T>
int LinkedListStack<T>::getSize(){
    return linkedList.getSize();
}

template <typename T>
bool LinkedListStack<T>::isEmpty(){
    return linkedList.isEmpty();
}

template <typename T>
void LinkedListStack<T>::push(T e){
    linkedList.addFirst(e);
}

template <typename T>
T LinkedListStack<T>::pop(){
    return linkedList.removeFirst();
}

template <typename T>
T LinkedListStack<T>::peek(){
    return linkedList.getFirst();
}

#endif