#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        vector<char> word(len, '?');

        // Apply 'T'
        for (int i = 0; i < n; i++){
            if (str1[i] == 'T'){
                for (int j = 0; j < m; j++){
                    if (word[i+j] == '?' || word[i+j] == str2[j]){
                        word[i+j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        // Filling '?' 
        for (int i = 0; i < len; i++){
            if (word[i] == '?') {

                // Try smallest possible character
                for (char c = 'a'; c <= 'z'; c++) {

                    word[i] = c;
                    bool valid = true;

                    // Check all substrings that include i
                    for (int start = max(0, i - m + 1); start <= i && start + m <= len; start++) {

                        int idx = start;
                        if (idx < n && str1[idx] == 'F') {

                            // check if this substring becomes equal to str2
                            bool match = true;
                            for (int j = 0; j < m; j++) {
                                if (word[start + j] != str2[j]) {
                                    match = false;
                                    break;
                                }
                            }

                            if (match) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) break; 
                }
            }
        }

        // Final check 
        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }

            if (str1[i] == 'T' && !match) return "";
            if (str1[i] == 'F' && match) return "";
        }

        return string(word.begin(), word.end());
    }
};

int main(){
    Solution sol;
    // cout << sol.generateString("TFTF", "ab") << endl;
    cout << sol.generateString("FTF", "aa") << endl;
    return 0;
}