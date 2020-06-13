#ifndef STACK__H
#define STACK__H
#include "01-GenericDynamicArray.h"

template <typename T>
class MyArray;

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
class MyArrayStack : public MyStack<T>{
    private:
    MyArray<T> myArray;

    public:
    MyArrayStack(int c=10);
    virtual int getSize();
    virtual bool isEmpty();
    virtual void push(T e);
    virtual T pop();
    virtual T peek();
};

template <typename T>
MyArrayStack<T>::MyArrayStack(int c){
    myArray.resize(c);
}

template <typename T>
int MyArrayStack<T>::getSize(){
    return myArray.getSize();
}

template <typename T>
bool MyArrayStack<T>::isEmpty(){
    return myArray.isEmpty();
}

template <typename T>
void MyArrayStack<T>::push(T e){
    myArray.addLast(e);
}

template <typename T>
T MyArrayStack<T>::pop(){
    return myArray.removeLast();
}

template <typename T>
T MyArrayStack<T>::peek(){
    return myArray.getLast();
}

#endif