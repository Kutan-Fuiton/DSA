#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4 || s.length() > 12) return res;
        
        vector<string> current_ip;
        backtrack(s, 0, 0, current_ip, res);
        return res;
    }

private:
    void backtrack(const string& s, int start_idx, int dots, vector<string>& current_ip, vector<string>& res) {
        if (dots == 4 && start_idx == s.length()) {
            res.push_back(current_ip[0] + "." + current_ip[1] + "." + current_ip[2] + "." + current_ip[3]);
            return;
        }
        if (dots == 4 || start_idx >= s.length()) return;

        for (int len = 1; len <= 3 && start_idx + len <= s.length(); len++) {
            string segment = s.substr(start_idx, len);
            
            if (segment.length() > 1 && segment[0] == '0') break;
            
            if (stoi(segment) <= 255) {
                current_ip.push_back(segment);
                backtrack(s, start_idx + len, dots + 1, current_ip, res);
                current_ip.pop_back();
            }
        }
    }
};