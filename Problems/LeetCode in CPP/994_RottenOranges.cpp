#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> rotten_bucket; // (row, col) coord of the rotten orange

        int fresh_count = 0;

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                // inserting coords of rotten oranges in queue
                if (grid[r][c] == 2) rotten_bucket.push({r, c});

                // incrementing the fresh oranges count
                else if (grid[r][c] == 1) fresh_count++;
            }
        }

        // Edge Case: If no fresh oranges left initially
        if (fresh_count == 0) return 0;

        int mins = 0; // minutes
        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4-directions

        // Each minute, we are gonna take a screenshot of the situation and then action and then move to next minute, what do we mean by screenshot
        // For example, at first there is 2 rotten oranges, so at first, will push those two into queue, and will exactly iterate 2 times...
        // that means 2 times item will pop from queue, while processing each rotten oranges, we will make 4 directions rotten oranges too...
        // those will be pushed to the back of queue, and will be untouched for now, after processing 2 rotten, and doing action that means...
        // infecting the 4 directionsal oranges, the first minute is over, now increment the minute, and stop again... 
        // Now again taking screenshot of current queue and proceed...


        while ((!rotten_bucket.empty()) && fresh_count > 0){
            mins++;
            int len = rotten_bucket.size();

            for (int i = 0; i < len; i++){
                int r = rotten_bucket.front().first;
                int c = rotten_bucket.front().second;
                rotten_bucket.pop();

                for (const auto& dir : dirs){
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;  // Mark rotten (acts as visited)
                        fresh_count -= 1;
                        rotten_bucket.push({nr, nc});
                    }
                }
            }
        }

        return (fresh_count == 0) ? mins : -1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    cout << sol.orangesRotting(grid) << endl;
    return 0;
}