#ifndef BST_MAP__H
#define BST_MAP__H

#include "05-Map.h"
template <typename K, typename V>
class Node{
    public:
    K key;
    V value;
    Node<K,V>* left;
    Node<K,V>* right;
    Node(K k, V v){
        key = k;
        value = v;
    }
};

template <typename K, typename V>
class TreeMap : public Map<K,V>{
    private:
    Node<K,V>* root;
    int size;
    Node<K,V>* add(Node<K,V>* node, K key, V value);
    Node<K,V>* getNode(Node<K,V>* node, K key);
    Node<K,V>* minimum(Node<K,V>* node);
    Node<K,V>* removeMin(Node<K,V>* node);
    Node<K,V>* remove(Node<K,V>* node, K key);

    public:
    TreeMap();
    int getSize();
    bool isEmpty();
    void add(K key, V value);
    bool contains(K key);
    V get(K key);
    void set(K key, V newValue);
    V remove(K key);

};

template <typename K, typename V>
TreeMap<K,V>::TreeMap(){
    root = NULL;
    size = 0;
}

template <typename K, typename V>
int TreeMap<K,V>::getSize(){
    return size;
}

template <typename K, typename V>
bool TreeMap<K,V>::isEmpty(){
    return size == 0;
}

template <typename K, typename V>
Node<K,V>* TreeMap<K,V>::add(Node<K,V>* node, K key, V value){
    if(node == NULL){
        size++;
        return new Node<K,V>(key, value);
    }
    if(node->key < key){
        node->right = add(node->right, key, value);
    }else if(node->key > key){
        node->left = add(node->left, key, value);
    }else{
        node->value = value;
    }
    return node;
}

template <typename K, typename V>
void TreeMap<K,V>::add(K key, V value){
    root = add(root, key, value);
}

template <typename K, typename V>
Node<K,V>* TreeMap<K,V>::getNode(Node<K,V>* node, K key){
    if(node == NULL){
        return NULL;
    }
    if(key < node->key){
        return getNode(node->left, key);
    }else if(key > node->key){
        return getNode(node->right, key);
    }else{
        return node;
    }
}

template <typename K, typename V>
bool TreeMap<K,V>::contains(K key){
    return getNode(root, key) != NULL;
}

template <typename K, typename V>
V TreeMap<K,V>::get(K key){
    Node<K,V>* node = getNode(root, key);
    if(node == NULL){
        return 0;
    }
    return node->value;
}

template <typename K, typename V>
void TreeMap<K,V>::set(K key, V newValue){
    Node<K,V>* node = getNode(root, key);
    if(node == NULL){
        return;
    }
    node->value = newValue;
}

template <typename K, typename V>
Node<K,V>* TreeMap<K,V>::minimum(Node<K,V>* node){
    if(node->left == NULL){
        return node;
    }
    return minimum(node->left);
}

template <typename K, typename V>
Node<K,V>* TreeMap<K,V>::removeMin(Node<K,V>* node){
    if(node->left == NULL){
        Node<K,V>* rightNode = node->right;
        node->right = NULL;
        size--;
        return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
}

template <typename K, typename V>
V TreeMap<K,V>::remove(K key){
    Node<K,V>* node = getNode(root, key);
    if(node != NULL){
        root = remove(root, key);
        return node->value;
    }
    return 0;
}

template <typename K, typename V>
Node<K,V>* TreeMap<K,V>::remove(Node<K,V>* node, K key){
    if(node == NULL){
        return NULL;
    }
    if(node->key < key){
        node->right = remove(node->right, key);
    }else if(node->key > key){
        node->left = remove(node->left, key);
    }else{
        if(node->left == NULL){
            Node<K,V>* rightNode = node->right;
            node->right = NULL;
            size--;
            return rightNode;
        }

        if(node->right == NULL){
            Node<K,V>* leftNode = node->left;
            node->left = NULL;
            size--;
            return leftNode;
        }

        Node<K,V>* successor = minimum(node->right);
        successor->left = node->left;
        successor->right = removeMin(node->right);

        node->left = node->right = NULL;
        return successor;

    }
    return NULL;

}

#endif