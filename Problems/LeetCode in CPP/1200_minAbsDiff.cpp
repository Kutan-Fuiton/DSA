#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        // finding minimum difference
        int MIN = INT32_MAX;
        for (int i = 0; i < arr.size()-1; i++){
            MIN = min(MIN, arr[i+1]-arr[i]);
        }

        // only pushing that elements which are equal to minimum difference
        for (int i = 0; i < arr.size()-1; i++){
            if (arr[i+1]-arr[i] == MIN){
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};


// This is One solution which dont have to find minimum at first...

// class Solution {
// public:
//     vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
//         vector<vector<int>> res;
//         sort(arr.begin(), arr.end());
//         int MIN = INT32_MAX;
//         for (int i = 0; i < arr.size()-1; i++){
//             int temp = arr[i+1]-arr[i];
//             if (temp < MIN){
//                 MIN = temp;
//                 res.clear();
//                 res.push_back({arr[i], arr[i+1]});
//             }
//             else if (temp == MIN){
//                 res.push_back({arr[i], arr[i+1]});
//             }
//             else {
//                 continue;
//             }
//         }
//         return res;
//     }
// };

int main(){
    Solution sol;
    // vector<int> arr = {4,2,1,3};
    vector<int> arr = {1,3,6,10,15};

    vector<vector<int>> res = sol.minimumAbsDifference(arr);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}