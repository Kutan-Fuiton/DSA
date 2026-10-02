#include<iostream>
#include<vector>
using namespace std;

// A dfs will work maintaining each cell's state, will check each cell's row number, column number and balance of that cell
// We will calculate each cell's balance like, balance can't be negative, cant't be more thant (m+n)/2, like this
// dfs will work only two way, either right or down, so this is how it will calculate possibility...

class Solution {
    int m, n;
    bool visited[101][101][101];

    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid) {
        // increment decrement balance
        bal += (grid[r][c] == '(' ? 1 : -1);

        // balance cannot be negative
        if (bal < 0) return false;

        // if remaining steps < bal, then it isnt possible to have a valid path
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (bal > remaining_steps) return false;

        // Base case: reached bottom right cell
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        // if this state was already explored and failed
        if (visited[r][c][bal]) return false;
        visited[r][c][bal] = true;

        // move right
        if (c + 1 < n && dfs(r, c + 1, bal, grid)) return true;

        // move down
        if (r + 1 < m && dfs(r + 1, c, bal, grid)) return true;

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m+n-1)%2 != 0) return false;

        // Start must be '(' and end must be ')'
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') return false;

        // reset visited table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n) / 2; ++k) {
                    visited[i][j][k] = false;
                }
            }
        }

        return dfs(0, 0, 0, grid);
    }
};

int main(){
    return 0;
}