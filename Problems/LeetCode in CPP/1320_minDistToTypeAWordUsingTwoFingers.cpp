#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        
        // dp[j] = max saving if second finger is at letter j
        vector<int> dp(26, 0);

        int total = 0;

        for (int i = 1; i < n; i++) {
            char prev = word[i - 1];
            char curr = word[i];

            int d = dist(prev, curr);
            total += d;

            vector<int> new_dp = dp;

            for (int j = 0; j < 26; j++) {
                char pos2 = 'A' + j;

                // saving if we use second finger instead of first
                int gain = d - dist(pos2, curr);

                // second finger moves -> now first finger stays at prev
                new_dp[prev - 'A'] = max(new_dp[prev - 'A'], dp[j] + gain);
            }

            dp = new_dp;
        }

        int saved = 0;
        for (int j = 0; j < 26; j++) {
            saved = max(saved, dp[j]);
        }

        return total - saved;
    }

private:
    int dist(char ch1, char ch2){
        int x = abs(((ch1 - 'A')/6) - ((ch2 - 'A')/6));
        int y = abs(((ch1 - 'A')%6) - ((ch2 - 'A')%6));

        return x + y;
    }
};

int main(){
    Solution sol;
    cout << sol.minimumDistance("HAPPY") << endl;
    return 0;
}