#include<iostream>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1'000'000'007;

        if (n==0) return 0;
        if (n==1) return 12;

        long long type1 = 6;   // next available patterns 5
        long long type2 = 6;   // next available patterns 4

        for (int i = 2; i <= n; i++){
            long long new_type1 = (3*type1 + 2*type2) % mod;
            long long new_type2 = (2*type1 + 2*type2) % mod;

            type1 = new_type1;
            type2 = new_type2;
        }

        return ((type1 + type2) % mod);
    }
};

int main(){
    Solution sol;

    cout << sol.numOfWays(5000) << endl;


    return 0;
}