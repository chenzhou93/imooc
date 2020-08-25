#ifndef UNIONFIND_2_H__
#define UNIONFIND_2_H__

#include "01-UF.h"

class UnionFind2{
    private:
    int* parent;
    int size;
    int find(int p);

    public:
    UnionFind2(int size=10);
    int getSize();
    bool isConnected(int p, int q);
    void unionElements(int p, int q);
};

UnionFind2::UnionFind2(int size){
    parent = new int[size];
    this->size = size;
    for(int i=0; i<size; i++){
        parent[i] = i;
    }
}

int UnionFind2::getSize(){
    return size;
}

bool UnionFind2::isConnected(int p, int q){
    return find(p) == find(q);
}

void UnionFind2::unionElements(int p, int q){
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot == qRoot){
        return;
    }
    parent[pRoot] = qRoot;
}

int UnionFind2::find(int p){
    if(p < 0 || p >= size){
        return -1;
    }
    while(p != parent[p]){
        p = parent[p];
    }
    return p;
}

#endif