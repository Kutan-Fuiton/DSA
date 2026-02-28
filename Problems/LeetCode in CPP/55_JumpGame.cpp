#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MAX = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > MAX) return false;

            MAX = max(MAX, i + nums[i]);
        }
        return true;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};

    cout << sol.canJump(nums) << endl;

    return 0;
}