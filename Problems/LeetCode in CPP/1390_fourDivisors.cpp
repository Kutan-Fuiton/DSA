#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (const int &num : nums){
            if (hasExactlyFourDivisors(num)){
                res += 1 + num;
                for (int i = 2; i <= num; i++){
                    if (num%i == 0){
                        res += i+(num/i);
                        break;
                    }
                }
            }
        }
        return res;
    }

private: 
    // O(√n) algorithm
    bool hasExactlyFourDivisors(int n) {
        // Numbers with exactly 4 divisors are either:
        // 1. p³ (cube of a prime) → divisors: 1, p, p², p³
        // 2. p*q (product of two distinct primes) → divisors: 1, p, q, p*q
        if (n < 6) return false;  
        
        int divisors = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors++;
                if (i != n / i) {  
                    divisors++;
                }
                if (divisors > 4) return false;
            }
        }
        
        return divisors == 4;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {21, 21};
    vector<int> nums = {21,4,7};

    cout << sol.sumFourDivisors(nums) << endl;
    // cout << sol.hasExactlyFourDivisors(10) << endl;

    return 0;
}