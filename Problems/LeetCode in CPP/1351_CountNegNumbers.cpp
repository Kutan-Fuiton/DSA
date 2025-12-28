#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // This is O(n.m) algorithm
    // int countNegatives(vector<vector<int>>& grid) {
    //     int count = 0;
    //     for (int i = 0; i < grid.size(); i++){
    //         for (int j = 0; j < grid[i].size(); j++){
    //             if (grid[i][j] < 0){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
    
    // To make it O(n+m) algorithm
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int row = m - 1;
        int col = 0;
        
        while(row >= 0 && col < n) {
            if(grid[row][col] < 0) {
                count += (n - col);
                row--;  
            } else {
                col++; 
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {
        {4,3,2,-1},
        {3,2,1,-1},
        {1,1,-1,-2},
        {-1,-1,-2,-3}
    };

    cout << sol.countNegatives(grid) << endl;

    return 0;
}