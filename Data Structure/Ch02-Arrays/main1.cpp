#include <iostream>
#include "03-GenericDynamicArray.h"

using namespace std;

int main(){
    //2-6 generic
    MyArray<int> array;

    //2-7 Dynamic
    MyArray<int> array2;
    for(int i=0; i<10; i++){
        array2.addLast(i);
    }
    for(int i=0; i<10; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
    array2.add(1, 100);
    for(int i=0; i<10; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
    array2.addFirst(101);
    for(int i=0; i<10; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
    return 0;
}