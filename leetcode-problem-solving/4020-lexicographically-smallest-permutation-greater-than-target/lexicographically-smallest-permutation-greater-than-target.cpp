#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (const char c : s) count[c-'a']++;

        // Maximum Match len from start for both s and target string
        int match_len = 0;
        while (match_len < n && count[target[match_len] - 'a'] > 0){
            count[target[match_len] - 'a']--;
            match_len++;
        }

        // backtrack from maximum match len to 0
        for (int i = match_len; i >= 0; i--){
            if (i<n){
                // smallest character strictly greater than target[i]
                for (int c = (target[i] - 'a') + 1; c < 26; c++){
                    if (count[c] > 0){
                        count[c]--;

                        string res = target.substr(0, i);
                        res.push_back('a' + c);

                        // fill the rest in ascending order
                        for (int rem = 0; rem < 26; rem++){
                            while (count[rem] > 0){
                                res.push_back('a' + rem);
                                count[rem]--;
                            }
                        }
                        return res;
                    }
                }
            }

            // backtrack target[i-1]
            if (i > 0){
                count[target[i-1] - 'a']++;
            }
        }

        return "";
    }
};