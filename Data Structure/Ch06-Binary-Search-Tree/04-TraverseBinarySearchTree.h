#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node{
    public:
    T e;
    Node<T>* left;
    Node<T>* right;

    Node(T e){
        this->e = e;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinarySearchTree{
    private:
    Node<T>* root;
    int size;

    public:
    BinarySearchTree();
    int length();
    bool isEmpty();
    Node<T>*  add(Node<T>* node, T e);
    void add(T e);

    bool contains(Node<T>* node, T e);
    bool contains(T e);

    void preOrder(Node<T>* node);
    void preOrder();

    void inOrder(Node<T>* node);
    void inOrder();

    void postOrder(Node<T>* node);
    void postOrder();

    string generateDepthString(int depth);
    void generateBSTString(Node<T>* node, int depth, string& res);
    void print();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
    size = 0;
}

template <typename T>
int BinarySearchTree<T>::length(){
    return size;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty(){
    return size == 0;
}

template <typename T>
Node<T>* BinarySearchTree<T>::add(Node<T>* node, T e){
    if(node == NULL){
        size++;
        return new Node<T>(e);
    }
    if(node->e < e){
        node->right = add(node->right, e);
    }else if(node->e > e){
        node->left = add(node->left, e);
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::add(T e){
    add(root, e);
}

template <typename T>
bool BinarySearchTree<T>::contains(Node<T>* node, T e){
    if(node == NULL){
        return false;
    }
    if(node->e == e){
        return true;
    }else if(node->e < e){
        contains(node->right, e);
    }else{
        contains(node->left, e);
    }
}

template <typename T>
bool BinarySearchTree<T>::contains(T e){
    return contains(root, e);
}

template <typename T>
void BinarySearchTree<T>::preOrder(Node<T>* node){
    if(node == NULL){
        return;
    }
    cout << node->e << endl;
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void BinarySearchTree<T>::preOrder(){
    preOrder(root);
}

template <typename T>
void BinarySearchTree<T>::inOrder(Node<T>* node){
    if(node == NULL){
        return;
    }
    inOrder(node->left);
    cout << node->e << endl;
    inOrder(node->right);
}

template <typename T>
void BinarySearchTree<T>::inOrder(){
    inOrder(root);
}

template <typename T>
void BinarySearchTree<T>::postOrder(Node<T>* node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->e << endl;
}

template <typename T>
void BinarySearchTree<T>::postOrder(){
    postOrder(root);
}

template <typename T>
string BinarySearchTree<T>::generateDepthString(int depth){
    string res;
    for(int i=0; i<depth; i++){
        res.append("--");
    }
    return res;
}

template <typename T>
void BinarySearchTree<T>::generateBSTString(Node<T>* node, int depth, string& res){
    if(node == NULL){
        res.append(generateDepthString(depth) + "null\n");
        return;
    }

    res.append(generateDepthString(depth) + node->e + "\n");

    generateBSTString(node->left, depth+1, res);
    generateBSTString(node->right, depth+1, res);

}

template <typename T>
void BinarySearchTree<T>::print(){
    string result;
    string& res = result;
    generateBSTString(root, 0, res);
    cout << res << endl;
}



