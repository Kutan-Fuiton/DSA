#include<iostream>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int bcount = 0; 
        int del = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'a' && bcount>0){
                del = min(del+1, bcount);
            } else if (s[i] == 'b'){
                bcount++;
            }
        }
        return del;
    }
};

int main(){
    Solution sol;
    cout << sol.minimumDeletions("aababbab") << endl;
    return 0;
}