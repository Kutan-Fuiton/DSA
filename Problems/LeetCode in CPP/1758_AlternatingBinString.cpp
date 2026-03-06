#include<iostream>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ch0 = 0;
        
        for (int i = 0; i < n; i++) {
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) ch0++;
        }
        
        return min(ch0, n - ch0);
    }
};

int main(){
    Solution sol;
    cout << sol.minOperations("11110110") << endl;
    return 0;
}