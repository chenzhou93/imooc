#ifndef MyLinkedList_H__
#define MyLinkedList_H__

#include <iostream>
using namespace std;

template <typename T>
class MyLinkedList{
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
    MyLinkedList();
    ~MyLinkedList();
    int getSize();
    bool isEmpty();
    void add(int index, T e);
    void addFirst(T e);
    void addLast(T e);
    void print();

    T get(int index);
    T getFirst();
    T getLast();
    void set(int index, T e);
    bool contains(T e);
};

template <typename T>
MyLinkedList<T>::MyLinkedList(){
    dummyHead = new Node(0,NULL);
    size = 0;
}

template <typename T>
MyLinkedList<T>::~MyLinkedList(){
    Node* p = dummyHead;
    while(p->next != NULL){
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
}

template <typename T>
int MyLinkedList<T>::getSize(){
    return size;
}

template <typename T>
bool MyLinkedList<T>::isEmpty(){
    return size == 0;
}

template <typename T>
void MyLinkedList<T>::add(int index, T e){
    if(index < 0 || index > size){
        return;
    }

    Node* prev = dummyHead;
    for(int i=0; i<index; i++){
        prev = prev->next;
    }
    prev->next = new Node(e, prev->next);
    size++;
}

template <typename T>
void MyLinkedList<T>::addFirst(T e){
    add(0, e);
}

template <typename T>
void MyLinkedList<T>::addLast(T e){
    add(size, e);
}

template <typename T>
void MyLinkedList<T>::print(){
    Node* p = dummyHead->next;
    while(p != NULL){
        cout << p->e << endl;
        p = p->next;
    }
}

template <typename T>
T MyLinkedList<T>::get(int index){
    if(index < 0 || index >= size){
        return -1;
    }
    Node* cur = dummyHead->next;
    for(int i=0; i<index; i++){
        cur = cur->next;
    }
    return cur->e;
}

template <typename T>
T MyLinkedList<T>::getFirst(){
    return get(0);
}

template <typename T>
T MyLinkedList<T>::getLast(){
    return get(size-1);
}

template <typename T>
void MyLinkedList<T>::set(int index, T e){
    if(index < 0 || index >= size){
        return;
    }
    Node* cur = dummyHead->next;
    for(int i=0; i<index; i++){
        cur = cur->next;
    }
    cur->e = e;
}

template <typename T>
bool MyLinkedList<T>::contains(T e){
    Node* cur = dummyHead->next;
    while(cur != NULL){
        if(cur->e == e){
            return true;
        }
        cur = cur->next;
    }
    return false;
}

#endif