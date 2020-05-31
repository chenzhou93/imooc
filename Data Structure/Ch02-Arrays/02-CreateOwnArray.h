#ifndef MYARRAY_H__
#define MYARRAY_H__

class Array{
    private:
    int* data;
    int size;
    int length;

    public:
    Array(int s=10);
    ~Array();
    int getSize();
    int getCapacity();
    bool isEmpty();
    void addLast(int e);
    void addFirst(int e);
    void add(int index, int e);
    int get(int index);
    void set(int index, int e);
    bool contains(int e);
    int find(int e);
    int remove(int index);
    int removeFirst();
    int removeLast();
    void removeElement(int e);
    int& operator[](int index);
};

#endif