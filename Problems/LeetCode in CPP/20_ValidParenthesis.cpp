#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brac;
        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                brac.push(c);
            } else {
                if (brac.empty()){
                    brac.push(c);
                }
                else if (c == ')' && brac.top() == '('){
                    brac.pop();
                }
                else if (c == '}' && brac.top() == '{'){
                    brac.pop();
                }
                else if (c == ']' && brac.top() == '['){
                    brac.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (brac.empty()) return true;
        else return false;
    }
};

int main(){
    Solution sol;

    cout << sol.isValid(")}][]") << endl;

    return 0;
}