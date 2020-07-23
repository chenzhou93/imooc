#ifndef BSTSET_H
#define BSTSET_H

#include "01-Set.h"
#include "01-BST.h"

template <typename T>
class BSTSet : public Set<T>{
    private:
    BinarySearchTree<T> bst;

    public:
    BSTSet();
    void add(T e);
    void remove(T e);
    bool contains(T e);
    int getSize();
    bool isEmpty();
};

template <typename T>
BSTSet<T>::BSTSet(){
    
}

template <typename T>
void BSTSet<T>::add(T e){
    bst.add(e);
}

template <typename T>
void BSTSet<T>::remove(T e){
    bst.remove(e);
}

template <typename T>
bool BSTSet<T>::contains(T e){
    return bst.contains(e);
}

template <typename T>
int BSTSet<T>::getSize(){
    return bst.length();
}

template <typename T>
bool BSTSet<T>::isEmpty(){
    return bst.isEmpty();
}

#endif

