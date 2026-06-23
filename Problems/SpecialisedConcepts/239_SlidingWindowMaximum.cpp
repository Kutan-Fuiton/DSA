#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < n; i++){

            // Clearing those first indexes which are going out of window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // current element is larger than last element of deque, then that last element will be pop out
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // and now the current element is smaller than last element of deque, so will push_back in deque
            dq.push_back(i);

            // now, maximum elements will start to show after k elements, so from k-1, the window maximum will start appending
            if (i >= k-1){
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7}; int k = 3;

    vector<int> res = sol.maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}