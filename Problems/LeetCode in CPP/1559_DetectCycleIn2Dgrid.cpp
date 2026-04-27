#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited)) return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[x][y] = true;

        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // boundary check
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            // same value check
            if (grid[nx][ny] != grid[x][y]) continue;

            // case 1: not visited
            if (!vis[nx][ny]) {
                if (dfs(nx, ny, x, y, grid, vis)) return true;
            }
            // case 2 & 3: visited
            else if (nx != px || ny != py) {
                // visited and not parent → cycle
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {
        {'B','A','A','A','A'},
        {'B','A','B','A','A'},
        {'A','A','B','B','A'},
        {'B','A','B','B','A'},
        {'B','A','A','A','A'}
    };

    cout << sol.containsCycle(grid) << endl;

    return 0;
}