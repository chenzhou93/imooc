#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include <iostream>
using namespace std;

template <typename T>
class LinkedList{
    private:
    struct Node{
        T e;
        Node* next;
        Node(){
            e = 0;
            next = NULL;
        }
        Node(T n, Node* p){
            e = n;
            next = p;
        }
        Node(T n){
            e = n;
            next = NULL;
        }
    };
    
    Node* dummyHead;
    int size;

    public:
    LinkedList();
    ~LinkedList();
    int getSize();
    bool isEmpty();
    void add(int index, T e);
    void addFirst(T e);
    void addLast(T e);
    void print();
};

template <typename T>
LinkedList<T>::LinkedList(){
    dummyHead = NULL;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node* p = dummyHead;
    while(p->next != NULL){
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
}

template <typename T>
int LinkedList<T>::getSize(){
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

template <typename T>
void LinkedList<T>::add(int index, T e){
    if(index < 0 || index > size){
        return;
    }

    Node* prev = dummyHead;
    for(int i=0; i<index; i++){
        prev = prev->next;
    }
    prev = new Node(e, prev->next);
    size++;
    
}

template <typename T>
void LinkedList<T>::addFirst(T e){
    add(0, e);
}

template <typename T>
void LinkedList<T>::addLast(T e){
    add(size, e);
}

template <typename T>
void LinkedList<T>::print(){
    Node* p = dummyHead->next;
    while(p != NULL){
        cout << p->e << endl;
        p = p->next;
    }
}

#endif