#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // if diagonals are decreasing
        for (int i = 0; i < n; i++){
            if (lcp[i][i] != n-i){
                return "";
            }
        }

        // lcp is symmetric
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (lcp[i][j] != lcp[j][i]){
                    return "";
                }
            }
        }

        // forming the word
        string word(n, '?');
        char ch = 'a';

        for (int i = 0; i < n; i++){
            if (word[i] == '?'){
                if (ch > 'z') return "";

                for (int j = 0; j < n; j++){
                    if (lcp[i][j] > 0){
                        word[j] = ch;
                    }
                }
                ch++;
            }
        }

        // final checking
        for (int i = n-1; i >= 0; i--){
            for (int j = n-1; j >= 0; j--){
                int expected = 0;

                if (word[i] == word[j]){
                    if (i+1 < n && j+1 < n) expected = 1 + lcp[i+1][j+1];
                    else expected = 1;
                }

                if (lcp[i][j] != expected) {
                    return "";
                }
            }
        }

        return word;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> lcp = {
        {6,0,4,0,2,0},
        {0,5,0,3,0,1},
        {4,0,4,0,2,0},
        {0,3,0,3,0,1},
        {2,0,2,0,2,0},
        {0,1,0,1,0,1}
    };

    cout << sol.findTheString(lcp) << endl;

    return 0;
}