#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int i = 0;
        while (i <= max(n-start-1, start-0)){
            if ((start + i < nums.size() && nums[start + i] == target) || (start - i >= 0 && nums[start-i] == target)) return i;
            i++;
        }

        return 0;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1,2,3,4,5};
    // int target = 5, start = 3;

    vector<int> nums = {1};
    int target = 1, start = 0;

    cout << sol.getMinDistance(nums, target, start);
    return 0;
}