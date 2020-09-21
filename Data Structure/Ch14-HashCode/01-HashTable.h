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

template <typename K, typename V>
V HashTable<K, V>::remove(K key){
    map<K, V> map1 = hashtable[hash(key)];
    V ret;
    if(map[key]){
        ret = map[key];
        map.erase(key);
        size--;

        if(size < lowerTol * M && M/2 >= initCapacity){
            resize(M/2);
        }
    }
    return ret;
}

template <typename K, typename V>
void HashTable<K, V>::set(K key, V value){
    map<K, V> map1 = hashtable[hash(key)];
    if(!map1[key]){
        return;
    }
    map1[key] = value;
}

template <typename K, typename V>
bool HashTable<K, V>::contains(K key){
    return (hashtable[hash(key)])[key] == 0 ? false : true;
}

template <typename K, typename V>
V HashTable<K, V>::get(K key){
    (hashtable[hash(key)])[key];
}

template <typename K, typename V>
void HashTable<K, V>::resize(int newM){
    map<K, V> newHashTable1[capacity];
    for(int i=0; i<newM; i++){
        newHashTable[i];
    }

    int oldM = M;
    this->M = newM;

    for(int i=0; i<oldM; i++){
        map<K,V> map1 = hashtable[i];
        for(int j =0; j<map1.size(); j++){
            (newHashTable[hash(key)])[key] = value;
        }
    }

    this->hashtable = newHashTable;

}


#endif