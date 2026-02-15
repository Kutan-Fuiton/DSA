#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) return triangle[0][0];

        vector<int> dp = triangle[n-1]; 
        for (int i = 1; i < n; i++){
            vector<int> temp;
            for (int j = 0; j < triangle[n-i-1].size(); j++){
                temp.push_back(triangle[n-i-1][j] + min(dp[j], dp[j+1]));
            }
            dp = temp;
        }
        return dp[0];
    }
};

int main(){
    Solution sol;

    // vector<vector<int>> triangle = {
    //     {-1},
    //     {2, 3},
    //     {1, -1, -3}
    // };
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << sol.minimumTotal(triangle) << endl;

    return 0;
}