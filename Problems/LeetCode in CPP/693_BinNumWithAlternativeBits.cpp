// Ok there is an approach, at first, first right shift then check for alternative 0 and 1, but yess, if we right shift the original number and then XOR with the original number, everything will give 11111111....

// n = 10101010
// n >> 1 = 01010101

// XORing both, we gets, 11111111

// and the condition for checking, all 1s is (x & (x+1)) == 0

#include<iostream>
using namespace std;

// class Solution {
// public:
//     bool hasAlternatingBits(int n) {
//         long long x = n ^ (n >> 1);
//         return (long long) (x & (x + 1)) == 0;
//     }
// };

// my first approach was right...

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n >>= 1;
        while (n > 0) {
            int curr = n & 1;
            if (curr == prev) return false;
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};

int main(){
    Solution sol;
    cout << sol.hasAlternatingBits(5) << endl;
    return 0;
}