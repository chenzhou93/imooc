#include "01-Trie.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    Trie trie;

    string word1 = "hello";
    string word2 = "people";
    string word3 = "hell";

    trie.add(word1);
    trie.add(word2);
    trie.add(word3);

    cout << trie.getSize() << endl;

    cout << trie.contains("hel") << endl;
    
    return 0;
}