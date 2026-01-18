#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();                            
        int n = grid[0].size();                         
        int k = min(m, n);                              

        if (k == 0) return 0;
        if (k == 1) return 1;

        while (k >= 2) { 
            for (int i = 0; i <= m - k; i++) {          
                for (int j = 0; j <= n - k; j++) {      
                    if (magic(grid, i, j, k)) {
                        return k;
                    } 
                }
            }
            k--;
        }
        return 1;   
    }

private:
    bool magic(vector<vector<int>>& grid, int x, int y, int k) {
        int target = 0;

        // target sum (first row)
        for (int i = y; i < y + k; i++) {
            target += grid[x][i];
        }

        // row sums
        for (int i = x + 1; i < x + k; i++) {
            int rowSum = 0;
            for (int j = y; j < y + k; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != target) {
                return false;
            }
        }

        // column sums
        for (int j = y; j < y + k; j++) {
            int colSum = 0;
            for (int i = x; i < x + k; i++) {
                colSum += grid[i][j];
            }
            if (colSum != target) {
                return false;
            }
        }

        // main diagonal
        int diag = 0;
        for (int i = 0; i < k; i++) {
            diag += grid[x + i][y + i];
        }

        // anti-diagonal
        int antidiag = 0;
        for (int i = 0; i < k; i++) {
            antidiag += grid[x + i][y + k - 1 - i];
        }

        if (diag != target || antidiag != target) {
            return false;
        }

        return true;
    }
};


int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {7, 1, 4, 5, 6},
        {2, 5, 1, 6, 4},
        {1, 5, 4, 3, 2},
        {1, 2, 7, 3, 4},
        {4, 3, 2, 1, 5}
    };

    cout << sol.largestMagicSquare(grid) << endl;
    // cout << sol.magic(grid, 1, 1, 3);

    return 0;
}