#ifndef BST_H__
#define BST_H__

#include <cmath>
#include <iostream>
using namespace std;

template<typename K, typename V>
class Node{
    public:
    K key;
    V value;
    Node<K,V>* left;
    Node<K,V>* right;
    int height;
    Node(K k, V v){
        key = k;
        value = v;
        height = 1;
    }
};

template<typename K, typename V>
class BST{
    private:
    Node<K,V>* root;
    int size;
    Node<K,V>* add(Node<K,V>* node, K key, V value);
    Node<K,V>* getNode(Node<K,V>* node, K key);
    Node<K,V>* minimum(Node<K,V>* node);
    Node<K,V>* removeMin(Node<K,V>* node);
    Node<K,V>* remove(Node<K,V>* node, K key);
    bool isBalanced(Node<K,V>* node);
    int getHeight(Node<K,V>* node);
    int getBalanceFactor(Node<K,V>* node);

    public:
    BST(){
        size = 0;
    }
    int getSize(){return size;}
    bool isEmpty(){return size == 0;}
    void add(K key, V value);
    bool contains(K key);
    V get(K key);
    void set(K key, V newValue);
    V remove(K key);
    bool isBalanced();
};

template<typename K, typename V>
int BST<K,V>::getHeight(Node<K,V>* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

template<typename K, typename V>
int BST<K,V>::getBalanceFactor(Node<K,V>* node){
    if(node == NULL){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template<typename K, typename V>
bool BST<K,V>::isBalanced(Node<K,V>* node){
    if(node == NULL){
        return true;
    }
    int balanceFactor = getBalanceFactor(node);
    if(abs(balanceFactor) > 1){
        return false;
    }
    return isBalanced(node->left) && isBalanced(node->right);
}

template<typename K, typename V>
bool BST<K,V>::isBalanced(){
    return isBalanced(root);
}

template<typename K, typename V>
Node<K,V>* BST<K,V>::add(Node<K,V>* node, K key, V value){
    if(node == NULL){
        size++;
        return new Node<K,V>(key, value);
    }
    if(key < node->key ){
        node->left = add(node->left, key, value);
    }else if(key > node->key){
        node->right = add(node->right, key, value);
    }else{
        node->value = value;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balanceFactor = getBalanceFactor(node);

    if(abs(balanceFactor) > 1){
        cout << "unbalanced: " << balanceFactor << endl;
    }
    
    

    return node;
}

template<typename K, typename V>
void BST<K,V>::add(K key, V value){
    root = add(key, value);
}

template<typename K, typename V>
Node<K,V>* BST<K,V>::getNode(Node<K,V>* node, K key){
    if(node == NULL){
        return NULL;
    }
    if(node->key == key){
        return node;
    }else if(node->key < key){
        return getNode(node->left, key);
    }else{
        return getNode(node->right, key);
    }
}

template<typename K, typename V>
bool BST<K,V>::contains(K key){
    return getNode(root, key) != NULL;
}

template<typename K, typename V>
V BST<K,V>::get(K key){
    Node<K,V>* node = getNode(root, key);
    return node == NULL ? NULL : node->value;
}

template<typename K, typename V>
void BST<K,V>::set(K key, V newValue){
    Node<K,V>* node = getNode(root, key);
    node->value = newValue;
}

template<typename K, typename V>
Node<K,V>* BST<K,V>::minimum(Node<K,V>* node){
    if(node->left == NULL){
        return node;
    }
    return minimum(node->left);
}

template<typename K, typename V>
Node<K,V>* BST<K,V>::removeMin(Node<K,V>* node){
    if(node->left == NULL){
        Node<K,V>* rightNode = node->right;
        node->right = NULL;
        size--;
        return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
}

template<typename K, typename V>
Node<K,V>* BST<K,V>::remove(Node<K,V>* node, K key){
    if(node == NULL){
        return NULL;
    }
    if(key < node->key){
        node->left = remove(node->left, key);
    }else if(key > node->key){
        node->right = remove(node->right, key);
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
}

template<typename K, typename V>
V BST<K,V>::remove(K key){
    Node<K,V>* node = getNode(root, key);
    if(node != NULL){
        root = remove(root, key);
        return node->value;
    }
    return NULL;
}





#endif