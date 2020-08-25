#ifndef UNIONFIND_1_H__
#define UNIONFIND_1_H__

#include "01-UF.h"

class UnionFind1{
    private:
    int* id;
    int size;
    int find(int p);

    public:
    UnionFind1(int size=10);
    int getSize();
    bool isConnected(int p, int q);
    void unionElements(int p, int q);
};

UnionFind1::UnionFind1(int size){
    id = new int[size];
    this->size = size;
    for(int i=0; i<size; i++){
        id[i] = i;
    }
}

int UnionFind1::getSize(){
    return size;
}

bool UnionFind1::isConnected(int p, int q){
    return find(p) == find(q);
}

void UnionFind1::unionElements(int p, int q){
    int pID = find(p);
    int qID = find(q);
    if(pID == qID){
        return;
    }
    for(int i=0; i<size; i++){
        if(id[i] == pID){
            id[i] = qID;
        }
    }
}

int UnionFind1::find(int p){
    if(p < 0 || p >= size){
        return -1;
    }
    return id[p];
}

#endif