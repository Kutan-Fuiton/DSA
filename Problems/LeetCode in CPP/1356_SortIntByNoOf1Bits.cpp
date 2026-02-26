#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int A = __builtin_popcount(a);
            int B = __builtin_popcount(b);

            if (A == B)
                return a < b;   // tie-breaker

            return A < B;
        });

        return arr;
    }
};

int main(){
    Solution sol;
    // vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> arr = {1024,512,256,128,64,32,16,8,4,2,1};

    vector<int> res = sol.sortByBits(arr);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}