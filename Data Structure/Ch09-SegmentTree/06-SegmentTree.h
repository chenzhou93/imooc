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
    T query(int treeIndex, int l, int r, int queryL, int queryR);
    void set(int treeIndex, int l, int r, int index, T e);

    public:
    SegmentTree(T* arr, int n);
    ~SegmentTree();
    int getSize();
    T get(int index);
    void print();
    T query(int queryL, int queryR);
    void set(int index, T e);
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

template<typename T>
T SegmentTree<T>::query(int treeIndex, int l, int r, int queryL, int queryR){
    if(l == queryL && r == queryR){
        return tree[treeIndex];
    }

    int mid = l + (r-l)/2;
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);

    if(queryL >= mid + 1){
        return query(rightTreeIndex, mid+1, r, queryL, queryR);
    }else if(queryR <= mid){
        return query(leftTreeIndex, l, mid, queryL, queryR);
    }

    T leftResult = query(leftTreeIndex, l, mid, queryL, mid);
    T rightResult = query(rightTreeIndex, mid+1, r, mid+1, queryR);

    return merge(leftResult, rightResult);
}

template<typename T>
T SegmentTree<T>::query(int queryL, int queryR){
    if(queryL <0 || queryR >= size || queryR<0 || queryR >=size || queryL > queryR){
        return -1;
    }
    return query(0, 0, size-1, queryL, queryR);
}

template <typename T>
void set(int treeIndex, int l, int r, int index, T e){
    if(l == r){
        tree[treeIndex] = e;
        return;
    }
    int mid = l + (r-l)/2;
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);

    if(index >= mid+1){
        set(rightTreeIndex, mid+1, r, index, e);
    }else{
        set(leftTreeIndex, l, mid, index, e);
    }
    tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
}

template <typename T>
void set(int index, T e){
    if(index < 0 || index >= size){
        return;
    }
    data[index] = e;
    set(0, 0, size-1, index, e);
}

#endif