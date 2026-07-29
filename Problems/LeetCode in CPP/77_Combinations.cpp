#include<iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (int i = start; i <= n; ++i) {
            current.push_back(i);              
            backtrack(i + 1, n, k, current, result); 
            current.pop_back();               
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};
// {{1,2,3}, {1,2,4}, {1,2,5}, {1,3,4}, {1,3,5}, {1,4,5}, {2,3,4}, {2,3,5}, {2,4,5}, {3,4,5}}
// n = 5, k = 3

int main(){
    Solution sol;
    vector<vector<int>> res = sol.combine(5,3);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}