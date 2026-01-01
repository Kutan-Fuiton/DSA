#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int count = 0;
//         for (int i = 0; i <= grid.size()-3; i++){
//             for (int j = 0; j <= grid[i].size()-3; j++){
//                 if (checkMagic(grid, i, j)) {
//                     cout << "(" << i << "," << j << ")" << endl;
//                     for(int m = i; m < i+3; m++){
//                         for (int n = j; n < j+3; n++){
//                             cout << grid[m][n] << " ";
//                         }
//                         cout << endl;
//                     }
//                     cout << endl;

//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

//     bool checkMagic(vector<vector<int>>& grid, int x, int y){
//         vector<int> sum;
//         int ref;
//         int diag1 = 0, diag2 = 0;
//         for (int i = 0; i < 3; i++){
//             int row = 0, col = 0;
//             for (int j = 0; j < 3; j++){
//                 row += grid[x+i][y+j];
//                 col += grid[y+j][x+i];
//                 if (i == j) diag1 += grid[x+i][y+j];
//                 if (i + j == 2) diag2 += grid[x+i][y+j];
//             }
//             if (i == 0){
//                 ref = row;
//                 sum.push_back(row);
//                 sum.push_back(col);
//             } else {
//                 if (ref == row) sum.push_back(row);
//                 else return false;
//                 if (ref == col) sum.push_back(col);
//                 else return false;
//             }
//         }
//         if (ref == diag1) sum.push_back(diag1);
//         else return false;
//         if (ref == diag2) sum.push_back(diag2);
//         else return false;
        
//         return true;
//     }
// };

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        for (int i = 0; i <= grid.size()-3; i++){
            for (int j = 0; j <= grid[i].size()-3; j++){
                
            }
        }
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> grid = {{8,1,6,8},{3,5,7,3},{4,9,2,4}};
    // vector<vector<int>> grid = {{4,3,8,4,3},{9,5,1,9,5},{2,7,6,2,7},{4,3,8,4,3},{9,5,1,9,5}};
    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    // vector<vector<int>> grid = {{4,3,8},{9,5,1},{2,7,6}};
    
    cout << sol.numMagicSquaresInside(grid) << endl;
    // cout << sol.checkMagic(grid, 0, 0) << endl;
    
    // vector<int> res;
    // res = sol.checkMagic(grid);
    // for (int num : res){
    //     cout << num << " ";
    // }

    return 0;
}