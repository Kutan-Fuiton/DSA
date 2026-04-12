#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // storing indices
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT32_MAX;

        for (auto &p : mp){
            vector<int> indic = p.second;

            if (indic.size() < 3) continue;

            for (int i = 0; i+2 < indic.size(); i++){
                int dist = 2 * (indic[i+2] - indic [i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT32_MAX ? -1 : ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,2,3,2,1,2};
    cout << sol.minimumDistance(nums) << endl;
    return 0;
}