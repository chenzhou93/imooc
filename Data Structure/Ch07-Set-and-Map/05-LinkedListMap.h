#ifndef LINKEDLISTMAP_H__
#define LINKEDLISTMAP_H__

#include "05-Map.h"
#include <iostream>
using namespace std;

template <typename K, typename V>
class Node{
    public:
    K key;
    V value;
    Node<K,V>* next;

    Node(K k, V v, Node<K,V>* node){
        key = k;
        value = v;
        next = node;
    }

    Node(K k){
        key = k;
        value = 0;
        next = NULL;
    }

    Node(){
        key = 0;
        value = 0;
        next = NULL;
    }
};

template <typename K, typename V>
class LinkedListMap : public Map<K,V>, public Node<K, V>{
    private:
    Node<K,V>* dummyHead;
    int size;

    public:
    LinkedListMap();
    Node<K, V>* getNode(K key);
    int getSize();
    bool isEmpty();
    void add(K key, V value);
    V remove(K key);
    bool contains(K key);
    V get(K key);
    void set(K key, V newValue);
    //~LinkedListMap();
};

template <typename K, typename V>
LinkedListMap<K,V>::LinkedListMap(){
    dummyHead = new Node<K,V>();
    size = 0;
}

template <typename K, typename V>
Node<K, V>* LinkedListMap<K,V>::getNode(K key){
    Node<K,V>* p = dummyHead->next;
    while(p != NULL){
        if(p->key == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

template <typename K, typename V>
int LinkedListMap<K,V>::getSize(){
    return size;
}

template <typename K, typename V>
bool LinkedListMap<K,V>::isEmpty(){
    return size == 0;
}

template <typename K, typename V>
void LinkedListMap<K,V>::add(K key, V value){
    Node<K,V>* node = getNode(key);
    if(node == NULL){
        dummyHead->next = new Node<K,V>(key, value, dummyHead->next);
        size++;
    }else{
        node->value = value;
    }
}

template <typename K, typename V>
V LinkedListMap<K,V>::remove(K key){
    Node<K,V>* prev = dummyHead;
    while(prev->next != NULL){
        if(prev->next->key == key){
            Node<K,V>* delNode = prev->next;
            prev->next = delNode->next;
            delNode->next = NULL;
            size--;
            V ret = delNode->value;
            return ret;
        }
        prev = prev->next;
    }
    return 0;
}

template <typename K, typename V>
bool LinkedListMap<K,V>::contains(K key){
    return getNode(key) != NULL;
}   

template <typename K, typename V>
V LinkedListMap<K,V>::get(K key){
    Node<K,V>* node = getNode(key);
    return node == NULL ? 0 : node->value;
}

template <typename K, typename V>
void LinkedListMap<K,V>::set(K key, V newValue){
    Node<K,V>* node = getNode(key);
    if(node == NULL){
        return;
    }
    node->value = newValue;
}

// template <typename K, typename V>
// LinkedListMap<K,V>::~LinkedListMap(){
//     while(dummyHead->next != NULL){
//         Node<K,V>* delNode = dummyHead->next;
//         dummyHead->next = delNode->next;
//         delete delNode;
//     }
//     dummyHead = NULL;
//     size = 0;
// }


#endif