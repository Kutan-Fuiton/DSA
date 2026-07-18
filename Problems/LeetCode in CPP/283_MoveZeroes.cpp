#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for (const int num : nums){
            if (num == 0) zeroCount++;
        }
        int j = 0; 
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                swap(nums, j, i);
                j++;
            }
        }
    }

private: 
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(){
    Solution sol; 
    vector<int> nums = {0,1,0,3,12};

    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }cout << endl;

    return 0;
}