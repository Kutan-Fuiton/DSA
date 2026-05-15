#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int MAX = 0;

        vector<int> arr(n-1, 0);

        for (const int& num : nums){
            if (num > n-1) return false;
            arr[num-1]++;
            MAX = max(MAX, num);
        }

        // check the size
        if (MAX != n-1) return false;

        // check
        for (int i = 0; i < n-1; i++){
            if (((i != n - 2) && (arr[i] != 1)) || ((i == n -2) && arr[i] != 2)) return false;
        }

        return true;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1, 1};
    // vector<int> nums = {1, 3, 3, 2};
    vector<int> nums = {2, 1, 3};

    cout << sol.isGood(nums) << endl;
    return 0;
}