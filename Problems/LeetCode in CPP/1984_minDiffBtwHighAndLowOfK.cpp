#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int MIN = INT32_MAX;
        for (int i = 0; i <= n-k; i ++){
            MIN = min(MIN, nums[i+k-1]-nums[i]);
        }  
        return MIN;  
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {9,4,1,7}; int k = 2;
    // vector<int> nums = {90}; int k = 1;
    vector<int> nums = {}; int k = 1;

    cout << sol.minimumDifference(nums, k) << endl;

    return 0;
}