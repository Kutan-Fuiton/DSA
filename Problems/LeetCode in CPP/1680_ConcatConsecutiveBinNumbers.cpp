#include<iostream>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1000000007;
        long long res = 0;

        for (int i = 1; i <= n; i++){
            int bits = 32 - __builtin_clz(i);
            res = ((res << bits) + i) % MOD;
        }

        return (int)res;
    }
};

int main(){
    Solution sol;
    cout << sol.concatenatedBinary(12) << endl;
    return 0;
}