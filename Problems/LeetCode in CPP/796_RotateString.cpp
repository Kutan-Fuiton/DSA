#include<iostream>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.empty() && goal.empty()) return true;
        
        if (s.length() != goal.length())  return false;
        
        string doubled = s + s;
        
        // string::npos means "not found"
        return doubled.find(goal) != string::npos;
    }
};

int main(){
    Solution sol;
    cout << sol.rotateString("abcde", "abced") << endl;
    return 0;
}