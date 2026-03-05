#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        return nthGen(n)[k-1];
    }

private:
    string nthGen(int n){
        if (n == 1) return "0";

        string prev = nthGen(n-1);

        string res = prev + "1";

        // invert
        transform(prev.begin(), prev.end(), prev.begin(), [](char c) {
            return (c == '0') ? '1' : '0';
        });
        // reverse
        reverse(prev.begin(), prev.end());

        res += prev;

        return res;
    }
};

int main(){
    Solution sol;

    // int num = 0;
    // cout << ~num << endl;

    cout << sol.findKthBit(4, 11) << endl;

    return 0;
}