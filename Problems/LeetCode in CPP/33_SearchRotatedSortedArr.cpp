#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while (low <= high){
            int mid = low + (high - low)/2;

            // if target found, then return it's index
            if (nums[mid] == target){
                return mid;
            }

            // if left half sorted
            if (nums[low] <= nums[mid]){
                if (target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // else right half sorted
            else {
                if (target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {4,5,6,7,0,1,2}; int target = 0;
    vector<int> nums = {5,1,3}; int target = 3;

    cout << sol.search(nums, target) << endl;
    return 0;
}