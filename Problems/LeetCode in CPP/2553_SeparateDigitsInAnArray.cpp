#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        deque<int> deq;

        for (int i = nums.size()-1; i >= 0; i--){
            int num = nums[i];

            while (num != 0){
                deq.push_front(num%10);
                num /= 10;
            }
        }

        return vector<int> (deq.begin(), deq.end());
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {13,25,83,77};
    vector<int> nums = {7,1,3,9};

    vector<int> res = sol.separateDigits(nums);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}