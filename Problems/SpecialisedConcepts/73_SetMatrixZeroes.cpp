// Basically, at first will note, will check whether the firstrow and firstcol has zero or not, and will store it in boolean variable 

// That means, 0th row and 0th col, will get occupied for markers of "gonna be zero" rows and cols,
// So will search for zero from (1th row, 1th col) to (rows-1th row, cols-1th col),
// wherever there is zero in searching those cells, if get zero, then 0th row equivalent cell will be marked as zero, and 0th column equivalent cell will also be marked as zero...
// after traversing all cells, and its corresponding marked done in first row and first column

// Based on those marking in 0th row and 0th col, will make zero to that whole row and whole column which have zero in the cells of 0th row and 0th col respectively...

// Lastly, if 0th row have zeroes, then will make whole 0th row fill with zeroes, or if 0th col have zeroes, then will make whole 0th col fill with zeroes...


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        bool firstRowHasZero = false;
        bool firstColHasZero = false;
        
        // Check if the first row has any zeroes
        for (int c = 0; c < cols; ++c) {
            if (matrix[0][c] == 0) {
                firstRowHasZero = true;
                break;
            }
        }
        
        // Check if the first column has any zeroes
        for (int r = 0; r < rows; ++r) {
            if (matrix[r][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }
        
        // Use the first row and column as markers
        for (int r = 1; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0; // Mark row header
                    matrix[0][c] = 0; // Mark column header
                }
            }
        }
        
        // Update the inner matrix based on the markers
        for (int r = 1; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        
        // Handle the first row marker
        if (firstRowHasZero) {
            for (int c = 0; c < cols; ++c) {
                matrix[0][c] = 0;
            }
        }
        
        // Handle the first column marker
        if (firstColHasZero) {
            for (int r = 0; r < rows; ++r) {
                matrix[r][0] = 0;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    sol.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}