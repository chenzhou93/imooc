#include <map>
#include <vector>

using namespace std;
int main(){
    vector<map<int, int>> map;

    for(int i=0; i<5; i++){
        (map[i])[i] = i;
    }


    return 0;
}