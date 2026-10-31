#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int MOD = 1000000007;
        int m = grid.size(), n = grid[0].size();

        // Edge case
        if (m == 1 && n == 1) return 1;

        vector<vector<int>> right_in(m, vector<int>(n, 0));
        vector<vector<int>> top_in(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // Starting cell {0, 0}
                if (r == 0 && c == 0) {
                    if (c + 1 < n) {
                        right_in[r][c + 1] = (right_in[r][c + 1] + 1) % MOD;
                    }
                    if (r + 1 < m) { 
                        top_in[r + 1][c] = (top_in[r + 1][c] + 1) % MOD;
                    }
                    continue; 
                }

                // Normal empty cell
                if (grid[r][c] == 0) {
                    int total = (right_in[r][c] + top_in[r][c]) % MOD;
                    if (total == 0) continue;

                    if (c + 1 < n) {
                        right_in[r][c + 1] = (right_in[r][c + 1] + total) % MOD;
                    }
                    if (r + 1 < m) {
                        top_in[r + 1][c] = (top_in[r + 1][c] + total) % MOD;
                    }
                } 
                // Mirror cell
                else {
                    // Moving right -> turned down
                    if (r + 1 < m && right_in[r][c] > 0) {
                        top_in[r + 1][c] = (top_in[r + 1][c] + right_in[r][c]) % MOD;
                    }
                    // Moving down -> turned right
                    if (c + 1 < n && top_in[r][c] > 0) {
                        right_in[r][c + 1] = (right_in[r][c + 1] + top_in[r][c]) % MOD;
                    }
                }
            }
        }

        return (right_in[m - 1][n - 1] + top_in[m - 1][n - 1]) % MOD;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    
    cout << sol.uniquePaths(grid) << endl;
    return 0;
}