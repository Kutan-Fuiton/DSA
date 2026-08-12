#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.size();
        
        while (i < n && s[i] == ' ') {i++;}
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        int res = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            
            if (res > (INT32_MAX - digit) / 10) return (sign == 1) ? INT32_MAX : INT32_MIN;
            
            res = res * 10 + digit;
            i++;
        }
        
        return res * sign;
    }
};

int main(){
    Solution sol;
    cout << sol.myAtoi("   -000456700  ") << endl;
    return 0;
}