#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        // calculating base function F(0)
        int func = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            func += (i * nums[i]);
            sum += nums[i];
        }

        int MAX = func;

        for (int i = 1; i < n; i++){
            int function = func + sum - (n * nums[n-i]);

            MAX = max(MAX, function);
            func = function;
        }

        return MAX;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,3,2,6};
    // vector<int> nums = {100};
    cout << sol.maxRotateFunction(nums) << endl;
    return 0;
}