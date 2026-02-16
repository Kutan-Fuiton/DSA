#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        string res;
        int sum, carry = 0;
        for (int i = 0; i < n; i++){  
            int op1 = (i >= a.size()) ? 0 : (a[a.size()-1-i] - '0');
            int op2 = (i >= b.size()) ? 0 : (b[b.size()-1-i] - '0');

            sum = (op1 ^ op2) ^ carry;
            carry = (op1 & op2) | (op1 & carry) | (op2 & carry);  

            res.insert(res.begin(), sum ? '1' : '0');
        }
        
        if (carry) res.insert(res.begin(), '1');
        return res;
    }
};

int main(){
    Solution sol;

    cout << sol.addBinary("101011", "1010") << endl;

    return 0;
}