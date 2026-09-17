#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int total_n = n + k - 1;
        int total_r = 2 * k;

        if (total_r > total_n) return 0;

        long long num = 1;
        long long den = 1;

        auto power = [&](long long base, long long exp) -> long long {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        // if i find (num/den)%mod, then in num/den we will loose the denominator portion already, so to avoid that
        // We will use the Fermat's little theorem which states that
        // If M is a prime number and n is not divisible by M, then:     (n^(M-1)) % M = 1
        // now multiplying with n^(-1) in both sides, we get,     (n^(M-2)) % M = n^(-1)
        // so basically what we will do is, instead of doing (num/den)%mod ==> (num * den^(-1))%mod
        // This den^(-1) = den^(MOD - 2) % MOD   --> ModInverse
        auto modInverse = [&](long long n) -> long long {
            return power(n, MOD - 2);
        };

        for (int i = 0; i < total_r; ++i) {
            num = (num * (total_n - i)) % MOD;  // -> numerator modded
            den = (den * (i + 1)) % MOD;        // -> denominator modded
        }

        // (num * den^(-1)) % mod
        return (num * modInverse(den)) % MOD;
    }
};

int main(){
    Solution sol;
    cout << sol.numberOfSets(30, 7) << endl;
    return 0;
}