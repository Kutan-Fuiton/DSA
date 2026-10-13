#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1000000007;

        vector<int> bit_count(31, 0);
        for (const int num : nums){
            for (int b = 0; b < 31; ++b){
                if ((num>>b) & 1){
                    bit_count[b]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; ++i){
            long long val = 0;
            for (int b = 0; b < 31; b++){
                if (bit_count[b] > 0){
                    val = val | (1LL << b);
                    bit_count[b]--;
                }
            }
            ans = (ans + (val * val) % MOD) % MOD;
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,6,5,8};

    cout << sol.maxSum(nums, 2) << endl;
    return 0;
}