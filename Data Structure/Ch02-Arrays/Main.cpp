#include <iostream>
#include "02-CreateOwnArray.h"

using namespace std;

int main(){
    Array array(20);
    for(int i=0; i<10; i++){
        array.addLast(i);
    }

    for(int i=0; i<10; i++){
        //cout << array.get(i) << endl;
        cout << array[i] << endl;
    }

    array.add(1, 100);
    for(int i=0; i<10; i++){
        cout << array[i] << endl;
    }

    array.remove(2);
    for(int i=0; i<10; i++){
        cout << array[i] << endl;
    }

    return 0;
}