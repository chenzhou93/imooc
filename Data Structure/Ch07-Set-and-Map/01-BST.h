#ifndef BST_H__
#define BST_H__

#include <iostream>
#include <string>
#include <stack>
#include <queue>
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

    void preOrderNR();

    void inOrder(Node<T>* node);
    void inOrder();

    void postOrder(Node<T>* node);
    void postOrder();

    void levelOrder();

    string generateDepthString(int depth);
    void generateBSTString(Node<T>* node, int depth, string& res);
    void print();

    Node<T>* mininum(Node<T>* node);
    T mininum();
    Node<T>* maxinum(Node<T>* node);
    T maxinum();

    Node<T>* removeMin(Node<T>* node);
    T removeMin();
    
    Node<T>* removeMax(Node<T>* node);
    T removeMax();

    Node<T>* remove(Node<T>* node, T e);
    void remove(T e);
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
        Node<T>* tmp = new Node<T>(e);
        return tmp;
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
    if(root == NULL){
        root = new Node<T>(e);
        size++;
    }else{
        add(root, e);
    }
    
}

template <typename T>
bool BinarySearchTree<T>::contains(Node<T>* node, T e){
    if(node == NULL){
        return false;
    }
    if(node->e == e){
        return true;
    }else if(node->e < e){
        return contains(node->right, e);
    }else{
        return contains(node->left, e);
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
void BinarySearchTree<T>::preOrderNR(){
    stack<Node<T>*> stk;
    stk.push(root);
    while(!stk.empty()){
        Node<T>* cur = stk.top();
        cout << cur->e << " ";
        stk.pop();
        if(cur->right != NULL){
            stk.push(cur->right);
        }
        if(cur->left != NULL){
            stk.push(cur->left);
        }
    }
    cout << endl;
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
void BinarySearchTree<T>::levelOrder(){
    queue<Node<T>*> myQueue;
    myQueue.push(root);
    while(!myQueue.empty()){
        Node<T>* cur = myQueue.front();
        cout << cur->e << " ";
        myQueue.pop();
        if(cur->left != NULL){
            myQueue.push(cur->left);
        }
        if(cur->right != NULL){
            myQueue.push(cur->right);
        }
    }
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
        res.append(generateDepthString(depth));
        return;
    }
    string tmp = generateDepthString(depth);
    
    //res.append(tmp);
    cout << tmp;
    cout << node->e;
    cout << endl;
    generateBSTString(node->left, depth+1, res);
    generateBSTString(node->right, depth+1, res);

}

template <typename T>
void BinarySearchTree<T>::print(){
    string result;
    generateBSTString(root, 0, result);
}

template <typename T>
T BinarySearchTree<T>::mininum(){
    if(root == NULL){
        return -1;
    }
    Node<T>* res = mininum(root);
    return res->e;
}

template <typename T>
Node<T>* BinarySearchTree<T>::mininum(Node<T>* node){
    if(node->left == NULL){
        return node;
    }
    return mininum(node->left);
}

template <typename T>
Node<T>* BinarySearchTree<T>::maxinum(Node<T>* node){
    if(node->right == NULL){
        return node;
    }
    return maxinum(node->right);
}

template <typename T>
T BinarySearchTree<T>::maxinum(){
    if(root == NULL){
        return -1;
    }
    Node<T>* res = maxinum(root);
    return res->e;
}

template <typename T>
Node<T>* BinarySearchTree<T>::removeMin(Node<T>* node){
    if(node->left == NULL){
        Node<T>* rightNode = node->right;
        node->right = NULL;
        size--;
        return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
}

template <typename T>
T BinarySearchTree<T>::removeMin(){
    Node<T>* res = removeMin(root);
    return res->e;
}

template <typename T>
Node<T>* BinarySearchTree<T>::removeMax(Node<T>* node){
    if(node->right == NULL){
        Node<T>* leftNode = node->left;
        node->left = NULL;
        size--;
        return leftNode;
    }
    node->right = removeMax(node->right);
    return node;
}

template <typename T>
T BinarySearchTree<T>::removeMax(){
    Node<T>* res = removeMax(root);
    return res->e;
}

template <typename T>
Node<T>* BinarySearchTree<T>::remove(Node<T>* node, T e){
    if(node == NULL){
        return NULL;
    }
    if(e < node->e){
        node->left = remove(node->left, e);
        return node;
    }else if(e > node->e){
        node->right = remove(node->right, e);
        return node;
    }else{
        if(node->left == NULL){
            Node<T>* rightNode = node->right;
            node->right = NULL;
            size--;
            return rightNode;
        }
        if(node->right == NULL){
            Node<T>* leftNode = node->left;
            node->left = NULL;
            size--;
            return leftNode;
        }

        Node<T>* successor = mininum(node->right);
        successor->right = removeMin(node->right);
        successor->left = node->left;
        
        node->left = node->right = NULL;
        return successor;
    }
}

template <typename T>
void BinarySearchTree<T>::remove(T e){
    remove(root, e);
}


#endif
