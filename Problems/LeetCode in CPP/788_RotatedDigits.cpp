#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    string num;
    int dp[20][2][2][2];   // pos, tight, hasGood, started

    int solve(int pos, int tight, int hasGood, int started) {

        if (pos == num.size()) {
            return (started && hasGood);
        }

        int &res = dp[pos][tight][hasGood][started];
        if (res != -1) return res;

        res = 0;

        int limit = tight ? (num[pos] - '0') : 9;

        for (int d = 0; d <= limit; d++) {

            // skip bad digits
            if (d == 3 || d == 4 || d == 7) continue;

            int new_tight = tight && (d == limit);
            int new_started = started || (d != 0);

            int new_hasGood = hasGood;
            if (new_started && (d == 2 || d == 5 || d == 6 || d == 9)) {
                new_hasGood = 1;
            }

            res += solve(pos + 1, new_tight, new_hasGood, new_started);
        }

        return res;
    }

    int rotatedDigits(int n) {
        num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, 0);
    }
};

int main(){
    Solution sol;
    cout << sol.rotatedDigits(16) << endl;
    return 0;
}