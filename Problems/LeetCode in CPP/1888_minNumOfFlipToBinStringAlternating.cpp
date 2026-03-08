#include<iostream>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int alt1 = 0, alt2 = 0;
        int res = INT32_MAX;

        for (int i = 0; i < 2 * n; i++) {
            char exp1 = (i % 2) ? '1' : '0'; // 010101...
            char exp2 = (i % 2) ? '0' : '1'; // 101010...

            if (t[i] != exp1) alt1++;
            if (t[i] != exp2) alt2++;

            if (i >= n) {
                char old1 = ((i - n) % 2) ? '1' : '0';
                char old2 = ((i - n) % 2) ? '0' : '1';

                if (t[i - n] != old1) alt1--;
                if (t[i - n] != old2) alt2--;
            }

            if (i >= n - 1) {
                res = min(res, min(alt1, alt2));
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.minFlips("1110000") << endl;
    return 0;
}