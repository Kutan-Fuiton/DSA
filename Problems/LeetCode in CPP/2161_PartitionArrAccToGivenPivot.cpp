#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        
        // first pass : all less element in left side
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < pivot){
                res.push_back(nums[i]);
            }
        }
        
        // second pass : all equal element in left side
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == pivot){
                res.push_back(nums[i]);
            }
        }
        
        // third pass : all more element in left side
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > pivot){
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {9,12,5,10,14,3,10}; int pivot = 10;

    vector<int> res = sol.pivotArray(nums, pivot);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}