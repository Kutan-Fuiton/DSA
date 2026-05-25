#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++){
                if (grid[r][c] == '1'){
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int m = grid.size();
        int n = grid[0].size();

        // boundaries plus water check
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') return;

        // mark visited
        grid[r][c] = '0';

        // search adjacent cells
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << sol.numIslands(grid) << endl;

    return 0;
}