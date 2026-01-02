#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] == nums[i+1]){
                return nums[i];
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,1,2,5,3,2};

    cout << sol.repeatedNTimes(nums) << endl;

    return 0;
}