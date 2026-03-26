#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";

        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '0')
                res += '1';
            else
                res += '0';
        }

        return res;
    }
};

int main(){
    Solution sol;
    // vector<string> nums = {"010", "001", "000", "100", "111", "110", "101"};
    vector<string> nums = {"00", "01"};

    cout << sol.findDifferentBinaryString(nums) << endl;
    // sol.findDifferentBinaryString(nums);

    return 0;
}