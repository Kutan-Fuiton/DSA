#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;

        for (int i = 0; i < n; i++){
            int start = nums[i];

            // if consecutive
            while (i + 1 < n && nums[i+1] == nums[i] + 1) i++;

            // if not consecutive
            // 1. check whether, it ended as isolated or not...
            if (start == nums[i]){
                res.push_back(to_string(start));
            } 

            // 2. its not isolated, after a long consecutive range, it ended...
            else {
                res.push_back(to_string(start)+"->"+to_string(nums[i]));
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,1,2,4,5,7};

    vector<string> res = sol.summaryRanges(nums);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}