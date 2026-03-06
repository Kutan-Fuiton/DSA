#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        int special = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    special++;
                }
            }
        }
        
        return special;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat = {
        {1,0,0,0},
        {0,0,1,0},
        {0,1,1,0},
        {0,0,0,1}
    };

    cout << sol.numSpecial(mat) << endl;

    return 0;
}