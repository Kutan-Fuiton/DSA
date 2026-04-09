#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = 1LL * nums[idx] * v % MOD;
            }
        }
        
        int XOR = 0;
        for (int x : nums) XOR ^= x;
        return XOR;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,5,4};
    vector<vector<int>> queries = {{1,4,2,3},{0,2,1,2}};

    cout << sol.xorAfterQueries(nums, queries) << endl;

    return 0;
}