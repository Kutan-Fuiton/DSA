#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        for (int i = 0; i < nums.size()-1; i++){
            for (int j = i+1; j <= i+indexDiff && j < nums.size(); j++){
                if (abs(nums[i]-nums[j]) <= valueDiff) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,1};

    cout << sol.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;

    return 0;
}