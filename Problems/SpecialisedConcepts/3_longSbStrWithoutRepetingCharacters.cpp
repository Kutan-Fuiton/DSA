#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        unordered_set<char> chk;
        int left = 0;
        int len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // If we find a duplicate, shrink the window from the left
            while (chk.find(s[i]) != chk.end()) {
                chk.erase(s[left]);
                left++;
            }
            
            // Add the current character to the set and update maxLength
            chk.insert(s[i]);
            len = max(len, i - left + 1);
        }
        
        return len;
    }
};

int main(){
    Solution sol;

    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}