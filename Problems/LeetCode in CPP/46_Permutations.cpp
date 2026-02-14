#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, used, curr, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& res) {
        
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);

            backtrack(nums, used, curr, res);

            // Backtrack
            curr.pop_back();
            used[i] = false;
        }
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = sol.permute(nums);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}