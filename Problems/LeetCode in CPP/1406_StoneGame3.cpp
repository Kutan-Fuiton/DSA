#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Extra 3 spaces for dp[i+1], dp[i+2], dp[i+3]
        vector<int> dp(n+3, 0);

        for (int i = n - 1; i >= 0; i--) {
            int current_sum = 0;
            dp[i] = INT32_MIN;

            // try taking k = 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                current_sum += stoneValue[i + k - 1]; // points picked in this turn
                
                // current gain - opponent's best remaining advantage
                int choice = current_sum - dp[i + k];
                
                dp[i] = max(dp[i], choice);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};

int main(){
    Solution sol;
    vector<int> stoneValue = {1, 2, -3, 4, -1, -2, 5, -10, 6, 2};

    cout << sol.stoneGameIII(stoneValue) << endl;
    return 0;
}