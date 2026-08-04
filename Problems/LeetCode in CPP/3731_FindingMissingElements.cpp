#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++){
            int diff = nums[i]-nums[i-1];

            if (diff > 1){
                int adder = nums[i-1];
                while(diff != 1){
                    res.push_back(++adder);
                    diff--;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {9,10,4,7,2,5};
    vector<int> nums = {5,1};

    vector<int> res = sol.findMissingElements(nums);
    for (const int& num : res){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}