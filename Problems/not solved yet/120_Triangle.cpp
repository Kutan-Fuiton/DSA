#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;\

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        int j; 
        int total = 0;
        for (int i = 0; i < triangle.size(); i++){
            if (i == 0) j = 0;
            else {
                if (triangle[i][j] > triangle[i][j+1]) j++;
            }
            total += triangle[i][j];
        }
        return total;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> triangle = {
        {-1},
        {2, 3},
        {1, -1, -3}
    };

    cout << sol.minimumTotal(triangle) << endl;

    return 0;
}