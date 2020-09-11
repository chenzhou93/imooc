#ifndef BST_H__
#define BST_H__

const bool RED = true;
const bool BLACK = true;

template<typename K, typename V>
class Node{
    public:
    K key;
    V value;
    bool color;
    Node<K,V>* left;
    Node<K,V>* right;
    Node(K k, V v){
        key = k;
        value = v;
        color = RED;
    }
};

template<typename K, typename V>
class RedBlackTree{
    private:
    Node<K,V>* root;
    int size;

    Node<K,V>* add(Node<K,V>* node, K key, V value);
    Node<K,V>* getNode(Node<K,V>* node, K key);
    Node<K,V>* minimum(Node<K,V>* node);
    Node<K,V>* removeMin(Node<K,V>* node);
    Node<K,V>* remove(Node<K,V>* node, K key);
    bool isRed(Node<K,V>* node);
    Node<K,V>* leftRotate(Node<K,V>* node);
    Node<K,V>* rightRotate(Node<K,V>* node);
    void filpColors(Node<K,V>* node);

    public:
    RedBlackTree(){
        size = 0;
    }
    int getSize(){return size;}
    bool isEmpty(){return size == 0;}
    void add(K key, V value);
    bool contains(K key);
    V get(K key);
    void set(K key, V newValue);
    V remove(K key);
};

template<typename K, typename V>
bool RedBlackTree<K,V>::isRed(Node<K,V>* node){
    if(node == NULL){
        return BLACK;
    }
    return node->color;
}

    //   node                     x
    //  /   \     左旋转         /  \
    // T1   x   --------->   node   T3
    //     / \              /   \
    //    T2 T3            T1   T2

template<typename K, typename V>
Node<K,V>* RedBlackTree<K,V>::leftRotate(Node<K,V>* node){
    Node<K,V>* x = node->right;
    node->right = x->left;
    x->left = node;

    x->color = node->color;
    node->color = RED;
    
    return x;
}

template<typename K, typename V>
Node<K,V>* RedBlackTree<K,V>::rightRotate(Node<K,V>* node){
    Node<K,V>* x = node->left;
    node->left = x->right;
    x->right = node;

    x->color = node->color;
    node->color = RED;

    return x;
}

template<typename K, typename V>
void RedBlackTree<K,V>::filpColors(Node<K,V>* node){
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
}

template<typename K, typename V>
Node<K,V>* RedBlackTree<K,V>::add(Node<K,V>* node, K key, V value){
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
    return node;
}

template<typename K, typename V>
void RedBlackTree<K,V>::add(K key, V value){
    root = add(key, value);
}

template<typename K, typename V>
Node<K,V>* RedBlackTree<K,V>::getNode(Node<K,V>* node, K key){
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
bool RedBlackTree<K,V>::contains(K key){
    return getNode(root, key) != NULL;
}

template<typename K, typename V>
V RedBlackTree<K,V>::get(K key){
    Node<K,V>* node = getNode(root, key);
    return node == NULL ? NULL : node->value;
}

template<typename K, typename V>
void RedBlackTree<K,V>::set(K key, V newValue){
    Node<K,V>* node = getNode(root, key);
    node->value = newValue;
}

template<typename K, typename V>
Node<K,V>* RedBlackTree<K,V>::minimum(Node<K,V>* node){
    if(node->left == NULL){
        return node;
    }
    return minimum(node->left);
}

template<typename K, typename V>
Node<K,V>* RedBlackTree<K,V>::removeMin(Node<K,V>* node){
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
Node<K,V>* RedBlackTree<K,V>::remove(Node<K,V>* node, K key){
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
V RedBlackTree<K,V>::remove(K key){
    Node<K,V>* node = getNode(root, key);
    if(node != NULL){
        root = remove(root, key);
        return node->value;
    }
    return NULL;
}



#endif