#include<iostream>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0, prev = 0, curr = 0;
        char set = s[0];
        for (int i = 0; i < s.size(); i++){
            if (set == s[i]){
                curr++;
            } else {
                count += min(prev, curr);
                set = (set == '0') ? '1' : '0';
                prev = curr;
                curr = 1;
            }

            if (i == s.size()-1) count += min(prev, curr);
        }
        return count;
    }
};

int main(){
    Solution sol;
    cout << sol.countBinarySubstrings("0011100110") << endl;
    return 0;
}