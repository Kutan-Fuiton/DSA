#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};


int main(){
    Solution sol;
    // vector<vector<int>> intervals = {{1,2}, {3,5}, {6,7}};
    // vector<vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8, 10}, {12,16}};
    // vector<int> newInterval = {4,8};
    // vector<vector<int>> intervals = {{1,3}, {6,9}};
    // vector<int> newInterval = {4,5};
    // vector<vector<int>> intervals = {{1,3}, {6,9}};
    // vector<int> newInterval = {10, 11};
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {2,7};

    vector<vector<int>> res = sol.insert(intervals, newInterval);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}