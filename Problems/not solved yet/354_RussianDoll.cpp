#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
            if (a[0] == b[0])
                return a[1] < b[1];  
            return a[0] < b[0];      
        });
        int count = 0, j = 0;
        for (int i = 1; i < envelopes.size(); i++){
            if ((envelopes[i][0]>envelopes[j][0]) && (envelopes[i][1]>envelopes[j][1])){
                count++;
                j = i;
                cout << i << ": " << count << endl;
            } else if (j == 0 && (envelopes[i][0]>envelopes[i-1][0]) && (envelopes[i][1]>envelopes[i-1][1])){
                count++; 
                j = i;
            } else {
                continue;
            }
        }
        count++;
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> envelopes = {
        {2, 100},
        {3, 200},
        {4, 300},
        {5, 500},
        {5, 400},
        {5, 250},
        {6, 370},
        {6, 360},
        {7, 380}
    };
    // vector<vector<int>> envelopes = {
    //     {1, 2},  
    //     {2, 3},  
    //     {3, 4},  
    //     {3, 5},  
    //     {4, 5},  
    //     {5, 5},
    //     {5, 6},
    //     {6, 7},
    //     {7, 8}
    // };
    // vector<vector<int>> envelopes = {
    //     {5,4},
    //     {6,4},
    //     {6,7}, 
    //     {2,3}
    // };
    // vector<vector<int>> envelopes = {
    //     {1,8},
    //     {2,3},
    //     {3,4},
    //     {4,5},
    //     {5,6}
    // };

    cout << sol.maxEnvelopes(envelopes) << endl;

    sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
        if (a[0] == b[0])
            return a[1] < b[1];  
        return a[0] < b[0];      
    });

    for (int i = 0; i < envelopes.size(); i++){
        for (int j = 0; j < envelopes[i].size(); j++){
            cout << envelopes[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}