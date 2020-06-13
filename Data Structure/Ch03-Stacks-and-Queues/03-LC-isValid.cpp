#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
   bool isValid(string s) {
        if(s.empty()){
            return true;
        }
       
        stack<char> stk;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }
                if(s[i] == ')' && stk.top() != '('){
                    return false;
                }
                if(s[i] == ']' && stk.top() != '['){
                    return false;
                }
                if(s[i] == '}' && stk.top() != '{'){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};


int main(){
    Solution solution;
    string s;
    cin >> s;

    cout << solution.isValid(s) << endl;

    return 0;

}