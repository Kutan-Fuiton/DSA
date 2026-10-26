#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0) {
                    long long totalSum = 0;
                    queue<pair<int, int>> q;

                    q.push({i, j});
                    totalSum += grid[i][j];
                    grid[i][j] = 0; // Mark visited

                    while (!q.empty()) {
                        auto cell = q.front();
                        int r = cell.first;
                        int c = cell.second;
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int nr = r + dRow[d];
                            int nc = c + dCol[d];

                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] > 0) {
                                totalSum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark visited immediately to prevent duplicate enqueuing
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (totalSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };

    cout << sol.countIslands(grid, 5) << endl;
    return 0;
}