// Here, I use 4 pointer method, where each pointer represents the 4 boundary of matrix (top, left, bottom, right)

// as we will go inserting each row or col, will shrink that boundary part by 1...
// starting the spiral from left to right(top++), top to bottom(right--), right to left(bottom--), bottom to top(left++)

// at middle, check conditions for left <= right and top <= bottom so that it doesnt overlap...


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int top = 0;
        int right = m-1;
        int bottom = n-1;
        int left = 0;

        vector<int> res;

        while (left <= right && top <= bottom){
            // left to right
            for (int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;  // shrink the top 

            // top to bottom
            for (int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;  // shrink the right

            if (top <= bottom){   // boundary check
                // right to left
                for (int i = right; i >= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;  // shrink the bottom
            }

            if (left <= right){  // boundary check
                // bottom to top
                for (int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;  // shrink the left
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> res = sol.spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}