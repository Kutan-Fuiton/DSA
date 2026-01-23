// __builtin_ctz(x) counts trailing zeros in binary representation of x
// In this program, how will it work...
// if i have to count number of trailing ones in binary representation of 'n'
// let n = ......011111
// what we will do, we will add 1 to n, then every consecutive 1 will become zero from right, and first 0 will become 1, like this 
// n + 1 = ......100000, now here the number of trailing zeroes is equal to no of trailing 1s we need
// so will apply __builtin_ctz(n+1)

// On the next step, i have to return (n - 2^(k-1))
// we know that, (1 << x) means 2^x, instead of 2^(k-1) will replace by (1 << (k-1))
// that's it, (n - (1 << (k-1)))


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size());

        for (int n : nums) {
            if (n == 2 || (n & 1) == 0) {
                res.push_back(-1);
            } else {
                int k = __builtin_ctz(n + 1);
                res.push_back(n - (1 << (k - 1)));
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 3, 5, 7, 11, 13, 31};

    vector<int> res = sol.minBitwiseArray(nums);
    for (const int num : res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}