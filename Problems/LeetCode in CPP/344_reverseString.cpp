#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n/2; i++){
            swap(s[i], s[n-i-1]);
        }
    }
};

int main(){
    Solution sol;
    vector<char> s = {'H','a','n','n','a','h'};

    sol.reverseString(s);

    for (const char & ch : s){
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}