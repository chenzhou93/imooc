#ifndef GARRAY_H__
#define GARRAY_H__
#include <iostream>
using namespace std;

template <typename T>
class MyArray{
    private:
    T* data;
    int size;
    int length;

    public:
    MyArray(int s=10);
    ~MyArray();
    int getSize();
    int getCapacity();
    bool isEmpty();
    void addLast(T e);
    void addFirst(T e);
    void add(int index, T e);
    T get(int index);
    T getFirst();
    T getLast();
    void set(int index, T e);
    bool contains(T e);
    int find(T e);
    T remove(int index);
    T removeFirst();
    T removeLast();
    void removeElement(T e);
    T& operator[](int index);
    void resize(int c);
};

template<typename T>
MyArray<T>::MyArray(int s){
    data = new T[s];
    size = 0;
    length = s;
}

template<typename T>
MyArray<T>::~MyArray(){
    if(data){
        delete[] data;
    }
}

template<typename T>
T& MyArray<T>::operator[](int index){
    return data[index];
}

template<typename T>
int MyArray<T>::getSize(){
    return size;
}

template<typename T>
int MyArray<T>::getCapacity(){
    return length;
}

template<typename T>
bool MyArray<T>::isEmpty(){
    return size == 0;
}

template<typename T>
void MyArray<T>::add(int index, T e){
    if(index < 0 || index > size){
        cout << "error: index out of boundry" << endl;
        return;
    }
    if(size == length){
        // cout << "error: MyArray is full" << endl;
        // return;
        resize(2 * length);
    }
    for(int i=size-1; i>=index; i--){
        data[i+1] = data[i];
    }
    data[index] = e;
    size++;
}

template<typename T>
void MyArray<T>::addLast(T e){
    add(size,e);
}

template<typename T>
void MyArray<T>::addFirst(T e){
    add(0,e);
}

template<typename T>
T MyArray<T>::get(int index){
    if(index < 0 || index >= size){
        cout << "error: index out of boundry" << endl;
        return -1;
    }
    return data[index];
}

template<typename T>
T MyArray<T>::getFirst(){
    return get(0);
}

template<typename T>
T MyArray<T>::getLast(){
    return get(size-1);
}

template<typename T>
void MyArray<T>::set(int index, T e){
    if(index < 0 || index >= size){
        cout << "error: index out of boundry" << endl;
        return;
    }
    data[index] = e;
}

template<typename T>
bool MyArray<T>::contains(T e){
    for(int i=0; i<size; i++){
        if(data[i] == e){
            return true;
        }
    }
    return false;
}

template<typename T>
int MyArray<T>::find(T e){
    for(int i=0; i<size; i++){
        if(data[i] == e){
            return i;
        }
    }
    return -1;
}

template<typename T>
T MyArray<T>::remove(int index){
    if(index < 0 || index >= size){
        cout << "error: index out of boundry" << endl;
        return -1;
    }
    if(isEmpty()){
        cout << "error: MyArray is empty" << endl;
        return -1;
    }
    T res = data[index];
    for(int i=index; i<size-1; i++){
        data[i] = data[i+1];
    }
    size--;
    if(size == length/4 && length/2 != 0){
        resize(length/2);
    }
    return res;
}

template<typename T>
T MyArray<T>::removeFirst(){
    return remove(0);
}

template<typename T>
T MyArray<T>::removeLast(){
    return remove(size-1);
}

template<typename T>
void MyArray<T>::removeElement(T e){
    int index = find(e);
    if(index > -1){
        remove(index);
    }
}

template<typename T>
void MyArray<T>::resize(int c){
    T* tmpData = new T[c];
    for(int i=0; i<size; i++){
        tmpData[i] = data[i];
    }
    length = c;
    data = tmpData;
    tmpData = nullptr;
    delete[] tmpData;
}



#endif