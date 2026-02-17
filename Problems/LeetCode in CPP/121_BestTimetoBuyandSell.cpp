#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN = INT32_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++){
            MIN = min(MIN, prices[i]);
            profit = max(profit, prices[i] - MIN);
        }
        return profit;
    }
};

int main(){
    Solution sol;
    // vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices = {2,3,7,1,3,5};

    cout << sol.maxProfit(prices) << endl;

    return 0;
}