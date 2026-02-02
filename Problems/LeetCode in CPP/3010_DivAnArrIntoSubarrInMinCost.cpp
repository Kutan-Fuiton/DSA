#include<iostream>
#include<vector>
using namespace std;


// O(n^2) algorithm

// class Solution {
// public:
//     int minimumCost(vector<int>& nums) {
//         int MIN = INT32_MAX;
//         for (int i = 1; i < nums.size()-1; i++){
//             for (int j = i+1; j < nums.size(); j++){
//                 MIN = min(MIN, nums[0]+nums[i]+nums[j]);
//             }
//         }
//         return MIN;
//     }
// };


// O(n) algorithm - finding two minimum number in the array except the first number...

class Solution {
public:
    int minimumCost(vector<int>& nums) {

        // First Minimum
        int MIN = INT32_MAX;
        int idx;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < MIN){
                MIN = nums[i];
                idx = i;
            }
        }

        // Second Minimum
        int Min = INT32_MAX;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < Min && i != idx) Min = nums[i];
        }

        return nums[0]+MIN+Min;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,12};
    // vector<int> nums = {10,3,1,1,5,7,2,3};

    cout << sol.minimumCost(nums) << endl;

    return 0;
}