#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int MAX = 0; 
        for (int i = 0; i < n/2; i++){
            MAX = max(MAX, nums[i] + nums[n-i-1]);
        }
        return MAX;
    }
};

int main(){
    Solution sol;
    // vector<int> nums ={3,5,4,2,4,6};
    vector<int> nums ={3,5,2,3};

    cout << sol.minPairSum(nums) << endl;

    return 0;
}