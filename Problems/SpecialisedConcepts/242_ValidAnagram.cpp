#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (n != t.size()) return false;

        vector<int> count (26, 0);

        for (const char ch : s){
            count[ch - 'a']++;
        }

        for (const char ch : t){
            count[ch - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};

int main(){
    Solution sol;
    // cout << sol.isAnagram("anagram","nagaram");
    cout << sol.isAnagram("act","cat");
    return 0;
}