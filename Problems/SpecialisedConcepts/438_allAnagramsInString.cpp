#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        // Edge Case
        if (n < k) return {};

        vector<int> freq_perm(26, 0);
        vector<int> freq_temp(26, 0);

        vector<int> res;

        for (int i = 0; i < k; i++){
            freq_perm[p[i] - 'a']++; // permanent freq set (string p)
            freq_temp[s[i] - 'a']++; // first window initiate of string s of length k
        }

        // first window check
        if (freq_perm == freq_temp) res.push_back(0);

        for (int i = k; i < n; i++){
            freq_temp[s[i]-'a']++; // rightmost element enter
            freq_temp[s[i-k]-'a']--; // leftmost element exit

            if (freq_perm == freq_temp) res.push_back(i-k+1);
        }

        return res;
    }
};

int main(){
    Solution sol;
    // vector<int> res = sol.findAnagrams("cbaebabacd", "abc");
    vector<int> res = sol.findAnagrams("cbaebabacd", "xyz");
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}