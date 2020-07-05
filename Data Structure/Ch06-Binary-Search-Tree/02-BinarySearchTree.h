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
    int size();
    bool isEmpty();
    Node<T>*  add(Node<T>* node, T e);
    void add(T e);

    bool contains(Node<T>* node, T e);
    bool contains(T e);
    
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
    size = 0;
}


template <typename T>
int BinarySearchTree<T>::size(){
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
        return new Node<T>* node(e);
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




