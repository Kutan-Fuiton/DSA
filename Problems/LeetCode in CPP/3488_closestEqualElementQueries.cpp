#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, set<int>> map;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].insert(i);
        }
        for (const int& val : queries){
            res.push_back(minDist(map[nums[val]], val, nums.size()));
        }

        return res;
    }

    int minDist(const set<int>& s, int curr, int SIZE) {
        if (s.size() < 2) return -1;
        auto it = s.find(curr);
        
        int MIN = INT32_MAX;

        // before
        if (it != s.begin()) {
            int before = *prev(it);
            int d = abs(curr - before);
            MIN = min(MIN, min(d, SIZE - d));
        } else {
            // wrap to last
            int before = *s.rbegin();
            int d = abs(curr - before);
            MIN = min(MIN, min(d, SIZE - d));
        }

        // after
        if (next(it) != s.end()) {
            int after = *next(it);
            int d = abs(after - curr);
            MIN = min(MIN, min(d, SIZE - d));
        } else {
            // wrap to first
            int after = *s.begin();
            int d = abs(after - curr);
            MIN = min(MIN, min(d, SIZE - d));
        }

        return MIN;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1,3,1,4,1,3,2};
    // vector<int> queries = {0,3,5};
    vector<int> nums = {14,14,4,2,19,19,14,19,14};
    vector<int> queries = {2,4,8,6,3};

    vector<int> res = sol.solveQueries(nums, queries);

    for (const int val : res){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}