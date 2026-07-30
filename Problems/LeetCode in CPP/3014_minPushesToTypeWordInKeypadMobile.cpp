#include<iostream>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n<8) return n;

        int pushes = n;
        while (n>=8){
            n -= 8;
            pushes += n;
        }
        return pushes;
    }
};

int main(){
    Solution sol;
    cout << sol.minimumPushes("xycdefghij") << endl;
    cout << sol.minimumPushes("abcde") << endl;
    return 0;
}