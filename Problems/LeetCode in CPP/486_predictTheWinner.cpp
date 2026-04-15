// recursively performing maximum from last game to first game


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() -1) >= 0;
    }

    int solve(vector<int>& nums, int i, int j){
        if (i > j) return 0;
        
        // Pick left: gain nums[i], then opponent gets solve(i+1, j)
        int left = nums[i] - solve(nums, i+1, j);
        
        // Pick right: gain nums[j], then opponent gets solve(i, j-1)
        int right = nums[j] - solve(nums, i, j-1);
        
        return max(left, right);
    } 
};

int main(){
    Solution sol;
    vector<int> nums = {1,5,233,7};

    cout << sol.predictTheWinner(nums) << endl;
    return 0;
}