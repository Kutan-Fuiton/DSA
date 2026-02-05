#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false; 
        
        int crit = 0;
        bool up = true;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) return false; 
            
            if (nums[i] > nums[i-1]) {
                if (!up) {
                    crit++;
                    up = true;
                }
            } else { 
                if (up) {
                    crit++;
                    up = false;
                }
            }
        }
        
        return crit == 2 && nums[1] > nums[0];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,5,4,2,6};

    cout << sol.isTrionic(nums) << endl;

    return 0;
}