#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size(), k = 0;
        int cols = len/rows;

        string res = "";
        vector<vector<char>> build (rows, vector<char> (cols));

        for (int i = 0; k < len && i < rows; i++){
            for (int j = 0; k < len && j < cols; j++){
                build[i][j] = encodedText[k];
                k++;
            }
        }
        
        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;
            while (i < rows && j < cols) {
                res += build[i][j];
                i++; j++;
            }
        }
        
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.decodeCiphertext("iveo    eed   l te   olc", 4);
    // cout << sol.decodeCiphertext("coding", 1);
    return 0;
}