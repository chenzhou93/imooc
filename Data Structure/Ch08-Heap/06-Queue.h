#ifndef QUEUE_H__
#define QUEUE_H__

template <typename T>
class Queue{
    public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void enqueue(T e) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() = 0;
};

#endif