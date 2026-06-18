// Well, we can easily solve this problem by taking another dummy array, and then take n-k to n-1 at first, and then 0 to n-k-1 at second, and completely filled the array, but ofc it takes O(n) SC besides O(n) TC.

// But here, for O(n) TC and O(1) SC approach, we will use `Triple reversal algorithm`.
// First Reversal: reverse the complete array from 0 to n-1
// Second Reversal: reverse the complete array from 0 to n-k-1
// Third Reversal: reverse the complete array from n-k to n-1

//1,2,3,4,5,6,7

//7,6,5,4,3,2,1  --> first reversal 
//5,6,7,4,3,2,1  --> second reversal 
//5,6,7,1,2,3,4  --> third reversal

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // k >= n
        k = k % n; 

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7}; int k = 3;

    sol.rotate(nums, k);

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}