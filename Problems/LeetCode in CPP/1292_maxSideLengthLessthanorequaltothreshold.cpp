#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        int low = 0, high = min(m, n);
        int res = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(pref, m, n, mid, threshold)) {
                res = mid;        
                low = mid + 1;    
            } else {
                high = mid - 1;   
            }
        }

        return res;
    }

private:
    bool check(vector<vector<int>>& pref, int m, int n, int k, int threshold) {
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                int sum = pref[i + k][j + k] - pref[i][j + k] - pref[i + k][j] + pref[i][j];
                if (sum <= threshold) return true;
            }
        }
        return false;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> mat = {
        {2,2,2,2},
        {2,2,2,2},
        {2,2,2,2}
    };
    // vector<vector<int>> mat = {
    //     {1, 1, 3, 2, 4, 3, 2},
    //     {1, 1, 3, 2, 4, 3, 2},
    //     {1, 1, 3, 2, 4, 3, 2}
    // };

    cout << sol.maxSideLength(mat, 1) << endl;
    // cout << sol.maxSideLength(mat, 4) << endl;
    // cout << sol.match(mat, 0,0,3,4) << endl;

    return 0;
}