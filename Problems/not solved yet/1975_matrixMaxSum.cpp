#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int MIN = INT32_MAX;
        int neg_count = 0;
        long long sum = 0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                MIN = min(MIN, abs(matrix[i][j]));
                if (matrix[i][j] < 0) neg_count++;
                sum += abs(matrix[i][j]);
            }
        }

        if (neg_count%2 == 0) return sum;
        else return (sum - 2*MIN);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,-5,6},
        {-7,8,-9}
    };

    cout << sol.maxMatrixSum(matrix) << endl;

    return 0;
}