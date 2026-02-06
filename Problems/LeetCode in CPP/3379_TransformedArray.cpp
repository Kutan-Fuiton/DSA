#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int j = ((i + nums[i]) % n + n) % n;
            res.push_back(nums[j]);
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,-2,1,1};

    vector<int> res = sol.constructTransformedArray(nums);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}