#ifndef BST_H__
#define BST_H__

#include <cmath>
#include <iostream>
#include <vector>
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
    void inorder(vector<K>& array, Node<K,V>* node);
    Node<K,V>* rightRotate(Node<K,V>* y);
    Node<K,V>* leftRotate(Node<K,V>* y);

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
    bool isBST();
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
Node<K,V>* rightRotate(Node<K,V>* y){
    Node<K,V>* x = y->left;
    Node<K,V>* T3 = x->right;
    x->right = y;
    y->left = T3;

    //update height
    y->height = max(getHeight(y->left), getHeight(y->right) + 1);
    x->height = max(getHeight(x->left), getHeight(x->right) + 1);

    return x;
}

template<typename K, typename V>
Node<K,V>* leftRotate(Node<K,V>* y){
    Node<K,V>* x = y->right;
    Node<K,V>* T2 = x->left;
    x->left = y;
    y->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)+1);
    y->height = max(getHeight(y->left), getHeight(y->right)+1);

    return x;
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
    
    //LL
    if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0){
        return rightRotate(node);
    }

    //RR
    if(balanceFactor < -1 && getBalanceFactor(node->right) <=0){
        return leftRotate(node);
    }

    //LR
    if(balanceFactor > 1 && getBalanceFactor(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //RL
    if(balanceFactor < -1 && getBalanceFactor(node->right) < 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
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
    Node<K, V>* retNode;
    if(key < node->key){
        node->left = remove(node->left, key);
        retNode = node;
        return node;
    }else if(key > node->key){
        node->right = remove(node->right, key);
        retNode = node;
        return node;
    }else{
        if(node->left == NULL){
            Node<K,V>* rightNode = node->right;
            node->right = NULL;
            size--;
            retNode = rightNode;
        }
        if(node->right == NULL){
            Node<K,V>* leftNode = node->left;
            node->left = NULL;
            size--;
            retNode = leftNode;
        }

        Node<K,V>* successor = minimum(node->right);
        successor->left = node->left;
        successor->right = remove(node->right, successor->key);
        
        node->left = node->right = NULL;
        retNode = successor;
    }

    if(retNode == NULL){
        return NULL;
    }

    retNode->height = 1 + max(getHeight(retNode->left), getHeight(retNode->right));
    int balanceFactor = getBalanceFactor(retNode);

    if(balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0){
        return rightRotate(retNode);
    }
    if(balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0){
        return leftRotate(retNode);
    }
    if(balanceFactor > 1 && getBalanceFactor(retNode->left) < 0){
        retNode.left = leftRotate(retNode.left);
        return rightRotate(retNode);
    }
    if(balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0){
        retNode.right = rightRotate(retNode.right);
        return leftRotate(retNode);
    }
    return retNode;
    
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

template<typename K, typename V>
void BST<K,V>::inorder(vector<K>& array, Node<K,V>* node){
    if(node == NULL){
        return;
    }
    inorder(array, node->left);
    array.push_back(node->key);
    inorder(array, node->right);
}

template<typename K, typename V>
bool BST<K,V>::isBST(){
    vector<K> array;
    inorder(array, root);
    for(int i=1; i<array.size(); i++){
        if(array[i] < array[i-1]){
            return false;
        }
    }
    return true;
}



#endif