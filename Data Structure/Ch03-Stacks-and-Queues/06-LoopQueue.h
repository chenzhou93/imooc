#ifndef LOOPQUEUE_H__
#define LOOPQUEUE_H__


#include <iostream>


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
class LoopQueue : public Queue<T>{
    private:
    T* data;
    T front, tail;
    int size, capacity;

    public:
    LoopQueue(int c = 10);
    ~LoopQueue();
    int getCapacity();
    int getSize();
    bool isEmpty();
    void enqueue(T e);
    T dequeue();
    T getFront();
    void resize(int cap);
};

template <typename T>
LoopQueue<T>::LoopQueue(int c){
    if(c > 0){
        data = new T[c+1];
        capacity = c;
        size = 0;
        front = 0;
        tail = 0;
    }
}

template <typename T>
LoopQueue<T>::~LoopQueue(){
    if(data){
        data = NULL;
        delete[] data;
    }
}

template <typename T>
int LoopQueue<T>::getCapacity(){
    return capacity;
}

template <typename T>
int LoopQueue<T>::getSize(){
    return size;
}

template <typename T>
bool LoopQueue<T>::isEmpty(){
    return size == 0;
}

template <typename T>
void LoopQueue<T>::enqueue(T e){
    if((tail+1)%capacity == front){
        resize(2 * getCapacity());
    }else{
        data[tail] = e;
        tail = (tail + 1)%capacity;
        //cout << "tail: " << tail << endl;
        size++;
    }   
}

template <typename T>
T LoopQueue<T>::dequeue(){
    if(isEmpty()){
        return -1;
    }
    //cout << front << endl;
    T res = data[front];
    front = (front + 1) % capacity;
    size--;
    // if(getSize() == getCapacity()/4 && getCapacity()/2 != 0){
    //     resize(getCapacity()/2);
    // }
    return res;
    
}

template <typename T>
T LoopQueue<T>::getFront(){
    if(isEmpty()){
        return -1;
    }
    return data[front];
}

template <typename T>
void LoopQueue<T>::resize(int cap){
    //cout << "resize..." << cap << endl;
    T* newData = new T[cap+1];
    for(int i=0; i<size; i++){
        newData[i] = data[(i+front)%capacity];
        //cout << "new data " << i << " " <<  newData[i] << endl;
    }
    data = newData;
    front = 0;
    tail = size;
    capacity = cap;
    newData = NULL;
    delete[] newData;
}

#endif