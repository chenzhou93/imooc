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
    
    Node* head;
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
    head = NULL;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node* p = head;
    while(p != NULL){
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
    if(index == 0){
        addFirst(e);
    }else{
        Node* prev;
        for(int i=0; i<index-1; i++){
            prev = prev->next;
        }
        prev = new Node(e,prev->next);
        size++;
    }
}

template <typename T>
void LinkedList<T>::addFirst(T e){
    head = new Node(e, head);
    size++;
}

template <typename T>
void LinkedList<T>::addLast(T e){
    add(size, e);
}

template <typename T>
void LinkedList<T>::print(){
    Node* p = head;
    while(p != NULL){
        cout << p->e << endl;
        p = p->next;
    }
}

#endif