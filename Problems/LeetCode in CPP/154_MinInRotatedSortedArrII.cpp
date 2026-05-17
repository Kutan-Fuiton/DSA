#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // minimum in right half
            if (nums[mid] > nums[right])  left = mid + 1;

            // minimum in left half
            else if (nums[mid] < nums[left])  right = mid;

            // duplicate case
            else right--;
        }

        return nums[left];
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1,3,5};
    // vector<int> nums = {2,2,2,0,1};
    // vector<int> nums = {4, 5, 6, 6, 7, 2, 2, 3, 3, 3};
    vector<int> nums = {3, 3, 1, 3};
    // vector<int> nums = {1, 3, 3};

    cout << sol.findMin(nums) << endl;
    return 0;
}