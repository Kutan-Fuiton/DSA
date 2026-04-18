#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> map;
        int MIN = INT32_MAX;
        for (int i = 0; i < nums.size(); i++){
            
            if (map.count(nums[i])){
                MIN = min(MIN, i - map[nums[i]]);
            }
            
            int rev = reverse(nums[i]);
            map[rev] = i;
        }

        return MIN == INT32_MAX ? -1 : MIN;
    }

private:
    int reverse(int a){
        int rev = 0;
        while (a > 0){
            rev = rev*10 + (a%10);
            a /= 10;
        }

        return rev;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {12,21,45,33,54};
    // vector<int> nums = {21,120};
    vector<int> nums = {120,21};

    cout << sol.minMirrorPairDistance(nums) << endl;
    
    return 0;
}