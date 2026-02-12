#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);
            int uniq = 0;
            int maxFreq = 0;

            for (int j = i; j < s.size(); j++) {
                int idx = s[j] - 'a';
                if (freq[idx] == 0) uniq++;
                freq[idx]++;

                maxFreq = max(maxFreq, freq[idx]);

                int len = j - i + 1;

                if (maxFreq * uniq == len)   // checking condition for balanced 
                    ans = max(ans, len);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.longestBalanced("abbac") << endl;
    return 0;
}