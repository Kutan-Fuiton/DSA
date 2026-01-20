#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (const int& n : nums){
            if (n == 2) res.push_back(-1);
            else res.push_back(ans(n));
        }
        return res;
    }

private:
    int ans(int n){
        int count = 1;
        int x = n;  
        while ((x & 1) == 1) {  
            count*=2;
            x >>= 1;  
        }
        count/=2;
        return (n - count);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 3, 5, 7, 11, 13, 31};

    vector<int> res = sol.minBitwiseArray(nums);
    for (const int num : res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}