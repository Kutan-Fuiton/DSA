#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string res = "";

        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ' && (s[i+1] == ' ' || i == s.size()-1)){
                res += s[i];
                temp.push_back(res);
                res.clear();
            } else if (s[i] != ' ') {
                res += s[i];
            } else continue;
        }

        for (int i = temp.size()-1; i >= 0; i--) res += temp[i] + " ";

        res.pop_back();

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.reverseWords("the sky   is    blue") << endl;
    return 0;
}