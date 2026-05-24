#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int drop = 0; 
        int n = nums.size();

        for (int i = 1; i < n; i++){
            if (nums[i] < nums[i-1]) drop++;
            if (drop > 1) return false;
        }

        if ((drop == 1) && nums[0] >= nums[n-1]) return true;
        else if ((drop == 0) && nums[0] <= nums[n-1]) return true;
        else return false;
    }
};

int main(){
    Solution sol;

    vector<int> nums1 = {3,4,5,1,2};
    vector<int> nums2 = {2,1,3,4};
    vector<int> nums3 = {1,2,3};
    vector<int> nums4 = {2,1};

    cout << sol.check(nums1) << endl;
    cout << sol.check(nums2) << endl;
    cout << sol.check(nums3) << endl;
    cout << sol.check(nums4) << endl;

    return 0;
}