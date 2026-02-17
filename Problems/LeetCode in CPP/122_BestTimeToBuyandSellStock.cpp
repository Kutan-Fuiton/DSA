#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] - prices[i-1] > 0){
                count += prices[i] - prices[i-1];
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    // vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices = {1,2,3,4,5};

    cout << sol.maxProfit(prices) << endl;
    return 0;
}