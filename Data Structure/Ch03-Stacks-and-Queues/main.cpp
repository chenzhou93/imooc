#include <iostream>
#include "01-Stack.h"
using namespace std;


int main(){
    MyArrayStack<int> stack(10);

    for(int i=0; i<10; i++){
        stack.push(i);
    }

    for(int i=0; i<10; i++){
        cout << stack.pop() << endl;
    }


    return 0;
}