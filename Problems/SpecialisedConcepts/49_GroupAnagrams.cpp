#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping;

        for (const string& s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());

            mapping[sorted].push_back(s);
        }

        vector<vector<string>> res;

        // pair means (key, value) pair in hash map (or unordered map)
        for (const auto& pair : mapping){
            res.push_back(pair.second);
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> group = sol.groupAnagrams(strs);
    for (int i = 0; i < group.size(); i++){
        for (int j = 0; j < group[i].size(); j++){
            cout << group[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}