#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sorting the 2d array, with 0th element of 1d sub arrays...
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});

    }
};

int main(){
    Solution sol;
    // vector<vector<int>> meetings = {
    //     {5, 6}, 
    //     {0, 10}, 
    //     {3, 4}, 
    //     {1, 2}
    // };
    vector<vector<int>> meetings = {
        {10, 20},
        {2, 5},
        {3, 7}, 
        {5, 9},
        {1, 15},
        {12, 18}, 
        {6, 8},
    };
    int n = 2;

    cout << sol.mostBooked(n, meetings) << endl;

    // for (int i = 0; i < meetings.size(); i++){
    //     for (int j = 0; j < meetings[i].size(); j++){
    //         cout << meetings[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b){
    //     return a[0] < b[0];
    // });
    
    // for (int i = 0; i < meetings.size(); i++){
    //     for (int j = 0; j < meetings[i].size(); j++){
    //         cout << meetings[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}