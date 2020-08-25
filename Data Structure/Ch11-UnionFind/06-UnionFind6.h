#ifndef UNIONFIND_6_H__
#define UNIONFIND_6_H__

#include "01-UF.h"

class UnionFind6{
    private:
    int* parent;
    int* rank;//以i为根的集合所表示的树的层数
    int size;
    int find(int p);

    public:
    UnionFind6(int size=10);
    int getSize();
    bool isConnected(int p, int q);
    void unionElements(int p, int q);
};

UnionFind6::UnionFind6(int size){
    parent = new int[size];
    this->size = size;
    for(int i=0; i<size; i++){
        parent[i] = i;
        rank[i] = 1;
    }
}

int UnionFind6::getSize(){
    return size;
}

bool UnionFind6::isConnected(int p, int q){
    return find(p) == find(q);
}

void UnionFind6::unionElements(int p, int q){
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot == qRoot){
        return;
    }
    if(rank[pRoot] < rank[qRoot]){
        parent[pRoot] = qRoot;
    }else if(rank[pRoot] > rank[qRoot]){
        parent[qRoot] = pRoot;
    }else{
        parent[qRoot] = pRoot;
        rank[pRoot] += 1;
    }
}

int UnionFind6::find(int p){
    if(p < 0 || p >= size){
        return -1;
    }
    if(p != parent[p]){
        parent[p] = find(parent[p]);
    }
    return p;
}

#endif