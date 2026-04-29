#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> flatten;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                flatten.push_back(grid[i][j]);
            }
        }
        sort(flatten.begin(), flatten.end());

        int median = flatten[(m*n)/2];

        int total = 0;
        int rem = flatten[0] % x;
        for (int i = 0; i < (m*n); i++){
            if (flatten[i] % x != rem) return -1;
            total += abs(flatten[i]-median)/x;
        }

        return total;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,5},{2,3}};

    cout << sol.minOperations(grid, 1) << endl;

    return 0;
}