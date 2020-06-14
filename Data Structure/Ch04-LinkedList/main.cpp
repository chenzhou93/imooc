#include <iostream>
//#include "01-LinkedList.h"
#include "04-LinkedListGetSet.h"
using namespace std;

int main(){
    // LinkedList<int> linkedlist;
    // for(int i=0; i<5; i++){
    //     linkedlist.addFirst(i);
    // }

    //linkedlist.print();

    MyLinkedList<int> mylinkedlist;
    for(int i=0; i<5; i++){
        mylinkedlist.addFirst(i);
    }

    mylinkedlist.add(2, 666);
    mylinkedlist.print();
    return 0;   
}