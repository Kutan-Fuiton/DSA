#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int j = 0;

            while (j < n) {

                int k = j;
                int stones = 0;

                // Process segment till obstacle or end
                while (k < n && boxGrid[i][k] != '*') {
                    if (boxGrid[i][k] == '#') stones++;
                    k++;
                }

                int len = k - j;

                // stones to the right 
                for (int x = 0; x < len; x++) {
                    if (x < len - stones) boxGrid[i][j + x] = '.';
                    else boxGrid[i][j + x] = '#';
                }

                // Place obstacle if exists
                if (k < n && boxGrid[i][k] == '*') k++;

                j = k;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> boxGrid = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}
    };

    vector<vector<char>> res = sol.rotateTheBox(boxGrid);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}