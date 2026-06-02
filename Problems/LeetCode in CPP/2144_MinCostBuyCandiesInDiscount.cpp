#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int n = cost.size();

        int count = 0; 
        for (int i = 0; i < n; i++){
            if ((i+1)%3 == 0 && n >=3) continue;
            count += cost[i];
        }

        return count;
    }
};

int main(){
    Solution sol;
    // vector<int> cost = {6,5,7,9,2,2};
    vector<int> cost = {3,3,3,1};

    cout << sol.minimumCost(cost) << endl;
    return 0;
}