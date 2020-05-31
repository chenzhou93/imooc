#include <iostream>
#include "02-CreateOwnArray.h"
using namespace std;

Array::Array(int s){
    data = new int[s];
    size = 0;
    length = s;
}

Array::~Array(){
    if(data){
        delete[] data;
    }
}

int& Array::operator[](int index){
    return data[index];
}

int Array::getSize(){
    return size;
}

int Array::getCapacity(){
    return length;
}

bool Array::isEmpty(){
    return size == 0;
}

void Array::add(int index, int e){
    if(index < 0 || index > size){
        cout << "error: index out of boundry" << endl;
        return;
    }
    if(size == length){
        cout << "error: array is full" << endl;
        return;
    }
    for(int i=size-1; i>=index; i--){
        data[i+1] = data[i];
    }
    data[index] = e;
    size++;
}

void Array::addLast(int e){
    add(size,e);
}

void Array::addFirst(int e){
    add(0,e);
}

int Array::get(int index){
    if(index < 0 || index >= size){
        cout << "error: index out of boundry" << endl;
        return -1;
    }
    return data[index];
}

void Array::set(int index, int e){
    if(index < 0 || index >= size){
        cout << "error: index out of boundry" << endl;
        return;
    }
    data[index] = e;
}

bool Array::contains(int e){
    for(int i=0; i<size; i++){
        if(data[i] == e){
            return true;
        }
    }
    return false;
}

int Array::find(int e){
    for(int i=0; i<size; i++){
        if(data[i] == e){
            return i;
        }
    }
    return -1;
}

int Array::remove(int index){
    if(index < 0 || index >= size){
        cout << "error: index out of boundry" << endl;
        return -1;
    }
    if(isEmpty()){
        cout << "error: array is empty" << endl;
        return -1;
    }
    int res = data[index];
    for(int i=index; i<size-1; i++){
        data[i] = data[i+1];
    }
    size--;
    return res;
}

int Array::removeFirst(){
    return remove(0);
}

int Array::removeLast(){
    return remove(size-1);
}

void Array::removeElement(int e){
    int index = find(e);
    if(index > -1){
        remove(index);
    }
}

