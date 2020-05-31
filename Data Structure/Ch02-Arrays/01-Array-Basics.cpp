#include <iostream>
using namespace std;

int main(){
    //Open new space
    int arr[10];
    //Visit, assignment
    for(int i=0; i<10; i++){
        arr[i] = i;
    }
    //Initialization
    int scores[] = {100, 99, 66};
    for(int i=0; i<3; i++){
        cout << scores[i] << endl;
    }
    //For each loop
    for(int& i : scores){
        cout << i << endl;
    }
    //Edit
    scores[0] = 98;

    return 0;
}