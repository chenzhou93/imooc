#include <iostream>
using namespace std;

template <typename T>
class Queue{
    public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void enqueue(T e) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() = 0;
};

template <typename T>
class LinkedListQueue : public Queue<T>{
    private:
    struct Node{
        T e;
        Node* next;
        Node(){
            e = 0;
            next = NULL;
        }
        Node(T n, Node* p){
            e = n;
            next = p;
        }
        Node(T n){
            e = n;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int size;

    public:
    LinkedListQueue();
    ~LinkedListQueue();
    int getSize();
    bool isEmpty();
    void enqueue(T e);
    T dequeue();
    T getFront();
    void print();
};

template <typename T>
LinkedListQueue<T>::LinkedListQueue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
LinkedListQueue<T>::~LinkedListQueue(){
    while(head != tail){
        dequeue();
    }
}

template <typename T>
int LinkedListQueue<T>::getSize(){
    return size;
}

template <typename T>
bool LinkedListQueue<T>::isEmpty(){
    return size == 0;
}

template <typename T>
void LinkedListQueue<T>::enqueue(T e){
    if(tail == NULL){
        tail = new Node(e);
        head = tail;
    }else{
        tail->next = new Node(e);
        tail = tail->next;
    }
    size++;
}

template <typename T>
T LinkedListQueue<T>::dequeue(){
    if(isEmpty()){
        return -1;
    }
    Node* tmp = head;
    head = head->next;
    tmp->next = NULL;
    if(head == NULL){
        tail = NULL;
    }
    size--;
    return tmp->e;
}

template <typename T>
T LinkedListQueue<T>::getFront(){
    if(isEmpty()){
        return -1;
    }
    return head->e;
}

template <typename T>
void LinkedListQueue<T>::print(){
    Node* p = head;
    while(p != NULL){
        cout << p->e << "->";
        p = p->next;
    }
    cout << endl;
}

int main(){
    LinkedListQueue<int> queue;
    for(int i=0; i<10; i++){
        queue.enqueue(i);
        queue.print();

        if(i%3 ==2){
            queue.dequeue();
            queue.print();
        }
    }
        
}