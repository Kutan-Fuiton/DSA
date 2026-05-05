#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9]; // creating 9 seperate sets for 9 rows
        unordered_set<char> col[9]; // creating 9 seperate sets for 9 cols
        unordered_set<char> box[9]; // creating 9 seperate sets for 9 (3x3) boxes

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char cell = board[i][j];

                if (cell == '.') continue;

                if (row[i].count(cell)) return false;
                row[i].insert(cell);

                if (col[j].count(cell)) return false;
                col[j].insert(cell);

                int boxIndex = (i / 3) * 3 + (j / 3);
                if (box[boxIndex].count(cell)) return false;
                box[boxIndex].insert(cell);
            }
        }

        return true;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << sol.isValidSudoku(board) << endl;

    return 0;
}