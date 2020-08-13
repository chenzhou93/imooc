#ifndef SEGMENT_TREE_H__
#define SEGMENT_TREE_H__

#include <iostream>
using namespace std;

template <typename T>
class Merger{
    public:
    virtual T merge(T a, T b) = 0;
};

template <typename T>
class SegmentTree : public Merger<T>{
    private:
    T* data;
    T* tree;
    int size;
    T merge(T a, T b){
        return a + b;
    }
    
    int leftChild(int index){
        return 2 * index + 1;
    }
    int rightChild(int index){
        return 2 * index + 2;
    }
    void buildSegmentTree(int treeIndex, int l, int r);

    public:
    SegmentTree(T* arr, int n);
    ~SegmentTree();
    int getSize();
    T get(int index);
    void print();
};

template<typename T>
SegmentTree<T>::SegmentTree(T* arr, int n){
    data = new T[n];
    for(int i=0; i<n; i++){
        data[i] = arr[i];
    }
    size = n;

    tree = new T[n*4];
    buildSegmentTree(0, 0, size-1);
}

template<typename T>
SegmentTree<T>::~SegmentTree(){
    if(data){
        delete[] data;
    }
    if(tree){
        delete[] tree;
    }
}

template<typename T>
int SegmentTree<T>::getSize(){
    return size;
}

template<typename T>
T SegmentTree<T>::get(int index){
    if(index < 0 || index >= size){
        return -1;
    }
    return data[index];
}

template<typename T>
void SegmentTree<T>::buildSegmentTree(int treeIndex, int l, int r){
    if(l==r){
        tree[treeIndex] = data[l];
        return;
    }
    int mid = l + (r-l)/2;
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);
    buildSegmentTree(leftTreeIndex, l, mid);
    buildSegmentTree(rightTreeIndex, mid+1, r);
    tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);

}

template<typename T>
void SegmentTree<T>::print(){
    for(int i=0; i < 4*size; i++){
        cout << tree[i] << ", ";
    }
    cout << endl;
}


#endif