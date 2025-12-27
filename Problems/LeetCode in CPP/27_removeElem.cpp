#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int i = 0, j = nums.size() - 1;
        int count = 0;
        while (i < j){
            if (nums[i] == val && nums[j] == val){
                j--; count++;
            } else if (nums[i] == val && nums[j] != val) {
                swap(nums[i], nums[j]);
                i++; j--; count++;
            } else {
                i++;
            }
        }
        if (i == j && nums[i] == val){count++;}
        return (nums.size() - count);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    cout << sol.removeElement(nums, val) << endl;

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }

    return 0;
}