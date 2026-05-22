#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> pref;
        for (const int& num : arr1){
            int n = num;
            while (n != 0){
                pref.insert(n);
                n /= 10;
            }
        }

        int MAX = 0;
        for (const int& num : arr2){
            int n = num;
            while (n != 0){
                if (pref.count(n)){
                    int len = (n == 0) ? 1 : (int)log10(abs(n)) + 1;
                    MAX = max(MAX, len);
                }
                n /= 10;
            }
        }

        return MAX;
    }
};

int main(){
    Solution sol;
    // vector<int> arr1 = {1,10,100}; vector<int> arr2 = {1000};
    vector<int> arr1 = {10,17}; vector<int> arr2 = {11};

    cout << sol.longestCommonPrefix(arr1, arr2) << endl;

    return 0;
}