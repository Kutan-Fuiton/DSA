#include<iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string res;

        for (const char ch : s){
            if (ch == '('){
                if (depth > 0) res.push_back(ch);
                depth++;
            } else {
                depth--;
                if (depth > 0) res.push_back(ch);
            }
        }
        
        return res;
    }
};

int main(){
    Solution sol;

    cout << sol.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << sol.removeOuterParentheses("(()())(())") << endl;

    return 0;
}