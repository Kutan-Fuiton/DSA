#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        queue<int> q;
        string best = "";
        int min_len = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                q.push(i);
            }

            if (q.size() > k) {
                q.pop();
            }

            if (q.size() == k) {
                int start = q.front();
                int end = q.back();
                int len = end - start + 1;
                string sub = s.substr(start, len);

                if (len < min_len) {
                    min_len = len;
                    best = sub;
                } else if (len == min_len) {
                    best = min(best, sub); // Lexicographically smallest
                }
            }
        }

        return best;
    }
};

int main(){
    Solution sol;
    cout << sol.shortestBeautifulSubstring("1000111000111", 3) << endl;
    return 0;
}