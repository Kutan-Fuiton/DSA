#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxNum(n);
        vector<int> minNum(n);

        maxNum[0] = nums[0]; minNum[n-1] = nums[n-1];

        // calculating the maximum of all indexes from the left to i
        // calculating the minimum of all indexes from the right to i
        for (int i = 1; i < n; ++i){
            maxNum[i] = (nums[i] > maxNum[i-1]) ? nums[i] : maxNum[i-1];
            minNum[n-i-1] = (nums[n-i-1] < minNum[n-i]) ? nums[n-i-1] : minNum[n-i];
        }

        for (int i = 0; i < n; ++i) if (maxNum[i] - minNum[i] <= k) return i;

        return -1;
    }
};


        // For testing purpose
        // for (int i = 0; i < n; ++i){
        //     cout << maxNum[i] << "   " << minNum[i] << endl;
        // }

int main(){
    Solution sol;
    // vector<int> nums = {5, 0, 1, 4}; int k = 3;
    // vector<int> nums = {3, 2, 1}; int k = 1; 
    vector<int> nums = {0}; int k = 0; 

    cout << sol.firstStableIndex(nums, k);
    return 0;
}