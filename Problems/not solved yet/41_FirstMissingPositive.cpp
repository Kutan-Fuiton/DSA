#include<iostream>
#include<vector>
#include<algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min = INT32_MAX;
        int max = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0 && nums[i] < min){
                min = nums[i];
            }
            if (nums[i] > 0 && nums[i] > max){
                max = nums[i];
            }
        }
        if (min != 1) return 1;
        int i = 0;
        while (i < nums.size() && min == 1){

        }
        
    }
};

int main(){
    Solution sol;
    vector<int> nums = {};

    cout << sol.firstMissingPositive(nums) << endl;

    return 0;
}