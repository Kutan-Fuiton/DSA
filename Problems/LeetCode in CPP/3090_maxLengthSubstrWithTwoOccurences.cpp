#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, max_len = 0;
        vector<int> freq(26);
        for (int right = 0; right < s.size(); ++right){
            int idx = s[right] - 'a';
            freq[idx]++;
            
            while (freq[idx] > 2){
                freq[s[left]-'a']--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main(){
    Solution sol;
    cout << sol.maximumLengthSubstring("bcbbbcba") << endl;
    return 0;
}