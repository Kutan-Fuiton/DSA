#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n - 2;

        while (j >= 0 && nums[j] >= nums[j + 1]) j--;  // i got the pivot element here, where the graph drops

        if (j < 0) {            // checking whether it is descending or not, then will just reverse it and return
            reverse(nums.begin(), nums.end());
            return;
        } 

        int i = n - 1;
        while (nums[i] <= nums[j]) i--;   // setting the i, which is the smallest greater than jth element

        swap(nums[i], nums[j]);
        reverse(nums.begin() + j + 1, nums.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 4, 3, 2};

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    sol.nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }

    return 0;
}