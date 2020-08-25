#ifndef UNIONFIND_3_H__
#define UNIONFIND_3_H__

#include "01-UF.h"

class UnionFind3{
    private:
    int* parent;
    int* sz;
    int size;
    int find(int p);

    public:
    UnionFind3(int size=10);
    int getSize();
    bool isConnected(int p, int q);
    void unionElements(int p, int q);
};

UnionFind3::UnionFind3(int size){
    parent = new int[size];
    this->size = size;
    for(int i=0; i<size; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int UnionFind3::getSize(){
    return size;
}

bool UnionFind3::isConnected(int p, int q){
    return find(p) == find(q);
}

void UnionFind3::unionElements(int p, int q){
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot == qRoot){
        return;
    }
    if(sz[pRoot] < sz[qRoot]){
        parent[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
    }else{
        parent[qRoot] = pRoot;
        sz[pRoot] += sz[qRoot];
    }
}

int UnionFind3::find(int p){
    if(p < 0 || p >= size){
        return -1;
    }
    while(p != parent[p]){
        p = parent[p];
    }
    return p;
}

#endif