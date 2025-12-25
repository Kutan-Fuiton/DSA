#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int ops, bracket = 0;
        char op1 = 0, op2 = 0, res = 0;
        for (char c : expression){
            if (c == '!') ops = 0; continue;
            if (c == '|') ops = 1; continue;
            if (c == '&') ops = 2; continue;
            if (c == '(') bracket++; continue;
            if ((c == 't' || c == 'f') && op1 == 0) {
                op1 = c;
                if (ops == 0){
                    if (c == 't') res = 'f';
                    else res = 't';
                }
            }
            if ((c == 't' || c == 'f') && op1 != 0 && op2 == 0) op2 = c;
            if ((c == 't' || c == 'f') && op1 != 0 && op2 != 0) {
                if (ops == 1) {
                    if (op1 == 'f' && op2 == 'f') res = 'f';
                    else res = 't';
                }
                if (ops == 2) {
                    if (op1 == 't' && op2 == 't') res = 't';
                    else res = 'f';
                }
            }

        }
    }
};

int main(){
    Solution sol;
    string str = "&(t,t,f)";
    string NOT = "!(t)";
    string AND = "&(t,t,f)";
    string OR = "|(t,t,t)";

    cout << sol.parseBoolExpr(str) << endl;

    return 0;
}