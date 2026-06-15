// At first i thought of calculating the product of all elems of array, and then divide by nums[i] for ith position.
// but as the division is limited, it stopped that approach...

// Now lets think the problem as, 
// every ith position is basically, (product of left side of i) * (product of right side of i)
// so in one pass (prefix pass), will calculate product of left side
// and in another pass (suffix pass), will calculate product of right side
// and then multiply it to get ith position


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // left side multiplication
        vector<int> answer;
        answer.push_back(1);
        for (int i = 1; i < n; i++){
            answer.push_back(answer[i-1]*nums[i-1]);
        }

        // right side multiplication
        int right_product = 1;
        for (int i = n-1; i >= 0; i--){
            answer[i] *= right_product;
            right_product *= nums[i];
        }
        
        return answer;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1,2,3,4};
    vector<int> nums = {-1,1,0,-3,3};

    vector<int> res = sol.productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}