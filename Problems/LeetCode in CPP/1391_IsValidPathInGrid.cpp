#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, vector<pair<int,int>>> dirs;
        dirs[1] = {{0,-1}, {0,1}};
        dirs[2] = {{-1,0}, {1,0}};
        dirs[3] = {{0,-1}, {1,0}};
        dirs[4] = {{0,1}, {1,0}};
        dirs[5] = {{0,-1}, {-1,0}};
        dirs[6] = {{0,1}, {-1,0}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        q.push(make_pair(0, 0));
        visited[0][0] = true;

        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            if (r == m - 1 && c == n - 1)
                return true;

            vector<pair<int,int>> moves = dirs[grid[r][c]];

            for (int i = 0; i < moves.size(); i++) {   // trying both directions for street
                int dr = moves[i].first;
                int dc = moves[i].second;

                int nr = r + dr;
                int nc = c + dc;

                // check next one is not out of bound and check we not meeting visited cell again or not
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {

                    vector<pair<int,int>> next = dirs[grid[nr][nc]];

                    for (int j = 0; j < next.size(); j++) {
                        int ndr = next[j].first;
                        int ndc = next[j].second;

                        if (ndr == -dr && ndc == -dc) {
                            visited[nr][nc] = true;
                            q.push(make_pair(nr, nc));
                            break;
                        }
                    }
                }
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> grid = {{1,2,1},{1,2,1}};
    vector<vector<int>> grid = {{2,4,3},{6,5,2}};

    cout << sol.hasValidPath(grid) << endl;
    return 0;
}