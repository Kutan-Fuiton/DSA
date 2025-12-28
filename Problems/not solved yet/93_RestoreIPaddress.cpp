#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> res;
    }
};

int main(){
    Solution sol;
    // string s = "255255255255";
    // string s = "0000";
    string s = "25525511135";

    cout << s.size() << endl;
    vector<string> res = sol.restoreIpAddresses(s);

    for (string s: res){
        cout << s << endl;
    }

    return 0;
}