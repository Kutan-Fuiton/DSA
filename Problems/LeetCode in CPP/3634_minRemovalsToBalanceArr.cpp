#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return 0;

        sort(nums.begin(), nums.end());

        int j = 0;
        int len = 0;

        for (int i = 0; i < n; i++) {
            if (j < i) j = i;

            while (j < n && (long long)nums[j] <= (long long)nums[i] * k) {
                j++;
            }

            // window is [i, j-1]
            len = max(len, j - i);
        }

        return n - len;
    }
};


int main(){
    Solution sol;
    // vector<int> nums = {2,1,5}; int k = 2;
    vector<int> nums = {1,6,2,9}; int k = 3;

    cout << sol.minRemoval(nums, k) << endl;

    return 0;
}