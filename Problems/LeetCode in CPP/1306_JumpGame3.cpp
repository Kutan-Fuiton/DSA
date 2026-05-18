#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size()) return false;
        if (arr[start] == 0) return true;
        
        if (arr[start] < 0) return false; 
        
        int jump = arr[start];
        arr[start] = -1; // Mark as visited
        
        // Try both directions
        return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};

int main(){
    Solution sol;
    vector<int> arr = {4,2,3,0,3,1,2}; int start = 5;
    // vector<int> arr = {3,0,2,1,2}; int start = 2;

    cout << sol.canReach(arr, start) << endl;

    return 0;
}