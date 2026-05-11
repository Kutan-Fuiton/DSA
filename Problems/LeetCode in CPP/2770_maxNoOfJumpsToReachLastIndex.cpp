#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = 0; // first step

        for (int i = 1; i < n; i++){
            int MAX = -1;

            for (int j = 0; j < i; j++){
                if (dp[j] == -1) continue;
                if (abs(nums[j]-nums[i]) <= target) MAX = max(MAX, dp[j]+1);
            }

            dp[i] = MAX;
        }

        return dp[n-1];
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1,3,6,4,1,2}; int target = 2;
    vector<int> nums = {1,3,6,4,1,2}; int target = 0;
    
    cout << sol.maximumJumps(nums, target) << endl;

    return 0;
}