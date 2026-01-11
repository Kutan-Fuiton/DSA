#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int total = 0;
        for (const int &s : s1){
            total += s;
        }
        for (const int &s : s2){
            total += s;
        }

        int MAX = 0;
        // vector<vector<int>> ascii;
        vector<vector<int>> ascii(s1.size()+1, vector<int>(s2.size()+1, 0));

        // initalise first row and column as 0
        for (int i = 0; i <= s1.size(); i++){
            for (int j = 0; j <= s2.size(); j++){
                ascii[i][j] = 0;
            }
        }

        for (int i = 1; i <= s1.size(); i++){
            for (int j = 1; j <= s2.size(); j++){
                int num;

                if (s1[i-1] == s2[j-1]) num = ascii[i-1][j-1] + (int)s2[j-1];
                else num = max(ascii[i-1][j], ascii[i][j-1]);

                ascii[i][j] = num;
                MAX = max(MAX, num);
            }
        }

        for (int i = 0; i <= s1.size(); i++){
            cout << i << "--> ";
            for (int j = 0; j <= s2.size(); j++){
                cout << "(" << j << ":" << ascii[i][j] << ")" << " ";
            }
            cout << endl;
        }

        return total - (2*MAX);
    }
};

int main(){
    Solution sol;
    string s1 = "z";
    string s2 = "a";

    cout << sol.minimumDeleteSum(s1, s2) << endl;

    return 0;
}