#ifndef HASH_TABLE_H__
#define HASH_TABLE_H__

#include <string>
#include <map>
using namespace std;

template <typename K, typename V>
class HashTable{
    private:
    static const int upperTol = 10;
    static const int lowerTol = 2;
    static const int capacity = 7;

    vector<map<K, V>> hashtable;
    int M;
    int size;

    int hash(K key);

    public:
    HashTable(int m);
    HashTable();
    int getSize();
    void add(K key, V value);
    V remove(K key);
    void set(K key, V value);
    bool contains(K key);
    V get(K key);
    void resize(int newM);
};

template <typename K, typename V>
HashTable<K, V>::HashTable(int m){
    M = m;
    size = 0;
    vector<map<K, V>> myMap1(m);
    hashtable = myMap1;

    for(int i=0; i<m; i++){
        (hashtable[i])[0] = 0;
    }
}

template <typename K, typename V>
HashTable<K, V>::HashTable(){
    HashTable(capacity);
}

template <typename K, typename V>
int HashTable<K, V>::hash(K key){
    return key & 0x7fffffff % M;
}

template <typename K, typename V>
int HashTable<K, V>::getSize(){
    return size;
}



template <typename K, typename V>
void HashTable<K, V>::add(K key, V value){
    map<K,V> tmpMap = hashtable[hash(key)];
    V res;
    if(map.find(key)){
        tmpMap[key] = value;
    }else{
        tmpMap[key] = value;
        size++;
        if(size >= upperTol*M){
            resize(2 * M);
        }
    }
}






#endif