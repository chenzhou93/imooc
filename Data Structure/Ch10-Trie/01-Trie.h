#ifndef TRIE_H__
#define TRIE_H__
#include <map>
#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    bool isWord;
    map<char, Node*> next;

    Node(bool word){
        isWord = word;
    }
    Node(){
        isWord = false;
    }
};


class Trie{
    private:
    Node* root;
    int size;

    public:
    Trie();
    int getSize();
    void add(string word);
    bool contains(string word);
};

Trie::Trie(){
    root = new Node();
    size = 0;
}

int Trie::getSize(){
    return size;
}

void Trie::add(string word){
    Node* cur = root;
    for(int i=0; i<word.size(); i++){
        char c = word[i];
        if(cur->next[c] == NULL){
            Node* tmpNode = new Node();
            cur->next[c] = tmpNode;
        }
        cur = cur->next[c];
    }

    if(!cur->isWord){
        cur->isWord = true;
        size++;
    }
}

bool Trie::contains(string word){
    Node* cur = root;
    for(int i=0; i<word.size(); i++){
        char c = word[i];
        if(cur->next[c] == NULL){
            return false;
        }
        cur = cur->next[c];
    }
    return cur->isWord;
}

#endif