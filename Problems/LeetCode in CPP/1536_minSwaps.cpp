#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            zeros[i] = count;
        }
        
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int req = n - 1 - i; // no of trailing zeros required for that row
            int j = i;  // iterator: which will traverse through the zeros array, to check which one matching with this row
            
            // Find a row with enough trailing zeros
            while (j < n && zeros[j] < req) {
                j++;
            }
            
            // no row found condition
            if (j == n) return -1;
            
            // jth row to position i
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> inp = {{0,0,1}, {1,1,0}, {1,0,0}};

    cout << sol.minSwaps(inp) << endl;

    return 0;
}