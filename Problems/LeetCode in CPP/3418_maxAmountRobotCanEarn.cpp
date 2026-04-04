#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT32_MIN)));

        return solve(coins, 0, 0, 2);
    }

    int solve(vector<vector<int>>& coins, int i, int j, int k) {
        // Out of bounds
        if (i >= m || j >= n) return INT32_MIN;

        // Destination
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] >= 0) return coins[i][j];

            // If negative
            if (k > 0) return 0; // neutralize
            return coins[i][j];  // take loss
        }

        if (dp[i][j][k] != INT32_MIN) return dp[i][j][k];

        int val = coins[i][j];

        int best = INT32_MIN;

        if (val >= 0) {
            int down = solve(coins, i + 1, j, k);
            int right = solve(coins, i, j + 1, k);

            best = val + max(down, right);
        } 
        else {
            // Option 1: take loss
            int down1 = solve(coins, i + 1, j, k);
            int right1 = solve(coins, i, j + 1, k);

            int takeLoss = val + max(down1, right1);

            best = takeLoss;

            // Option 2: neutralize (if possible)
            if (k > 0) {
                int down2 = solve(coins, i + 1, j, k - 1);
                int right2 = solve(coins, i, j + 1, k - 1);

                int neutralize = max(down2, right2);

                best = max(best, neutralize);
            }
        }

        return dp[i][j][k] = best;
    }
};

int main(){
    return 0;
}