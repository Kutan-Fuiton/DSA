#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int lim = 1 << k;

        if (s.size() < lim) return false;

        unordered_set<int> store;
        for (int i = 0; i <= s.size()-k; i++){
            int num = stoi(s.substr(i, k), nullptr, 2);
            if (num < lim) {
                store.insert(num);
            } 
        }
        if (store.size() == lim){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Solution sol;
    // cout << sol.hasAllCodes("00011100101", 3) << endl;
    // cout << sol.hasAllCodes("0110", 1) << endl;
    // cout << sol.hasAllCodes("0110", 2) << endl;
    // cout << sol.hasAllCodes("00110110", 2) << endl;
    cout << sol.hasAllCodes("0", 20) << endl;
    return 0;
}