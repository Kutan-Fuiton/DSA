#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (!isSorted(nums)) {
            int min_sum = INT32_MAX;
            int min_idx = 0;

            // find min adjacent sum
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] + nums[i + 1] < min_sum) {
                    min_sum = nums[i] + nums[i + 1];
                    min_idx = i;
                }
            }

            // merge pair
            nums[min_idx] += nums[min_idx + 1];

            // shift left
            for (int i = min_idx + 1; i < nums.size() - 1; i++) {
                nums[i] = nums[i + 1];
            }

            nums.pop_back(); 

            for (const int& num : nums){
                cout << num << " ";
            }
            cout << endl;
            count++;
        }

        return count;
    }

private:
    bool isSorted(const vector<int>& nums) {
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {5,2,3,1};

    cout << sol.minimumPairRemoval(nums) << endl;

    return 0;
}