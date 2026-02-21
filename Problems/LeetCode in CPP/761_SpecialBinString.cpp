#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) return s;

        vector<string> div;
        int idx;
        int bal = 0;
        for (int i = 0; i < s.size(); i++){
            if (bal == 0) idx = i;

            if (s[i] == '1') bal++;
            else bal--;

            if (bal == 0) {
                div.push_back(s.substr(idx, i - idx + 1));
            }
        }
        
        for (int i = 0; i < div.size(); i++){
            if (div[i].size() <= 2) continue;
            
            div[i] = '1' + makeLargestSpecial(div[i].substr(1, div[i].size()-2)) + '0';
        }
        
        sort(div.begin(), div.end(), greater<string>());

        string res;
        for (int i = 0; i < div.size(); i++){
            res.append(div[i]);
        }

        return res;
    }
};

int main(){
    Solution sol;

    cout << sol.makeLargestSpecial("110110110000") << endl;
    // cout << sol.makeLargestSpecial("1101001100") << endl;

    return 0;
}