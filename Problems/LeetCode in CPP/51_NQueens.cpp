// Board will store each queens col number row wise, 
// like row 0 will have queen in col 1, so board[0] = 1, row 1 will have queen in col 3, so board[1] = 3, like this ...
// So in Board vector, it stores the position of queen in row:col manner, that means index i is row and its value is column
// Board[i] -> col and i -> row

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<int> board(n, -1);
        solve(res, board, 0, n);

        return res;
    }

private:
    // Check if a queen can be placed at (row, col)
    bool isSafe(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            
            // Same column
            if (board[i] == col) return false;

            // Same diagonal
            if (abs(board[i] - col) == abs(i - row)) return false;
        }
        return true;
    }

    // It solves rowwise...
    void solve(vector<vector<string>>& res, vector<int>& board, int row, int N) {

        // Base case: all queens placed
        if (row == N) {
            res.push_back(output(board, N));
            return;
        }

        // Try every column in current row
        for (int col = 0; col < N; col++) {

            if (isSafe(board, row, col)) {

                board[row] = col; // Place queen
                solve(res, board, row + 1, N); // Move to next row
                board[row] = -1; // Backtrack
            }
        }
    }

    vector<string> output(vector<int>& board, int N){
        vector<string> res(N, string(N, '.'));
        for (int i = 0; i < N; i++){
            res[i][board[i]] = 'Q';
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(5);

    for (int i = 0; i < res.size(); i ++){
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << endl;
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}