// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution {
// public:
//     bool pyramidTransition(string bottom, vector<string>& allowed) {
//         if (bottom.size()<2) return true;

//         vector<vector<string>> cont;

//         for (int i = 0; i < bottom.size()-1; i++){
//             vector<string> curr;
//             for (const string& s : allowed){
//                 if (bottom.substr(i, 2) == s.substr(0,2)){
//                     curr.push_back(s.substr(2,1));
//                 }
//             }

//             if (curr.empty()) return false;
//             cont.push_back(curr);
//         }

//         vector <string> next_bottom = build(cont, 0);

//         for (const string& s : next_bottom){
//             if (pyramidTransition(s, allowed)) return true;
//         }
//         return false;
//     }

// private:
//     static vector<string> build(const vector<vector<string>>& cont, int row) {
//         if (row == cont.size()) {
//             return {""};  // base: one empty combination
//         }

//         vector<string> result;
//         vector<string> suffixes = build(cont, row + 1);

//         for (const string& c : cont[row]) {
//             for (const string& s : suffixes) {
//                 result.push_back(c + s);
//             }
//         }

//         return result;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        if (mp.empty()) {
            for (auto &s : allowed)
                mp[s.substr(0,2)].push_back(s[2]);
        }

        vector<string> next;
        build(bottom, 0, "", next);

        for (auto &s : next)
            if (pyramidTransition(s, allowed))
                return memo[bottom] = true;

        return memo[bottom] = false;
    }

private:
    void build(string &bottom, int i, string cur, vector<string>& res) {
        if (i == bottom.size() - 1) {
            res.push_back(cur);
            return;
        }

        string key = bottom.substr(i, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key])
            build(bottom, i + 1, cur + c, res);
    }
};

int main(){
    Solution sol;
    // string bottom = "BCD";
    // vector<string> str = {"BCC","CDE","CEA","FFF"};

    // string bottom = "AAAA";
    // vector<string> str = {"AAB","AAC","BCD","BBE","DEF"};

    // string bottom = "ABCD";
    // vector<string> str = {"ABC", "ABD", "ACD", "BCD", "BCE", "BDD", "BDE", "CDE", "CED", "DEE", "CEE"};
    
    // string bottom = "ABCD";
    // vector<string> str = {"ABE", "BCF", "CDG", "AEF", "BFG", "EGH", "FGH", "HHG", "EFH"};
    
    string bottom = "AFFFA";
    vector<string> str = {"ADA","ADC","ADB","AEA","AEC","AEB","AFA","AFC","AFB","CDA","CDC","CDB","CEA","CEC","CEB","CFA","CFC","CFB","BDA","BDC","BDB","BEA","BEC","BEB","BFA","BFC","BFB","DAA","DAC","DAB","DCA","DCC","DCB","DBA","DBC","DBB","EAA","EAC","EAB","ECA","ECC","ECB","EBA","EBC","EBB","FAA","FAC","FAB","FCA","FCC","FCB","FBA","FBC","FBB","DDA","DDC","DDB","DEA","DEC","DEB","DFA","DFC","DFB","EDA","EDC","EDB","EEA","EEC","EEB","EFA","EFC","EFB","FDA","FDC","FDB","FEA","FEC","FEB","FFA","FFC","FFB","DDD","DDE","DDF","DED","DEE","DEF","DFD","DFE","DFF","EDD","EDE","EDF","EED","EEE","EEF","EFD","EFE","EFF","FDD","FDE","FDF","FED","FEE","FEF","FFD","FFE","FFF"};
    
    cout << sol.pyramidTransition(bottom, str) << endl;

    return 0;
}